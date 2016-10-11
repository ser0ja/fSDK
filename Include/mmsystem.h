/*+@@file@@----------------------------------------------------------------*//*!
 \file		mmsystem.h
 \par Description 
            Extension and update of headers for PellesC compiler suite.
 \par Project: 
            PellesC Headers extension
 \date		Created  on Mon Jun 27 01:27:14 2016
 \date		Modified on Mon Jun 27 01:27:14 2016
 \author	frankie
\*//*-@@file@@----------------------------------------------------------------*/

#ifndef _INC_MMSYSTEM
#define _INC_MMSYSTEM
#if __POCC__ >= 500
#pragma once
#endif
#ifdef _WIN32
#include <pshpack1.h>
#else
#ifndef RC_INVOKED
#pragma pack(1)
#endif
#endif

#ifdef _WIN32
#ifndef _WINMM_
#define WINMMAPI        DECLSPEC_IMPORT
#else
#define WINMMAPI
#endif
#define _loadds
#define _huge
#else
#define WINMMAPI
#endif
#define MAXPNAMELEN      32
#define MAXERRORLENGTH   256
#define MAX_JOYSTICKOEMVXDNAME 260
#if (WINVER <= 0x0400)
#ifndef MM_MICROSOFT
#define MM_MICROSOFT            1
#endif
#ifndef MM_MIDI_MAPPER
#define MM_MIDI_MAPPER          1
#define MM_WAVE_MAPPER          2
#define MM_SNDBLST_MIDIOUT      3
#define MM_SNDBLST_MIDIIN       4
#define MM_SNDBLST_SYNTH        5
#define MM_SNDBLST_WAVEOUT      6
#define MM_SNDBLST_WAVEIN       7
#define MM_ADLIB                9
#define MM_MPU401_MIDIOUT      10
#define MM_MPU401_MIDIIN       11
#define MM_PC_JOYSTICK         12
#endif
#endif
#ifdef _WIN32
typedef UINT MMVERSION;
#else
typedef UINT VERSION;
#endif
typedef UINT MMRESULT;
#define _MMRESULT_
typedef UINT FAR *LPUINT;
typedef struct mmtime_tag {
	UINT wType;
	union {
		DWORD ms;
		DWORD sample;
		DWORD cb;
		DWORD ticks;
		struct {
			BYTE hour;
			BYTE min;
			BYTE sec;
			BYTE frame;
			BYTE fps;
			BYTE dummy;
#ifdef _WIN32
			BYTE pad[2];
#endif
		} smpte;
		struct {
			DWORD songptrpos;
		} midi;
	} u;
} MMTIME, *PMMTIME, NEAR * NPMMTIME, FAR * LPMMTIME;
#define TIME_MS         0x0001
#define TIME_SAMPLES    0x0002
#define TIME_BYTES      0x0004
#define TIME_SMPTE      0x0008
#define TIME_MIDI       0x0010
#define TIME_TICKS      0x0020
#define MAKEFOURCC(ch0, ch1, ch2, ch3)                              \
                ((DWORD)(BYTE)(ch0) | ((DWORD)(BYTE)(ch1) << 8) |   \
                ((DWORD)(BYTE)(ch2) << 16) | ((DWORD)(BYTE)(ch3) << 24 ))
#define MM_JOY1MOVE         0x3A0
#define MM_JOY2MOVE         0x3A1
#define MM_JOY1ZMOVE        0x3A2
#define MM_JOY2ZMOVE        0x3A3
#define MM_JOY1BUTTONDOWN   0x3B5
#define MM_JOY2BUTTONDOWN   0x3B6
#define MM_JOY1BUTTONUP     0x3B7
#define MM_JOY2BUTTONUP     0x3B8
#define MM_MCINOTIFY        0x3B9
#define MM_WOM_OPEN         0x3BB
#define MM_WOM_CLOSE        0x3BC
#define MM_WOM_DONE         0x3BD
#define MM_WIM_OPEN         0x3BE
#define MM_WIM_CLOSE        0x3BF
#define MM_WIM_DATA         0x3C0
#define MM_MIM_OPEN         0x3C1
#define MM_MIM_CLOSE        0x3C2
#define MM_MIM_DATA         0x3C3
#define MM_MIM_LONGDATA     0x3C4
#define MM_MIM_ERROR        0x3C5
#define MM_MIM_LONGERROR    0x3C6
#define MM_MOM_OPEN         0x3C7
#define MM_MOM_CLOSE        0x3C8
#define MM_MOM_DONE         0x3C9
#ifndef MM_DRVM_OPEN
#define MM_DRVM_OPEN       0x3D0
#define MM_DRVM_CLOSE      0x3D1
#define MM_DRVM_DATA       0x3D2
#define MM_DRVM_ERROR      0x3D3
#endif
#define MM_STREAM_OPEN      0x3D4
#define MM_STREAM_CLOSE     0x3D5
#define MM_STREAM_DONE      0x3D6
#define MM_STREAM_ERROR     0x3D7
#if(WINVER >= 0x0400)
#define MM_MOM_POSITIONCB   0x3CA
#ifndef MM_MCISIGNAL
#define MM_MCISIGNAL        0x3CB
#endif
#define MM_MIM_MOREDATA      0x3CC
#endif
#define MM_MIXM_LINE_CHANGE     0x3D0
#define MM_MIXM_CONTROL_CHANGE  0x3D1
#define MMSYSERR_BASE          0
#define WAVERR_BASE            32
#define MIDIERR_BASE           64
#define TIMERR_BASE            96
#define JOYERR_BASE            160
#define MCIERR_BASE            256
#define MIXERR_BASE            1024
#define MCI_STRING_OFFSET      512
#define MCI_VD_OFFSET          1024
#define MCI_CD_OFFSET          1088
#define MCI_WAVE_OFFSET        1152
#define MCI_SEQ_OFFSET         1216
#define MMSYSERR_NOERROR      0
#define MMSYSERR_ERROR        (MMSYSERR_BASE + 1)
#define MMSYSERR_BADDEVICEID  (MMSYSERR_BASE + 2)
#define MMSYSERR_NOTENABLED   (MMSYSERR_BASE + 3)
#define MMSYSERR_ALLOCATED    (MMSYSERR_BASE + 4)
#define MMSYSERR_INVALHANDLE  (MMSYSERR_BASE + 5)
#define MMSYSERR_NODRIVER     (MMSYSERR_BASE + 6)
#define MMSYSERR_NOMEM        (MMSYSERR_BASE + 7)
#define MMSYSERR_NOTSUPPORTED (MMSYSERR_BASE + 8)
#define MMSYSERR_BADERRNUM    (MMSYSERR_BASE + 9)
#define MMSYSERR_INVALFLAG    (MMSYSERR_BASE + 10)
#define MMSYSERR_INVALPARAM   (MMSYSERR_BASE + 11)
#define MMSYSERR_HANDLEBUSY   (MMSYSERR_BASE + 12)
#define MMSYSERR_INVALIDALIAS (MMSYSERR_BASE + 13)
#define MMSYSERR_BADDB        (MMSYSERR_BASE + 14)
#define MMSYSERR_KEYNOTFOUND  (MMSYSERR_BASE + 15)
#define MMSYSERR_READERROR    (MMSYSERR_BASE + 16)
#define MMSYSERR_WRITEERROR   (MMSYSERR_BASE + 17)
#define MMSYSERR_DELETEERROR  (MMSYSERR_BASE + 18)
#define MMSYSERR_VALNOTFOUND  (MMSYSERR_BASE + 19)
#define MMSYSERR_NODRIVERCB   (MMSYSERR_BASE + 20)
#define MMSYSERR_MOREDATA     (MMSYSERR_BASE + 21)
#define MMSYSERR_LASTERROR    (MMSYSERR_BASE + 21)
#if (WINVER < 0x030a) || defined(_WIN32)
DECLARE_HANDLE(HDRVR);
#endif
#ifndef MMNODRV
#ifdef _WIN32
typedef struct DRVCONFIGINFOEX {
	DWORD dwDCISize;
	LPCWSTR lpszDCISectionName;
	LPCWSTR lpszDCIAliasName;
	DWORD dnDevNode;
} DRVCONFIGINFOEX, *PDRVCONFIGINFOEX, NEAR * NPDRVCONFIGINFOEX, FAR * LPDRVCONFIGINFOEX;
#else
typedef struct DRVCONFIGINFOEX {
	DWORD dwDCISize;
	LPCSTR lpszDCISectionName;
	LPCSTR lpszDCIAliasName;
	DWORD dnDevNode;
} DRVCONFIGINFOEX, *PDRVCONFIGINFOEX, NEAR * NPDRVCONFIGINFOEX, FAR * LPDRVCONFIGINFOEX;
#endif
#if (WINVER < 0x030a) || defined(_WIN32)
#ifndef DRV_LOAD
#define DRV_LOAD                0x0001
#define DRV_ENABLE              0x0002
#define DRV_OPEN                0x0003
#define DRV_CLOSE               0x0004
#define DRV_DISABLE             0x0005
#define DRV_FREE                0x0006
#define DRV_CONFIGURE           0x0007
#define DRV_QUERYCONFIGURE      0x0008
#define DRV_INSTALL             0x0009
#define DRV_REMOVE              0x000A
#define DRV_EXITSESSION         0x000B
#define DRV_POWER               0x000F
#define DRV_RESERVED            0x0800
#define DRV_USER                0x4000
#ifdef _WIN32
typedef struct tagDRVCONFIGINFO {
	DWORD dwDCISize;
	LPCWSTR lpszDCISectionName;
	LPCWSTR lpszDCIAliasName;
} DRVCONFIGINFO, *PDRVCONFIGINFO, NEAR * NPDRVCONFIGINFO, FAR * LPDRVCONFIGINFO;
#else
typedef struct tagDRVCONFIGINFO {
	DWORD dwDCISize;
	LPCSTR lpszDCISectionName;
	LPCSTR lpszDCIAliasName;
} DRVCONFIGINFO, *PDRVCONFIGINFO, NEAR * NPDRVCONFIGINFO, FAR * LPDRVCONFIGINFO;
#endif
#define DRVCNF_CANCEL           0x0000
#define DRVCNF_OK               0x0001
#define DRVCNF_RESTART          0x0002
#ifdef _WIN32
typedef LRESULT(CALLBACK *DRIVERPROC) (DWORD_PTR, HDRVR, UINT, LPARAM, LPARAM);
WINMMAPI LRESULT WINAPI CloseDriver(HDRVR hDriver, LPARAM lParam1, LPARAM lParam2);
WINMMAPI HDRVR WINAPI OpenDriver(LPCWSTR szDriverName, LPCWSTR szSectionName, LPARAM lParam2);
WINMMAPI LRESULT WINAPI SendDriverMessage(HDRVR hDriver, UINT message, LPARAM lParam1, LPARAM lParam2);
WINMMAPI HMODULE WINAPI DrvGetModuleHandle(HDRVR hDriver);
WINMMAPI HMODULE WINAPI GetDriverModuleHandle(HDRVR hDriver);
WINMMAPI LRESULT WINAPI DefDriverProc(DWORD_PTR dwDriverIdentifier, HDRVR hdrvr, UINT uMsg, LPARAM lParam1, LPARAM lParam2);
#else
LRESULT WINAPI DrvClose(HDRVR hdrvr, LPARAM lParam1, LPARAM lParam2);
HDRVR WINAPI DrvOpen(LPCSTR szDriverName, LPCSTR szSectionName, LPARAM lParam2);
LRESULT WINAPI DrvSendMessage(HDRVR hdrvr, UINT uMsg, LPARAM lParam1, LPARAM lParam2);
HINSTANCE WINAPI DrvGetModuleHandle(HDRVR hdrvr);
LRESULT WINAPI DrvDefDriverProc(DWORD dwDriverIdentifier, HDRVR hdrvr, UINT uMsg, LPARAM lParam1, LPARAM lParam2);
#define DefDriverProc DrvDefDriverProc
#endif
#endif
#endif
#if (WINVER >= 0x030a)
#define DRV_CANCEL             DRVCNF_CANCEL
#define DRV_OK                 DRVCNF_OK
#define DRV_RESTART            DRVCNF_RESTART
#endif
#define DRV_MCI_FIRST          DRV_RESERVED
#define DRV_MCI_LAST           (DRV_RESERVED + 0xFFF)
#endif
#define CALLBACK_TYPEMASK   0x00070000l
#define CALLBACK_NULL       0x00000000l
#define CALLBACK_WINDOW     0x00010000l
#define CALLBACK_TASK       0x00020000l
#define CALLBACK_FUNCTION   0x00030000l
#ifdef _WIN32
#define CALLBACK_THREAD     (CALLBACK_TASK)
#define CALLBACK_EVENT      0x00050000l
#endif
typedef void (CALLBACK DRVCALLBACK) (HDRVR hdrvr, UINT uMsg, DWORD_PTR dwUser, DWORD_PTR dw1, DWORD_PTR dw2);
typedef DRVCALLBACK FAR *LPDRVCALLBACK;
#ifdef _WIN32
typedef DRVCALLBACK *PDRVCALLBACK;
#endif
#ifndef MMNOSOUND
#ifdef _WIN32
WINMMAPI BOOL WINAPI sndPlaySoundA(LPCSTR pszSound, UINT fuSound);
WINMMAPI BOOL WINAPI sndPlaySoundW(LPCWSTR pszSound, UINT fuSound);
#ifdef UNICODE
#define sndPlaySound  sndPlaySoundW
#else
#define sndPlaySound  sndPlaySoundA
#endif
#else
BOOL WINAPI sndPlaySound(LPCSTR pszSound, UINT fuSound);
#endif
#define SND_SYNC            0x0000
#define SND_ASYNC           0x0001
#define SND_NODEFAULT       0x0002
#define SND_MEMORY          0x0004
#define SND_LOOP            0x0008
#define SND_NOSTOP          0x0010
#define SND_NOWAIT      0x00002000L
#define SND_ALIAS       0x00010000L
#define SND_ALIAS_ID    0x00110000L
#define SND_FILENAME    0x00020000L
#define SND_RESOURCE    0x00040004L
#if(WINVER >= 0x0400)
#define SND_PURGE           0x0040
#define SND_APPLICATION     0x0080
#endif
#define SND_SENTRY      0x00080000L
#define SND_RING        0x00100000L
#define SND_SYSTEM      0x00200000L
#define SND_ALIAS_START 0
#ifdef _WIN32
#define sndAlias(ch0, ch1)      (SND_ALIAS_START + (DWORD)(BYTE)(ch0) | ((DWORD)(BYTE)(ch1) << 8))
#define SND_ALIAS_SYSTEMASTERISK        sndAlias('S', '*')
#define SND_ALIAS_SYSTEMQUESTION        sndAlias('S', '?')
#define SND_ALIAS_SYSTEMHAND            sndAlias('S', 'H')
#define SND_ALIAS_SYSTEMEXIT            sndAlias('S', 'E')
#define SND_ALIAS_SYSTEMSTART           sndAlias('S', 'S')
#define SND_ALIAS_SYSTEMWELCOME         sndAlias('S', 'W')
#define SND_ALIAS_SYSTEMEXCLAMATION     sndAlias('S', '!')
#define SND_ALIAS_SYSTEMDEFAULT         sndAlias('S', 'D')
WINMMAPI BOOL WINAPI PlaySoundA(LPCSTR pszSound, HMODULE hmod, DWORD fdwSound);
WINMMAPI BOOL WINAPI PlaySoundW(LPCWSTR pszSound, HMODULE hmod, DWORD fdwSound);
#ifdef UNICODE
#define PlaySound  PlaySoundW
#else
#define PlaySound  PlaySoundA
#endif
#else
BOOL WINAPI PlaySound(LPCSTR pszSound, HMODULE hmod, DWORD fdwSound);
#endif
#endif
#ifndef MMNOWAVE
#define WAVERR_BADFORMAT      (WAVERR_BASE + 0)
#define WAVERR_STILLPLAYING   (WAVERR_BASE + 1)
#define WAVERR_UNPREPARED     (WAVERR_BASE + 2)
#define WAVERR_SYNC           (WAVERR_BASE + 3)
#define WAVERR_LASTERROR      (WAVERR_BASE + 3)
DECLARE_HANDLE(HWAVE);
DECLARE_HANDLE(HWAVEIN);
DECLARE_HANDLE(HWAVEOUT);
typedef HWAVEIN FAR *LPHWAVEIN;
typedef HWAVEOUT FAR *LPHWAVEOUT;
typedef DRVCALLBACK WAVECALLBACK;
typedef WAVECALLBACK FAR *LPWAVECALLBACK;
#define WOM_OPEN        MM_WOM_OPEN
#define WOM_CLOSE       MM_WOM_CLOSE
#define WOM_DONE        MM_WOM_DONE
#define WIM_OPEN        MM_WIM_OPEN
#define WIM_CLOSE       MM_WIM_CLOSE
#define WIM_DATA        MM_WIM_DATA
#define WAVE_MAPPER     ((UINT)-1)
#define  WAVE_FORMAT_QUERY                          0x0001
#define  WAVE_ALLOWSYNC                             0x0002
#if(WINVER >= 0x0400)
#define  WAVE_MAPPED                                0x0004
#define  WAVE_FORMAT_DIRECT                         0x0008
#define  WAVE_FORMAT_DIRECT_QUERY                   (WAVE_FORMAT_QUERY | WAVE_FORMAT_DIRECT)
#define  WAVE_MAPPED_DEFAULT_COMMUNICATION_DEVICE   0x0010
#endif
typedef struct wavehdr_tag {
	LPSTR lpData;
	DWORD dwBufferLength;
	DWORD dwBytesRecorded;
	DWORD_PTR dwUser;
	DWORD dwFlags;
	DWORD dwLoops;
	struct wavehdr_tag FAR *lpNext;
	DWORD_PTR reserved;
} WAVEHDR, *PWAVEHDR, NEAR * NPWAVEHDR, FAR * LPWAVEHDR;
#define WHDR_DONE       0x00000001
#define WHDR_PREPARED   0x00000002
#define WHDR_BEGINLOOP  0x00000004
#define WHDR_ENDLOOP    0x00000008
#define WHDR_INQUEUE    0x00000010
#ifdef _WIN32
typedef struct tagWAVEOUTCAPSA {
	WORD wMid;
	WORD wPid;
	MMVERSION vDriverVersion;
	CHAR szPname[MAXPNAMELEN];
	DWORD dwFormats;
	WORD wChannels;
	WORD wReserved1;
	DWORD dwSupport;
} WAVEOUTCAPSA, *PWAVEOUTCAPSA, *NPWAVEOUTCAPSA, *LPWAVEOUTCAPSA;
typedef struct tagWAVEOUTCAPSW {
	WORD wMid;
	WORD wPid;
	MMVERSION vDriverVersion;
	WCHAR szPname[MAXPNAMELEN];
	DWORD dwFormats;
	WORD wChannels;
	WORD wReserved1;
	DWORD dwSupport;
} WAVEOUTCAPSW, *PWAVEOUTCAPSW, *NPWAVEOUTCAPSW, *LPWAVEOUTCAPSW;
#ifdef UNICODE
typedef WAVEOUTCAPSW WAVEOUTCAPS;
typedef PWAVEOUTCAPSW PWAVEOUTCAPS;
typedef NPWAVEOUTCAPSW NPWAVEOUTCAPS;
typedef LPWAVEOUTCAPSW LPWAVEOUTCAPS;
#else
typedef WAVEOUTCAPSA WAVEOUTCAPS;
typedef PWAVEOUTCAPSA PWAVEOUTCAPS;
typedef NPWAVEOUTCAPSA NPWAVEOUTCAPS;
typedef LPWAVEOUTCAPSA LPWAVEOUTCAPS;
#endif
typedef struct tagWAVEOUTCAPS2A {
	WORD wMid;
	WORD wPid;
	MMVERSION vDriverVersion;
	CHAR szPname[MAXPNAMELEN];
	DWORD dwFormats;
	WORD wChannels;
	WORD wReserved1;
	DWORD dwSupport;
	GUID ManufacturerGuid;
	GUID ProductGuid;
	GUID NameGuid;
} WAVEOUTCAPS2A, *PWAVEOUTCAPS2A, *NPWAVEOUTCAPS2A, *LPWAVEOUTCAPS2A;
typedef struct tagWAVEOUTCAPS2W {
	WORD wMid;
	WORD wPid;
	MMVERSION vDriverVersion;
	WCHAR szPname[MAXPNAMELEN];
	DWORD dwFormats;
	WORD wChannels;
	WORD wReserved1;
	DWORD dwSupport;
	GUID ManufacturerGuid;
	GUID ProductGuid;
	GUID NameGuid;
} WAVEOUTCAPS2W, *PWAVEOUTCAPS2W, *NPWAVEOUTCAPS2W, *LPWAVEOUTCAPS2W;
#ifdef UNICODE
typedef WAVEOUTCAPS2W WAVEOUTCAPS2;
typedef PWAVEOUTCAPS2W PWAVEOUTCAPS2;
typedef NPWAVEOUTCAPS2W NPWAVEOUTCAPS2;
typedef LPWAVEOUTCAPS2W LPWAVEOUTCAPS2;
#else
typedef WAVEOUTCAPS2A WAVEOUTCAPS2;
typedef PWAVEOUTCAPS2A PWAVEOUTCAPS2;
typedef NPWAVEOUTCAPS2A NPWAVEOUTCAPS2;
typedef LPWAVEOUTCAPS2A LPWAVEOUTCAPS2;
#endif
#else
typedef struct waveoutcaps_tag {
	WORD wMid;
	WORD wPid;
	VERSION vDriverVersion;
	char szPname[MAXPNAMELEN];
	DWORD dwFormats;
	WORD wChannels;
	DWORD dwSupport;
} WAVEOUTCAPS, *PWAVEOUTCAPS, NEAR * NPWAVEOUTCAPS, FAR * LPWAVEOUTCAPS;
#endif
#define WAVECAPS_PITCH          0x0001
#define WAVECAPS_PLAYBACKRATE   0x0002
#define WAVECAPS_VOLUME         0x0004
#define WAVECAPS_LRVOLUME       0x0008
#define WAVECAPS_SYNC           0x0010
#define WAVECAPS_SAMPLEACCURATE 0x0020
#ifdef _WIN32
typedef struct tagWAVEINCAPSA {
	WORD wMid;
	WORD wPid;
	MMVERSION vDriverVersion;
	CHAR szPname[MAXPNAMELEN];
	DWORD dwFormats;
	WORD wChannels;
	WORD wReserved1;
} WAVEINCAPSA, *PWAVEINCAPSA, *NPWAVEINCAPSA, *LPWAVEINCAPSA;
typedef struct tagWAVEINCAPSW {
	WORD wMid;
	WORD wPid;
	MMVERSION vDriverVersion;
	WCHAR szPname[MAXPNAMELEN];
	DWORD dwFormats;
	WORD wChannels;
	WORD wReserved1;
} WAVEINCAPSW, *PWAVEINCAPSW, *NPWAVEINCAPSW, *LPWAVEINCAPSW;
#ifdef UNICODE
typedef WAVEINCAPSW WAVEINCAPS;
typedef PWAVEINCAPSW PWAVEINCAPS;
typedef NPWAVEINCAPSW NPWAVEINCAPS;
typedef LPWAVEINCAPSW LPWAVEINCAPS;
#else
typedef WAVEINCAPSA WAVEINCAPS;
typedef PWAVEINCAPSA PWAVEINCAPS;
typedef NPWAVEINCAPSA NPWAVEINCAPS;
typedef LPWAVEINCAPSA LPWAVEINCAPS;
#endif
typedef struct tagWAVEINCAPS2A {
	WORD wMid;
	WORD wPid;
	MMVERSION vDriverVersion;
	CHAR szPname[MAXPNAMELEN];
	DWORD dwFormats;
	WORD wChannels;
	WORD wReserved1;
	GUID ManufacturerGuid;
	GUID ProductGuid;
	GUID NameGuid;
} WAVEINCAPS2A, *PWAVEINCAPS2A, *NPWAVEINCAPS2A, *LPWAVEINCAPS2A;
typedef struct tagWAVEINCAPS2W {
	WORD wMid;
	WORD wPid;
	MMVERSION vDriverVersion;
	WCHAR szPname[MAXPNAMELEN];
	DWORD dwFormats;
	WORD wChannels;
	WORD wReserved1;
	GUID ManufacturerGuid;
	GUID ProductGuid;
	GUID NameGuid;
} WAVEINCAPS2W, *PWAVEINCAPS2W, *NPWAVEINCAPS2W, *LPWAVEINCAPS2W;
#ifdef UNICODE
typedef WAVEINCAPS2W WAVEINCAPS2;
typedef PWAVEINCAPS2W PWAVEINCAPS2;
typedef NPWAVEINCAPS2W NPWAVEINCAPS2;
typedef LPWAVEINCAPS2W LPWAVEINCAPS2;
#else
typedef WAVEINCAPS2A WAVEINCAPS2;
typedef PWAVEINCAPS2A PWAVEINCAPS2;
typedef NPWAVEINCAPS2A NPWAVEINCAPS2;
typedef LPWAVEINCAPS2A LPWAVEINCAPS2;
#endif
#else
typedef struct waveincaps_tag {
	WORD wMid;
	WORD wPid;
	VERSION vDriverVersion;
	char szPname[MAXPNAMELEN];
	DWORD dwFormats;
	WORD wChannels;
} WAVEINCAPS, *PWAVEINCAPS, NEAR * NPWAVEINCAPS, FAR * LPWAVEINCAPS;
#endif
#define WAVE_INVALIDFORMAT     0x00000000
#define WAVE_FORMAT_1M08       0x00000001
#define WAVE_FORMAT_1S08       0x00000002
#define WAVE_FORMAT_1M16       0x00000004
#define WAVE_FORMAT_1S16       0x00000008
#define WAVE_FORMAT_2M08       0x00000010
#define WAVE_FORMAT_2S08       0x00000020
#define WAVE_FORMAT_2M16       0x00000040
#define WAVE_FORMAT_2S16       0x00000080
#define WAVE_FORMAT_4M08       0x00000100
#define WAVE_FORMAT_4S08       0x00000200
#define WAVE_FORMAT_4M16       0x00000400
#define WAVE_FORMAT_4S16       0x00000800
#define WAVE_FORMAT_44M08      0x00000100
#define WAVE_FORMAT_44S08      0x00000200
#define WAVE_FORMAT_44M16      0x00000400
#define WAVE_FORMAT_44S16      0x00000800
#define WAVE_FORMAT_48M08      0x00001000
#define WAVE_FORMAT_48S08      0x00002000
#define WAVE_FORMAT_48M16      0x00004000
#define WAVE_FORMAT_48S16      0x00008000
#define WAVE_FORMAT_96M08      0x00010000
#define WAVE_FORMAT_96S08      0x00020000
#define WAVE_FORMAT_96M16      0x00040000
#define WAVE_FORMAT_96S16      0x00080000
#ifndef WAVE_FORMAT_PCM
typedef struct waveformat_tag {
	WORD wFormatTag;
	WORD nChannels;
	DWORD nSamplesPerSec;
	DWORD nAvgBytesPerSec;
	WORD nBlockAlign;
} WAVEFORMAT, *PWAVEFORMAT, NEAR * NPWAVEFORMAT, FAR * LPWAVEFORMAT;
#define WAVE_FORMAT_PCM     1
typedef struct pcmwaveformat_tag {
	WAVEFORMAT wf;
	WORD wBitsPerSample;
} PCMWAVEFORMAT, *PPCMWAVEFORMAT, NEAR * NPPCMWAVEFORMAT, FAR * LPPCMWAVEFORMAT;
#endif
#ifndef _WAVEFORMATEX_
#define _WAVEFORMATEX_
typedef struct tWAVEFORMATEX {
	WORD wFormatTag;
	WORD nChannels;
	DWORD nSamplesPerSec;
	DWORD nAvgBytesPerSec;
	WORD nBlockAlign;
	WORD wBitsPerSample;
	WORD cbSize;
} WAVEFORMATEX, *PWAVEFORMATEX, NEAR * NPWAVEFORMATEX, FAR * LPWAVEFORMATEX;
#endif
typedef const WAVEFORMATEX FAR *LPCWAVEFORMATEX;
WINMMAPI UINT WINAPI waveOutGetNumDevs(void);
#ifdef _WIN32
WINMMAPI MMRESULT WINAPI waveOutGetDevCapsA(UINT_PTR uDeviceID, LPWAVEOUTCAPSA pwoc, UINT cbwoc);
WINMMAPI MMRESULT WINAPI waveOutGetDevCapsW(UINT_PTR uDeviceID, LPWAVEOUTCAPSW pwoc, UINT cbwoc);
#ifdef UNICODE
#define waveOutGetDevCaps  waveOutGetDevCapsW
#else
#define waveOutGetDevCaps  waveOutGetDevCapsA
#endif
#else
WINMMAPI MMRESULT WINAPI waveOutGetDevCaps(UINT uDeviceID, LPWAVEOUTCAPS pwoc, UINT cbwoc);
#endif
#if (WINVER >= 0x0400)
WINMMAPI MMRESULT WINAPI waveOutGetVolume(HWAVEOUT hwo, LPDWORD pdwVolume);
WINMMAPI MMRESULT WINAPI waveOutSetVolume(HWAVEOUT hwo, DWORD dwVolume);
#else
WINMMAPI MMRESULT WINAPI waveOutGetVolume(UINT uId, LPDWORD pdwVolume);
WINMMAPI MMRESULT WINAPI waveOutSetVolume(UINT uId, DWORD dwVolume);
#endif
#ifdef _WIN32
WINMMAPI MMRESULT WINAPI waveOutGetErrorTextA(MMRESULT mmrError, LPSTR pszText, UINT cchText);
WINMMAPI MMRESULT WINAPI waveOutGetErrorTextW(MMRESULT mmrError, LPWSTR pszText, UINT cchText);
#ifdef UNICODE
#define waveOutGetErrorText  waveOutGetErrorTextW
#else
#define waveOutGetErrorText  waveOutGetErrorTextA
#endif
#else
MMRESULT WINAPI waveOutGetErrorText(MMRESULT mmrError, LPSTR pszText, UINT cchText);
#endif
WINMMAPI MMRESULT WINAPI waveOutOpen(LPHWAVEOUT phwo, UINT uDeviceID, LPCWAVEFORMATEX pwfx, DWORD_PTR dwCallback, DWORD_PTR dwInstance, DWORD fdwOpen);
WINMMAPI MMRESULT WINAPI waveOutClose(HWAVEOUT hwo);
WINMMAPI MMRESULT WINAPI waveOutPrepareHeader(HWAVEOUT hwo, LPWAVEHDR pwh, UINT cbwh);
WINMMAPI MMRESULT WINAPI waveOutUnprepareHeader(HWAVEOUT hwo, LPWAVEHDR pwh, UINT cbwh);
WINMMAPI MMRESULT WINAPI waveOutWrite(HWAVEOUT hwo, LPWAVEHDR pwh, UINT cbwh);
WINMMAPI MMRESULT WINAPI waveOutPause(HWAVEOUT hwo);
WINMMAPI MMRESULT WINAPI waveOutRestart(HWAVEOUT hwo);
WINMMAPI MMRESULT WINAPI waveOutReset(HWAVEOUT hwo);
WINMMAPI MMRESULT WINAPI waveOutBreakLoop(HWAVEOUT hwo);
WINMMAPI MMRESULT WINAPI waveOutGetPosition(HWAVEOUT hwo, LPMMTIME pmmt, UINT cbmmt);
WINMMAPI MMRESULT WINAPI waveOutGetPitch(HWAVEOUT hwo, LPDWORD pdwPitch);
WINMMAPI MMRESULT WINAPI waveOutSetPitch(HWAVEOUT hwo, DWORD dwPitch);
WINMMAPI MMRESULT WINAPI waveOutGetPlaybackRate(HWAVEOUT hwo, LPDWORD pdwRate);
WINMMAPI MMRESULT WINAPI waveOutSetPlaybackRate(HWAVEOUT hwo, DWORD dwRate);
WINMMAPI MMRESULT WINAPI waveOutGetID(HWAVEOUT hwo, LPUINT puDeviceID);
#if (WINVER >= 0x030a)
#ifdef _WIN32
WINMMAPI MMRESULT WINAPI waveOutMessage(HWAVEOUT hwo, UINT uMsg, DWORD_PTR dw1, DWORD_PTR dw2);
#else
DWORD WINAPI waveOutMessage(HWAVEOUT hwo, UINT uMsg, DWORD dw1, DWORD dw2);
#endif
#endif
WINMMAPI UINT WINAPI waveInGetNumDevs(void);
#ifdef _WIN32
WINMMAPI MMRESULT WINAPI waveInGetDevCapsA(UINT_PTR uDeviceID, LPWAVEINCAPSA pwic, UINT cbwic);
WINMMAPI MMRESULT WINAPI waveInGetDevCapsW(UINT_PTR uDeviceID, LPWAVEINCAPSW pwic, UINT cbwic);
#ifdef UNICODE
#define waveInGetDevCaps  waveInGetDevCapsW
#else
#define waveInGetDevCaps  waveInGetDevCapsA
#endif
#else
MMRESULT WINAPI waveInGetDevCaps(UINT uDeviceID, LPWAVEINCAPS pwic, UINT cbwic);
#endif
#ifdef _WIN32
WINMMAPI MMRESULT WINAPI waveInGetErrorTextA(MMRESULT mmrError, LPSTR pszText, UINT cchText);
WINMMAPI MMRESULT WINAPI waveInGetErrorTextW(MMRESULT mmrError, LPWSTR pszText, UINT cchText);
#ifdef UNICODE
#define waveInGetErrorText  waveInGetErrorTextW
#else
#define waveInGetErrorText  waveInGetErrorTextA
#endif
#else
MMRESULT WINAPI waveInGetErrorText(MMRESULT mmrError, LPSTR pszText, UINT cchText);
#endif
WINMMAPI MMRESULT WINAPI waveInOpen(LPHWAVEIN phwi, UINT uDeviceID, LPCWAVEFORMATEX pwfx, DWORD_PTR dwCallback, DWORD_PTR dwInstance, DWORD fdwOpen);
WINMMAPI MMRESULT WINAPI waveInClose(HWAVEIN hwi);
WINMMAPI MMRESULT WINAPI waveInPrepareHeader(HWAVEIN hwi, LPWAVEHDR pwh, UINT cbwh);
WINMMAPI MMRESULT WINAPI waveInUnprepareHeader(HWAVEIN hwi, LPWAVEHDR pwh, UINT cbwh);
WINMMAPI MMRESULT WINAPI waveInAddBuffer(HWAVEIN hwi, LPWAVEHDR pwh, UINT cbwh);
WINMMAPI MMRESULT WINAPI waveInStart(HWAVEIN hwi);
WINMMAPI MMRESULT WINAPI waveInStop(HWAVEIN hwi);
WINMMAPI MMRESULT WINAPI waveInReset(HWAVEIN hwi);
WINMMAPI MMRESULT WINAPI waveInGetPosition(HWAVEIN hwi, LPMMTIME pmmt, UINT cbmmt);
WINMMAPI MMRESULT WINAPI waveInGetID(HWAVEIN hwi, LPUINT puDeviceID);
#if (WINVER >= 0x030a)
#ifdef _WIN32
WINMMAPI MMRESULT WINAPI waveInMessage(HWAVEIN hwi, UINT uMsg, DWORD_PTR dw1, DWORD_PTR dw2);
#else
DWORD WINAPI waveInMessage(HWAVEIN hwi, UINT uMsg, DWORD dw1, DWORD dw2);
#endif
#endif
#endif
#ifndef MMNOMIDI
#define MIDIERR_UNPREPARED    (MIDIERR_BASE + 0)
#define MIDIERR_STILLPLAYING  (MIDIERR_BASE + 1)
#define MIDIERR_NOMAP         (MIDIERR_BASE + 2)
#define MIDIERR_NOTREADY      (MIDIERR_BASE + 3)
#define MIDIERR_NODEVICE      (MIDIERR_BASE + 4)
#define MIDIERR_INVALIDSETUP  (MIDIERR_BASE + 5)
#define MIDIERR_BADOPENMODE   (MIDIERR_BASE + 6)
#define MIDIERR_DONT_CONTINUE (MIDIERR_BASE + 7)
#define MIDIERR_LASTERROR     (MIDIERR_BASE + 7)
DECLARE_HANDLE(HMIDI);
DECLARE_HANDLE(HMIDIIN);
DECLARE_HANDLE(HMIDIOUT);
DECLARE_HANDLE(HMIDISTRM);
typedef HMIDI FAR *LPHMIDI;
typedef HMIDIIN FAR *LPHMIDIIN;
typedef HMIDIOUT FAR *LPHMIDIOUT;
typedef HMIDISTRM FAR *LPHMIDISTRM;
typedef DRVCALLBACK MIDICALLBACK;
typedef MIDICALLBACK FAR *LPMIDICALLBACK;
#define MIDIPATCHSIZE   128
typedef WORD PATCHARRAY[MIDIPATCHSIZE];
typedef WORD FAR *LPPATCHARRAY;
typedef WORD KEYARRAY[MIDIPATCHSIZE];
typedef WORD FAR *LPKEYARRAY;
#define MIM_OPEN        MM_MIM_OPEN
#define MIM_CLOSE       MM_MIM_CLOSE
#define MIM_DATA        MM_MIM_DATA
#define MIM_LONGDATA    MM_MIM_LONGDATA
#define MIM_ERROR       MM_MIM_ERROR
#define MIM_LONGERROR   MM_MIM_LONGERROR
#define MOM_OPEN        MM_MOM_OPEN
#define MOM_CLOSE       MM_MOM_CLOSE
#define MOM_DONE        MM_MOM_DONE
#if(WINVER >= 0x0400)
#define MIM_MOREDATA      MM_MIM_MOREDATA
#define MOM_POSITIONCB    MM_MOM_POSITIONCB
#endif
#define MIDIMAPPER     ((UINT)-1)
#define MIDI_MAPPER    ((UINT)-1)
#if(WINVER >= 0x0400)
#define MIDI_IO_STATUS      0x00000020L
#endif
#define MIDI_CACHE_ALL      1
#define MIDI_CACHE_BESTFIT  2
#define MIDI_CACHE_QUERY    3
#define MIDI_UNCACHE        4
#ifdef _WIN32
typedef struct tagMIDIOUTCAPSA {
	WORD wMid;
	WORD wPid;
	MMVERSION vDriverVersion;
	CHAR szPname[MAXPNAMELEN];
	WORD wTechnology;
	WORD wVoices;
	WORD wNotes;
	WORD wChannelMask;
	DWORD dwSupport;
} MIDIOUTCAPSA, *PMIDIOUTCAPSA, *NPMIDIOUTCAPSA, *LPMIDIOUTCAPSA;
typedef struct tagMIDIOUTCAPSW {
	WORD wMid;
	WORD wPid;
	MMVERSION vDriverVersion;
	WCHAR szPname[MAXPNAMELEN];
	WORD wTechnology;
	WORD wVoices;
	WORD wNotes;
	WORD wChannelMask;
	DWORD dwSupport;
} MIDIOUTCAPSW, *PMIDIOUTCAPSW, *NPMIDIOUTCAPSW, *LPMIDIOUTCAPSW;
#ifdef UNICODE
typedef MIDIOUTCAPSW MIDIOUTCAPS;
typedef PMIDIOUTCAPSW PMIDIOUTCAPS;
typedef NPMIDIOUTCAPSW NPMIDIOUTCAPS;
typedef LPMIDIOUTCAPSW LPMIDIOUTCAPS;
#else
typedef MIDIOUTCAPSA MIDIOUTCAPS;
typedef PMIDIOUTCAPSA PMIDIOUTCAPS;
typedef NPMIDIOUTCAPSA NPMIDIOUTCAPS;
typedef LPMIDIOUTCAPSA LPMIDIOUTCAPS;
#endif
typedef struct tagMIDIOUTCAPS2A {
	WORD wMid;
	WORD wPid;
	MMVERSION vDriverVersion;
	CHAR szPname[MAXPNAMELEN];
	WORD wTechnology;
	WORD wVoices;
	WORD wNotes;
	WORD wChannelMask;
	DWORD dwSupport;
	GUID ManufacturerGuid;
	GUID ProductGuid;
	GUID NameGuid;
} MIDIOUTCAPS2A, *PMIDIOUTCAPS2A, *NPMIDIOUTCAPS2A, *LPMIDIOUTCAPS2A;
typedef struct tagMIDIOUTCAPS2W {
	WORD wMid;
	WORD wPid;
	MMVERSION vDriverVersion;
	WCHAR szPname[MAXPNAMELEN];
	WORD wTechnology;
	WORD wVoices;
	WORD wNotes;
	WORD wChannelMask;
	DWORD dwSupport;
	GUID ManufacturerGuid;
	GUID ProductGuid;
	GUID NameGuid;
} MIDIOUTCAPS2W, *PMIDIOUTCAPS2W, *NPMIDIOUTCAPS2W, *LPMIDIOUTCAPS2W;
#ifdef UNICODE
typedef MIDIOUTCAPS2W MIDIOUTCAPS2;
typedef PMIDIOUTCAPS2W PMIDIOUTCAPS2;
typedef NPMIDIOUTCAPS2W NPMIDIOUTCAPS2;
typedef LPMIDIOUTCAPS2W LPMIDIOUTCAPS2;
#else
typedef MIDIOUTCAPS2A MIDIOUTCAPS2;
typedef PMIDIOUTCAPS2A PMIDIOUTCAPS2;
typedef NPMIDIOUTCAPS2A NPMIDIOUTCAPS2;
typedef LPMIDIOUTCAPS2A LPMIDIOUTCAPS2;
#endif
#else
typedef struct midioutcaps_tag {
	WORD wMid;
	WORD wPid;
	VERSION vDriverVersion;
	char szPname[MAXPNAMELEN];
	WORD wTechnology;
	WORD wVoices;
	WORD wNotes;
	WORD wChannelMask;
	DWORD dwSupport;
} MIDIOUTCAPS, *PMIDIOUTCAPS, NEAR * NPMIDIOUTCAPS, FAR * LPMIDIOUTCAPS;
#endif
#define MOD_MIDIPORT    1
#define MOD_SYNTH       2
#define MOD_SQSYNTH     3
#define MOD_FMSYNTH     4
#define MOD_MAPPER      5
#define MOD_WAVETABLE   6
#define MOD_SWSYNTH     7
#define MIDICAPS_VOLUME          0x0001
#define MIDICAPS_LRVOLUME        0x0002
#define MIDICAPS_CACHE           0x0004
#if(WINVER >= 0x0400)
#define MIDICAPS_STREAM          0x0008
#endif
#ifdef _WIN32
typedef struct tagMIDIINCAPSA {
	WORD wMid;
	WORD wPid;
	MMVERSION vDriverVersion;
	CHAR szPname[MAXPNAMELEN];
#if (WINVER >= 0x0400)
	DWORD dwSupport;
#endif
} MIDIINCAPSA, *PMIDIINCAPSA, *NPMIDIINCAPSA, *LPMIDIINCAPSA;
typedef struct tagMIDIINCAPSW {
	WORD wMid;
	WORD wPid;
	MMVERSION vDriverVersion;
	WCHAR szPname[MAXPNAMELEN];
#if (WINVER >= 0x0400)
	DWORD dwSupport;
#endif
} MIDIINCAPSW, *PMIDIINCAPSW, *NPMIDIINCAPSW, *LPMIDIINCAPSW;
#ifdef UNICODE
typedef MIDIINCAPSW MIDIINCAPS;
typedef PMIDIINCAPSW PMIDIINCAPS;
typedef NPMIDIINCAPSW NPMIDIINCAPS;
typedef LPMIDIINCAPSW LPMIDIINCAPS;
#else
typedef MIDIINCAPSA MIDIINCAPS;
typedef PMIDIINCAPSA PMIDIINCAPS;
typedef NPMIDIINCAPSA NPMIDIINCAPS;
typedef LPMIDIINCAPSA LPMIDIINCAPS;
#endif
typedef struct tagMIDIINCAPS2A {
	WORD wMid;
	WORD wPid;
	MMVERSION vDriverVersion;
	CHAR szPname[MAXPNAMELEN];
#if (WINVER >= 0x0400)
	DWORD dwSupport;
#endif
	GUID ManufacturerGuid;
	GUID ProductGuid;
	GUID NameGuid;
} MIDIINCAPS2A, *PMIDIINCAPS2A, *NPMIDIINCAPS2A, *LPMIDIINCAPS2A;
typedef struct tagMIDIINCAPS2W {
	WORD wMid;
	WORD wPid;
	MMVERSION vDriverVersion;
	WCHAR szPname[MAXPNAMELEN];
#if (WINVER >= 0x0400)
	DWORD dwSupport;
#endif
	GUID ManufacturerGuid;
	GUID ProductGuid;
	GUID NameGuid;
} MIDIINCAPS2W, *PMIDIINCAPS2W, *NPMIDIINCAPS2W, *LPMIDIINCAPS2W;
#ifdef UNICODE
typedef MIDIINCAPS2W MIDIINCAPS2;
typedef PMIDIINCAPS2W PMIDIINCAPS2;
typedef NPMIDIINCAPS2W NPMIDIINCAPS2;
typedef LPMIDIINCAPS2W LPMIDIINCAPS2;
#else
typedef MIDIINCAPS2A MIDIINCAPS2;
typedef PMIDIINCAPS2A PMIDIINCAPS2;
typedef NPMIDIINCAPS2A NPMIDIINCAPS2;
typedef LPMIDIINCAPS2A LPMIDIINCAPS2;
#endif
#else
typedef struct midiincaps_tag {
	WORD wMid;
	WORD wPid;
	VERSION vDriverVersion;
	char szPname[MAXPNAMELEN];
#if (WINVER >= 0x0400)
	DWORD dwSupport;
#endif
} MIDIINCAPS, *PMIDIINCAPS, NEAR * NPMIDIINCAPS, FAR * LPMIDIINCAPS;
#endif
typedef struct midihdr_tag {
	LPSTR lpData;
	DWORD dwBufferLength;
	DWORD dwBytesRecorded;
	DWORD_PTR dwUser;
	DWORD dwFlags;
	struct midihdr_tag far *lpNext;
	DWORD_PTR reserved;
#if (WINVER >= 0x0400)
	DWORD dwOffset;
	DWORD_PTR dwReserved[8];
#endif
} MIDIHDR, *PMIDIHDR, NEAR * NPMIDIHDR, FAR * LPMIDIHDR;
#if(WINVER >= 0x0400)
typedef struct midievent_tag {
	DWORD dwDeltaTime;
	DWORD dwStreamID;
	DWORD dwEvent;
	DWORD dwParms[1];
} MIDIEVENT;
typedef struct midistrmbuffver_tag {
	DWORD dwVersion;
	DWORD dwMid;
	DWORD dwOEMVersion;
} MIDISTRMBUFFVER;
#endif
#define MHDR_DONE       0x00000001
#define MHDR_PREPARED   0x00000002
#define MHDR_INQUEUE    0x00000004
#define MHDR_ISSTRM     0x00000008
#if(WINVER >= 0x0400)
#define MEVT_F_SHORT        0x00000000L
#define MEVT_F_LONG         0x80000000L
#define MEVT_F_CALLBACK     0x40000000L
#define MEVT_EVENTTYPE(x)   ((BYTE)(((x)>>24)&0xFF))
#define MEVT_EVENTPARM(x)   ((DWORD)((x)&0x00FFFFFFL))
#define MEVT_SHORTMSG       ((BYTE)0x00)
#define MEVT_TEMPO          ((BYTE)0x01)
#define MEVT_NOP            ((BYTE)0x02)
#define MEVT_LONGMSG        ((BYTE)0x80)
#define MEVT_COMMENT        ((BYTE)0x82)
#define MEVT_VERSION        ((BYTE)0x84)
#define MIDISTRM_ERROR      (-2)
#define MIDIPROP_SET        0x80000000L
#define MIDIPROP_GET        0x40000000L
#define MIDIPROP_TIMEDIV    0x00000001L
#define MIDIPROP_TEMPO      0x00000002L
typedef struct midiproptimediv_tag {
	DWORD cbStruct;
	DWORD dwTimeDiv;
} MIDIPROPTIMEDIV,  FAR * LPMIDIPROPTIMEDIV;
typedef struct midiproptempo_tag {
	DWORD cbStruct;
	DWORD dwTempo;
} MIDIPROPTEMPO,  FAR * LPMIDIPROPTEMPO;
#endif
WINMMAPI UINT WINAPI midiOutGetNumDevs(void);
#if(WINVER >= 0x0400)
WINMMAPI MMRESULT WINAPI midiStreamOpen(LPHMIDISTRM phms, LPUINT puDeviceID, DWORD cMidi, DWORD_PTR dwCallback, DWORD_PTR dwInstance, DWORD fdwOpen);
WINMMAPI MMRESULT WINAPI midiStreamClose(HMIDISTRM hms);
WINMMAPI MMRESULT WINAPI midiStreamProperty(HMIDISTRM hms, LPBYTE lppropdata, DWORD dwProperty);
WINMMAPI MMRESULT WINAPI midiStreamPosition(HMIDISTRM hms, LPMMTIME lpmmt, UINT cbmmt);
WINMMAPI MMRESULT WINAPI midiStreamOut(HMIDISTRM hms, LPMIDIHDR pmh, UINT cbmh);
WINMMAPI MMRESULT WINAPI midiStreamPause(HMIDISTRM hms);
WINMMAPI MMRESULT WINAPI midiStreamRestart(HMIDISTRM hms);
WINMMAPI MMRESULT WINAPI midiStreamStop(HMIDISTRM hms);
#ifdef _WIN32
WINMMAPI MMRESULT WINAPI midiConnect(HMIDI hmi, HMIDIOUT hmo, LPVOID pReserved);
WINMMAPI MMRESULT WINAPI midiDisconnect(HMIDI hmi, HMIDIOUT hmo, LPVOID pReserved);
#endif
#endif
#ifdef _WIN32
WINMMAPI MMRESULT WINAPI midiOutGetDevCapsA(UINT_PTR uDeviceID, LPMIDIOUTCAPSA pmoc, UINT cbmoc);
WINMMAPI MMRESULT WINAPI midiOutGetDevCapsW(UINT_PTR uDeviceID, LPMIDIOUTCAPSW pmoc, UINT cbmoc);
#ifdef UNICODE
#define midiOutGetDevCaps  midiOutGetDevCapsW
#else
#define midiOutGetDevCaps  midiOutGetDevCapsA
#endif
#else
MMRESULT WINAPI midiOutGetDevCaps(UINT uDeviceID, LPMIDIOUTCAPS pmoc, UINT cbmoc);
#endif
#if (WINVER >= 0x0400)
WINMMAPI MMRESULT WINAPI midiOutGetVolume(HMIDIOUT hmo, LPDWORD pdwVolume);
WINMMAPI MMRESULT WINAPI midiOutSetVolume(HMIDIOUT hmo, DWORD dwVolume);
#else
WINMMAPI MMRESULT WINAPI midiOutGetVolume(UINT uId, LPDWORD pdwVolume);
WINMMAPI MMRESULT WINAPI midiOutSetVolume(UINT uId, DWORD dwVolume);
#endif
#ifdef _WIN32
WINMMAPI MMRESULT WINAPI midiOutGetErrorTextA(MMRESULT mmrError, LPSTR pszText, UINT cchText);
WINMMAPI MMRESULT WINAPI midiOutGetErrorTextW(MMRESULT mmrError, LPWSTR pszText, UINT cchText);
#ifdef UNICODE
#define midiOutGetErrorText  midiOutGetErrorTextW
#else
#define midiOutGetErrorText  midiOutGetErrorTextA
#endif
#else
WINMMAPI MMRESULT WINAPI midiOutGetErrorText(MMRESULT mmrError, LPSTR pszText, UINT cchText);
#endif
WINMMAPI MMRESULT WINAPI midiOutOpen(LPHMIDIOUT phmo, UINT uDeviceID, DWORD_PTR dwCallback, DWORD_PTR dwInstance, DWORD fdwOpen);
WINMMAPI MMRESULT WINAPI midiOutClose(HMIDIOUT hmo);
WINMMAPI MMRESULT WINAPI midiOutPrepareHeader(HMIDIOUT hmo, LPMIDIHDR pmh, UINT cbmh);
WINMMAPI MMRESULT WINAPI midiOutUnprepareHeader(HMIDIOUT hmo, LPMIDIHDR pmh, UINT cbmh);
WINMMAPI MMRESULT WINAPI midiOutShortMsg(HMIDIOUT hmo, DWORD dwMsg);
WINMMAPI MMRESULT WINAPI midiOutLongMsg(HMIDIOUT hmo, LPMIDIHDR pmh, UINT cbmh);
WINMMAPI MMRESULT WINAPI midiOutReset(HMIDIOUT hmo);
WINMMAPI MMRESULT WINAPI midiOutCachePatches(HMIDIOUT hmo, UINT uBank, LPWORD pwpa, UINT fuCache);
WINMMAPI MMRESULT WINAPI midiOutCacheDrumPatches(HMIDIOUT hmo, UINT uPatch, LPWORD pwkya, UINT fuCache);
WINMMAPI MMRESULT WINAPI midiOutGetID(HMIDIOUT hmo, LPUINT puDeviceID);
#if (WINVER >= 0x030a)
#ifdef _WIN32
WINMMAPI MMRESULT WINAPI midiOutMessage(HMIDIOUT hmo, UINT uMsg, DWORD_PTR dw1, DWORD_PTR dw2);
#else
DWORD WINAPI midiOutMessage(HMIDIOUT hmo, UINT uMsg, DWORD dw1, DWORD dw2);
#endif
#endif
WINMMAPI UINT WINAPI midiInGetNumDevs(void);
#ifdef _WIN32
WINMMAPI MMRESULT WINAPI midiInGetDevCapsA(UINT_PTR uDeviceID, LPMIDIINCAPSA pmic, UINT cbmic);
WINMMAPI MMRESULT WINAPI midiInGetDevCapsW(UINT_PTR uDeviceID, LPMIDIINCAPSW pmic, UINT cbmic);
#ifdef UNICODE
#define midiInGetDevCaps  midiInGetDevCapsW
#else
#define midiInGetDevCaps  midiInGetDevCapsA
#endif
WINMMAPI MMRESULT WINAPI midiInGetErrorTextA(MMRESULT mmrError, LPSTR pszText, UINT cchText);
WINMMAPI MMRESULT WINAPI midiInGetErrorTextW(MMRESULT mmrError, LPWSTR pszText, UINT cchText);
#ifdef UNICODE
#define midiInGetErrorText  midiInGetErrorTextW
#else
#define midiInGetErrorText  midiInGetErrorTextA
#endif
#else
MMRESULT WINAPI midiInGetDevCaps(UINT uDeviceID, LPMIDIINCAPS pmic, UINT cbmic);
WINMMAPI MMRESULT WINAPI midiInGetErrorText(MMRESULT mmrError, LPSTR pszText, UINT cchText);
#endif
WINMMAPI MMRESULT WINAPI midiInOpen(LPHMIDIIN phmi, UINT uDeviceID, DWORD_PTR dwCallback, DWORD_PTR dwInstance, DWORD fdwOpen);
WINMMAPI MMRESULT WINAPI midiInClose(HMIDIIN hmi);
WINMMAPI MMRESULT WINAPI midiInPrepareHeader(HMIDIIN hmi, LPMIDIHDR pmh, UINT cbmh);
WINMMAPI MMRESULT WINAPI midiInUnprepareHeader(HMIDIIN hmi, LPMIDIHDR pmh, UINT cbmh);
WINMMAPI MMRESULT WINAPI midiInAddBuffer(HMIDIIN hmi, LPMIDIHDR pmh, UINT cbmh);
WINMMAPI MMRESULT WINAPI midiInStart(HMIDIIN hmi);
WINMMAPI MMRESULT WINAPI midiInStop(HMIDIIN hmi);
WINMMAPI MMRESULT WINAPI midiInReset(HMIDIIN hmi);
WINMMAPI MMRESULT WINAPI midiInGetID(HMIDIIN hmi, LPUINT puDeviceID);
#if (WINVER >= 0x030a)
#ifdef _WIN32
WINMMAPI MMRESULT WINAPI midiInMessage(HMIDIIN hmi, UINT uMsg, DWORD_PTR dw1, DWORD_PTR dw2);
#else
DWORD WINAPI midiInMessage(HMIDIIN hmi, UINT uMsg, DWORD dw1, DWORD dw2);
#endif
#endif
#endif
#ifndef MMNOAUX
#define AUX_MAPPER     ((UINT)-1)
#ifdef _WIN32
typedef struct tagAUXCAPSA {
	WORD wMid;
	WORD wPid;
	MMVERSION vDriverVersion;
	CHAR szPname[MAXPNAMELEN];
	WORD wTechnology;
	WORD wReserved1;
	DWORD dwSupport;
} AUXCAPSA, *PAUXCAPSA, *NPAUXCAPSA, *LPAUXCAPSA;
typedef struct tagAUXCAPSW {
	WORD wMid;
	WORD wPid;
	MMVERSION vDriverVersion;
	WCHAR szPname[MAXPNAMELEN];
	WORD wTechnology;
	WORD wReserved1;
	DWORD dwSupport;
} AUXCAPSW, *PAUXCAPSW, *NPAUXCAPSW, *LPAUXCAPSW;
#ifdef UNICODE
typedef AUXCAPSW AUXCAPS;
typedef PAUXCAPSW PAUXCAPS;
typedef NPAUXCAPSW NPAUXCAPS;
typedef LPAUXCAPSW LPAUXCAPS;
#else
typedef AUXCAPSA AUXCAPS;
typedef PAUXCAPSA PAUXCAPS;
typedef NPAUXCAPSA NPAUXCAPS;
typedef LPAUXCAPSA LPAUXCAPS;
#endif
typedef struct tagAUXCAPS2A {
	WORD wMid;
	WORD wPid;
	MMVERSION vDriverVersion;
	CHAR szPname[MAXPNAMELEN];
	WORD wTechnology;
	WORD wReserved1;
	DWORD dwSupport;
	GUID ManufacturerGuid;
	GUID ProductGuid;
	GUID NameGuid;
} AUXCAPS2A, *PAUXCAPS2A, *NPAUXCAPS2A, *LPAUXCAPS2A;
typedef struct tagAUXCAPS2W {
	WORD wMid;
	WORD wPid;
	MMVERSION vDriverVersion;
	WCHAR szPname[MAXPNAMELEN];
	WORD wTechnology;
	WORD wReserved1;
	DWORD dwSupport;
	GUID ManufacturerGuid;
	GUID ProductGuid;
	GUID NameGuid;
} AUXCAPS2W, *PAUXCAPS2W, *NPAUXCAPS2W, *LPAUXCAPS2W;
#ifdef UNICODE
typedef AUXCAPS2W AUXCAPS2;
typedef PAUXCAPS2W PAUXCAPS2;
typedef NPAUXCAPS2W NPAUXCAPS2;
typedef LPAUXCAPS2W LPAUXCAPS2;
#else
typedef AUXCAPS2A AUXCAPS2;
typedef PAUXCAPS2A PAUXCAPS2;
typedef NPAUXCAPS2A NPAUXCAPS2;
typedef LPAUXCAPS2A LPAUXCAPS2;
#endif
#else
typedef struct auxcaps_tag {
	WORD wMid;
	WORD wPid;
	VERSION vDriverVersion;
	char szPname[MAXPNAMELEN];
	WORD wTechnology;
	DWORD dwSupport;
} AUXCAPS, *PAUXCAPS, NEAR * NPAUXCAPS, FAR * LPAUXCAPS;
#endif
#define AUXCAPS_CDAUDIO    1
#define AUXCAPS_AUXIN      2
#define AUXCAPS_VOLUME          0x0001
#define AUXCAPS_LRVOLUME        0x0002
WINMMAPI UINT WINAPI auxGetNumDevs(void);
#ifdef _WIN32
WINMMAPI MMRESULT WINAPI auxGetDevCapsA(UINT_PTR uDeviceID, LPAUXCAPSA pac, UINT cbac);
WINMMAPI MMRESULT WINAPI auxGetDevCapsW(UINT_PTR uDeviceID, LPAUXCAPSW pac, UINT cbac);
#ifdef UNICODE
#define auxGetDevCaps  auxGetDevCapsW
#else
#define auxGetDevCaps  auxGetDevCapsA
#endif
#else
MMRESULT WINAPI auxGetDevCaps(UINT uDeviceID, LPAUXCAPS pac, UINT cbac);
#endif
WINMMAPI MMRESULT WINAPI auxSetVolume(UINT uDeviceID, DWORD dwVolume);
WINMMAPI MMRESULT WINAPI auxGetVolume(UINT uDeviceID, LPDWORD pdwVolume);
#if (WINVER >= 0x030a)
#ifdef _WIN32
WINMMAPI MMRESULT WINAPI auxOutMessage(UINT uDeviceID, UINT uMsg, DWORD_PTR dw1, DWORD_PTR dw2);
#else
DWORD WINAPI auxOutMessage(UINT uDeviceID, UINT uMsg, DWORD dw1, DWORD dw2);
#endif
#endif
#endif
#ifndef MMNOMIXER
DECLARE_HANDLE(HMIXEROBJ);
typedef HMIXEROBJ FAR *LPHMIXEROBJ;
DECLARE_HANDLE(HMIXER);
typedef HMIXER FAR *LPHMIXER;
#define MIXER_SHORT_NAME_CHARS   16
#define MIXER_LONG_NAME_CHARS    64
#define MIXERR_INVALLINE            (MIXERR_BASE + 0)
#define MIXERR_INVALCONTROL         (MIXERR_BASE + 1)
#define MIXERR_INVALVALUE           (MIXERR_BASE + 2)
#define MIXERR_LASTERROR            (MIXERR_BASE + 2)
#define MIXER_OBJECTF_HANDLE    0x80000000L
#define MIXER_OBJECTF_MIXER     0x00000000L
#define MIXER_OBJECTF_HMIXER    (MIXER_OBJECTF_HANDLE|MIXER_OBJECTF_MIXER)
#define MIXER_OBJECTF_WAVEOUT   0x10000000L
#define MIXER_OBJECTF_HWAVEOUT  (MIXER_OBJECTF_HANDLE|MIXER_OBJECTF_WAVEOUT)
#define MIXER_OBJECTF_WAVEIN    0x20000000L
#define MIXER_OBJECTF_HWAVEIN   (MIXER_OBJECTF_HANDLE|MIXER_OBJECTF_WAVEIN)
#define MIXER_OBJECTF_MIDIOUT   0x30000000L
#define MIXER_OBJECTF_HMIDIOUT  (MIXER_OBJECTF_HANDLE|MIXER_OBJECTF_MIDIOUT)
#define MIXER_OBJECTF_MIDIIN    0x40000000L
#define MIXER_OBJECTF_HMIDIIN   (MIXER_OBJECTF_HANDLE|MIXER_OBJECTF_MIDIIN)
#define MIXER_OBJECTF_AUX       0x50000000L
WINMMAPI UINT WINAPI mixerGetNumDevs(void);
#ifdef _WIN32
typedef struct tagMIXERCAPSA {
	WORD wMid;
	WORD wPid;
	MMVERSION vDriverVersion;
	CHAR szPname[MAXPNAMELEN];
	DWORD fdwSupport;
	DWORD cDestinations;
} MIXERCAPSA, *PMIXERCAPSA, *LPMIXERCAPSA;
typedef struct tagMIXERCAPSW {
	WORD wMid;
	WORD wPid;
	MMVERSION vDriverVersion;
	WCHAR szPname[MAXPNAMELEN];
	DWORD fdwSupport;
	DWORD cDestinations;
} MIXERCAPSW, *PMIXERCAPSW, *LPMIXERCAPSW;
#ifdef UNICODE
typedef MIXERCAPSW MIXERCAPS;
typedef PMIXERCAPSW PMIXERCAPS;
typedef LPMIXERCAPSW LPMIXERCAPS;
#else
typedef MIXERCAPSA MIXERCAPS;
typedef PMIXERCAPSA PMIXERCAPS;
typedef LPMIXERCAPSA LPMIXERCAPS;
#endif
typedef struct tagMIXERCAPS2A {
	WORD wMid;
	WORD wPid;
	MMVERSION vDriverVersion;
	CHAR szPname[MAXPNAMELEN];
	DWORD fdwSupport;
	DWORD cDestinations;
	GUID ManufacturerGuid;
	GUID ProductGuid;
	GUID NameGuid;
} MIXERCAPS2A, *PMIXERCAPS2A, *LPMIXERCAPS2A;
typedef struct tagMIXERCAPS2W {
	WORD wMid;
	WORD wPid;
	MMVERSION vDriverVersion;
	WCHAR szPname[MAXPNAMELEN];
	DWORD fdwSupport;
	DWORD cDestinations;
	GUID ManufacturerGuid;
	GUID ProductGuid;
	GUID NameGuid;
} MIXERCAPS2W, *PMIXERCAPS2W, *LPMIXERCAPS2W;
#ifdef UNICODE
typedef MIXERCAPS2W MIXERCAPS2;
typedef PMIXERCAPS2W PMIXERCAPS2;
typedef LPMIXERCAPS2W LPMIXERCAPS2;
#else
typedef MIXERCAPS2A MIXERCAPS2;
typedef PMIXERCAPS2A PMIXERCAPS2;
typedef LPMIXERCAPS2A LPMIXERCAPS2;
#endif
#else
typedef struct tMIXERCAPS {
	WORD wMid;
	WORD wPid;
	VERSION vDriverVersion;
	char szPname[MAXPNAMELEN];
	DWORD fdwSupport;
	DWORD cDestinations;
} MIXERCAPS, *PMIXERCAPS, FAR * LPMIXERCAPS;
#endif
#ifdef _WIN32
WINMMAPI MMRESULT WINAPI mixerGetDevCapsA(UINT_PTR uMxId, LPMIXERCAPSA pmxcaps, UINT cbmxcaps);
WINMMAPI MMRESULT WINAPI mixerGetDevCapsW(UINT_PTR uMxId, LPMIXERCAPSW pmxcaps, UINT cbmxcaps);
#ifdef UNICODE
#define mixerGetDevCaps  mixerGetDevCapsW
#else
#define mixerGetDevCaps  mixerGetDevCapsA
#endif
#else
MMRESULT WINAPI mixerGetDevCaps(UINT uMxId, LPMIXERCAPS pmxcaps, UINT cbmxcaps);
#endif
WINMMAPI MMRESULT WINAPI mixerOpen(LPHMIXER phmx, UINT uMxId, DWORD_PTR dwCallback, DWORD_PTR dwInstance, DWORD fdwOpen);
WINMMAPI MMRESULT WINAPI mixerClose(HMIXER hmx);
WINMMAPI DWORD WINAPI mixerMessage(HMIXER hmx, UINT uMsg, DWORD_PTR dwParam1, DWORD_PTR dwParam2);
#ifdef _WIN32
typedef struct tagMIXERLINEA {
	DWORD cbStruct;
	DWORD dwDestination;
	DWORD dwSource;
	DWORD dwLineID;
	DWORD fdwLine;
	DWORD_PTR dwUser;
	DWORD dwComponentType;
	DWORD cChannels;
	DWORD cConnections;
	DWORD cControls;
	CHAR szShortName[MIXER_SHORT_NAME_CHARS];
	CHAR szName[MIXER_LONG_NAME_CHARS];
	struct {
		DWORD dwType;
		DWORD dwDeviceID;
		WORD wMid;
		WORD wPid;
		MMVERSION vDriverVersion;
		CHAR szPname[MAXPNAMELEN];
	} Target;
} MIXERLINEA, *PMIXERLINEA, *LPMIXERLINEA;
typedef struct tagMIXERLINEW {
	DWORD cbStruct;
	DWORD dwDestination;
	DWORD dwSource;
	DWORD dwLineID;
	DWORD fdwLine;
	DWORD_PTR dwUser;
	DWORD dwComponentType;
	DWORD cChannels;
	DWORD cConnections;
	DWORD cControls;
	WCHAR szShortName[MIXER_SHORT_NAME_CHARS];
	WCHAR szName[MIXER_LONG_NAME_CHARS];
	struct {
		DWORD dwType;
		DWORD dwDeviceID;
		WORD wMid;
		WORD wPid;
		MMVERSION vDriverVersion;
		WCHAR szPname[MAXPNAMELEN];
	} Target;
} MIXERLINEW, *PMIXERLINEW, *LPMIXERLINEW;
#ifdef UNICODE
typedef MIXERLINEW MIXERLINE;
typedef PMIXERLINEW PMIXERLINE;
typedef LPMIXERLINEW LPMIXERLINE;
#else
typedef MIXERLINEA MIXERLINE;
typedef PMIXERLINEA PMIXERLINE;
typedef LPMIXERLINEA LPMIXERLINE;
#endif
#else
typedef struct tMIXERLINE {
	DWORD cbStruct;
	DWORD dwDestination;
	DWORD dwSource;
	DWORD dwLineID;
	DWORD fdwLine;
	DWORD dwUser;
	DWORD dwComponentType;
	DWORD cChannels;
	DWORD cConnections;
	DWORD cControls;
	char szShortName[MIXER_SHORT_NAME_CHARS];
	char szName[MIXER_LONG_NAME_CHARS];
	struct {
		DWORD dwType;
		DWORD dwDeviceID;
		WORD wMid;
		WORD wPid;
		VERSION vDriverVersion;
		char szPname[MAXPNAMELEN];
	} Target;
} MIXERLINE, *PMIXERLINE, FAR * LPMIXERLINE;
#endif
#define MIXERLINE_LINEF_ACTIVE              0x00000001L
#define MIXERLINE_LINEF_DISCONNECTED        0x00008000L
#define MIXERLINE_LINEF_SOURCE              0x80000000L
#define MIXERLINE_COMPONENTTYPE_DST_FIRST       0x00000000L
#define MIXERLINE_COMPONENTTYPE_DST_UNDEFINED   (MIXERLINE_COMPONENTTYPE_DST_FIRST + 0)
#define MIXERLINE_COMPONENTTYPE_DST_DIGITAL     (MIXERLINE_COMPONENTTYPE_DST_FIRST + 1)
#define MIXERLINE_COMPONENTTYPE_DST_LINE        (MIXERLINE_COMPONENTTYPE_DST_FIRST + 2)
#define MIXERLINE_COMPONENTTYPE_DST_MONITOR     (MIXERLINE_COMPONENTTYPE_DST_FIRST + 3)
#define MIXERLINE_COMPONENTTYPE_DST_SPEAKERS    (MIXERLINE_COMPONENTTYPE_DST_FIRST + 4)
#define MIXERLINE_COMPONENTTYPE_DST_HEADPHONES  (MIXERLINE_COMPONENTTYPE_DST_FIRST + 5)
#define MIXERLINE_COMPONENTTYPE_DST_TELEPHONE   (MIXERLINE_COMPONENTTYPE_DST_FIRST + 6)
#define MIXERLINE_COMPONENTTYPE_DST_WAVEIN      (MIXERLINE_COMPONENTTYPE_DST_FIRST + 7)
#define MIXERLINE_COMPONENTTYPE_DST_VOICEIN     (MIXERLINE_COMPONENTTYPE_DST_FIRST + 8)
#define MIXERLINE_COMPONENTTYPE_DST_LAST        (MIXERLINE_COMPONENTTYPE_DST_FIRST + 8)
#define MIXERLINE_COMPONENTTYPE_SRC_FIRST       0x00001000L
#define MIXERLINE_COMPONENTTYPE_SRC_UNDEFINED   (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 0)
#define MIXERLINE_COMPONENTTYPE_SRC_DIGITAL     (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 1)
#define MIXERLINE_COMPONENTTYPE_SRC_LINE        (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 2)
#define MIXERLINE_COMPONENTTYPE_SRC_MICROPHONE  (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 3)
#define MIXERLINE_COMPONENTTYPE_SRC_SYNTHESIZER (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 4)
#define MIXERLINE_COMPONENTTYPE_SRC_COMPACTDISC (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 5)
#define MIXERLINE_COMPONENTTYPE_SRC_TELEPHONE   (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 6)
#define MIXERLINE_COMPONENTTYPE_SRC_PCSPEAKER   (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 7)
#define MIXERLINE_COMPONENTTYPE_SRC_WAVEOUT     (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 8)
#define MIXERLINE_COMPONENTTYPE_SRC_AUXILIARY   (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 9)
#define MIXERLINE_COMPONENTTYPE_SRC_ANALOG      (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 10)
#define MIXERLINE_COMPONENTTYPE_SRC_LAST        (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 10)
#define MIXERLINE_TARGETTYPE_UNDEFINED      0
#define MIXERLINE_TARGETTYPE_WAVEOUT        1
#define MIXERLINE_TARGETTYPE_WAVEIN         2
#define MIXERLINE_TARGETTYPE_MIDIOUT        3
#define MIXERLINE_TARGETTYPE_MIDIIN         4
#define MIXERLINE_TARGETTYPE_AUX            5
#ifdef _WIN32
WINMMAPI MMRESULT WINAPI mixerGetLineInfoA(HMIXEROBJ hmxobj, LPMIXERLINEA pmxl, DWORD fdwInfo);
WINMMAPI MMRESULT WINAPI mixerGetLineInfoW(HMIXEROBJ hmxobj, LPMIXERLINEW pmxl, DWORD fdwInfo);
#ifdef UNICODE
#define mixerGetLineInfo  mixerGetLineInfoW
#else
#define mixerGetLineInfo  mixerGetLineInfoA
#endif
#else
MMRESULT WINAPI mixerGetLineInfo(HMIXEROBJ hmxobj, LPMIXERLINE pmxl, DWORD fdwInfo);
#endif
#define MIXER_GETLINEINFOF_DESTINATION      0x00000000L
#define MIXER_GETLINEINFOF_SOURCE           0x00000001L
#define MIXER_GETLINEINFOF_LINEID           0x00000002L
#define MIXER_GETLINEINFOF_COMPONENTTYPE    0x00000003L
#define MIXER_GETLINEINFOF_TARGETTYPE       0x00000004L
#define MIXER_GETLINEINFOF_QUERYMASK        0x0000000FL
WINMMAPI MMRESULT WINAPI mixerGetID(HMIXEROBJ hmxobj, UINT FAR *puMxId, DWORD fdwId);
#ifdef _WIN32
typedef struct tagMIXERCONTROLA {
	DWORD cbStruct;
	DWORD dwControlID;
	DWORD dwControlType;
	DWORD fdwControl;
	DWORD cMultipleItems;
	CHAR szShortName[MIXER_SHORT_NAME_CHARS];
	CHAR szName[MIXER_LONG_NAME_CHARS];
	union {
		struct {
			LONG lMinimum;
			LONG lMaximum;
		} DUMMYSTRUCTNAME;
		struct {
			DWORD dwMinimum;
			DWORD dwMaximum;
		} DUMMYSTRUCTNAME2;
		DWORD dwReserved[6];
	} Bounds;
	union {
		DWORD cSteps;
		DWORD cbCustomData;
		DWORD dwReserved[6];
	} Metrics;
} MIXERCONTROLA, *PMIXERCONTROLA, *LPMIXERCONTROLA;
typedef struct tagMIXERCONTROLW {
	DWORD cbStruct;
	DWORD dwControlID;
	DWORD dwControlType;
	DWORD fdwControl;
	DWORD cMultipleItems;
	WCHAR szShortName[MIXER_SHORT_NAME_CHARS];
	WCHAR szName[MIXER_LONG_NAME_CHARS];
	union {
		struct {
			LONG lMinimum;
			LONG lMaximum;
		} DUMMYSTRUCTNAME;
		struct {
			DWORD dwMinimum;
			DWORD dwMaximum;
		} DUMMYSTRUCTNAME2;
		DWORD dwReserved[6];
	} Bounds;
	union {
		DWORD cSteps;
		DWORD cbCustomData;
		DWORD dwReserved[6];
	} Metrics;
} MIXERCONTROLW, *PMIXERCONTROLW, *LPMIXERCONTROLW;
#ifdef UNICODE
typedef MIXERCONTROLW MIXERCONTROL;
typedef PMIXERCONTROLW PMIXERCONTROL;
typedef LPMIXERCONTROLW LPMIXERCONTROL;
#else
typedef MIXERCONTROLA MIXERCONTROL;
typedef PMIXERCONTROLA PMIXERCONTROL;
typedef LPMIXERCONTROLA LPMIXERCONTROL;
#endif
#else
typedef struct tMIXERCONTROL {
	DWORD cbStruct;
	DWORD dwControlID;
	DWORD dwControlType;
	DWORD fdwControl;
	DWORD cMultipleItems;
	char szShortName[MIXER_SHORT_NAME_CHARS];
	char szName[MIXER_LONG_NAME_CHARS];
	union {
		struct {
			LONG lMinimum;
			LONG lMaximum;
		} DUMMYSTRUCTNAME;
		struct {
			DWORD dwMinimum;
			DWORD dwMaximum;
		} DUMMYSTRUCTNAME2;
		DWORD dwReserved[6];
	} Bounds;
	union {
		DWORD cSteps;
		DWORD cbCustomData;
		DWORD dwReserved[6];
	} Metrics;
} MIXERCONTROL, *PMIXERCONTROL, FAR * LPMIXERCONTROL;
#endif
#define MIXERCONTROL_CONTROLF_UNIFORM   0x00000001L
#define MIXERCONTROL_CONTROLF_MULTIPLE  0x00000002L
#define MIXERCONTROL_CONTROLF_DISABLED  0x80000000L
#define MIXERCONTROL_CT_CLASS_MASK          0xF0000000L
#define MIXERCONTROL_CT_CLASS_CUSTOM        0x00000000L
#define MIXERCONTROL_CT_CLASS_METER         0x10000000L
#define MIXERCONTROL_CT_CLASS_SWITCH        0x20000000L
#define MIXERCONTROL_CT_CLASS_NUMBER        0x30000000L
#define MIXERCONTROL_CT_CLASS_SLIDER        0x40000000L
#define MIXERCONTROL_CT_CLASS_FADER         0x50000000L
#define MIXERCONTROL_CT_CLASS_TIME          0x60000000L
#define MIXERCONTROL_CT_CLASS_LIST          0x70000000L
#define MIXERCONTROL_CT_SUBCLASS_MASK       0x0F000000L
#define MIXERCONTROL_CT_SC_SWITCH_BOOLEAN   0x00000000L
#define MIXERCONTROL_CT_SC_SWITCH_BUTTON    0x01000000L
#define MIXERCONTROL_CT_SC_METER_POLLED     0x00000000L
#define MIXERCONTROL_CT_SC_TIME_MICROSECS   0x00000000L
#define MIXERCONTROL_CT_SC_TIME_MILLISECS   0x01000000L
#define MIXERCONTROL_CT_SC_LIST_SINGLE      0x00000000L
#define MIXERCONTROL_CT_SC_LIST_MULTIPLE    0x01000000L
#define MIXERCONTROL_CT_UNITS_MASK          0x00FF0000L
#define MIXERCONTROL_CT_UNITS_CUSTOM        0x00000000L
#define MIXERCONTROL_CT_UNITS_BOOLEAN       0x00010000L
#define MIXERCONTROL_CT_UNITS_SIGNED        0x00020000L
#define MIXERCONTROL_CT_UNITS_UNSIGNED      0x00030000L
#define MIXERCONTROL_CT_UNITS_DECIBELS      0x00040000L
#define MIXERCONTROL_CT_UNITS_PERCENT       0x00050000L
#define MIXERCONTROL_CONTROLTYPE_CUSTOM         (MIXERCONTROL_CT_CLASS_CUSTOM | MIXERCONTROL_CT_UNITS_CUSTOM)
#define MIXERCONTROL_CONTROLTYPE_BOOLEANMETER   (MIXERCONTROL_CT_CLASS_METER | MIXERCONTROL_CT_SC_METER_POLLED | MIXERCONTROL_CT_UNITS_BOOLEAN)
#define MIXERCONTROL_CONTROLTYPE_SIGNEDMETER    (MIXERCONTROL_CT_CLASS_METER | MIXERCONTROL_CT_SC_METER_POLLED | MIXERCONTROL_CT_UNITS_SIGNED)
#define MIXERCONTROL_CONTROLTYPE_PEAKMETER      (MIXERCONTROL_CONTROLTYPE_SIGNEDMETER + 1)
#define MIXERCONTROL_CONTROLTYPE_UNSIGNEDMETER  (MIXERCONTROL_CT_CLASS_METER | MIXERCONTROL_CT_SC_METER_POLLED | MIXERCONTROL_CT_UNITS_UNSIGNED)
#define MIXERCONTROL_CONTROLTYPE_BOOLEAN        (MIXERCONTROL_CT_CLASS_SWITCH | MIXERCONTROL_CT_SC_SWITCH_BOOLEAN | MIXERCONTROL_CT_UNITS_BOOLEAN)
#define MIXERCONTROL_CONTROLTYPE_ONOFF          (MIXERCONTROL_CONTROLTYPE_BOOLEAN + 1)
#define MIXERCONTROL_CONTROLTYPE_MUTE           (MIXERCONTROL_CONTROLTYPE_BOOLEAN + 2)
#define MIXERCONTROL_CONTROLTYPE_MONO           (MIXERCONTROL_CONTROLTYPE_BOOLEAN + 3)
#define MIXERCONTROL_CONTROLTYPE_LOUDNESS       (MIXERCONTROL_CONTROLTYPE_BOOLEAN + 4)
#define MIXERCONTROL_CONTROLTYPE_STEREOENH      (MIXERCONTROL_CONTROLTYPE_BOOLEAN + 5)
#define MIXERCONTROL_CONTROLTYPE_BASS_BOOST     (MIXERCONTROL_CONTROLTYPE_BOOLEAN + 0x00002277)
#define MIXERCONTROL_CONTROLTYPE_BUTTON         (MIXERCONTROL_CT_CLASS_SWITCH | MIXERCONTROL_CT_SC_SWITCH_BUTTON | MIXERCONTROL_CT_UNITS_BOOLEAN)
#define MIXERCONTROL_CONTROLTYPE_DECIBELS       (MIXERCONTROL_CT_CLASS_NUMBER | MIXERCONTROL_CT_UNITS_DECIBELS)
#define MIXERCONTROL_CONTROLTYPE_SIGNED         (MIXERCONTROL_CT_CLASS_NUMBER | MIXERCONTROL_CT_UNITS_SIGNED)
#define MIXERCONTROL_CONTROLTYPE_UNSIGNED       (MIXERCONTROL_CT_CLASS_NUMBER | MIXERCONTROL_CT_UNITS_UNSIGNED)
#define MIXERCONTROL_CONTROLTYPE_PERCENT        (MIXERCONTROL_CT_CLASS_NUMBER | MIXERCONTROL_CT_UNITS_PERCENT)
#define MIXERCONTROL_CONTROLTYPE_SLIDER         (MIXERCONTROL_CT_CLASS_SLIDER | MIXERCONTROL_CT_UNITS_SIGNED)
#define MIXERCONTROL_CONTROLTYPE_PAN            (MIXERCONTROL_CONTROLTYPE_SLIDER + 1)
#define MIXERCONTROL_CONTROLTYPE_QSOUNDPAN      (MIXERCONTROL_CONTROLTYPE_SLIDER + 2)
#define MIXERCONTROL_CONTROLTYPE_FADER          (MIXERCONTROL_CT_CLASS_FADER | MIXERCONTROL_CT_UNITS_UNSIGNED)
#define MIXERCONTROL_CONTROLTYPE_VOLUME         (MIXERCONTROL_CONTROLTYPE_FADER + 1)
#define MIXERCONTROL_CONTROLTYPE_BASS           (MIXERCONTROL_CONTROLTYPE_FADER + 2)
#define MIXERCONTROL_CONTROLTYPE_TREBLE         (MIXERCONTROL_CONTROLTYPE_FADER + 3)
#define MIXERCONTROL_CONTROLTYPE_EQUALIZER      (MIXERCONTROL_CONTROLTYPE_FADER + 4)
#define MIXERCONTROL_CONTROLTYPE_SINGLESELECT   (MIXERCONTROL_CT_CLASS_LIST | MIXERCONTROL_CT_SC_LIST_SINGLE | MIXERCONTROL_CT_UNITS_BOOLEAN)
#define MIXERCONTROL_CONTROLTYPE_MUX            (MIXERCONTROL_CONTROLTYPE_SINGLESELECT + 1)
#define MIXERCONTROL_CONTROLTYPE_MULTIPLESELECT (MIXERCONTROL_CT_CLASS_LIST | MIXERCONTROL_CT_SC_LIST_MULTIPLE | MIXERCONTROL_CT_UNITS_BOOLEAN)
#define MIXERCONTROL_CONTROLTYPE_MIXER          (MIXERCONTROL_CONTROLTYPE_MULTIPLESELECT + 1)
#define MIXERCONTROL_CONTROLTYPE_MICROTIME      (MIXERCONTROL_CT_CLASS_TIME | MIXERCONTROL_CT_SC_TIME_MICROSECS | MIXERCONTROL_CT_UNITS_UNSIGNED)
#define MIXERCONTROL_CONTROLTYPE_MILLITIME      (MIXERCONTROL_CT_CLASS_TIME | MIXERCONTROL_CT_SC_TIME_MILLISECS | MIXERCONTROL_CT_UNITS_UNSIGNED)
#ifdef _WIN32
typedef struct tagMIXERLINECONTROLSA {
	DWORD cbStruct;
	DWORD dwLineID;
	union {
		DWORD dwControlID;
		DWORD dwControlType;
	} DUMMYUNIONNAME;
	DWORD cControls;
	DWORD cbmxctrl;
	LPMIXERCONTROLA pamxctrl;
} MIXERLINECONTROLSA, *PMIXERLINECONTROLSA, *LPMIXERLINECONTROLSA;
typedef struct tagMIXERLINECONTROLSW {
	DWORD cbStruct;
	DWORD dwLineID;
	union {
		DWORD dwControlID;
		DWORD dwControlType;
	} DUMMYUNIONNAME;
	DWORD cControls;
	DWORD cbmxctrl;
	LPMIXERCONTROLW pamxctrl;
} MIXERLINECONTROLSW, *PMIXERLINECONTROLSW, *LPMIXERLINECONTROLSW;
#ifdef UNICODE
typedef MIXERLINECONTROLSW MIXERLINECONTROLS;
typedef PMIXERLINECONTROLSW PMIXERLINECONTROLS;
typedef LPMIXERLINECONTROLSW LPMIXERLINECONTROLS;
#else
typedef MIXERLINECONTROLSA MIXERLINECONTROLS;
typedef PMIXERLINECONTROLSA PMIXERLINECONTROLS;
typedef LPMIXERLINECONTROLSA LPMIXERLINECONTROLS;
#endif
#else
typedef struct tMIXERLINECONTROLS {
	DWORD cbStruct;
	DWORD dwLineID;
	union {
		DWORD dwControlID;
		DWORD dwControlType;
	};
	DWORD cControls;
	DWORD cbmxctrl;
	LPMIXERCONTROL pamxctrl;
} MIXERLINECONTROLS, *PMIXERLINECONTROLS, FAR * LPMIXERLINECONTROLS;
#endif
#ifdef _WIN32
WINMMAPI MMRESULT WINAPI mixerGetLineControlsA(HMIXEROBJ hmxobj, LPMIXERLINECONTROLSA pmxlc, DWORD fdwControls);
WINMMAPI MMRESULT WINAPI mixerGetLineControlsW(HMIXEROBJ hmxobj, LPMIXERLINECONTROLSW pmxlc, DWORD fdwControls);
#ifdef UNICODE
#define mixerGetLineControls  mixerGetLineControlsW
#else
#define mixerGetLineControls  mixerGetLineControlsA
#endif
#else
MMRESULT WINAPI mixerGetLineControls(HMIXEROBJ hmxobj, LPMIXERLINECONTROLS pmxlc, DWORD fdwControls);
#endif
#define MIXER_GETLINECONTROLSF_ALL          0x00000000L
#define MIXER_GETLINECONTROLSF_ONEBYID      0x00000001L
#define MIXER_GETLINECONTROLSF_ONEBYTYPE    0x00000002L
#define MIXER_GETLINECONTROLSF_QUERYMASK    0x0000000FL
typedef struct tMIXERCONTROLDETAILS {
	DWORD cbStruct;
	DWORD dwControlID;
	DWORD cChannels;
	union {
		HWND hwndOwner;
		DWORD cMultipleItems;
	} DUMMYUNIONNAME;
	DWORD cbDetails;
	LPVOID paDetails;
} MIXERCONTROLDETAILS, *PMIXERCONTROLDETAILS, FAR * LPMIXERCONTROLDETAILS;
#ifdef _WIN32
typedef struct tagMIXERCONTROLDETAILS_LISTTEXTA {
	DWORD dwParam1;
	DWORD dwParam2;
	CHAR szName[MIXER_LONG_NAME_CHARS];
} MIXERCONTROLDETAILS_LISTTEXTA, *PMIXERCONTROLDETAILS_LISTTEXTA, *LPMIXERCONTROLDETAILS_LISTTEXTA;
typedef struct tagMIXERCONTROLDETAILS_LISTTEXTW {
	DWORD dwParam1;
	DWORD dwParam2;
	WCHAR szName[MIXER_LONG_NAME_CHARS];
} MIXERCONTROLDETAILS_LISTTEXTW, *PMIXERCONTROLDETAILS_LISTTEXTW, *LPMIXERCONTROLDETAILS_LISTTEXTW;
#ifdef UNICODE
typedef MIXERCONTROLDETAILS_LISTTEXTW MIXERCONTROLDETAILS_LISTTEXT;
typedef PMIXERCONTROLDETAILS_LISTTEXTW PMIXERCONTROLDETAILS_LISTTEXT;
typedef LPMIXERCONTROLDETAILS_LISTTEXTW LPMIXERCONTROLDETAILS_LISTTEXT;
#else
typedef MIXERCONTROLDETAILS_LISTTEXTA MIXERCONTROLDETAILS_LISTTEXT;
typedef PMIXERCONTROLDETAILS_LISTTEXTA PMIXERCONTROLDETAILS_LISTTEXT;
typedef LPMIXERCONTROLDETAILS_LISTTEXTA LPMIXERCONTROLDETAILS_LISTTEXT;
#endif
#else
typedef struct tMIXERCONTROLDETAILS_LISTTEXT {
	DWORD dwParam1;
	DWORD dwParam2;
	char szName[MIXER_LONG_NAME_CHARS];
} MIXERCONTROLDETAILS_LISTTEXT, *PMIXERCONTROLDETAILS_LISTTEXT, FAR * LPMIXERCONTROLDETAILS_LISTTEXT;
#endif
typedef struct tMIXERCONTROLDETAILS_BOOLEAN {
	LONG fValue;
} MIXERCONTROLDETAILS_BOOLEAN, *PMIXERCONTROLDETAILS_BOOLEAN, FAR * LPMIXERCONTROLDETAILS_BOOLEAN;
typedef struct tMIXERCONTROLDETAILS_SIGNED {
	LONG lValue;
} MIXERCONTROLDETAILS_SIGNED, *PMIXERCONTROLDETAILS_SIGNED, FAR * LPMIXERCONTROLDETAILS_SIGNED;
typedef struct tMIXERCONTROLDETAILS_UNSIGNED {
	DWORD dwValue;
} MIXERCONTROLDETAILS_UNSIGNED, *PMIXERCONTROLDETAILS_UNSIGNED, FAR * LPMIXERCONTROLDETAILS_UNSIGNED;
#ifdef _WIN32
WINMMAPI MMRESULT WINAPI mixerGetControlDetailsA(HMIXEROBJ hmxobj, LPMIXERCONTROLDETAILS pmxcd, DWORD fdwDetails);
WINMMAPI MMRESULT WINAPI mixerGetControlDetailsW(HMIXEROBJ hmxobj, LPMIXERCONTROLDETAILS pmxcd, DWORD fdwDetails);
#ifdef UNICODE
#define mixerGetControlDetails  mixerGetControlDetailsW
#else
#define mixerGetControlDetails  mixerGetControlDetailsA
#endif
#else
MMRESULT WINAPI mixerGetControlDetails(HMIXEROBJ hmxobj, LPMIXERCONTROLDETAILS pmxcd, DWORD fdwDetails);
#endif
#define MIXER_GETCONTROLDETAILSF_VALUE      0x00000000L
#define MIXER_GETCONTROLDETAILSF_LISTTEXT   0x00000001L
#define MIXER_GETCONTROLDETAILSF_QUERYMASK  0x0000000FL
WINMMAPI MMRESULT WINAPI mixerSetControlDetails(HMIXEROBJ hmxobj, LPMIXERCONTROLDETAILS pmxcd, DWORD fdwDetails);
#define MIXER_SETCONTROLDETAILSF_VALUE      0x00000000L
#define MIXER_SETCONTROLDETAILSF_CUSTOM     0x00000001L
#define MIXER_SETCONTROLDETAILSF_QUERYMASK  0x0000000FL
#endif
#ifndef MMNOTIMER
#define TIMERR_NOERROR        (0)
#define TIMERR_NOCANDO        (TIMERR_BASE+1)
#define TIMERR_STRUCT         (TIMERR_BASE+33)
typedef void (CALLBACK TIMECALLBACK) (UINT uTimerID, UINT uMsg, DWORD_PTR dwUser, DWORD_PTR dw1, DWORD_PTR dw2);
typedef TIMECALLBACK FAR *LPTIMECALLBACK;
#define TIME_ONESHOT    0x0000
#define TIME_PERIODIC   0x0001
#ifdef _WIN32
#define TIME_CALLBACK_FUNCTION      0x0000
#define TIME_CALLBACK_EVENT_SET     0x0010
#define TIME_CALLBACK_EVENT_PULSE   0x0020
#endif
#if WINVER >= 0x0501
#define TIME_KILL_SYNCHRONOUS   0x0100
#endif
typedef struct timecaps_tag {
	UINT wPeriodMin;
	UINT wPeriodMax;
} TIMECAPS, *PTIMECAPS, NEAR * NPTIMECAPS, FAR * LPTIMECAPS;
WINMMAPI MMRESULT WINAPI timeGetSystemTime(LPMMTIME pmmt, UINT cbmmt);
WINMMAPI DWORD WINAPI timeGetTime(void);
WINMMAPI MMRESULT WINAPI timeSetEvent(UINT uDelay, UINT uResolution, LPTIMECALLBACK fptc, DWORD_PTR dwUser, UINT fuEvent);
WINMMAPI MMRESULT WINAPI timeKillEvent(UINT uTimerID);
WINMMAPI MMRESULT WINAPI timeGetDevCaps(LPTIMECAPS ptc, UINT cbtc);
WINMMAPI MMRESULT WINAPI timeBeginPeriod(UINT uPeriod);
WINMMAPI MMRESULT WINAPI timeEndPeriod(UINT uPeriod);
#endif
#ifndef MMNOJOY
#define JOYERR_NOERROR        (0)
#define JOYERR_PARMS          (JOYERR_BASE+5)
#define JOYERR_NOCANDO        (JOYERR_BASE+6)
#define JOYERR_UNPLUGGED      (JOYERR_BASE+7)
#define JOY_BUTTON1         0x0001
#define JOY_BUTTON2         0x0002
#define JOY_BUTTON3         0x0004
#define JOY_BUTTON4         0x0008
#define JOY_BUTTON1CHG      0x0100
#define JOY_BUTTON2CHG      0x0200
#define JOY_BUTTON3CHG      0x0400
#define JOY_BUTTON4CHG      0x0800
#define JOY_BUTTON5         0x00000010l
#define JOY_BUTTON6         0x00000020l
#define JOY_BUTTON7         0x00000040l
#define JOY_BUTTON8         0x00000080l
#define JOY_BUTTON9         0x00000100l
#define JOY_BUTTON10        0x00000200l
#define JOY_BUTTON11        0x00000400l
#define JOY_BUTTON12        0x00000800l
#define JOY_BUTTON13        0x00001000l
#define JOY_BUTTON14        0x00002000l
#define JOY_BUTTON15        0x00004000l
#define JOY_BUTTON16        0x00008000l
#define JOY_BUTTON17        0x00010000l
#define JOY_BUTTON18        0x00020000l
#define JOY_BUTTON19        0x00040000l
#define JOY_BUTTON20        0x00080000l
#define JOY_BUTTON21        0x00100000l
#define JOY_BUTTON22        0x00200000l
#define JOY_BUTTON23        0x00400000l
#define JOY_BUTTON24        0x00800000l
#define JOY_BUTTON25        0x01000000l
#define JOY_BUTTON26        0x02000000l
#define JOY_BUTTON27        0x04000000l
#define JOY_BUTTON28        0x08000000l
#define JOY_BUTTON29        0x10000000l
#define JOY_BUTTON30        0x20000000l
#define JOY_BUTTON31        0x40000000l
#define JOY_BUTTON32        0x80000000l
#define JOY_POVCENTERED         (WORD) -1
#define JOY_POVFORWARD          0
#define JOY_POVRIGHT            9000
#define JOY_POVBACKWARD         18000
#define JOY_POVLEFT             27000
#define JOY_RETURNX             0x00000001l
#define JOY_RETURNY             0x00000002l
#define JOY_RETURNZ             0x00000004l
#define JOY_RETURNR             0x00000008l
#define JOY_RETURNU             0x00000010l
#define JOY_RETURNV             0x00000020l
#define JOY_RETURNPOV           0x00000040l
#define JOY_RETURNBUTTONS       0x00000080l
#define JOY_RETURNRAWDATA       0x00000100l
#define JOY_RETURNPOVCTS        0x00000200l
#define JOY_RETURNCENTERED      0x00000400l
#define JOY_USEDEADZONE         0x00000800l
#define JOY_RETURNALL           (JOY_RETURNX | JOY_RETURNY | JOY_RETURNZ | \
                                 JOY_RETURNR | JOY_RETURNU | JOY_RETURNV | \
                                 JOY_RETURNPOV | JOY_RETURNBUTTONS)
#define JOY_CAL_READALWAYS      0x00010000l
#define JOY_CAL_READXYONLY      0x00020000l
#define JOY_CAL_READ3           0x00040000l
#define JOY_CAL_READ4           0x00080000l
#define JOY_CAL_READXONLY       0x00100000l
#define JOY_CAL_READYONLY       0x00200000l
#define JOY_CAL_READ5           0x00400000l
#define JOY_CAL_READ6           0x00800000l
#define JOY_CAL_READZONLY       0x01000000l
#define JOY_CAL_READRONLY       0x02000000l
#define JOY_CAL_READUONLY       0x04000000l
#define JOY_CAL_READVONLY       0x08000000l
#define JOYSTICKID1         0
#define JOYSTICKID2         1
#define JOYCAPS_HASZ            0x0001
#define JOYCAPS_HASR            0x0002
#define JOYCAPS_HASU            0x0004
#define JOYCAPS_HASV            0x0008
#define JOYCAPS_HASPOV          0x0010
#define JOYCAPS_POV4DIR         0x0020
#define JOYCAPS_POVCTS          0x0040
#ifdef _WIN32
typedef struct tagJOYCAPSA {
	WORD wMid;
	WORD wPid;
	CHAR szPname[MAXPNAMELEN];
	UINT wXmin;
	UINT wXmax;
	UINT wYmin;
	UINT wYmax;
	UINT wZmin;
	UINT wZmax;
	UINT wNumButtons;
	UINT wPeriodMin;
	UINT wPeriodMax;
#if (WINVER >= 0x0400)
	UINT wRmin;
	UINT wRmax;
	UINT wUmin;
	UINT wUmax;
	UINT wVmin;
	UINT wVmax;
	UINT wCaps;
	UINT wMaxAxes;
	UINT wNumAxes;
	UINT wMaxButtons;
	CHAR szRegKey[MAXPNAMELEN];
	CHAR szOEMVxD[MAX_JOYSTICKOEMVXDNAME];
#endif
} JOYCAPSA, *PJOYCAPSA, *NPJOYCAPSA, *LPJOYCAPSA;
typedef struct tagJOYCAPSW {
	WORD wMid;
	WORD wPid;
	WCHAR szPname[MAXPNAMELEN];
	UINT wXmin;
	UINT wXmax;
	UINT wYmin;
	UINT wYmax;
	UINT wZmin;
	UINT wZmax;
	UINT wNumButtons;
	UINT wPeriodMin;
	UINT wPeriodMax;
#if (WINVER >= 0x0400)
	UINT wRmin;
	UINT wRmax;
	UINT wUmin;
	UINT wUmax;
	UINT wVmin;
	UINT wVmax;
	UINT wCaps;
	UINT wMaxAxes;
	UINT wNumAxes;
	UINT wMaxButtons;
	WCHAR szRegKey[MAXPNAMELEN];
	WCHAR szOEMVxD[MAX_JOYSTICKOEMVXDNAME];
#endif
} JOYCAPSW, *PJOYCAPSW, *NPJOYCAPSW, *LPJOYCAPSW;
#ifdef UNICODE
typedef JOYCAPSW JOYCAPS;
typedef PJOYCAPSW PJOYCAPS;
typedef NPJOYCAPSW NPJOYCAPS;
typedef LPJOYCAPSW LPJOYCAPS;
#else
typedef JOYCAPSA JOYCAPS;
typedef PJOYCAPSA PJOYCAPS;
typedef NPJOYCAPSA NPJOYCAPS;
typedef LPJOYCAPSA LPJOYCAPS;
#endif
typedef struct tagJOYCAPS2A {
	WORD wMid;
	WORD wPid;
	CHAR szPname[MAXPNAMELEN];
	UINT wXmin;
	UINT wXmax;
	UINT wYmin;
	UINT wYmax;
	UINT wZmin;
	UINT wZmax;
	UINT wNumButtons;
	UINT wPeriodMin;
	UINT wPeriodMax;
	UINT wRmin;
	UINT wRmax;
	UINT wUmin;
	UINT wUmax;
	UINT wVmin;
	UINT wVmax;
	UINT wCaps;
	UINT wMaxAxes;
	UINT wNumAxes;
	UINT wMaxButtons;
	CHAR szRegKey[MAXPNAMELEN];
	CHAR szOEMVxD[MAX_JOYSTICKOEMVXDNAME];
	GUID ManufacturerGuid;
	GUID ProductGuid;
	GUID NameGuid;
} JOYCAPS2A, *PJOYCAPS2A, *NPJOYCAPS2A, *LPJOYCAPS2A;
typedef struct tagJOYCAPS2W {
	WORD wMid;
	WORD wPid;
	WCHAR szPname[MAXPNAMELEN];
	UINT wXmin;
	UINT wXmax;
	UINT wYmin;
	UINT wYmax;
	UINT wZmin;
	UINT wZmax;
	UINT wNumButtons;
	UINT wPeriodMin;
	UINT wPeriodMax;
	UINT wRmin;
	UINT wRmax;
	UINT wUmin;
	UINT wUmax;
	UINT wVmin;
	UINT wVmax;
	UINT wCaps;
	UINT wMaxAxes;
	UINT wNumAxes;
	UINT wMaxButtons;
	WCHAR szRegKey[MAXPNAMELEN];
	WCHAR szOEMVxD[MAX_JOYSTICKOEMVXDNAME];
	GUID ManufacturerGuid;
	GUID ProductGuid;
	GUID NameGuid;
} JOYCAPS2W, *PJOYCAPS2W, *NPJOYCAPS2W, *LPJOYCAPS2W;
#ifdef UNICODE
typedef JOYCAPS2W JOYCAPS2;
typedef PJOYCAPS2W PJOYCAPS2;
typedef NPJOYCAPS2W NPJOYCAPS2;
typedef LPJOYCAPS2W LPJOYCAPS2;
#else
typedef JOYCAPS2A JOYCAPS2;
typedef PJOYCAPS2A PJOYCAPS2;
typedef NPJOYCAPS2A NPJOYCAPS2;
typedef LPJOYCAPS2A LPJOYCAPS2;
#endif
#else
typedef struct joycaps_tag {
	WORD wMid;
	WORD wPid;
	char szPname[MAXPNAMELEN];
	UINT wXmin;
	UINT wXmax;
	UINT wYmin;
	UINT wYmax;
	UINT wZmin;
	UINT wZmax;
	UINT wNumButtons;
	UINT wPeriodMin;
	UINT wPeriodMax;
#if (WINVER >= 0x0400)
	UINT wRmin;
	UINT wRmax;
	UINT wUmin;
	UINT wUmax;
	UINT wVmin;
	UINT wVmax;
	UINT wCaps;
	UINT wMaxAxes;
	UINT wNumAxes;
	UINT wMaxButtons;
	char szRegKey[MAXPNAMELEN];
	char szOEMVxD[MAX_JOYSTICKOEMVXDNAME];
#endif
} JOYCAPS, *PJOYCAPS, NEAR * NPJOYCAPS, FAR * LPJOYCAPS;
#endif
typedef struct joyinfo_tag {
	UINT wXpos;
	UINT wYpos;
	UINT wZpos;
	UINT wButtons;
} JOYINFO, *PJOYINFO, NEAR * NPJOYINFO, FAR * LPJOYINFO;
#if(WINVER >= 0x0400)
typedef struct joyinfoex_tag {
	DWORD dwSize;
	DWORD dwFlags;
	DWORD dwXpos;
	DWORD dwYpos;
	DWORD dwZpos;
	DWORD dwRpos;
	DWORD dwUpos;
	DWORD dwVpos;
	DWORD dwButtons;
	DWORD dwButtonNumber;
	DWORD dwPOV;
	DWORD dwReserved1;
	DWORD dwReserved2;
} JOYINFOEX, *PJOYINFOEX, NEAR * NPJOYINFOEX, FAR * LPJOYINFOEX;
#endif
WINMMAPI UINT WINAPI joyGetNumDevs(void);
#ifdef _WIN32
WINMMAPI MMRESULT WINAPI joyGetDevCapsA(UINT_PTR uJoyID, LPJOYCAPSA pjc, UINT cbjc);
WINMMAPI MMRESULT WINAPI joyGetDevCapsW(UINT_PTR uJoyID, LPJOYCAPSW pjc, UINT cbjc);
#ifdef UNICODE
#define joyGetDevCaps  joyGetDevCapsW
#else
#define joyGetDevCaps  joyGetDevCapsA
#endif
#else
MMRESULT WINAPI joyGetDevCaps(UINT uJoyID, LPJOYCAPS pjc, UINT cbjc);
#endif
WINMMAPI MMRESULT WINAPI joyGetPos(UINT uJoyID, LPJOYINFO pji);
#if(WINVER >= 0x0400)
WINMMAPI MMRESULT WINAPI joyGetPosEx(UINT uJoyID, LPJOYINFOEX pji);
#endif
WINMMAPI MMRESULT WINAPI joyGetThreshold(UINT uJoyID, LPUINT puThreshold);
WINMMAPI MMRESULT WINAPI joyReleaseCapture(UINT uJoyID);
WINMMAPI MMRESULT WINAPI joySetCapture(HWND hwnd, UINT uJoyID, UINT uPeriod, BOOL fChanged);
WINMMAPI MMRESULT WINAPI joySetThreshold(UINT uJoyID, UINT uThreshold);
#endif
#ifndef MMNOMMIO
#define MMIOERR_BASE                256
#define MMIOERR_FILENOTFOUND        (MMIOERR_BASE + 1)
#define MMIOERR_OUTOFMEMORY         (MMIOERR_BASE + 2)
#define MMIOERR_CANNOTOPEN          (MMIOERR_BASE + 3)
#define MMIOERR_CANNOTCLOSE         (MMIOERR_BASE + 4)
#define MMIOERR_CANNOTREAD          (MMIOERR_BASE + 5)
#define MMIOERR_CANNOTWRITE         (MMIOERR_BASE + 6)
#define MMIOERR_CANNOTSEEK          (MMIOERR_BASE + 7)
#define MMIOERR_CANNOTEXPAND        (MMIOERR_BASE + 8)
#define MMIOERR_CHUNKNOTFOUND       (MMIOERR_BASE + 9)
#define MMIOERR_UNBUFFERED          (MMIOERR_BASE + 10)
#define MMIOERR_PATHNOTFOUND        (MMIOERR_BASE + 11)
#define MMIOERR_ACCESSDENIED        (MMIOERR_BASE + 12)
#define MMIOERR_SHARINGVIOLATION    (MMIOERR_BASE + 13)
#define MMIOERR_NETWORKERROR        (MMIOERR_BASE + 14)
#define MMIOERR_TOOMANYOPENFILES    (MMIOERR_BASE + 15)
#define MMIOERR_INVALIDFILE         (MMIOERR_BASE + 16)
#define CFSEPCHAR       '+'
typedef DWORD FOURCC;
typedef char _huge *HPSTR;
DECLARE_HANDLE(HMMIO);
typedef LRESULT(CALLBACK MMIOPROC) (LPSTR lpmmioinfo, UINT uMsg, LPARAM lParam1, LPARAM lParam2);
typedef MMIOPROC FAR *LPMMIOPROC;
typedef struct _MMIOINFO {
	DWORD dwFlags;
	FOURCC fccIOProc;
	LPMMIOPROC pIOProc;
	UINT wErrorRet;
	HTASK htask;
	LONG cchBuffer;
	HPSTR pchBuffer;
	HPSTR pchNext;
	HPSTR pchEndRead;
	HPSTR pchEndWrite;
	LONG lBufOffset;
	LONG lDiskOffset;
	DWORD adwInfo[3];
	DWORD dwReserved1;
	DWORD dwReserved2;
	HMMIO hmmio;
} MMIOINFO, *PMMIOINFO, NEAR * NPMMIOINFO, FAR * LPMMIOINFO;
typedef const MMIOINFO FAR *LPCMMIOINFO;
typedef struct _MMCKINFO {
	FOURCC ckid;
	DWORD cksize;
	FOURCC fccType;
	DWORD dwDataOffset;
	DWORD dwFlags;
} MMCKINFO, *PMMCKINFO, NEAR * NPMMCKINFO, FAR * LPMMCKINFO;
typedef const MMCKINFO *LPCMMCKINFO;
#define MMIO_RWMODE     0x00000003
#define MMIO_SHAREMODE  0x00000070
#define MMIO_CREATE     0x00001000
#define MMIO_PARSE      0x00000100
#define MMIO_DELETE     0x00000200
#define MMIO_EXIST      0x00004000
#define MMIO_ALLOCBUF   0x00010000
#define MMIO_GETTEMP    0x00020000
#define MMIO_DIRTY      0x10000000
#define MMIO_READ       0x00000000
#define MMIO_WRITE      0x00000001
#define MMIO_READWRITE  0x00000002
#define MMIO_COMPAT     0x00000000
#define MMIO_EXCLUSIVE  0x00000010
#define MMIO_DENYWRITE  0x00000020
#define MMIO_DENYREAD   0x00000030
#define MMIO_DENYNONE   0x00000040
#define MMIO_FHOPEN             0x0010
#define MMIO_EMPTYBUF           0x0010
#define MMIO_TOUPPER            0x0010
#define MMIO_INSTALLPROC    0x00010000
#define MMIO_GLOBALPROC     0x10000000
#define MMIO_REMOVEPROC     0x00020000
#define MMIO_UNICODEPROC    0x01000000
#define MMIO_FINDPROC       0x00040000
#define MMIO_FINDCHUNK          0x0010
#define MMIO_FINDRIFF           0x0020
#define MMIO_FINDLIST           0x0040
#define MMIO_CREATERIFF         0x0020
#define MMIO_CREATELIST         0x0040
#define MMIOM_READ      MMIO_READ
#define MMIOM_WRITE    MMIO_WRITE
#define MMIOM_SEEK              2
#define MMIOM_OPEN              3
#define MMIOM_CLOSE             4
#define MMIOM_WRITEFLUSH        5
#if (WINVER >= 0x030a)
#define MMIOM_RENAME            6
#endif
#define MMIOM_USER         0x8000
#define FOURCC_RIFF     mmioFOURCC('R', 'I', 'F', 'F')
#define FOURCC_LIST     mmioFOURCC('L', 'I', 'S', 'T')
#define FOURCC_DOS      mmioFOURCC('D', 'O', 'S', ' ')
#define FOURCC_MEM      mmioFOURCC('M', 'E', 'M', ' ')
#ifndef SEEK_SET
#define SEEK_SET        0
#define SEEK_CUR        1
#define SEEK_END        2
#endif
#define MMIO_DEFAULTBUFFER      8192
#define mmioFOURCC(ch0, ch1, ch2, ch3)  MAKEFOURCC(ch0, ch1, ch2, ch3)
#ifdef _WIN32
WINMMAPI FOURCC WINAPI mmioStringToFOURCCA(LPCSTR sz, UINT uFlags);
WINMMAPI FOURCC WINAPI mmioStringToFOURCCW(LPCWSTR sz, UINT uFlags);
#ifdef UNICODE
#define mmioStringToFOURCC  mmioStringToFOURCCW
#else
#define mmioStringToFOURCC  mmioStringToFOURCCA
#endif
WINMMAPI LPMMIOPROC WINAPI mmioInstallIOProcA(FOURCC fccIOProc, LPMMIOPROC pIOProc, DWORD dwFlags);
WINMMAPI LPMMIOPROC WINAPI mmioInstallIOProcW(FOURCC fccIOProc, LPMMIOPROC pIOProc, DWORD dwFlags);
#ifdef UNICODE
#define mmioInstallIOProc  mmioInstallIOProcW
#else
#define mmioInstallIOProc  mmioInstallIOProcA
#endif
WINMMAPI HMMIO WINAPI mmioOpenA(LPSTR pszFileName, LPMMIOINFO pmmioinfo, DWORD fdwOpen);
WINMMAPI HMMIO WINAPI mmioOpenW(LPWSTR pszFileName, LPMMIOINFO pmmioinfo, DWORD fdwOpen);
#ifdef UNICODE
#define mmioOpen  mmioOpenW
#else
#define mmioOpen  mmioOpenA
#endif
WINMMAPI MMRESULT WINAPI mmioRenameA(LPCSTR pszFileName, LPCSTR pszNewFileName, LPCMMIOINFO pmmioinfo, DWORD fdwRename);
WINMMAPI MMRESULT WINAPI mmioRenameW(LPCWSTR pszFileName, LPCWSTR pszNewFileName, LPCMMIOINFO pmmioinfo, DWORD fdwRename);
#ifdef UNICODE
#define mmioRename  mmioRenameW
#else
#define mmioRename  mmioRenameA
#endif
#else
FOURCC WINAPI mmioStringToFOURCC(LPCSTR sz, UINT uFlags);
LPMMIOPROC WINAPI mmioInstallIOProc(FOURCC fccIOProc, LPMMIOPROC pIOProc, DWORD dwFlags);
HMMIO WINAPI mmioOpen(LPSTR pszFileName, LPMMIOINFO pmmioinfo, DWORD fdwOpen);
#if (WINVER >= 0x030a)
MMRESULT WINAPI mmioRename(LPCSTR pszFileName, LPCSTR pszNewFileName, const MMIOINFO FAR *pmmioinfo, DWORD fdwRename);
#endif
#endif
WINMMAPI MMRESULT WINAPI mmioClose(HMMIO hmmio, UINT fuClose);
WINMMAPI LONG WINAPI mmioRead(HMMIO hmmio, HPSTR pch, LONG cch);
WINMMAPI LONG WINAPI mmioWrite(HMMIO hmmio, const char _huge *pch, LONG cch);
WINMMAPI LONG WINAPI mmioSeek(HMMIO hmmio, LONG lOffset, int iOrigin);
WINMMAPI MMRESULT WINAPI mmioGetInfo(HMMIO hmmio, LPMMIOINFO pmmioinfo, UINT fuInfo);
WINMMAPI MMRESULT WINAPI mmioSetInfo(HMMIO hmmio, LPCMMIOINFO pmmioinfo, UINT fuInfo);
WINMMAPI MMRESULT WINAPI mmioSetBuffer(HMMIO hmmio, LPSTR pchBuffer, LONG cchBuffer, UINT fuBuffer);
WINMMAPI MMRESULT WINAPI mmioFlush(HMMIO hmmio, UINT fuFlush);
WINMMAPI MMRESULT WINAPI mmioAdvance(HMMIO hmmio, LPMMIOINFO pmmioinfo, UINT fuAdvance);
WINMMAPI LRESULT WINAPI mmioSendMessage(HMMIO hmmio, UINT uMsg, LPARAM lParam1, LPARAM lParam2);
WINMMAPI MMRESULT WINAPI mmioDescend(HMMIO hmmio, LPMMCKINFO pmmcki, const MMCKINFO FAR *pmmckiParent, UINT fuDescend);
WINMMAPI MMRESULT WINAPI mmioAscend(HMMIO hmmio, LPMMCKINFO pmmcki, UINT fuAscend);
WINMMAPI MMRESULT WINAPI mmioCreateChunk(HMMIO hmmio, LPMMCKINFO pmmcki, UINT fuCreate);
#endif
#ifndef MMNOMCI
#ifndef _MCIERROR_
#define _MCIERROR_
typedef DWORD MCIERROR;
#endif
#ifndef _MCIDEVICEID_
#define _MCIDEVICEID_
typedef UINT MCIDEVICEID;
#endif
typedef UINT(CALLBACK *YIELDPROC) (MCIDEVICEID mciId, DWORD dwYieldData);
#ifdef _WIN32
WINMMAPI MCIERROR WINAPI mciSendCommandA(MCIDEVICEID mciId, UINT uMsg, DWORD_PTR dwParam1, DWORD_PTR dwParam2);
WINMMAPI MCIERROR WINAPI mciSendCommandW(MCIDEVICEID mciId, UINT uMsg, DWORD_PTR dwParam1, DWORD_PTR dwParam2);
#ifdef UNICODE
#define mciSendCommand  mciSendCommandW
#else
#define mciSendCommand  mciSendCommandA
#endif
WINMMAPI MCIERROR WINAPI mciSendStringA(LPCSTR lpstrCommand, LPSTR lpstrReturnString, UINT uReturnLength, HWND hwndCallback);
WINMMAPI MCIERROR WINAPI mciSendStringW(LPCWSTR lpstrCommand, LPWSTR lpstrReturnString, UINT uReturnLength, HWND hwndCallback);
#ifdef UNICODE
#define mciSendString  mciSendStringW
#else
#define mciSendString  mciSendStringA
#endif
WINMMAPI MCIDEVICEID WINAPI mciGetDeviceIDA(LPCSTR pszDevice);
WINMMAPI MCIDEVICEID WINAPI mciGetDeviceIDW(LPCWSTR pszDevice);
#ifdef UNICODE
#define mciGetDeviceID  mciGetDeviceIDW
#else
#define mciGetDeviceID  mciGetDeviceIDA
#endif
WINMMAPI MCIDEVICEID WINAPI mciGetDeviceIDFromElementIDA(DWORD dwElementID, LPCSTR lpstrType);
WINMMAPI MCIDEVICEID WINAPI mciGetDeviceIDFromElementIDW(DWORD dwElementID, LPCWSTR lpstrType);
#ifdef UNICODE
#define mciGetDeviceIDFromElementID  mciGetDeviceIDFromElementIDW
#else
#define mciGetDeviceIDFromElementID  mciGetDeviceIDFromElementIDA
#endif
WINMMAPI BOOL WINAPI mciGetErrorStringA(MCIERROR mcierr, LPSTR pszText, UINT cchText);
WINMMAPI BOOL WINAPI mciGetErrorStringW(MCIERROR mcierr, LPWSTR pszText, UINT cchText);
#ifdef UNICODE
#define mciGetErrorString  mciGetErrorStringW
#else
#define mciGetErrorString  mciGetErrorStringA
#endif
#else
MCIERROR WINAPI mciSendCommand(MCIDEVICEID mciId, UINT uMsg, DWORD dwParam1, DWORD dwParam2);
MCIERROR WINAPI mciSendString(LPCSTR lpstrCommand, LPSTR lpstrReturnString, UINT uReturnLength, HWND hwndCallback);
MCIDEVICEID WINAPI mciGetDeviceID(LPCSTR pszDevice);
BOOL WINAPI mciGetErrorString(MCIERROR mcierr, LPSTR pszText, UINT cchText);
#endif
WINMMAPI BOOL WINAPI mciSetYieldProc(MCIDEVICEID mciId, YIELDPROC fpYieldProc, DWORD dwYieldData);
#if (WINVER >= 0x030a)
WINMMAPI HTASK WINAPI mciGetCreatorTask(MCIDEVICEID mciId);
WINMMAPI YIELDPROC WINAPI mciGetYieldProc(MCIDEVICEID mciId, LPDWORD pdwYieldData);
#endif
#if (WINVER < 0x030a)
WINMMAPI BOOL WINAPI mciExecute(LPCSTR pszCommand);
#endif
#define MCIERR_INVALID_DEVICE_ID        (MCIERR_BASE + 1)
#define MCIERR_UNRECOGNIZED_KEYWORD     (MCIERR_BASE + 3)
#define MCIERR_UNRECOGNIZED_COMMAND     (MCIERR_BASE + 5)
#define MCIERR_HARDWARE                 (MCIERR_BASE + 6)
#define MCIERR_INVALID_DEVICE_NAME      (MCIERR_BASE + 7)
#define MCIERR_OUT_OF_MEMORY            (MCIERR_BASE + 8)
#define MCIERR_DEVICE_OPEN              (MCIERR_BASE + 9)
#define MCIERR_CANNOT_LOAD_DRIVER       (MCIERR_BASE + 10)
#define MCIERR_MISSING_COMMAND_STRING   (MCIERR_BASE + 11)
#define MCIERR_PARAM_OVERFLOW           (MCIERR_BASE + 12)
#define MCIERR_MISSING_STRING_ARGUMENT  (MCIERR_BASE + 13)
#define MCIERR_BAD_INTEGER              (MCIERR_BASE + 14)
#define MCIERR_PARSER_INTERNAL          (MCIERR_BASE + 15)
#define MCIERR_DRIVER_INTERNAL          (MCIERR_BASE + 16)
#define MCIERR_MISSING_PARAMETER        (MCIERR_BASE + 17)
#define MCIERR_UNSUPPORTED_FUNCTION     (MCIERR_BASE + 18)
#define MCIERR_FILE_NOT_FOUND           (MCIERR_BASE + 19)
#define MCIERR_DEVICE_NOT_READY         (MCIERR_BASE + 20)
#define MCIERR_INTERNAL                 (MCIERR_BASE + 21)
#define MCIERR_DRIVER                   (MCIERR_BASE + 22)
#define MCIERR_CANNOT_USE_ALL           (MCIERR_BASE + 23)
#define MCIERR_MULTIPLE                 (MCIERR_BASE + 24)
#define MCIERR_EXTENSION_NOT_FOUND      (MCIERR_BASE + 25)
#define MCIERR_OUTOFRANGE               (MCIERR_BASE + 26)
#define MCIERR_FLAGS_NOT_COMPATIBLE     (MCIERR_BASE + 28)
#define MCIERR_FILE_NOT_SAVED           (MCIERR_BASE + 30)
#define MCIERR_DEVICE_TYPE_REQUIRED     (MCIERR_BASE + 31)
#define MCIERR_DEVICE_LOCKED            (MCIERR_BASE + 32)
#define MCIERR_DUPLICATE_ALIAS          (MCIERR_BASE + 33)
#define MCIERR_BAD_CONSTANT             (MCIERR_BASE + 34)
#define MCIERR_MUST_USE_SHAREABLE       (MCIERR_BASE + 35)
#define MCIERR_MISSING_DEVICE_NAME      (MCIERR_BASE + 36)
#define MCIERR_BAD_TIME_FORMAT          (MCIERR_BASE + 37)
#define MCIERR_NO_CLOSING_QUOTE         (MCIERR_BASE + 38)
#define MCIERR_DUPLICATE_FLAGS          (MCIERR_BASE + 39)
#define MCIERR_INVALID_FILE             (MCIERR_BASE + 40)
#define MCIERR_NULL_PARAMETER_BLOCK     (MCIERR_BASE + 41)
#define MCIERR_UNNAMED_RESOURCE         (MCIERR_BASE + 42)
#define MCIERR_NEW_REQUIRES_ALIAS       (MCIERR_BASE + 43)
#define MCIERR_NOTIFY_ON_AUTO_OPEN      (MCIERR_BASE + 44)
#define MCIERR_NO_ELEMENT_ALLOWED       (MCIERR_BASE + 45)
#define MCIERR_NONAPPLICABLE_FUNCTION   (MCIERR_BASE + 46)
#define MCIERR_ILLEGAL_FOR_AUTO_OPEN    (MCIERR_BASE + 47)
#define MCIERR_FILENAME_REQUIRED        (MCIERR_BASE + 48)
#define MCIERR_EXTRA_CHARACTERS         (MCIERR_BASE + 49)
#define MCIERR_DEVICE_NOT_INSTALLED     (MCIERR_BASE + 50)
#define MCIERR_GET_CD                   (MCIERR_BASE + 51)
#define MCIERR_SET_CD                   (MCIERR_BASE + 52)
#define MCIERR_SET_DRIVE                (MCIERR_BASE + 53)
#define MCIERR_DEVICE_LENGTH            (MCIERR_BASE + 54)
#define MCIERR_DEVICE_ORD_LENGTH        (MCIERR_BASE + 55)
#define MCIERR_NO_INTEGER               (MCIERR_BASE + 56)
#define MCIERR_WAVE_OUTPUTSINUSE        (MCIERR_BASE + 64)
#define MCIERR_WAVE_SETOUTPUTINUSE      (MCIERR_BASE + 65)
#define MCIERR_WAVE_INPUTSINUSE         (MCIERR_BASE + 66)
#define MCIERR_WAVE_SETINPUTINUSE       (MCIERR_BASE + 67)
#define MCIERR_WAVE_OUTPUTUNSPECIFIED   (MCIERR_BASE + 68)
#define MCIERR_WAVE_INPUTUNSPECIFIED    (MCIERR_BASE + 69)
#define MCIERR_WAVE_OUTPUTSUNSUITABLE   (MCIERR_BASE + 70)
#define MCIERR_WAVE_SETOUTPUTUNSUITABLE (MCIERR_BASE + 71)
#define MCIERR_WAVE_INPUTSUNSUITABLE    (MCIERR_BASE + 72)
#define MCIERR_WAVE_SETINPUTUNSUITABLE  (MCIERR_BASE + 73)
#define MCIERR_SEQ_DIV_INCOMPATIBLE     (MCIERR_BASE + 80)
#define MCIERR_SEQ_PORT_INUSE           (MCIERR_BASE + 81)
#define MCIERR_SEQ_PORT_NONEXISTENT     (MCIERR_BASE + 82)
#define MCIERR_SEQ_PORT_MAPNODEVICE     (MCIERR_BASE + 83)
#define MCIERR_SEQ_PORT_MISCERROR       (MCIERR_BASE + 84)
#define MCIERR_SEQ_TIMER                (MCIERR_BASE + 85)
#define MCIERR_SEQ_PORTUNSPECIFIED      (MCIERR_BASE + 86)
#define MCIERR_SEQ_NOMIDIPRESENT        (MCIERR_BASE + 87)
#define MCIERR_NO_WINDOW                (MCIERR_BASE + 90)
#define MCIERR_CREATEWINDOW             (MCIERR_BASE + 91)
#define MCIERR_FILE_READ                (MCIERR_BASE + 92)
#define MCIERR_FILE_WRITE               (MCIERR_BASE + 93)
#define MCIERR_NO_IDENTITY              (MCIERR_BASE + 94)
#define MCIERR_CUSTOM_DRIVER_BASE       (MCIERR_BASE + 256)
#define MCI_FIRST                       DRV_MCI_FIRST
#define MCI_OPEN                        0x0803
#define MCI_CLOSE                       0x0804
#define MCI_ESCAPE                      0x0805
#define MCI_PLAY                        0x0806
#define MCI_SEEK                        0x0807
#define MCI_STOP                        0x0808
#define MCI_PAUSE                       0x0809
#define MCI_INFO                        0x080A
#define MCI_GETDEVCAPS                  0x080B
#define MCI_SPIN                        0x080C
#define MCI_SET                         0x080D
#define MCI_STEP                        0x080E
#define MCI_RECORD                      0x080F
#define MCI_SYSINFO                     0x0810
#define MCI_BREAK                       0x0811
#define MCI_SAVE                        0x0813
#define MCI_STATUS                      0x0814
#define MCI_CUE                         0x0830
#define MCI_REALIZE                     0x0840
#define MCI_WINDOW                      0x0841
#define MCI_PUT                         0x0842
#define MCI_WHERE                       0x0843
#define MCI_FREEZE                      0x0844
#define MCI_UNFREEZE                    0x0845
#define MCI_LOAD                        0x0850
#define MCI_CUT                         0x0851
#define MCI_COPY                        0x0852
#define MCI_PASTE                       0x0853
#define MCI_UPDATE                      0x0854
#define MCI_RESUME                      0x0855
#define MCI_DELETE                      0x0856
#define MCI_USER_MESSAGES               (DRV_MCI_FIRST + 0x400)
#define MCI_LAST                        0x0FFF
#define MCI_ALL_DEVICE_ID               ((MCIDEVICEID)-1)
#define MCI_DEVTYPE_VCR                 513
#define MCI_DEVTYPE_VIDEODISC           514
#define MCI_DEVTYPE_OVERLAY             515
#define MCI_DEVTYPE_CD_AUDIO            516
#define MCI_DEVTYPE_DAT                 517
#define MCI_DEVTYPE_SCANNER             518
#define MCI_DEVTYPE_ANIMATION           519
#define MCI_DEVTYPE_DIGITAL_VIDEO       520
#define MCI_DEVTYPE_OTHER               521
#define MCI_DEVTYPE_WAVEFORM_AUDIO      522
#define MCI_DEVTYPE_SEQUENCER           523
#define MCI_DEVTYPE_FIRST               MCI_DEVTYPE_VCR
#define MCI_DEVTYPE_LAST                MCI_DEVTYPE_SEQUENCER
#define MCI_DEVTYPE_FIRST_USER          0x1000
#define MCI_MODE_NOT_READY              (MCI_STRING_OFFSET + 12)
#define MCI_MODE_STOP                   (MCI_STRING_OFFSET + 13)
#define MCI_MODE_PLAY                   (MCI_STRING_OFFSET + 14)
#define MCI_MODE_RECORD                 (MCI_STRING_OFFSET + 15)
#define MCI_MODE_SEEK                   (MCI_STRING_OFFSET + 16)
#define MCI_MODE_PAUSE                  (MCI_STRING_OFFSET + 17)
#define MCI_MODE_OPEN                   (MCI_STRING_OFFSET + 18)
#define MCI_FORMAT_MILLISECONDS         0
#define MCI_FORMAT_HMS                  1
#define MCI_FORMAT_MSF                  2
#define MCI_FORMAT_FRAMES               3
#define MCI_FORMAT_SMPTE_24             4
#define MCI_FORMAT_SMPTE_25             5
#define MCI_FORMAT_SMPTE_30             6
#define MCI_FORMAT_SMPTE_30DROP         7
#define MCI_FORMAT_BYTES                8
#define MCI_FORMAT_SAMPLES              9
#define MCI_FORMAT_TMSF                 10
#define MCI_MSF_MINUTE(msf)             ((BYTE)(msf))
#define MCI_MSF_SECOND(msf)             ((BYTE)(((WORD)(msf)) >> 8))
#define MCI_MSF_FRAME(msf)              ((BYTE)((msf)>>16))
#define MCI_MAKE_MSF(m, s, f)           ((DWORD)(((BYTE)(m) | \
                                                  ((WORD)(s)<<8)) | \
                                                 (((DWORD)(BYTE)(f))<<16)))
#define MCI_TMSF_TRACK(tmsf)            ((BYTE)(tmsf))
#define MCI_TMSF_MINUTE(tmsf)           ((BYTE)(((WORD)(tmsf)) >> 8))
#define MCI_TMSF_SECOND(tmsf)           ((BYTE)((tmsf)>>16))
#define MCI_TMSF_FRAME(tmsf)            ((BYTE)((tmsf)>>24))
#define MCI_MAKE_TMSF(t, m, s, f)       ((DWORD)(((BYTE)(t) | \
                                                  ((WORD)(m)<<8)) | \
                                                 (((DWORD)(BYTE)(s) | \
                                                   ((WORD)(f)<<8))<<16)))
#define MCI_HMS_HOUR(hms)               ((BYTE)(hms))
#define MCI_HMS_MINUTE(hms)             ((BYTE)(((WORD)(hms)) >> 8))
#define MCI_HMS_SECOND(hms)             ((BYTE)((hms)>>16))
#define MCI_MAKE_HMS(h, m, s)           ((DWORD)(((BYTE)(h) | \
                                                  ((WORD)(m)<<8)) | \
                                                 (((DWORD)(BYTE)(s))<<16)))
#define MCI_NOTIFY_SUCCESSFUL           0x0001
#define MCI_NOTIFY_SUPERSEDED           0x0002
#define MCI_NOTIFY_ABORTED              0x0004
#define MCI_NOTIFY_FAILURE              0x0008
#define MCI_NOTIFY                      0x00000001L
#define MCI_WAIT                        0x00000002L
#define MCI_FROM                        0x00000004L
#define MCI_TO                          0x00000008L
#define MCI_TRACK                       0x00000010L
#define MCI_OPEN_SHAREABLE              0x00000100L
#define MCI_OPEN_ELEMENT                0x00000200L
#define MCI_OPEN_ALIAS                  0x00000400L
#define MCI_OPEN_ELEMENT_ID             0x00000800L
#define MCI_OPEN_TYPE_ID                0x00001000L
#define MCI_OPEN_TYPE                   0x00002000L
#define MCI_SEEK_TO_START               0x00000100L
#define MCI_SEEK_TO_END                 0x00000200L
#define MCI_STATUS_ITEM                 0x00000100L
#define MCI_STATUS_START                0x00000200L
#define MCI_STATUS_LENGTH               0x00000001L
#define MCI_STATUS_POSITION             0x00000002L
#define MCI_STATUS_NUMBER_OF_TRACKS     0x00000003L
#define MCI_STATUS_MODE                 0x00000004L
#define MCI_STATUS_MEDIA_PRESENT        0x00000005L
#define MCI_STATUS_TIME_FORMAT          0x00000006L
#define MCI_STATUS_READY                0x00000007L
#define MCI_STATUS_CURRENT_TRACK        0x00000008L
#define MCI_INFO_PRODUCT                0x00000100L
#define MCI_INFO_FILE                   0x00000200L
#define MCI_INFO_MEDIA_UPC              0x00000400L
#define MCI_INFO_MEDIA_IDENTITY         0x00000800L
#define MCI_INFO_NAME                   0x00001000L
#define MCI_INFO_COPYRIGHT              0x00002000L
#define MCI_GETDEVCAPS_ITEM             0x00000100L
#define MCI_GETDEVCAPS_CAN_RECORD       0x00000001L
#define MCI_GETDEVCAPS_HAS_AUDIO        0x00000002L
#define MCI_GETDEVCAPS_HAS_VIDEO        0x00000003L
#define MCI_GETDEVCAPS_DEVICE_TYPE      0x00000004L
#define MCI_GETDEVCAPS_USES_FILES       0x00000005L
#define MCI_GETDEVCAPS_COMPOUND_DEVICE  0x00000006L
#define MCI_GETDEVCAPS_CAN_EJECT        0x00000007L
#define MCI_GETDEVCAPS_CAN_PLAY         0x00000008L
#define MCI_GETDEVCAPS_CAN_SAVE         0x00000009L
#define MCI_SYSINFO_QUANTITY            0x00000100L
#define MCI_SYSINFO_OPEN                0x00000200L
#define MCI_SYSINFO_NAME                0x00000400L
#define MCI_SYSINFO_INSTALLNAME         0x00000800L
#define MCI_SET_DOOR_OPEN               0x00000100L
#define MCI_SET_DOOR_CLOSED             0x00000200L
#define MCI_SET_TIME_FORMAT             0x00000400L
#define MCI_SET_AUDIO                   0x00000800L
#define MCI_SET_VIDEO                   0x00001000L
#define MCI_SET_ON                      0x00002000L
#define MCI_SET_OFF                     0x00004000L
#define MCI_SET_AUDIO_ALL               0x00000000L
#define MCI_SET_AUDIO_LEFT              0x00000001L
#define MCI_SET_AUDIO_RIGHT             0x00000002L
#define MCI_BREAK_KEY                   0x00000100L
#define MCI_BREAK_HWND                  0x00000200L
#define MCI_BREAK_OFF                   0x00000400L
#define MCI_RECORD_INSERT               0x00000100L
#define MCI_RECORD_OVERWRITE            0x00000200L
#define MCI_SAVE_FILE                   0x00000100L
#define MCI_LOAD_FILE                   0x00000100L
typedef struct tagMCI_GENERIC_PARMS {
	DWORD_PTR dwCallback;
} MCI_GENERIC_PARMS, *PMCI_GENERIC_PARMS, FAR * LPMCI_GENERIC_PARMS;
#ifdef _WIN32
typedef struct tagMCI_OPEN_PARMSA {
	DWORD_PTR dwCallback;
	MCIDEVICEID wDeviceID;
	LPCSTR lpstrDeviceType;
	LPCSTR lpstrElementName;
	LPCSTR lpstrAlias;
} MCI_OPEN_PARMSA, *PMCI_OPEN_PARMSA, *LPMCI_OPEN_PARMSA;
typedef struct tagMCI_OPEN_PARMSW {
	DWORD_PTR dwCallback;
	MCIDEVICEID wDeviceID;
	LPCWSTR lpstrDeviceType;
	LPCWSTR lpstrElementName;
	LPCWSTR lpstrAlias;
} MCI_OPEN_PARMSW, *PMCI_OPEN_PARMSW, *LPMCI_OPEN_PARMSW;
#ifdef UNICODE
typedef MCI_OPEN_PARMSW MCI_OPEN_PARMS;
typedef PMCI_OPEN_PARMSW PMCI_OPEN_PARMS;
typedef LPMCI_OPEN_PARMSW LPMCI_OPEN_PARMS;
#else
typedef MCI_OPEN_PARMSA MCI_OPEN_PARMS;
typedef PMCI_OPEN_PARMSA PMCI_OPEN_PARMS;
typedef LPMCI_OPEN_PARMSA LPMCI_OPEN_PARMS;
#endif
#else
typedef struct tagMCI_OPEN_PARMS {
	DWORD dwCallback;
	MCIDEVICEID wDeviceID;
	WORD wReserved0;
	LPCSTR lpstrDeviceType;
	LPCSTR lpstrElementName;
	LPCSTR lpstrAlias;
} MCI_OPEN_PARMS, FAR * LPMCI_OPEN_PARMS;
#endif
typedef struct tagMCI_PLAY_PARMS {
	DWORD_PTR dwCallback;
	DWORD dwFrom;
	DWORD dwTo;
} MCI_PLAY_PARMS, *PMCI_PLAY_PARMS, FAR * LPMCI_PLAY_PARMS;
typedef struct tagMCI_SEEK_PARMS {
	DWORD_PTR dwCallback;
	DWORD dwTo;
} MCI_SEEK_PARMS, *PMCI_SEEK_PARMS, FAR * LPMCI_SEEK_PARMS;
typedef struct tagMCI_STATUS_PARMS {
	DWORD_PTR dwCallback;
	DWORD_PTR dwReturn;
	DWORD dwItem;
	DWORD dwTrack;
} MCI_STATUS_PARMS, *PMCI_STATUS_PARMS, FAR * LPMCI_STATUS_PARMS;
#ifdef _WIN32
typedef struct tagMCI_INFO_PARMSA {
	DWORD_PTR dwCallback;
	LPSTR lpstrReturn;
	DWORD dwRetSize;
} MCI_INFO_PARMSA, *LPMCI_INFO_PARMSA;
typedef struct tagMCI_INFO_PARMSW {
	DWORD_PTR dwCallback;
	LPWSTR lpstrReturn;
	DWORD dwRetSize;
} MCI_INFO_PARMSW, *LPMCI_INFO_PARMSW;
#ifdef UNICODE
typedef MCI_INFO_PARMSW MCI_INFO_PARMS;
typedef LPMCI_INFO_PARMSW LPMCI_INFO_PARMS;
#else
typedef MCI_INFO_PARMSA MCI_INFO_PARMS;
typedef LPMCI_INFO_PARMSA LPMCI_INFO_PARMS;
#endif
#else
typedef struct tagMCI_INFO_PARMS {
	DWORD dwCallback;
	LPSTR lpstrReturn;
	DWORD dwRetSize;
} MCI_INFO_PARMS, FAR * LPMCI_INFO_PARMS;
#endif
typedef struct tagMCI_GETDEVCAPS_PARMS {
	DWORD_PTR dwCallback;
	DWORD dwReturn;
	DWORD dwItem;
} MCI_GETDEVCAPS_PARMS, *PMCI_GETDEVCAPS_PARMS, FAR * LPMCI_GETDEVCAPS_PARMS;
#ifdef _WIN32
typedef struct tagMCI_SYSINFO_PARMSA {
	DWORD_PTR dwCallback;
	LPSTR lpstrReturn;
	DWORD dwRetSize;
	DWORD dwNumber;
	UINT wDeviceType;
} MCI_SYSINFO_PARMSA, *PMCI_SYSINFO_PARMSA, *LPMCI_SYSINFO_PARMSA;
typedef struct tagMCI_SYSINFO_PARMSW {
	DWORD_PTR dwCallback;
	LPWSTR lpstrReturn;
	DWORD dwRetSize;
	DWORD dwNumber;
	UINT wDeviceType;
} MCI_SYSINFO_PARMSW, *PMCI_SYSINFO_PARMSW, *LPMCI_SYSINFO_PARMSW;
#ifdef UNICODE
typedef MCI_SYSINFO_PARMSW MCI_SYSINFO_PARMS;
typedef PMCI_SYSINFO_PARMSW PMCI_SYSINFO_PARMS;
typedef LPMCI_SYSINFO_PARMSW LPMCI_SYSINFO_PARMS;
#else
typedef MCI_SYSINFO_PARMSA MCI_SYSINFO_PARMS;
typedef PMCI_SYSINFO_PARMSA PMCI_SYSINFO_PARMS;
typedef LPMCI_SYSINFO_PARMSA LPMCI_SYSINFO_PARMS;
#endif
#else
typedef struct tagMCI_SYSINFO_PARMS {
	DWORD dwCallback;
	LPSTR lpstrReturn;
	DWORD dwRetSize;
	DWORD dwNumber;
	WORD wDeviceType;
	WORD wReserved0;
} MCI_SYSINFO_PARMS, FAR * LPMCI_SYSINFO_PARMS;
#endif
typedef struct tagMCI_SET_PARMS {
	DWORD_PTR dwCallback;
	DWORD dwTimeFormat;
	DWORD dwAudio;
} MCI_SET_PARMS, *PMCI_SET_PARMS, FAR * LPMCI_SET_PARMS;
typedef struct tagMCI_BREAK_PARMS {
	DWORD_PTR dwCallback;
#ifdef _WIN32
	int nVirtKey;
	HWND hwndBreak;
#else
	short nVirtKey;
	WORD wReserved0;
	HWND hwndBreak;
	WORD wReserved1;
#endif
} MCI_BREAK_PARMS, *PMCI_BREAK_PARMS, FAR * LPMCI_BREAK_PARMS;
#ifdef _WIN32
typedef struct tagMCI_SAVE_PARMSA {
	DWORD_PTR dwCallback;
	LPCSTR lpfilename;
} MCI_SAVE_PARMSA, *PMCI_SAVE_PARMSA, *LPMCI_SAVE_PARMSA;
typedef struct tagMCI_SAVE_PARMSW {
	DWORD_PTR dwCallback;
	LPCWSTR lpfilename;
} MCI_SAVE_PARMSW, *PMCI_SAVE_PARMSW, *LPMCI_SAVE_PARMSW;
#ifdef UNICODE
typedef MCI_SAVE_PARMSW MCI_SAVE_PARMS;
typedef PMCI_SAVE_PARMSW PMCI_SAVE_PARMS;
typedef LPMCI_SAVE_PARMSW LPMCI_SAVE_PARMS;
#else
typedef MCI_SAVE_PARMSA MCI_SAVE_PARMS;
typedef PMCI_SAVE_PARMSA PMCI_SAVE_PARMS;
typedef LPMCI_SAVE_PARMSA LPMCI_SAVE_PARMS;
#endif
#else
typedef struct tagMCI_SAVE_PARMS {
	DWORD_PTR dwCallback;
	LPCSTR lpfilename;
} MCI_SAVE_PARMS, FAR * LPMCI_SAVE_PARMS;
#endif
#ifdef _WIN32
typedef struct tagMCI_LOAD_PARMSA {
	DWORD_PTR dwCallback;
	LPCSTR lpfilename;
} MCI_LOAD_PARMSA, *PMCI_LOAD_PARMSA, *LPMCI_LOAD_PARMSA;
typedef struct tagMCI_LOAD_PARMSW {
	DWORD_PTR dwCallback;
	LPCWSTR lpfilename;
} MCI_LOAD_PARMSW, *PMCI_LOAD_PARMSW, *LPMCI_LOAD_PARMSW;
#ifdef UNICODE
typedef MCI_LOAD_PARMSW MCI_LOAD_PARMS;
typedef PMCI_LOAD_PARMSW PMCI_LOAD_PARMS;
typedef LPMCI_LOAD_PARMSW LPMCI_LOAD_PARMS;
#else
typedef MCI_LOAD_PARMSA MCI_LOAD_PARMS;
typedef PMCI_LOAD_PARMSA PMCI_LOAD_PARMS;
typedef LPMCI_LOAD_PARMSA LPMCI_LOAD_PARMS;
#endif
#else
typedef struct tagMCI_LOAD_PARMS {
	DWORD dwCallback;
	LPCSTR lpfilename;
} MCI_LOAD_PARMS, FAR * LPMCI_LOAD_PARMS;
#endif
typedef struct tagMCI_RECORD_PARMS {
	DWORD_PTR dwCallback;
	DWORD dwFrom;
	DWORD dwTo;
} MCI_RECORD_PARMS, FAR * LPMCI_RECORD_PARMS;
#define MCI_VD_MODE_PARK                (MCI_VD_OFFSET + 1)
#define MCI_VD_MEDIA_CLV                (MCI_VD_OFFSET + 2)
#define MCI_VD_MEDIA_CAV                (MCI_VD_OFFSET + 3)
#define MCI_VD_MEDIA_OTHER              (MCI_VD_OFFSET + 4)
#define MCI_VD_FORMAT_TRACK             0x4001
#define MCI_VD_PLAY_REVERSE             0x00010000L
#define MCI_VD_PLAY_FAST                0x00020000L
#define MCI_VD_PLAY_SPEED               0x00040000L
#define MCI_VD_PLAY_SCAN                0x00080000L
#define MCI_VD_PLAY_SLOW                0x00100000L
#define MCI_VD_SEEK_REVERSE             0x00010000L
#define MCI_VD_STATUS_SPEED             0x00004002L
#define MCI_VD_STATUS_FORWARD           0x00004003L
#define MCI_VD_STATUS_MEDIA_TYPE        0x00004004L
#define MCI_VD_STATUS_SIDE              0x00004005L
#define MCI_VD_STATUS_DISC_SIZE         0x00004006L
#define MCI_VD_GETDEVCAPS_CLV           0x00010000L
#define MCI_VD_GETDEVCAPS_CAV           0x00020000L
#define MCI_VD_SPIN_UP                  0x00010000L
#define MCI_VD_SPIN_DOWN                0x00020000L
#define MCI_VD_GETDEVCAPS_CAN_REVERSE   0x00004002L
#define MCI_VD_GETDEVCAPS_FAST_RATE     0x00004003L
#define MCI_VD_GETDEVCAPS_SLOW_RATE     0x00004004L
#define MCI_VD_GETDEVCAPS_NORMAL_RATE   0x00004005L
#define MCI_VD_STEP_FRAMES              0x00010000L
#define MCI_VD_STEP_REVERSE             0x00020000L
#define MCI_VD_ESCAPE_STRING            0x00000100L
typedef struct tagMCI_VD_PLAY_PARMS {
	DWORD_PTR dwCallback;
	DWORD dwFrom;
	DWORD dwTo;
	DWORD dwSpeed;
} MCI_VD_PLAY_PARMS, *PMCI_VD_PLAY_PARMS, FAR * LPMCI_VD_PLAY_PARMS;
typedef struct tagMCI_VD_STEP_PARMS {
	DWORD_PTR dwCallback;
	DWORD dwFrames;
} MCI_VD_STEP_PARMS, *PMCI_VD_STEP_PARMS, FAR * LPMCI_VD_STEP_PARMS;
#ifdef _WIN32
typedef struct tagMCI_VD_ESCAPE_PARMSA {
	DWORD_PTR dwCallback;
	LPCSTR lpstrCommand;
} MCI_VD_ESCAPE_PARMSA, *PMCI_VD_ESCAPE_PARMSA, *LPMCI_VD_ESCAPE_PARMSA;
typedef struct tagMCI_VD_ESCAPE_PARMSW {
	DWORD_PTR dwCallback;
	LPCWSTR lpstrCommand;
} MCI_VD_ESCAPE_PARMSW, *PMCI_VD_ESCAPE_PARMSW, *LPMCI_VD_ESCAPE_PARMSW;
#ifdef UNICODE
typedef MCI_VD_ESCAPE_PARMSW MCI_VD_ESCAPE_PARMS;
typedef PMCI_VD_ESCAPE_PARMSW PMCI_VD_ESCAPE_PARMS;
typedef LPMCI_VD_ESCAPE_PARMSW LPMCI_VD_ESCAPE_PARMS;
#else
typedef MCI_VD_ESCAPE_PARMSA MCI_VD_ESCAPE_PARMS;
typedef PMCI_VD_ESCAPE_PARMSA PMCI_VD_ESCAPE_PARMS;
typedef LPMCI_VD_ESCAPE_PARMSA LPMCI_VD_ESCAPE_PARMS;
#endif
#else
typedef struct tagMCI_VD_ESCAPE_PARMS {
	DWORD dwCallback;
	LPCSTR lpstrCommand;
} MCI_VD_ESCAPE_PARMS, FAR * LPMCI_VD_ESCAPE_PARMS;
#endif
#define MCI_CDA_STATUS_TYPE_TRACK       0x00004001L
#define MCI_CDA_TRACK_AUDIO             (MCI_CD_OFFSET + 0)
#define MCI_CDA_TRACK_OTHER             (MCI_CD_OFFSET + 1)
#define MCI_WAVE_PCM                    (MCI_WAVE_OFFSET + 0)
#define MCI_WAVE_MAPPER                 (MCI_WAVE_OFFSET + 1)
#define MCI_WAVE_OPEN_BUFFER            0x00010000L
#define MCI_WAVE_SET_FORMATTAG          0x00010000L
#define MCI_WAVE_SET_CHANNELS           0x00020000L
#define MCI_WAVE_SET_SAMPLESPERSEC      0x00040000L
#define MCI_WAVE_SET_AVGBYTESPERSEC     0x00080000L
#define MCI_WAVE_SET_BLOCKALIGN         0x00100000L
#define MCI_WAVE_SET_BITSPERSAMPLE      0x00200000L
#define MCI_WAVE_INPUT                  0x00400000L
#define MCI_WAVE_OUTPUT                 0x00800000L
#define MCI_WAVE_STATUS_FORMATTAG       0x00004001L
#define MCI_WAVE_STATUS_CHANNELS        0x00004002L
#define MCI_WAVE_STATUS_SAMPLESPERSEC   0x00004003L
#define MCI_WAVE_STATUS_AVGBYTESPERSEC  0x00004004L
#define MCI_WAVE_STATUS_BLOCKALIGN      0x00004005L
#define MCI_WAVE_STATUS_BITSPERSAMPLE   0x00004006L
#define MCI_WAVE_STATUS_LEVEL           0x00004007L
#define MCI_WAVE_SET_ANYINPUT           0x04000000L
#define MCI_WAVE_SET_ANYOUTPUT          0x08000000L
#define MCI_WAVE_GETDEVCAPS_INPUTS      0x00004001L
#define MCI_WAVE_GETDEVCAPS_OUTPUTS     0x00004002L
#ifdef _WIN32
typedef struct tagMCI_WAVE_OPEN_PARMSA {
	DWORD_PTR dwCallback;
	MCIDEVICEID wDeviceID;
	LPCSTR lpstrDeviceType;
	LPCSTR lpstrElementName;
	LPCSTR lpstrAlias;
	DWORD dwBufferSeconds;
} MCI_WAVE_OPEN_PARMSA, *PMCI_WAVE_OPEN_PARMSA, *LPMCI_WAVE_OPEN_PARMSA;
typedef struct tagMCI_WAVE_OPEN_PARMSW {
	DWORD_PTR dwCallback;
	MCIDEVICEID wDeviceID;
	LPCWSTR lpstrDeviceType;
	LPCWSTR lpstrElementName;
	LPCWSTR lpstrAlias;
	DWORD dwBufferSeconds;
} MCI_WAVE_OPEN_PARMSW, *PMCI_WAVE_OPEN_PARMSW, *LPMCI_WAVE_OPEN_PARMSW;
#ifdef UNICODE
typedef MCI_WAVE_OPEN_PARMSW MCI_WAVE_OPEN_PARMS;
typedef PMCI_WAVE_OPEN_PARMSW PMCI_WAVE_OPEN_PARMS;
typedef LPMCI_WAVE_OPEN_PARMSW LPMCI_WAVE_OPEN_PARMS;
#else
typedef MCI_WAVE_OPEN_PARMSA MCI_WAVE_OPEN_PARMS;
typedef PMCI_WAVE_OPEN_PARMSA PMCI_WAVE_OPEN_PARMS;
typedef LPMCI_WAVE_OPEN_PARMSA LPMCI_WAVE_OPEN_PARMS;
#endif
#else
typedef struct tagMCI_WAVE_OPEN_PARMS {
	DWORD dwCallback;
	MCIDEVICEID wDeviceID;
	WORD wReserved0;
	LPCSTR lpstrDeviceType;
	LPCSTR lpstrElementName;
	LPCSTR lpstrAlias;
	DWORD dwBufferSeconds;
} MCI_WAVE_OPEN_PARMS, FAR * LPMCI_WAVE_OPEN_PARMS;
#endif
typedef struct tagMCI_WAVE_DELETE_PARMS {
	DWORD_PTR dwCallback;
	DWORD dwFrom;
	DWORD dwTo;
} MCI_WAVE_DELETE_PARMS, *PMCI_WAVE_DELETE_PARMS, FAR * LPMCI_WAVE_DELETE_PARMS;
typedef struct tagMCI_WAVE_SET_PARMS {
	DWORD_PTR dwCallback;
	DWORD dwTimeFormat;
	DWORD dwAudio;
#ifdef _WIN32
	UINT wInput;
	UINT wOutput;
#else
	WORD wInput;
	WORD wReserved0;
	WORD wOutput;
	WORD wReserved1;
#endif
	WORD wFormatTag;
	WORD wReserved2;
	WORD nChannels;
	WORD wReserved3;
	DWORD nSamplesPerSec;
	DWORD nAvgBytesPerSec;
	WORD nBlockAlign;
	WORD wReserved4;
	WORD wBitsPerSample;
	WORD wReserved5;
} MCI_WAVE_SET_PARMS, *PMCI_WAVE_SET_PARMS, FAR * LPMCI_WAVE_SET_PARMS;
#define     MCI_SEQ_DIV_PPQN            (0 + MCI_SEQ_OFFSET)
#define     MCI_SEQ_DIV_SMPTE_24        (1 + MCI_SEQ_OFFSET)
#define     MCI_SEQ_DIV_SMPTE_25        (2 + MCI_SEQ_OFFSET)
#define     MCI_SEQ_DIV_SMPTE_30DROP    (3 + MCI_SEQ_OFFSET)
#define     MCI_SEQ_DIV_SMPTE_30        (4 + MCI_SEQ_OFFSET)
#define     MCI_SEQ_FORMAT_SONGPTR      0x4001
#define     MCI_SEQ_FILE                0x4002
#define     MCI_SEQ_MIDI                0x4003
#define     MCI_SEQ_SMPTE               0x4004
#define     MCI_SEQ_NONE                65533
#define     MCI_SEQ_MAPPER              65535
#define MCI_SEQ_STATUS_TEMPO            0x00004002L
#define MCI_SEQ_STATUS_PORT             0x00004003L
#define MCI_SEQ_STATUS_SLAVE            0x00004007L
#define MCI_SEQ_STATUS_MASTER           0x00004008L
#define MCI_SEQ_STATUS_OFFSET           0x00004009L
#define MCI_SEQ_STATUS_DIVTYPE          0x0000400AL
#define MCI_SEQ_STATUS_NAME             0x0000400BL
#define MCI_SEQ_STATUS_COPYRIGHT        0x0000400CL
#define MCI_SEQ_SET_TEMPO               0x00010000L
#define MCI_SEQ_SET_PORT                0x00020000L
#define MCI_SEQ_SET_SLAVE               0x00040000L
#define MCI_SEQ_SET_MASTER              0x00080000L
#define MCI_SEQ_SET_OFFSET              0x01000000L
typedef struct tagMCI_SEQ_SET_PARMS {
	DWORD_PTR dwCallback;
	DWORD dwTimeFormat;
	DWORD dwAudio;
	DWORD dwTempo;
	DWORD dwPort;
	DWORD dwSlave;
	DWORD dwMaster;
	DWORD dwOffset;
} MCI_SEQ_SET_PARMS, *PMCI_SEQ_SET_PARMS, FAR * LPMCI_SEQ_SET_PARMS;
#define MCI_ANIM_OPEN_WS                0x00010000L
#define MCI_ANIM_OPEN_PARENT            0x00020000L
#define MCI_ANIM_OPEN_NOSTATIC          0x00040000L
#define MCI_ANIM_PLAY_SPEED             0x00010000L
#define MCI_ANIM_PLAY_REVERSE           0x00020000L
#define MCI_ANIM_PLAY_FAST              0x00040000L
#define MCI_ANIM_PLAY_SLOW              0x00080000L
#define MCI_ANIM_PLAY_SCAN              0x00100000L
#define MCI_ANIM_STEP_REVERSE           0x00010000L
#define MCI_ANIM_STEP_FRAMES            0x00020000L
#define MCI_ANIM_STATUS_SPEED           0x00004001L
#define MCI_ANIM_STATUS_FORWARD         0x00004002L
#define MCI_ANIM_STATUS_HWND            0x00004003L
#define MCI_ANIM_STATUS_HPAL            0x00004004L
#define MCI_ANIM_STATUS_STRETCH         0x00004005L
#define MCI_ANIM_INFO_TEXT              0x00010000L
#define MCI_ANIM_GETDEVCAPS_CAN_REVERSE 0x00004001L
#define MCI_ANIM_GETDEVCAPS_FAST_RATE   0x00004002L
#define MCI_ANIM_GETDEVCAPS_SLOW_RATE   0x00004003L
#define MCI_ANIM_GETDEVCAPS_NORMAL_RATE 0x00004004L
#define MCI_ANIM_GETDEVCAPS_PALETTES    0x00004006L
#define MCI_ANIM_GETDEVCAPS_CAN_STRETCH 0x00004007L
#define MCI_ANIM_GETDEVCAPS_MAX_WINDOWS 0x00004008L
#define MCI_ANIM_REALIZE_NORM           0x00010000L
#define MCI_ANIM_REALIZE_BKGD           0x00020000L
#define MCI_ANIM_WINDOW_HWND            0x00010000L
#define MCI_ANIM_WINDOW_STATE           0x00040000L
#define MCI_ANIM_WINDOW_TEXT            0x00080000L
#define MCI_ANIM_WINDOW_ENABLE_STRETCH  0x00100000L
#define MCI_ANIM_WINDOW_DISABLE_STRETCH 0x00200000L
#define MCI_ANIM_WINDOW_DEFAULT         0x00000000L
#define MCI_ANIM_RECT                   0x00010000L
#define MCI_ANIM_PUT_SOURCE             0x00020000L
#define MCI_ANIM_PUT_DESTINATION        0x00040000L
#define MCI_ANIM_WHERE_SOURCE           0x00020000L
#define MCI_ANIM_WHERE_DESTINATION      0x00040000L
#define MCI_ANIM_UPDATE_HDC             0x00020000L
#ifdef _WIN32
typedef struct tagMCI_ANIM_OPEN_PARMSA {
	DWORD_PTR dwCallback;
	MCIDEVICEID wDeviceID;
	LPCSTR lpstrDeviceType;
	LPCSTR lpstrElementName;
	LPCSTR lpstrAlias;
	DWORD dwStyle;
	HWND hWndParent;
} MCI_ANIM_OPEN_PARMSA, *PMCI_ANIM_OPEN_PARMSA, *LPMCI_ANIM_OPEN_PARMSA;
typedef struct tagMCI_ANIM_OPEN_PARMSW {
	DWORD_PTR dwCallback;
	MCIDEVICEID wDeviceID;
	LPCWSTR lpstrDeviceType;
	LPCWSTR lpstrElementName;
	LPCWSTR lpstrAlias;
	DWORD dwStyle;
	HWND hWndParent;
} MCI_ANIM_OPEN_PARMSW, *PMCI_ANIM_OPEN_PARMSW, *LPMCI_ANIM_OPEN_PARMSW;
#ifdef UNICODE
typedef MCI_ANIM_OPEN_PARMSW MCI_ANIM_OPEN_PARMS;
typedef PMCI_ANIM_OPEN_PARMSW PMCI_ANIM_OPEN_PARMS;
typedef LPMCI_ANIM_OPEN_PARMSW LPMCI_ANIM_OPEN_PARMS;
#else
typedef MCI_ANIM_OPEN_PARMSA MCI_ANIM_OPEN_PARMS;
typedef PMCI_ANIM_OPEN_PARMSA PMCI_ANIM_OPEN_PARMS;
typedef LPMCI_ANIM_OPEN_PARMSA LPMCI_ANIM_OPEN_PARMS;
#endif
#else
typedef struct tagMCI_ANIM_OPEN_PARMS {
	DWORD dwCallback;
	MCIDEVICEID wDeviceID;
	WORD wReserved0;
	LPCSTR lpstrDeviceType;
	LPCSTR lpstrElementName;
	LPCSTR lpstrAlias;
	DWORD dwStyle;
	HWND hWndParent;
	WORD wReserved1;
} MCI_ANIM_OPEN_PARMS, FAR * LPMCI_ANIM_OPEN_PARMS;
#endif
typedef struct tagMCI_ANIM_PLAY_PARMS {
	DWORD_PTR dwCallback;
	DWORD dwFrom;
	DWORD dwTo;
	DWORD dwSpeed;
} MCI_ANIM_PLAY_PARMS, *PMCI_ANIM_PLAY_PARMS, FAR * LPMCI_ANIM_PLAY_PARMS;
typedef struct tagMCI_ANIM_STEP_PARMS {
	DWORD_PTR dwCallback;
	DWORD dwFrames;
} MCI_ANIM_STEP_PARMS, *PMCI_ANIM_STEP_PARMS, FAR * LPMCI_ANIM_STEP_PARMS;
#ifdef _WIN32
typedef struct tagMCI_ANIM_WINDOW_PARMSA {
	DWORD_PTR dwCallback;
	HWND hWnd;
	UINT nCmdShow;
	LPCSTR lpstrText;
} MCI_ANIM_WINDOW_PARMSA, *PMCI_ANIM_WINDOW_PARMSA, *LPMCI_ANIM_WINDOW_PARMSA;
typedef struct tagMCI_ANIM_WINDOW_PARMSW {
	DWORD_PTR dwCallback;
	HWND hWnd;
	UINT nCmdShow;
	LPCWSTR lpstrText;
} MCI_ANIM_WINDOW_PARMSW, *PMCI_ANIM_WINDOW_PARMSW, *LPMCI_ANIM_WINDOW_PARMSW;
#ifdef UNICODE
typedef MCI_ANIM_WINDOW_PARMSW MCI_ANIM_WINDOW_PARMS;
typedef PMCI_ANIM_WINDOW_PARMSW PMCI_ANIM_WINDOW_PARMS;
typedef LPMCI_ANIM_WINDOW_PARMSW LPMCI_ANIM_WINDOW_PARMS;
#else
typedef MCI_ANIM_WINDOW_PARMSA MCI_ANIM_WINDOW_PARMS;
typedef PMCI_ANIM_WINDOW_PARMSA PMCI_ANIM_WINDOW_PARMS;
typedef LPMCI_ANIM_WINDOW_PARMSA LPMCI_ANIM_WINDOW_PARMS;
#endif
#else
typedef struct tagMCI_ANIM_WINDOW_PARMS {
	DWORD dwCallback;
	HWND hWnd;
	WORD wReserved1;
	WORD nCmdShow;
	WORD wReserved2;
	LPCSTR lpstrText;
} MCI_ANIM_WINDOW_PARMS, FAR * LPMCI_ANIM_WINDOW_PARMS;
#endif
typedef struct tagMCI_ANIM_RECT_PARMS {
	DWORD_PTR dwCallback;
#ifdef MCI_USE_OFFEXT
	POINT ptOffset;
	POINT ptExtent;
#else
	RECT rc;
#endif
} MCI_ANIM_RECT_PARMS;
typedef MCI_ANIM_RECT_PARMS *PMCI_ANIM_RECT_PARMS;
typedef MCI_ANIM_RECT_PARMS FAR *LPMCI_ANIM_RECT_PARMS;
typedef struct tagMCI_ANIM_UPDATE_PARMS {
	DWORD_PTR dwCallback;
	RECT rc;
	HDC hDC;
} MCI_ANIM_UPDATE_PARMS, *PMCI_ANIM_UPDATE_PARMS, FAR * LPMCI_ANIM_UPDATE_PARMS;
#define MCI_OVLY_OPEN_WS                0x00010000L
#define MCI_OVLY_OPEN_PARENT            0x00020000L
#define MCI_OVLY_STATUS_HWND            0x00004001L
#define MCI_OVLY_STATUS_STRETCH         0x00004002L
#define MCI_OVLY_INFO_TEXT              0x00010000L
#define MCI_OVLY_GETDEVCAPS_CAN_STRETCH 0x00004001L
#define MCI_OVLY_GETDEVCAPS_CAN_FREEZE  0x00004002L
#define MCI_OVLY_GETDEVCAPS_MAX_WINDOWS 0x00004003L
#define MCI_OVLY_WINDOW_HWND            0x00010000L
#define MCI_OVLY_WINDOW_STATE           0x00040000L
#define MCI_OVLY_WINDOW_TEXT            0x00080000L
#define MCI_OVLY_WINDOW_ENABLE_STRETCH  0x00100000L
#define MCI_OVLY_WINDOW_DISABLE_STRETCH 0x00200000L
#define MCI_OVLY_WINDOW_DEFAULT         0x00000000L
#define MCI_OVLY_RECT                   0x00010000L
#define MCI_OVLY_PUT_SOURCE             0x00020000L
#define MCI_OVLY_PUT_DESTINATION        0x00040000L
#define MCI_OVLY_PUT_FRAME              0x00080000L
#define MCI_OVLY_PUT_VIDEO              0x00100000L
#define MCI_OVLY_WHERE_SOURCE           0x00020000L
#define MCI_OVLY_WHERE_DESTINATION      0x00040000L
#define MCI_OVLY_WHERE_FRAME            0x00080000L
#define MCI_OVLY_WHERE_VIDEO            0x00100000L
#ifdef _WIN32
typedef struct tagMCI_OVLY_OPEN_PARMSA {
	DWORD_PTR dwCallback;
	MCIDEVICEID wDeviceID;
	LPCSTR lpstrDeviceType;
	LPCSTR lpstrElementName;
	LPCSTR lpstrAlias;
	DWORD dwStyle;
	HWND hWndParent;
} MCI_OVLY_OPEN_PARMSA, *PMCI_OVLY_OPEN_PARMSA, *LPMCI_OVLY_OPEN_PARMSA;
typedef struct tagMCI_OVLY_OPEN_PARMSW {
	DWORD_PTR dwCallback;
	MCIDEVICEID wDeviceID;
	LPCWSTR lpstrDeviceType;
	LPCWSTR lpstrElementName;
	LPCWSTR lpstrAlias;
	DWORD dwStyle;
	HWND hWndParent;
} MCI_OVLY_OPEN_PARMSW, *PMCI_OVLY_OPEN_PARMSW, *LPMCI_OVLY_OPEN_PARMSW;
#ifdef UNICODE
typedef MCI_OVLY_OPEN_PARMSW MCI_OVLY_OPEN_PARMS;
typedef PMCI_OVLY_OPEN_PARMSW PMCI_OVLY_OPEN_PARMS;
typedef LPMCI_OVLY_OPEN_PARMSW LPMCI_OVLY_OPEN_PARMS;
#else
typedef MCI_OVLY_OPEN_PARMSA MCI_OVLY_OPEN_PARMS;
typedef PMCI_OVLY_OPEN_PARMSA PMCI_OVLY_OPEN_PARMS;
typedef LPMCI_OVLY_OPEN_PARMSA LPMCI_OVLY_OPEN_PARMS;
#endif
#else
typedef struct tagMCI_OVLY_OPEN_PARMS {
	DWORD dwCallback;
	MCIDEVICEID wDeviceID;
	WORD wReserved0;
	LPCSTR lpstrDeviceType;
	LPCSTR lpstrElementName;
	LPCSTR lpstrAlias;
	DWORD dwStyle;
	HWND hWndParent;
	WORD wReserved1;
} MCI_OVLY_OPEN_PARMS, FAR * LPMCI_OVLY_OPEN_PARMS;
#endif
#ifdef _WIN32
typedef struct tagMCI_OVLY_WINDOW_PARMSA {
	DWORD_PTR dwCallback;
	HWND hWnd;
	UINT nCmdShow;
	LPCSTR lpstrText;
} MCI_OVLY_WINDOW_PARMSA, *PMCI_OVLY_WINDOW_PARMSA, *LPMCI_OVLY_WINDOW_PARMSA;
typedef struct tagMCI_OVLY_WINDOW_PARMSW {
	DWORD_PTR dwCallback;
	HWND hWnd;
	UINT nCmdShow;
	LPCWSTR lpstrText;
} MCI_OVLY_WINDOW_PARMSW, *PMCI_OVLY_WINDOW_PARMSW, *LPMCI_OVLY_WINDOW_PARMSW;
#ifdef UNICODE
typedef MCI_OVLY_WINDOW_PARMSW MCI_OVLY_WINDOW_PARMS;
typedef PMCI_OVLY_WINDOW_PARMSW PMCI_OVLY_WINDOW_PARMS;
typedef LPMCI_OVLY_WINDOW_PARMSW LPMCI_OVLY_WINDOW_PARMS;
#else
typedef MCI_OVLY_WINDOW_PARMSA MCI_OVLY_WINDOW_PARMS;
typedef PMCI_OVLY_WINDOW_PARMSA PMCI_OVLY_WINDOW_PARMS;
typedef LPMCI_OVLY_WINDOW_PARMSA LPMCI_OVLY_WINDOW_PARMS;
#endif
#else
typedef struct tagMCI_OVLY_WINDOW_PARMS {
	DWORD dwCallback;
	HWND hWnd;
	WORD wReserved1;
	UINT nCmdShow;
	WORD wReserved2;
	LPCSTR lpstrText;
} MCI_OVLY_WINDOW_PARMS, FAR * LPMCI_OVLY_WINDOW_PARMS;
#endif
typedef struct tagMCI_OVLY_RECT_PARMS {
	DWORD_PTR dwCallback;
#ifdef MCI_USE_OFFEXT
	POINT ptOffset;
	POINT ptExtent;
#else
	RECT rc;
#endif
} MCI_OVLY_RECT_PARMS, *PMCI_OVLY_RECT_PARMS, FAR * LPMCI_OVLY_RECT_PARMS;
#ifdef _WIN32
typedef struct tagMCI_OVLY_SAVE_PARMSA {
	DWORD_PTR dwCallback;
	LPCSTR lpfilename;
	RECT rc;
} MCI_OVLY_SAVE_PARMSA, *PMCI_OVLY_SAVE_PARMSA, *LPMCI_OVLY_SAVE_PARMSA;
typedef struct tagMCI_OVLY_SAVE_PARMSW {
	DWORD_PTR dwCallback;
	LPCWSTR lpfilename;
	RECT rc;
} MCI_OVLY_SAVE_PARMSW, *PMCI_OVLY_SAVE_PARMSW, *LPMCI_OVLY_SAVE_PARMSW;
#ifdef UNICODE
typedef MCI_OVLY_SAVE_PARMSW MCI_OVLY_SAVE_PARMS;
typedef PMCI_OVLY_SAVE_PARMSW PMCI_OVLY_SAVE_PARMS;
typedef LPMCI_OVLY_SAVE_PARMSW LPMCI_OVLY_SAVE_PARMS;
#else
typedef MCI_OVLY_SAVE_PARMSA MCI_OVLY_SAVE_PARMS;
typedef PMCI_OVLY_SAVE_PARMSA PMCI_OVLY_SAVE_PARMS;
typedef LPMCI_OVLY_SAVE_PARMSA LPMCI_OVLY_SAVE_PARMS;
#endif
#else
typedef struct tagMCI_OVLY_SAVE_PARMS {
	DWORD dwCallback;
	LPCSTR lpfilename;
	RECT rc;
} MCI_OVLY_SAVE_PARMS, FAR * LPMCI_OVLY_SAVE_PARMS;
#endif
#ifdef _WIN32
typedef struct tagMCI_OVLY_LOAD_PARMSA {
	DWORD_PTR dwCallback;
	LPCSTR lpfilename;
	RECT rc;
} MCI_OVLY_LOAD_PARMSA, *PMCI_OVLY_LOAD_PARMSA, *LPMCI_OVLY_LOAD_PARMSA;
typedef struct tagMCI_OVLY_LOAD_PARMSW {
	DWORD_PTR dwCallback;
	LPCWSTR lpfilename;
	RECT rc;
} MCI_OVLY_LOAD_PARMSW, *PMCI_OVLY_LOAD_PARMSW, *LPMCI_OVLY_LOAD_PARMSW;
#ifdef UNICODE
typedef MCI_OVLY_LOAD_PARMSW MCI_OVLY_LOAD_PARMS;
typedef PMCI_OVLY_LOAD_PARMSW PMCI_OVLY_LOAD_PARMS;
typedef LPMCI_OVLY_LOAD_PARMSW LPMCI_OVLY_LOAD_PARMS;
#else
typedef MCI_OVLY_LOAD_PARMSA MCI_OVLY_LOAD_PARMS;
typedef PMCI_OVLY_LOAD_PARMSA PMCI_OVLY_LOAD_PARMS;
typedef LPMCI_OVLY_LOAD_PARMSA LPMCI_OVLY_LOAD_PARMS;
#endif
#else
typedef struct tagMCI_OVLY_LOAD_PARMS {
	DWORD dwCallback;
	LPCSTR lpfilename;
	RECT rc;
} MCI_OVLY_LOAD_PARMS, FAR * LPMCI_OVLY_LOAD_PARMS;
#endif
#endif
#ifndef NEWTRANSPARENT
#define NEWTRANSPARENT  3
#define QUERYROPSUPPORT 40
#endif
#define SELECTDIB       41
#define DIBINDEX(n)     MAKELONG((n),0x10FF)
#ifndef SC_SCREENSAVE
#define SC_SCREENSAVE   0xF140
#endif

#ifdef _WIN32
#include <poppack.h>
#else
#ifndef RC_INVOKED
#pragma pack()
#endif
#endif
#endif