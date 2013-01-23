#ifndef _MixerMicrophoneValue_H_
#define _MixerMicrophoneValue_H_
#pragma once
#include <windows.h>
#include <string>

class MixerMicrophoneValue
{//Adjust the microphone volume
    MIXERCONTROL LastMicroMixerControl;//vixercontrol of linked wavein of target device
    MIXERCONTROL LastMicroMixerControl_Mute;//mixer control for mute linked wavein of target device
	int ID_Device;
	int ID_Line_Dest;
	int ID_Line_SRC;
	int ID_Line_SRC_Num_Control;

    std::string NameOfLinkedWaveIn;
	bool flagLinkedToDeviceControl;
	std::string NameOfDefaultWaveIn;
	std::string NameOfTargetWaveIn;
	std::string defaultname;
	int ID_OfDefaultWaveIn;
	int ID_OfTargetWaveIn;
	unsigned int lastError;

    bool LinkToMicrophone(void);
    int CheckDefaultInDevice(void);//Get ID for Default WaveIn device

public:
	MixerMicrophoneValue(void);
	virtual ~MixerMicrophoneValue(void);

    const std::string &GetNameOfLinkedDevice();
	void Release(void);
	double GetVolume(void);
    void SetVolume(double volume);
    int MuteOff(bool state);
    bool IsMuteOff();
    int LinkToDevice(const std::string &namedevice);


};

#endif //_MixerMicrophoneValue_H_
