MicrophoneVolumeAdjust
======================

Adjust WaveIn volume in Windows.

Need compilator with C++11.

example of use
1. for Qt
add to .pro
QMAKE_CXXFLAGS += -std=c++0x
LIBS += -lwinmm

2. for MSVS 2010-2012
add in project - >properties->linker->additional libs - Winmm.lib

sample using code

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
}
