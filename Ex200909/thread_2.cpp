//#include <process.h>	      //begin thread �������� 
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
//		cout << "������ ���� ���� : " << GetLastError() << endl;
//		return -1;
//
//	}
//	WaitForSingleObject(hThread, INFINITE); //�߿�!
//	GetExitCodeThread(hThread, &retCode);
//	if (retCode != STILL_ACTIVE)
//	{
//		GetThreadTimes(hThread, &CreationTime, &ExitTime, &KernelTime, &UserTime);
//		FileTimeToSystemTime(&CreationTime, &Csystem);
//		FileTimeToSystemTime(&ExitTime, &Esystem);
//		FileTimeToSystemTime(&UserTime, &Usystem);
//
//		cout << "������ di:" << threadid << endl;
//		cout << "������ ���� ����" << Csystem.wYear
//			<< "year" << Csystem.wMonth
//			<< "month" << Csystem.wDay
//			<< "day" << Csystem.wHour
//			<< "hour" << Csystem.wMinute
//			<< "minute" << Csystem.wSecond
//			<< "second" << endl;
//		if (Esystem.wYear == 1601)
//			cout << "����ð��� ���� ���� �ʾҽ��ϴ�." << endl;
//		else
//			cout << "������ ���� �ð�" << Esystem.wYear
//			<< "year" << Esystem.wMonth
//			<< "month" << Esystem.wDay
//			<< "day" << Esystem.wHour
//			<< "hour" << Esystem.wMinute
//			<< "minute" << Esystem.wSecond
//			<< "second" << endl;
//
//		cout << "����� ��� ���� �ð�" << Usystem.wMinute
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