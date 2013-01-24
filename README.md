MicrophoneVolumeAdjust
======================

Adjust WaveIn volume in Windows: XP, Vista and 7.

Need compilator with C++11.

## Settings

Class need set some options in project:

1.  for Qt add to .pro file next lines:

	QMAKE_CXXFLAGS += -std=c++0x  
	LIBS += -lwinmm

2.  for MSVS 2010-2012
add in project - >properties->linker->additional libs - Winmm.lib

##  Sample using code
or see  \Example\Qt\mainwindow.cpp 

	#include "MixerMicrophoneValue.h"
	main()
	{
		MixerMicrophoneValue Adjuster;
		Adjuster.LinkToDevice(std::string("default"));//link to default WaveIn device
		std::cout<<Adjuster.GetVolume()<<std::endl;
		Adjuster.SetVolume(0.9);
		Adjuster.LinkToDevice(std::string("SBLive"));//link to default WaveIn device that name begin with "SBLive"
		std::cout<<Adjuster.GetVolume()<<std::endl;
		Adjuster.SetVolume(0.1);
		//Example of Mute
		bool muteoff=MixerInVolume.IsMuteOff();//check mute state
		std::cout<<"Microphone is mute "<<(muteoff?"Off":"On")<<std::endl;
		MixerInVolume.MuteOff(false);	//set mute on
		MixerInVolume.MuteOff(true);	//set mute off
	}
