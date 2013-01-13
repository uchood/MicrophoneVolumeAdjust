
#include "MixerMicrophoneValue.h"
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <iostream>

namespace MixerMicrophoneValue_namespace{
	std::unordered_map<size_t,std::string> map_componenttype;
	std::unordered_map<size_t,std::string> map_controltype;

    const char *GetTextErrorMMSystem(int err){
        const char *res=nullptr;
        switch(err){
            case MMSYSERR_NOERROR      :res="MMSYSERR_NOERROR";break;
            case MMSYSERR_ERROR        :res="MMSYSERR_ERROR";break;
            case MMSYSERR_BADDEVICEID  :res="MMSYSERR_BADDEVICEID";break;
            case MMSYSERR_NOTENABLED   :res="MMSYSERR_NOTENABLED";break;
            case MMSYSERR_ALLOCATED    :res="MMSYSERR_ALLOCATED";break;
            case MMSYSERR_INVALHANDLE  :res="MMSYSERR_INVALHANDLE";break;
            case MMSYSERR_NODRIVER     :res="MMSYSERR_NODRIVER";break;
            case MMSYSERR_NOMEM        :res="MMSYSERR_NOMEM";break;
            case MMSYSERR_NOTSUPPORTED :res="MMSYSERR_NOTSUPPORTED";break;
            case MMSYSERR_BADERRNUM    :res="MMSYSERR_BADERRNUM";break;
            case MMSYSERR_INVALFLAG    :res="MMSYSERR_INVALFLAG";break;
            case MMSYSERR_INVALPARAM   :res="MMSYSERR_INVALPARAM";break;
            case MMSYSERR_HANDLEBUSY   :res="MMSYSERR_HANDLEBUSY";break;
            case MMSYSERR_INVALIDALIAS :res="MMSYSERR_INVALIDALIAS";break;
            case MMSYSERR_BADDB        :res="MMSYSERR_BADDB";break;
            case MMSYSERR_KEYNOTFOUND  :res="MMSYSERR_KEYNOTFOUND";break;
            case MMSYSERR_READERROR    :res="MMSYSERR_READERROR";break;
            case MMSYSERR_WRITEERROR   :res="MMSYSERR_WRITEERROR";break;
            case MMSYSERR_DELETEERROR  :res="MMSYSERR_DELETEERROR";break;
            case MMSYSERR_VALNOTFOUND  :res="MMSYSERR_VALNOTFOUND";break;
            case MMSYSERR_NODRIVERCB   :res="MMSYSERR_NODRIVERCB";break;
    //		case MMSYSERR_MOREDATA     :res="MMSYSERR_MOREDATA ";break;
            case MIXERR_INVALCONTROL     :res="MIXERR_INVALCONTROL";break;

        }
        return res;
    }
    void FillComponetAndControlTypeMessges(){
        map_componenttype.clear();
        map_controltype.clear();
        using namespace std;
        map_componenttype.insert(pair<size_t,string>(MIXERLINE_COMPONENTTYPE_SRC_DIGITAL,"MIXERLINE_COMPONENTTYPE_SRC_DIGITAL"));
        map_componenttype.insert(pair<size_t,string>(MIXERLINE_COMPONENTTYPE_SRC_LINE,"MIXERLINE_COMPONENTTYPE_SRC_LINE"));
        map_componenttype.insert(pair<size_t,string>(MIXERLINE_COMPONENTTYPE_SRC_MICROPHONE,"MIXERLINE_COMPONENTTYPE_SRC_MICROPHONE"));
        map_componenttype.insert(pair<size_t,string>(MIXERLINE_COMPONENTTYPE_SRC_SYNTHESIZER,"MIXERLINE_COMPONENTTYPE_SRC_SYNTHESIZER"));
        map_componenttype.insert(pair<size_t,string>(MIXERLINE_COMPONENTTYPE_SRC_COMPACTDISC,"MIXERLINE_COMPONENTTYPE_SRC_COMPACTDISC"));
        map_componenttype.insert(pair<size_t,string>(MIXERLINE_COMPONENTTYPE_SRC_TELEPHONE,"MIXERLINE_COMPONENTTYPE_SRC_TELEPHONE"));
        map_componenttype.insert(pair<size_t,string>(MIXERLINE_COMPONENTTYPE_SRC_PCSPEAKER,"MIXERLINE_COMPONENTTYPE_SRC_PCSPEAKER"));
        map_componenttype.insert(pair<size_t,string>(MIXERLINE_COMPONENTTYPE_SRC_WAVEOUT,"MIXERLINE_COMPONENTTYPE_SRC_WAVEOUT"));
        map_componenttype.insert(pair<size_t,string>(MIXERLINE_COMPONENTTYPE_SRC_AUXILIARY,"MIXERLINE_COMPONENTTYPE_SRC_AUXILIARY"));
        map_componenttype.insert(pair<size_t,string>(MIXERLINE_COMPONENTTYPE_SRC_ANALOG,"MIXERLINE_COMPONENTTYPE_SRC_ANALOG"));
        map_componenttype.insert(pair<size_t,string>(MIXERLINE_COMPONENTTYPE_SRC_UNDEFINED,"MIXERLINE_COMPONENTTYPE_SRC_UNDEFINED"));
        map_componenttype.insert(pair<size_t,string>(MIXERLINE_COMPONENTTYPE_DST_DIGITAL,"MIXERLINE_COMPONENTTYPE_DST_DIGITAL"));
        map_componenttype.insert(pair<size_t,string>(MIXERLINE_COMPONENTTYPE_DST_LINE,"MIXERLINE_COMPONENTTYPE_DST_LINE"));
        map_componenttype.insert(pair<size_t,string>(MIXERLINE_COMPONENTTYPE_DST_MONITOR,"MIXERLINE_COMPONENTTYPE_DST_MONITOR"));
        map_componenttype.insert(pair<size_t,string>(MIXERLINE_COMPONENTTYPE_DST_SPEAKERS,"MIXERLINE_COMPONENTTYPE_DST_SPEAKERS"));
        map_componenttype.insert(pair<size_t,string>(MIXERLINE_COMPONENTTYPE_DST_HEADPHONES,"MIXERLINE_COMPONENTTYPE_DST_HEADPHONES"));
        map_componenttype.insert(pair<size_t,string>(MIXERLINE_COMPONENTTYPE_DST_TELEPHONE,"MIXERLINE_COMPONENTTYPE_DST_TELEPHONE"));
        map_componenttype.insert(pair<size_t,string>(MIXERLINE_COMPONENTTYPE_DST_WAVEIN,"MIXERLINE_COMPONENTTYPE_DST_WAVEIN"));
        map_componenttype.insert(pair<size_t,string>(MIXERLINE_COMPONENTTYPE_DST_VOICEIN,"MIXERLINE_COMPONENTTYPE_DST_VOICEIN"));
        map_componenttype.insert(pair<size_t,string>(MIXERLINE_COMPONENTTYPE_DST_UNDEFINED,"MIXERLINE_COMPONENTTYPE_DST_UNDEFINED"));

        map_controltype.insert(pair<size_t,string>(MIXERCONTROL_CONTROLTYPE_BASS ,"MIXERCONTROL_CONTROLTYPE_BASS "));
        map_controltype.insert(pair<size_t,string>(MIXERCONTROL_CONTROLTYPE_EQUALIZER ,"MIXERCONTROL_CONTROLTYPE_EQUALIZER "));
        map_controltype.insert(pair<size_t,string>(MIXERCONTROL_CONTROLTYPE_FADER ,"MIXERCONTROL_CONTROLTYPE_FADER "));
        map_controltype.insert(pair<size_t,string>(MIXERCONTROL_CONTROLTYPE_TREBLE ,"MIXERCONTROL_CONTROLTYPE_TREBLE "));
        map_controltype.insert(pair<size_t,string>(MIXERCONTROL_CONTROLTYPE_VOLUME,"MIXERCONTROL_CONTROLTYPE_VOLUME"));
        map_controltype.insert(pair<size_t,string>(MIXERCONTROL_CONTROLTYPE_MIXER ,"MIXERCONTROL_CONTROLTYPE_MIXER "));
        map_controltype.insert(pair<size_t,string>(MIXERCONTROL_CONTROLTYPE_MULTIPLESELECT ,"MIXERCONTROL_CONTROLTYPE_MULTIPLESELECT "));
        map_controltype.insert(pair<size_t,string>(MIXERCONTROL_CONTROLTYPE_MUX ,"MIXERCONTROL_CONTROLTYPE_MUX "));
        map_controltype.insert(pair<size_t,string>(MIXERCONTROL_CONTROLTYPE_SINGLESELECT,"MIXERCONTROL_CONTROLTYPE_SINGLESELECT"));
        map_controltype.insert(pair<size_t,string>(MIXERCONTROL_CONTROLTYPE_BOOLEANMETER ,"MIXERCONTROL_CONTROLTYPE_BOOLEANMETER "));
        map_controltype.insert(pair<size_t,string>(MIXERCONTROL_CONTROLTYPE_PEAKMETER ,"MIXERCONTROL_CONTROLTYPE_PEAKMETER "));
        map_controltype.insert(pair<size_t,string>(MIXERCONTROL_CONTROLTYPE_SIGNEDMETER ,"MIXERCONTROL_CONTROLTYPE_SIGNEDMETER "));
        map_controltype.insert(pair<size_t,string>(MIXERCONTROL_CONTROLTYPE_UNSIGNEDMETER,"MIXERCONTROL_CONTROLTYPE_UNSIGNEDMETER"));
        map_controltype.insert(pair<size_t,string>(MIXERCONTROL_CONTROLTYPE_DECIBELS ,"MIXERCONTROL_CONTROLTYPE_DECIBELS "));
        map_controltype.insert(pair<size_t,string>(MIXERCONTROL_CONTROLTYPE_PERCENT ,"MIXERCONTROL_CONTROLTYPE_PERCENT "));
        map_controltype.insert(pair<size_t,string>(MIXERCONTROL_CONTROLTYPE_SIGNED ,"MIXERCONTROL_CONTROLTYPE_SIGNED "));
        map_controltype.insert(pair<size_t,string>(MIXERCONTROL_CONTROLTYPE_UNSIGNED,"MIXERCONTROL_CONTROLTYPE_UNSIGNED"));
        map_controltype.insert(pair<size_t,string>(MIXERCONTROL_CONTROLTYPE_PAN ,"MIXERCONTROL_CONTROLTYPE_PAN "));
        map_controltype.insert(pair<size_t,string>(MIXERCONTROL_CONTROLTYPE_QSOUNDPAN ,"MIXERCONTROL_CONTROLTYPE_QSOUNDPAN "));
        map_controltype.insert(pair<size_t,string>(MIXERCONTROL_CONTROLTYPE_SLIDER,"MIXERCONTROL_CONTROLTYPE_SLIDER"));
        map_controltype.insert(pair<size_t,string>(MIXERCONTROL_CONTROLTYPE_BOOLEAN ,"MIXERCONTROL_CONTROLTYPE_BOOLEAN "));
        map_controltype.insert(pair<size_t,string>(MIXERCONTROL_CONTROLTYPE_BUTTON,"MIXERCONTROL_CONTROLTYPE_BUTTON"));
        map_controltype.insert(pair<size_t,string>(MIXERCONTROL_CONTROLTYPE_LOUDNESS ,"MIXERCONTROL_CONTROLTYPE_LOUDNESS "));
        map_controltype.insert(pair<size_t,string>(MIXERCONTROL_CONTROLTYPE_MONO,"MIXERCONTROL_CONTROLTYPE_MONO"));
        map_controltype.insert(pair<size_t,string>(MIXERCONTROL_CONTROLTYPE_MUTE,"MIXERCONTROL_CONTROLTYPE_MUTE"));
        map_controltype.insert(pair<size_t,string>(MIXERCONTROL_CONTROLTYPE_ONOFF,"MIXERCONTROL_CONTROLTYPE_ONOFF"));
        map_controltype.insert(pair<size_t,string>(MIXERCONTROL_CONTROLTYPE_STEREOENH,"MIXERCONTROL_CONTROLTYPE_STEREOENH"));
        map_controltype.insert(pair<size_t,string>(MIXERCONTROL_CONTROLTYPE_MICROTIME,"MIXERCONTROL_CONTROLTYPE_MICROTIME"));
        map_controltype.insert(pair<size_t,string>(MIXERCONTROL_CONTROLTYPE_MILLITIME,"MIXERCONTROL_CONTROLTYPE_MILLITIME"));
    }

};

using namespace MixerMicrophoneValue_namespace;
using namespace std;
MixerMicrophoneValue::MixerMicrophoneValue(void)
{
	flagLinkedToDeviceControl=false;
	defaultname.assign("default");
    MixerMicrophoneValue_namespace::FillComponetAndControlTypeMessges();
}


MixerMicrophoneValue::~MixerMicrophoneValue(void)
{
    Release();
}

const string &MixerMicrophoneValue::GetNameOfLinkedDevice()
{
    return NameOfLinkedWaveIn;
}


void MixerMicrophoneValue::Release(void)
{
	flagLinkedToDeviceControl=false;
}


int MixerMicrophoneValue::CheckDefaultInDevice(void)
{//return 0 in success
    int res=0;
	std::string resstring;
	WAVEFORMATEX wf;
	HWAVEIN HWI;
	int SamplesPerSec=16000;
	int BitsPerSample=16;
	int channels=2;
	wf.wBitsPerSample=static_cast<unsigned short>(BitsPerSample);
	wf.nAvgBytesPerSec=SamplesPerSec*BitsPerSample/8;
	wf.nChannels=static_cast<unsigned short>(channels);
	wf.nSamplesPerSec=SamplesPerSec;
	wf.wFormatTag=WAVE_FORMAT_PCM;
	wf.nBlockAlign=channels*BitsPerSample/8;
	wf.cbSize=0;
    //Name of default device restoring by waveInOpen with parameter WAVE_MAPPER
    int resOfOpen=waveInOpen(&HWI,WAVE_MAPPER,&wf,NULL,NULL,CALLBACK_NULL);
    if(resOfOpen==MMSYSERR_NOERROR){
		HMIXER        mixerHandle;
		MMRESULT  err = mixerOpen(&mixerHandle, (UINT)HWI, 0, 0, MIXER_OBJECTF_HWAVEIN);
		if(!err){
            MIXERCAPSA     mixcaps;
            if (!mixerGetDevCapsA((UINT)mixerHandle, &mixcaps, sizeof(MIXERCAPSA))){
                //found
				resstring.assign(mixcaps.szPname);
				NameOfDefaultWaveIn=resstring;
			}
			mixerClose(mixerHandle);
		}else{
            cerr<<"CheckDefaultInDevice error: "<<GetTextErrorMMSystem(err);
            res=-2;
		}
		waveInClose(HWI);
	}else{
        cerr<<"CheckDefaultInDevice error: "<<GetTextErrorMMSystem(resOfOpen);
        res=-1;
	}
    return res;
}


double MixerMicrophoneValue::GetVolume(void)
{// 0.-1.
	double res=0.;
    double Volume_01=0.;
	if(flagLinkedToDeviceControl){
		MMRESULT                        result;
		HMIXER                          hMixer;
		// get a handle to the mixer device
		result = mixerOpen(&hMixer, ID_OfTargetWaveIn , 0, 0, MIXER_OBJECTF_MIXER);
		if (MMSYSERR_NOERROR == result) {
			if(true){
				MIXERCONTROLDETAILS_UNSIGNED mixValue;
				MIXERCONTROLDETAILS mixDetails;
				mixDetails.cbStruct = sizeof(MIXERCONTROLDETAILS);
				mixDetails.dwControlID = LastMicroMixerControl.dwControlID;
				mixDetails.cChannels = (DWORD) 1;
				mixDetails.hwndOwner = NULL;
				mixDetails.cbDetails =sizeof(MIXERCONTROLDETAILS_UNSIGNED);
				mixDetails.paDetails = (LPMIXERCONTROLDETAILS_UNSIGNED)&mixValue;
                //read value
				result=mixerGetControlDetails((HMIXEROBJ)hMixer, (LPMIXERCONTROLDETAILS) &mixDetails,MIXER_SETCONTROLDETAILSF_VALUE);
				if(MMSYSERR_NOERROR == result){
                    Volume_01=(double)mixValue.dwValue/(double)LastMicroMixerControl.Bounds.lMaximum;
				}else{
                    cerr<<" mixerSetControlDetails for source failed\n";
                    cerr<<GetTextErrorMMSystem(result)<<endl;
				}
			}
			mixerClose(hMixer);
		}else{
            cerr<<"mixerOpen() failed"<<endl;
		}
	}
	return res=Volume_01;
}


void MixerMicrophoneValue::SetVolume(double Volume01)//
{   //[0.0,1.0]
    if(flagLinkedToDeviceControl){
		MMRESULT                        result;
		HMIXER                          hMixer;
		// get a handle to the mixer device
		result = mixerOpen(&hMixer, ID_OfTargetWaveIn , 0, 0, MIXER_OBJECTF_MIXER);
		if (MMSYSERR_NOERROR == result) {
			if(true){
				MIXERCONTROLDETAILS_UNSIGNED mixValue;
				mixValue.dwValue =(int)((double)LastMicroMixerControl.Bounds.lMaximum*Volume01) ;

				MIXERCONTROLDETAILS mixDetails;
				mixDetails.cbStruct = sizeof(MIXERCONTROLDETAILS);
				mixDetails.dwControlID = LastMicroMixerControl.dwControlID;
				mixDetails.cChannels = (DWORD) 1;
				mixDetails.hwndOwner = NULL;
				mixDetails.cbDetails =sizeof(MIXERCONTROLDETAILS_UNSIGNED);
				mixDetails.paDetails = (LPMIXERCONTROLDETAILS_UNSIGNED)&mixValue;
                //set value
				result=mixerSetControlDetails((HMIXEROBJ)hMixer, (LPMIXERCONTROLDETAILS) &mixDetails,MIXER_SETCONTROLDETAILSF_VALUE);
				if(MMSYSERR_NOERROR == result){
                //	clog<<" Volume changed to "<<mixValue.dwValue<<endl;
				}else{
                    cerr<<" mixerSetControlDetails for source failed\n";
                    cerr<<GetTextErrorMMSystem(result)<<endl;
				}
			}
			mixerClose(hMixer);
		}else{
            cerr<<"mixerOpen() failed"<<endl;
		}
	}
}


int MixerMicrophoneValue::LinkToDevice(const std::string &namedevice)
{
	int result=0;
    //restoring name of default device
    CheckDefaultInDevice();
    int numOfDefaultWaveIn=0;
	if(namedevice==defaultname){
        NameOfTargetWaveIn=NameOfDefaultWaveIn;
	}else{
        NameOfTargetWaveIn=namedevice;
	}
    MIXERCAPSA     mixcaps;
	unsigned long iNumDevs;
    // Get the number of Mixer devices in this computer
	iNumDevs = mixerGetNumDevs();
    std::vector<char> vector_NamePossibleTarget;
    int max_len=0;
    int targetdevice_num=-1;
    for (unsigned int i = 0; i < iNumDevs; i++){
        if (!mixerGetDevCapsA(i, &mixcaps, sizeof(MIXERCAPSA))){
            //check for ID of target WaveIn
            int len_name=strlen(mixcaps.szPname);
            auto pair_mismatch=std::mismatch(mixcaps.szPname,mixcaps.szPname+len_name,NameOfTargetWaveIn.begin());
            int lenequal_1=std::distance(NameOfTargetWaveIn.begin(),pair_mismatch.second);
            if(lenequal_1>max_len){//target - max distance of mismatch
                max_len=lenequal_1;
                targetdevice_num=i;//ID of possible target
                vector_NamePossibleTarget.resize(len_name);
                copy(mixcaps.szPname,mixcaps.szPname+len_name,vector_NamePossibleTarget.begin());
            }
            //check for ID of default WaveIn
            auto pair_mismatch_default=std::mismatch(mixcaps.szPname,mixcaps.szPname+len_name,NameOfDefaultWaveIn.begin());
            size_t lenequal_default=std::distance(NameOfDefaultWaveIn.begin(),pair_mismatch_default.second);
            if(lenequal_default==NameOfDefaultWaveIn.length()){
                numOfDefaultWaveIn=i;//ID of default
            }
        }
    }
    if(targetdevice_num>=0){//target found
        ID_OfTargetWaveIn=targetdevice_num;
        NameOfLinkedWaveIn.assign(&(vector_NamePossibleTarget[0]),vector_NamePossibleTarget.size());
    }else{//target not found - change target to deafult
        ID_OfTargetWaveIn=numOfDefaultWaveIn;
        NameOfLinkedWaveIn.assign(NameOfDefaultWaveIn);
    }
	flagLinkedToDeviceControl=true;
	LinkToMicrophone();
    result=flagLinkedToDeviceControl?0:-1;
    return result;
}


bool MixerMicrophoneValue::LinkToMicrophone(void)
{
	bool res=false;
	if(flagLinkedToDeviceControl){
		MMRESULT                        result;
		HMIXER                          hMixer;
		MIXERLINE                       ml   = {0};
		MIXERLINECONTROLS               mlc  = {0};
		MIXERCONTROLDETAILS             mcd  = {0};
		MIXERCONTROLDETAILS_UNSIGNED    mcdu = {0};

		// get a handle to the mixer device
		result = mixerOpen(&hMixer, ID_OfTargetWaveIn , 0, 0, MIXER_OBJECTF_MIXER);
		if (MMSYSERR_NOERROR == result) {
            MIXERCAPSA mixCaps;
            result = mixerGetDevCapsA(ID_OfTargetWaveIn, (LPMIXERCAPSA) &mixCaps,sizeof(MIXERCAPSA));
			if (MMSYSERR_NOERROR == result){
                std::clog<<mixCaps.szPname<<" #"<<ID_OfTargetWaveIn<<endl;
                bool flag_microphone_volume_control_found=false;
                for(unsigned int id=0;id<mixCaps.cDestinations;++id){
					if(flag_microphone_volume_control_found)break;
					bool flag_microphone=false;
                    unsigned int TypeSRCInMux=0;
					int NumSRCInMux=0;
					bool flag_NumSRCInMux_by_num=false;
                    // WwavIn or all than can be Microphone
					memset(&ml,0,sizeof(ml));
					ml.cbStruct = sizeof(MIXERLINE);
					ml.dwDestination = (DWORD) id;
					ml.dwSource = (DWORD) 0;
					// Get information on this line
					result = mixerGetLineInfo((HMIXEROBJ) hMixer, &ml, MIXER_GETLINEINFOF_DESTINATION);
					if (MMSYSERR_NOERROR == result){
                        if( ml.dwComponentType == MIXERLINE_COMPONENTTYPE_DST_VOICEIN
							||ml.dwComponentType == MIXERLINE_COMPONENTTYPE_DST_WAVEIN
							){ 
							flag_microphone=true;
						}
						if(flag_microphone){
                            // try find controller
							memset(&mlc,0,sizeof(mlc));
							mlc.cbStruct      = sizeof(MIXERLINECONTROLS);
							mlc.dwLineID      = ml.dwLineID;
                            mlc.cControls     = ml.cControls;//1;
							MIXERCONTROL                    mcarr[50];
							memset(&mcarr,0,sizeof(mcarr));
                            mlc.pamxctrl      = &(mcarr[0]);
							mlc.cbmxctrl      = sizeof(MIXERCONTROL);
							// get the volume controls associated with the speaker line
							result = mixerGetLineControls((HMIXEROBJ) hMixer, &mlc,MIXER_GETLINECONTROLSF_ALL /*MIXER_GETLINECONTROLSF_ONEBYTYPE*/);
							if (MMSYSERR_NOERROR == result){
                                for(unsigned int k=0;k<mlc.cControls;++k){
                                    // For this control, I make various checks on its type
									if(mcarr[k].dwControlType==MIXERCONTROL_CONTROLTYPE_VOLUME
										||mcarr[k].dwControlType==MIXERCONTROL_CONTROLTYPE_MUTE
                                        /*||mcarr[k].dwControlType==MIXERCONTROL_CONTROLTYPE_ONOFF*/ //onoff for usb it is usually automatic recording level control - DONT TOUCH
										){
                                        //if mute than ON
                                        //remember value of Volume contol
										memset(&mcdu,0,sizeof(mcdu));
										mcd.cbStruct    = sizeof(MIXERCONTROLDETAILS);
										mcd.hwndOwner   = 0;
										mcd.dwControlID = mcarr[k].dwControlID;//mc.dwControlID
										mcd.paDetails   = &mcdu;
										mcd.cbDetails   = sizeof(MIXERCONTROLDETAILS_UNSIGNED);
										mcd.cChannels   = 1;

										// set the volume
										result = mixerGetControlDetails((HMIXEROBJ) hMixer, &mcd, MIXER_SETCONTROLDETAILSF_VALUE);
										if (MMSYSERR_NOERROR == result){
											if(mcarr[k].dwControlType==MIXERCONTROL_CONTROLTYPE_VOLUME){
												LastMicroMixerControl=mcarr[k];
												ID_Device=ID_OfTargetWaveIn;
												ID_Line_Dest=ml.dwLineID;
												ID_Line_SRC=-1;
                                                ID_Line_SRC_Num_Control=-1;//id MIXERCONTROL_CONTROLTYPE_VOLUME
                                                flag_microphone_volume_control_found=true;
											}
											if(	mcarr[k].dwControlType==MIXERCONTROL_CONTROLTYPE_MUTE
                                                /*||mcarr[k].dwControlType==MIXERCONTROL_CONTROLTYPE_ONOFF*/ //onoff for usb it is usually automatic recording level control - DONT TOUCH
												){
												MIXERCONTROLDETAILS mixDetails;
												MIXERCONTROLDETAILS_BOOLEAN mixMute;
												mixDetails.cbStruct = sizeof(MIXERCONTROLDETAILS);
												mixDetails.dwControlID = mcarr[k].dwControlID;
												mixDetails.cChannels = (DWORD) 1;
												mixDetails.hwndOwner = NULL;
												mixDetails.cbDetails =sizeof(MIXERCONTROLDETAILS_BOOLEAN);
												mixDetails.paDetails = (LPMIXERCONTROLDETAILS_BOOLEAN)&mixMute;
												result = mixerGetControlDetails((HMIXEROBJ)hMixer,(LPMIXERCONTROLDETAILS) &mixDetails, MIXER_GETCONTROLDETAILSF_VALUE);
												if(MMSYSERR_NOERROR == result){
                                                    LastMicroMixerControl_Mute=mcarr[k];//remeber if we need in the future mute wavein
                                                    //Mute off
													mixMute.fValue = mcarr[k].Bounds.lMinimum;
													result=mixerSetControlDetails((HMIXEROBJ)hMixer, (LPMIXERCONTROLDETAILS) &mixDetails,MIXER_SETCONTROLDETAILSF_VALUE);
													if(MMSYSERR_NOERROR == result){
                                                    //	cout<<" Mute(OnOf) changed to "<<mixMute.fValue<<endl;
													}else{
                                                    //	cerr<<" mixerSetControlDetails for source failed\n";
                                                        cerr<<GetTextErrorMMSystem(result)<<endl;
													}
												}else{
                                                    cerr<<"mixerGetControlDetails for source failed\n";
                                                    cerr<<GetTextErrorMMSystem(result)<<endl;
												}
											}
										}else{
                                            cerr<<"mixerSetControlDetails() failed"<<endl;
                                            cerr<<GetTextErrorMMSystem(result)<<endl;

										}
									}
									if(mcarr[k].dwControlType == MIXERCONTROL_CONTROLTYPE_MUX ||
										mcarr[k].dwControlType ==MIXERCONTROL_CONTROLTYPE_MIXER){
                                        //remeber type of active device for src control
										// MIXERLINE_COMPONENTTYPE_SRC_MICROPHONE
                                        //find destination that work in source
										if(mcarr[k].cMultipleItems>1){
											MIXERCONTROLDETAILS_BOOLEAN mixBoolean[50];
											MIXERCONTROLDETAILS_LISTTEXT mixList[50];
//											flag_MUX=true;
											NumSRCInMux=0;
											mcd.cbStruct = sizeof(MIXERCONTROLDETAILS);
											mcd.dwControlID = mcarr[k].dwControlID;
											mcd.cChannels = 1;//mixLine.cChannels;
											mcd.cMultipleItems =  mcarr[k].cMultipleItems;
											mcd.cbDetails = sizeof(MIXERCONTROLDETAILS_BOOLEAN);
											mcd.paDetails = (LPMIXERCONTROLDETAILS_BOOLEAN)&mixBoolean[0];
											result = mixerGetControlDetails((HMIXEROBJ)hMixer, &mcd,	MIXER_GETCONTROLDETAILSF_VALUE);
											if (MMSYSERR_NOERROR ==result){
                                                for(unsigned int iS=0;iS<mcarr[k].cMultipleItems;iS++) {
													if(mixBoolean[iS].fValue==1){
														NumSRCInMux=iS;
													}
												}
                                                //check type of controller for NumSRCInMux
												mcd.cbStruct = sizeof(MIXERCONTROLDETAILS);
												mcd.dwControlID = mcarr[k].dwControlID;
												mcd.cChannels = 1;//mixLine.cChannels;
												mcd.cMultipleItems =  mcarr[k].cMultipleItems;
												mcd.cbDetails = sizeof(MIXERCONTROLDETAILS_LISTTEXT);
												mcd.paDetails = (LPMIXERCONTROLDETAILS_LISTTEXT)&mixList[0];
												result = mixerGetControlDetails((HMIXEROBJ)hMixer, &mcd,	MIXER_GETCONTROLDETAILSF_LISTTEXT);
												if (MMSYSERR_NOERROR ==result){
                                                    //type of controller for NumSRCInMux
													TypeSRCInMux=mixList[NumSRCInMux].dwParam2;
                                                //	cout<<"TypeSRCInMux: ["<<map_componenttype[mixList[NumSRCInMux].dwParam2]<<"] "<<endl;
												}else{					
                                                    cerr<<GetTextErrorMMSystem(result)<<endl;
												}
											}else{					
                                                cerr<<GetTextErrorMMSystem(result)<<endl;
											}
										}else{
											flag_NumSRCInMux_by_num=true;
										}
									}										
								}
							}else{
                                cerr<<"mixerGetLineControls for dest failed\n";
                                cerr<<GetTextErrorMMSystem(result)<<endl;
							}
							if(!flag_microphone_volume_control_found){
                                //try get control from SRC
                            //	cout<<"Get all "<<ml.cConnections<<" Source for this line \n";
                            //	cout<<"NumSRCInMux "<<NumSRCInMux<<endl;
								int cDest=ml.cConnections;
								bool flag_found_source=false;

								for(int iS=0;iS<cDest;++iS){
									if(flag_found_source){
										break;
									}
                                    //find source whose type is equal with TypeSRCInMux
									//может быть случай единственного источника
									MIXERLINE mixLine;
									mixLine.cbStruct = sizeof(MIXERLINE);
									mixLine.dwDestination = (DWORD) ml.dwDestination;
									mixLine.dwSource = (DWORD) iS;
									result = mixerGetLineInfo((HMIXEROBJ)hMixer, (LPMIXERLINE) &mixLine, MIXER_GETLINEINFOF_SOURCE);
									if(MMSYSERR_NOERROR == result){
											
                                    //	cout<<"\n"<<iS<<":"<<mixLine.szName<<" #"<<iS<<" "<<map_componenttype[mixLine.dwComponentType]<<endl;
										if(flag_NumSRCInMux_by_num||cDest==1){
                                    //		cout<<"Only one device source - we need it"<<endl;
											flag_found_source=true;
										}
										if(TypeSRCInMux==mixLine.dwComponentType){
                                    //		cout<<"WE nedeed it!"<<endl;
											flag_found_source=true;
										}
                                        if(!flag_found_source)continue;
										MIXERLINECONTROLS mixControls;
										MIXERCONTROL mixClist[50];
										mixControls.cbStruct = sizeof(MIXERLINECONTROLS);
										mixControls.dwLineID = mixLine.dwLineID;
										mixControls.cControls = mixLine.cControls;
										mixControls.cbmxctrl = sizeof(mixClist[0]);
										mixControls.pamxctrl = (LPMIXERCONTROL) &mixClist[0];
										result=mixerGetLineControls((HMIXEROBJ)hMixer, (LPMIXERLINECONTROLS) &mixControls,MIXER_GETLINECONTROLSF_ALL);
										if(MMSYSERR_NOERROR == result){
                                            //go throgh all cotntrols fo this line
                                            for(unsigned int iC=0;iC<mixLine.cControls;iC++){
												MIXERCONTROLDETAILS_UNSIGNED mixValue;
                                            //	cout<<map_controltype[mixClist[iC].dwControlType]<<" : "<<mixClist[iC].dwControlID;
												if(mixClist[iC].dwControlType==MIXERCONTROL_CONTROLTYPE_VOLUME){
													MIXERCONTROLDETAILS mixDetails;
													mixDetails.cbStruct = sizeof(MIXERCONTROLDETAILS);
													mixDetails.dwControlID = mixClist[iC].dwControlID;
													mixDetails.cChannels = (DWORD) 1;
													mixDetails.hwndOwner = NULL;
													mixDetails.cbDetails =sizeof(MIXERCONTROLDETAILS_UNSIGNED);
													mixDetails.paDetails = (LPMIXERCONTROLDETAILS_UNSIGNED)&mixValue;
														
													result = mixerGetControlDetails((HMIXEROBJ)hMixer,(LPMIXERCONTROLDETAILS) &mixDetails, MIXER_GETCONTROLDETAILSF_VALUE);
													if(MMSYSERR_NOERROR == result){
														if(flag_found_source){
                                                            //remeber sequence
															LastMicroMixerControl=mixClist[iC];
															ID_Device=ID_OfTargetWaveIn;
															ID_Line_Dest=id;
															ID_Line_SRC=iS;
                                                            ID_Line_SRC_Num_Control=iC;//number of MIXERCONTROL_CONTROLTYPE_VOLUME
														}
                                                    //	cout<<" mixValue="<<mixValue.dwValue<<" : ";
													}else{
                                                        cerr<<" mixerGetControlDetails for source failed\n";
                                                        cerr<<GetTextErrorMMSystem(result)<<endl;
													}
												}
                                                //if mute on - set OFF
												if(mixClist[iC].dwControlType==MIXERCONTROL_CONTROLTYPE_MUTE
                                                    /*||mixClist[iC].dwControlType==MIXERCONTROL_CONTROLTYPE_ONOFF*/ //onoff for usb it is usually automatic recording level control - DONT TOUCH
													){
													MIXERCONTROLDETAILS mixDetails;
													MIXERCONTROLDETAILS_BOOLEAN mixMute;
													mixDetails.cbStruct = sizeof(MIXERCONTROLDETAILS);
													mixDetails.dwControlID = mixClist[iC].dwControlID;
													mixDetails.cChannels = (DWORD) 1;
													mixDetails.hwndOwner = NULL;
													mixDetails.cbDetails =sizeof(MIXERCONTROLDETAILS_BOOLEAN);
													mixDetails.paDetails = (LPMIXERCONTROLDETAILS_BOOLEAN)&mixMute;
													result = mixerGetControlDetails((HMIXEROBJ)hMixer,(LPMIXERCONTROLDETAILS) &mixDetails, MIXER_GETCONTROLDETAILSF_VALUE);
													if(MMSYSERR_NOERROR == result){
                                                        LastMicroMixerControl_Mute=mixClist[iC];//remeber if we need in the future mute wavein
                                                        //set mute to off
														mixMute.fValue = mixClist[iC].Bounds.lMinimum;
														result=mixerSetControlDetails((HMIXEROBJ)hMixer, (LPMIXERCONTROLDETAILS) &mixDetails,MIXER_SETCONTROLDETAILSF_VALUE);
														if(MMSYSERR_NOERROR == result){
                                                        //	cerr<<" Mute(OnOf) changed to "<<mixMute.fValue<<endl;
														}else{
                                                            cerr<<" mixerSetControlDetails for source failed\n";
                                                            cerr<<GetTextErrorMMSystem(result)<<endl;
														}
													}else{
                                                        cerr<<"mixerGetControlDetails for source failed\n";
                                                        cerr<<GetTextErrorMMSystem(result)<<endl;
													}
												}
											}
										}else{
                                            cerr<<" mixerGetLineControls for source failed\n";
                                            cerr<<GetTextErrorMMSystem(result)<<endl;
										}
									}else{
                                        cerr<<" mixerGetLineInfo for source failed\n";
                                        cerr<<GetTextErrorMMSystem(result)<<endl;
									}
								}//iS
							}else{
								break;
							}
						};
					}else{
                        cerr<<"mixerGetLineInfo for dest failed\n";
                        cerr<<GetTextErrorMMSystem(result)<<endl;
					}
				}
				if(flag_microphone_volume_control_found)res=true;
			}else{
                cerr<<"mixerGetDevCaps failed\n";
                cerr<<GetTextErrorMMSystem(result)<<endl;
			}
			mixerClose(hMixer);
		}else{
            cerr<<"mixerOpen() failed"<<endl;
		}
	}
	return res;
}
