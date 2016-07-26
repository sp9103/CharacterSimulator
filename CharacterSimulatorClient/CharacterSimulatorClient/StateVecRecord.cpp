#include "StateVecRecord.h"


StateVecRecord::StateVecRecord(void)
{
	m_fp = NULL;
	m_aver = NULL;
	m_center = NULL;

	isOpen = false;
}


StateVecRecord::~StateVecRecord(void)
{
}

void StateVecRecord::OpenFile(char *Path, char *filename, char mode){
	char buf[256];
	char buf_aver[256];
	char buf_center[256];

	if(Path == NULL){	
		sprintf(buf, "%s/%s.bin", DEFAULT_FILE_PATH, filename);
		sprintf(buf_aver, "%s/%s_aver.bin", DEFAULT_FILE_PATH, filename);
		sprintf(buf_center, "%s/%s_center.bin", DEFAULT_FILE_PATH, filename);
	}
	else{				
		sprintf(buf, "%s/%s.bin", Path, filename);
		sprintf(buf_aver, "%s/%s_aver.bin", Path, filename);
		sprintf(buf_center, "%s/%s_center.bin", Path, filename);
	}

	if(mode == 'r'){
		m_fp = fopen(buf, "rb");
	}
	else if(mode == 'w'){
		m_fp = fopen(buf, "wb");
		m_aver = fopen(buf_aver, "wb");
		m_center = fopen(buf_center, "wb");
	}
	else{
		printf("OpenFile mode error!\n");
		return;
	}

	if(m_fp == NULL){
		printf("File not found!\n");
		return;
	}

	isOpen = true;
}

void StateVecRecord::CloseFile(){
	isOpen = false;

	if(m_fp != NULL){
		fclose(m_fp);
		m_fp = NULL;
	}

	if(m_aver != NULL){
		fclose(m_aver);
		m_aver = NULL;
	}

	if(m_center != NULL){
		fclose(m_center);
		m_center = NULL;
	}
}

void StateVecRecord::WriteState(StateVector src){
	if(m_fp != NULL && isOpen){
		fwrite(&src, sizeof(StateVector), 1, m_fp);
	}
}

bool StateVecRecord::ReadState(StateVector *dst){
	if(m_fp != NULL){
		fread(dst, sizeof(StateVector), 4, m_fp);
	}
	else return false;

	if(feof(m_fp)){
		printf("End of File!\n");
		return false;
	}

	return true;
}

bool StateVecRecord::ReadAver(StateVector *dst){
	if(m_fp != NULL){
		fread(dst, sizeof(StateVector), 1, m_aver);
	}
	else return false;

	if(feof(m_fp)){
		printf("End of File!\n");
		return false;
	}

	return true;
}

bool StateVecRecord::ReadCenter(StateVector *dst){
	if(m_fp != NULL){
		fread(dst, sizeof(StateVector), 1, m_center);
	}
	else return false;

	if(feof(m_fp)){
		printf("End of File!\n");
		return false;
	}

	return true;
}
