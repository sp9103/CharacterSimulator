enum _ActualJointType
{
	SpineBase	= 0,
	SpineMid	= 1,
	Neck	= 2,
	Head	= 3,
	ShoulderLeft	= 4,
	ElbowLeft	= 5,
	WristLeft	= 6,
	HandLeft	= 7,
	ShoulderRight	= 8,
	ElbowRight	= 9,
	WristRight	= 10,
	HandRight	= 11,
	HipLeft	= 12,
	KneeLeft	= 13,
	AnkleLeft	= 14,
	HipRight	= 16,
	KneeRight	= 17,
	AnkleRight	= 18,
	SpineShoulder	= 20,
	Actual_JointType_Count	= ( 19 ) 
} ;

typedef struct _CameraSpacePoint
{
	float X;
	float Y;
	float Z;
} 	CameraSpacePoint;

typedef struct StateVector{
	CameraSpacePoint joints[Actual_JointType_Count];
}StateVector;

typedef struct _renderData{
	int count;
	StateVector character[2];
}renderData;