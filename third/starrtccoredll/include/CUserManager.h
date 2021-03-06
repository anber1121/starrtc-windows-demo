#pragma once
#include<string>
using namespace std;
#include "CServiceParam.h"

#define AUDIO_SAMPLE_RATE	16000
#define AUDIO_CHANNELS		1
#define AUDIO_BIT_RATE		32
class CAudioParam
{
public:
	int m_nSampleRateInHz;
	int m_nChannels;
	int m_nBitRate;
};

class CUserManager
{

public:
	string m_strAuthKey;
	string  m_strTokenId;

	string m_strIMServerIp;
	int m_nIMServerPort;
	bool m_bUserDispatch;

	CServiceParam m_ServiceParam;
	CAudioParam m_AudioParam;
};

