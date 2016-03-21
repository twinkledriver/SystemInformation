#include "windows.h"
#if !defined(AFX_SYSTEMINFOTESTDLG_H__B644FC25_83FB_498B_A681_93CE0442F745__INCLUDED_)
#define AFX_SYSTEMINFOTESTDLG_H__B644FC25_83FB_498B_A681_93CE0442F745__INCLUDED_

#pragma once    //保证只编译一次

#define SystemBasicInformation 0 
#define SystemPerformanceInformation 2 
#define SystemTimeInformation 3 

#define Li2Double(x) ((double)((x).HighPart) * 4.294967296E9 + (double)((x).LowPart))    //指在生成EXE时，把所有以Li2Double(x)形式写的（标示符Li2Double + 一个参数）
																						 //替换成((double)((x).HighPart)*4.294967296E9+(double)((x).LowPart))的形式。
class CCpuUsage
{
public:
	CCpuUsage();
	~CCpuUsage();
public:
	float GetCpuTemp();							//获得Cpu温度
	int getCpuUsage();							//得到系统cpu利用率
	int SetRefreshInterval(int milli_sec);	//定时刷新间隔(毫秒)
private:
	typedef LONG (WINAPI *PROCNTQSI)(UINT,PVOID,ULONG,PULONG);

	typedef struct
	{
		DWORD dwUnknown1;
		ULONG uKeMaximumIncrement;
		ULONG uPageSize;
		ULONG uMmNumberOfPhysicalPages;
		ULONG uMmLowestPhysicalPage;
		ULONG uMmHighestPhysicalPage;
		ULONG uAllocationGranularity;
		PVOID pLowestUserAddress;
		PVOID pMmHighestUserAddress;
		ULONG uKeActiveProcessors;
		BYTE bKeNumberProcessors;
		BYTE bUnknown2;
		WORD wUnknown3;
	} SYSTEM_BASIC_INFORMATION;
	
	typedef struct
	{
		LARGE_INTEGER liIdleTime;
		DWORD dwSpare[76];
	}SYSTEM_PERFORMANCE_INFORMATION;

		typedef struct
	{
		LARGE_INTEGER liKeBootTime;
		LARGE_INTEGER liKeSystemTime;
		LARGE_INTEGER liExpTimeZoneBias;
		ULONG uCurrentTimeZoneId;
		DWORD dwReserved;
	} SYSTEM_TIME_INFORMATION;

	SYSTEM_PERFORMANCE_INFORMATION SysPerfInfo;
	SYSTEM_TIME_INFORMATION SysTimeInfo;
	SYSTEM_BASIC_INFORMATION SysBaseInfo;
	double dbIdleTime;
	double dbSystemTime;

	LONG status;
	
	LARGE_INTEGER liOldIdleTime;
	LARGE_INTEGER liOldSystemTime;
	
	PROCNTQSI NtQuerySystemInformation;

	int m_nCpuUsage;

	HWND m_hWnd;
	int  m_nRefreshInterval;//默认为1000毫秒
	int  m_nTimerID;

	private:
	static void CalcCpuUsage(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime);
	int OnTimer();

};


#endif