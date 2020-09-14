//����ȭ 4����
//Critical Section


//#include <process.h>	    
//#include <Windows.h>
//#include <tchar.h>	
//#include <iostream>
//
//using namespace std;
//
//unsigned WINAPI myFunction(void*);
//int GlobalVar = 1;
//CRITICAL_SECTION cs;
//
//int _tmain()
//{
//	HANDLE hThread1 = NULL, hThread2 = NULL;
//	unsigned threadid = NULL, threadid2 = NULL;
//	HANDLE handles[2];
//	BOOL bOK;
//	InitializeCriticalSection(&cs);
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
//
//	DeleteCriticalSection(&cs);
//	return 0;
//}
//
//unsigned WINAPI myFunction(void* p)
//{
//	EnterCriticalSection(&cs);
//	GlobalVar += 10;
//	Sleep(500);
//	cout << GlobalVar << endl;
//	LeaveCriticalSection(&cs);
//	return 0;
//}

//2. Mutex
//
//#include <process.h>	    
//#include <Windows.h>
//#include <tchar.h>	
//#include <iostream>
////#include <locale.h>	
//
//#define NUMBER_OF_THREADS 20
////������ Ǯ
//int GlobalVar = 1;
//HANDLE hMutex;
//unsigned int WINAPI ThreadFunc(void*);
//
//
//int _tmain(void)
//{
//	//false -- ������ ���� �� �ִ� ���� �� signal
//
//	hMutex = CreateMutex(NULL, FALSE, NULL);   //"MyMux��� ��������"
//
//	//HANDLE CreateMutexA(
//	//	LPSECURITY_ATTRIBUTES lpMutexAttributes,  //security
//	//	BOOL				  bInitialOwner,       //True: 
//	//	LPCSTR				  lpName          //mutex name -- ���� process�� ������ �� ���
//	//);
//	//HANDLE OpenMutex(DWORD fdwAccess, BOOL fInherit, LPTSTR lpszName)	
//	//�Ǵ� CreateMutex()               // ������ �̸����� ������ open���� ����
//
//	HANDLE hThreads[NUMBER_OF_THREADS];
//	unsigned int dwThreadIDS[NUMBER_OF_THREADS];
//	for (int i = 0; i < NUMBER_OF_THREADS; i++)
//	{
//		hThreads[i] = (HANDLE)_beginthreadex(NULL, 0, ThreadFunc, NULL, CREATE_SUSPENDED, &dwThreadIDS[i]);
//	}
//	// �����ٷ��� �����尡 ���� �Ȱ��� �뺸
//	for (int i = 0; i < NUMBER_OF_THREADS; i++)
//	{
//		ResumeThread(hThreads[i]);
//	}
//	WaitForMultipleObjects(NUMBER_OF_THREADS, hThreads, TRUE, INFINITE);  //20�� �����尡 �� �Ϸ� �� ������ ��ٸ� 
//
//	for (int i = 0; i < NUMBER_OF_THREADS; i++)
//	{
//		CloseHandle(hThreads[i]);
//	}
//	CloseHandle(hMutex);
//	return 0;
//
//}
//
//unsigned int WINAPI ThreadFunc(void* lParam)
//{
//	//Mytex �� signal �϶����� ��ٸ��� ������ signal������ ������ non-signal �� �ٲ�
//	WaitForSingleObject(hMutex, INFINITE);
//	GlobalVar += 10;
//
//	Sleep(500);
//	_tprintf(TEXT("Globalvar: %d\n"), GlobalVar);
//	ReleaseMutex(hMutex);
//	return 0;
//}

//critical section���� ������ --  ���� �ٸ� ���μ����� �ִµ� �Ѱ��� ������ �������� �� ��� critical section���δ� ���� ���μ��������� �������� 
//���� �ٸ� ���μ��������� �Ұ��� 

//���ý��� ���� �����ϱ� ������ ���� �ٸ� ���μ����� ��밡�� --> ���� mutex�� �̸��� �ְ� openMutex, CreateMutex �� ����ϸ� �ȴ�.
//������ �̸��̶��� ���� NULL�� �̸� �ٿ��ְ�  ����createMutex �����ϰ� �̹� mutex�� �����ϱ� openMutex�� ���ٴ� ���̳�


//semahore    // 2�� �̻��� ���� ���� �����带 ���� ���� 

//#include <process.h>	    
//#include <Windows.h>
//#include <tchar.h>	
//#include <stdio.h>	
//
//#define MAX_SEM_COUNT 5
//#define THREADCOUNT 15
//
//HANDLE ghSemahore;
//
//unsigned int WINAPI ThreadProc(void*);
//
//int _tmain(int argc, char* argv[])
//{
//	HANDLE aThread[THREADCOUNT];
//	unsigned int ThreadID[THREADCOUNT];
//
//	int i;
//
//	ghSemahore = CreateSemaphore(
//		NULL,
//		MAX_SEM_COUNT,
//		MAX_SEM_COUNT,
//		NULL
//	);
//	if (ghSemahore == NULL)
//	{
//		printf("CreateSemahore error: %d\n", GetLastError());
//		return 1;
//	}
//
//	for (i = 0; i < THREADCOUNT; i++)
//	{
//		//Thread ����
//		aThread[i] = (HANDLE)_beginthreadex(
//			NULL,
//			0,
//			ThreadProc,
//			NULL,
//			0,
//			&ThreadID[i]);
//		
//		//���� �ȵ��� �� �ַ� ó��
//		if (aThread[i] == NULL)
//		{
//			printf("CreateSemahore error: %d\n", GetLastError());
//			return 1;
//		}
//		else
//		{
//			printf("Create Thread : %d\n", ThreadID[i]);
//		}
//	}
//
//	WaitForMultipleObjects(THREADCOUNT, aThread, TRUE, INFINITE);
//	//DWORD WINAPI WaitForMultipleObjects(
//	//		_In_ DWORD nCount,                              //��ٸ� �̺�Ʈ ��
//	//		_In_reads_(nCount) CONST HANDLE * lpHandles,    //��ٸ� ������Ʈ��
//	//		_In_ BOOL bWaitAll,                             //��� ��ٸ����� �ϳ��� ��ٸ����� (false)
//	//		_In_ DWORD dwMilliseconds
//	//	);
//
//	for (i = 0; i < THREADCOUNT; i++)
//	{
//		CloseHandle(aThread[i]);
//
//	}
//	CloseHandle(ghSemahore);
//	return 0;
//
//}
//
//unsigned int WINAPI ThreadProc(void* lpParam)
//{
//	UNREFERENCED_PARAMETER(lpParam);
//
//	DWORD dwWaitResult;
//	BOOL bContinue = TRUE;
//
//	while (bContinue)
//	{
//		printf("Request key :THread %d\n", GetCurrentThreadId());
//
//		dwWaitResult = WaitForSingleObject(ghSemahore, 0L);   //0 -> �ٷ� �ѱ� 
//
//		switch (dwWaitResult)
//		{
//		case WAIT_OBJECT_0:
//			printf("Thread %d :enter succeeded\n", GetCurrentThreadId());
//			bContinue = FALSE;
//
//			Sleep(1500);
//
//			if (!ReleaseSemaphore(ghSemahore, 1, NULL))      //1 -> 1�� ������Ŵ, NULL former count
//			{
//				printf("ReleaseSemaphore error : %d\n", GetLastError());
//			}
//			break;
//		case WAIT_TIMEOUT:
//		{
//			printf("Thread %d: wait timed out\n", GetCurrentThreadId());
//			Sleep(1000);
//		}
//		break;
//		}
//		
//	}
//	printf("Thread %d: done \n", GetCurrentThreadId());
//	return TRUE;
//}



//Event  

//#include <process.h>	    
//#include <Windows.h>
//#include <tchar.h>	
//#include <iostream>
//
//using namespace std;
//
//unsigned int WINAPI myfunction(void*);
//int i=30;
//
//int _tmain()
//{
//	HANDLE hThread[5];
//	HANDLE hEvent;
//	unsigned int threadId = NULL;
//	BOOL bOK;
//	int j;
//	
//	
//	hEvent = CreateEvent(NULL, FALSE, TRUE, TEXT("MyEvent"));  //ACL , �ڵ��̺�Ʈ , �ʱ���� : ON ,�̺�Ʈ��
//	for (j = 0; j < 5; j++)
//	{
//		hThread[j] = (HANDLE)_beginthreadex(NULL, 0, myfunction, (void*)j, 0, &threadId);
//
//		if (hThread[j] == NULL)
//		{
//			cout << "thread error" << GetLastError() << endl;
//			return -1;
//		}
//	}
//	WaitForMultipleObjects(5, hThread, TRUE, INFINITE);
//	bOK = CloseHandle(hEvent);
//	for (j = 0; j < 5; j++)
//		bOK = CloseHandle(hThread[j]);
//	return 0;
//}
//
//unsigned int WINAPI myfunction(void* p)
//{
//	HANDLE hEvent = OpenEvent(EVENT_ALL_ACCESS, FALSE, TEXT("MyEvent"));
//	WaitForSingleObject(hEvent, INFINITE);
//	int j, k;
//	j = (int)p;
//	cout << "<-------------------" << j << "------------------->"<<endl;
//
//	for (k = 0; k < i; k++)
//	{
//		cout << k << endl;
//
//	}
//	SetEvent(hEvent);
//
//	return 0;
//
//
//
//}
