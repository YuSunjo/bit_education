//#include <process.h>	    
//#include <Windows.h>
//#include <tchar.h>	
//#include <iostream>
//
//using namespace std;
//
//unsigned WINAPI myFunction(void*);
//int GlobalVar = 1;
//
//int _tmain()
//{
//	HANDLE hThread1 = NULL, hThread2 = NULL;
//	unsigned threadid = NULL, threadid2 = NULL;
//	HANDLE handles[2];
//	BOOL bOK;
//
//	hThread1 = (HANDLE)_beginthreadex(NULL, 0, myFunction, NULL, 0, &threadid);
//	handles[0] = hThread1;
//	if (hThread1 == NULL)
//	{
//		cout << "�����带 �������� ���߽��ϴ�." << GetLastError() << endl;
//		return -1;
//	}
//	
//
//	hThread2 = (HANDLE)_beginthreadex(NULL, 0, myFunction, NULL, 0, &threadid2);
//	handles[1] = hThread2;
//	if (hThread2 == NULL)
//	{
//		cout << "������2�� �������� ���߽��ϴ�." << GetLastError() << endl;
//		return -1;
//	}
//	WaitForMultipleObjects(sizeof(handles) / sizeof(HANDLE), handles, TRUE, INFINITE);  //true�� 2�� ��� ��������Ǹ� ����
//	bOK = CloseHandle(hThread1);
//	bOK = CloseHandle(hThread2);
//	return 0;
//}
//
//unsigned WINAPI myFunction(void* p)
//{
//	GlobalVar += 10;
//	Sleep(500);
//	cout << GlobalVar << endl;
//	return 0;
//}