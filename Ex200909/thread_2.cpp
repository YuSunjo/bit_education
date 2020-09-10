//#include <process.h>	      //begin thread 여기있음 
//#include <Windows.h>
//#include <tchar.h>	
//#include <iostream>
//
//using namespace std;
//
//unsigned WINAPI myFunction(void*);
//
//int _tmain(void)
//{
//	HANDLE hThread = NULL;
//	unsigned threadid = NULL;
//	BOOL bOk;
//	FILETIME CreationTime, ExitTime, KernelTime, UserTime;
//	SYSTEMTIME Csystem, Esystem, Usystem;
//	DWORD retCode = 0;
//
//	hThread = (HANDLE)_beginthreadex(NULL, 0, myFunction, NULL, 0, &threadid);
//
//	if (hThread == NULL)
//	{
//		cout << "쓰레드 생성 실패 : " << GetLastError() << endl;
//		return -1;
//
//	}
//	WaitForSingleObject(hThread, INFINITE); //중요!
//	GetExitCodeThread(hThread, &retCode);
//	if (retCode != STILL_ACTIVE)
//	{
//		GetThreadTimes(hThread, &CreationTime, &ExitTime, &KernelTime, &UserTime);
//		FileTimeToSystemTime(&CreationTime, &Csystem);
//		FileTimeToSystemTime(&ExitTime, &Esystem);
//		FileTimeToSystemTime(&UserTime, &Usystem);
//
//		cout << "쓰레드 di:" << threadid << endl;
//		cout << "쓰레드 생성 시작" << Csystem.wYear
//			<< "year" << Csystem.wMonth
//			<< "month" << Csystem.wDay
//			<< "day" << Csystem.wHour
//			<< "hour" << Csystem.wMinute
//			<< "minute" << Csystem.wSecond
//			<< "second" << endl;
//		if (Esystem.wYear == 1601)
//			cout << "종료시각이 정의 되지 않았습니다." << endl;
//		else
//			cout << "쓰레드 종료 시각" << Esystem.wYear
//			<< "year" << Esystem.wMonth
//			<< "month" << Esystem.wDay
//			<< "day" << Esystem.wHour
//			<< "hour" << Esystem.wMinute
//			<< "minute" << Esystem.wSecond
//			<< "second" << endl;
//
//		cout << "사용자 모드 동작 시간" << Usystem.wMinute
//			<< "minute" << Usystem.wSecond
//			<< "second" << Usystem.wMilliseconds
//			<< "millisecond" << endl;
//
//		bOk = CloseHandle(hThread);
//		exit(0);
//	}
//
//}
//
//unsigned WINAPI myFunction(void* p)
//{
//	long j, k;
//	k = 0;
//	for (j = 1; j < 1000; j++)
//	{
//		k += j;
//		
//	}
//	_endthreadex(0);
//	return 0;
//}