//동기화 4가지
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
//		cout << "스레드를 생성하지 못했습니다." << GetLastError() << endl;
//		return -1;
//	}
//
//
//	hThread2 = (HANDLE)_beginthreadex(NULL, 0, myFunction, NULL, 0, &threadid2);
//	handles[1] = hThread2;
//	if (hThread2 == NULL)
//	{
//		cout << "쓰레드2를 생성하지 못했습니다." << GetLastError() << endl;
//		return -1;
//	}
//	WaitForMultipleObjects(sizeof(handles) / sizeof(HANDLE), handles, TRUE, INFINITE);  //true면 2개 모두 정상종료되면 끝남
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
////쓰레드 풀
//int GlobalVar = 1;
//HANDLE hMutex;
//unsigned int WINAPI ThreadFunc(void*);
//
//
//int _tmain(void)
//{
//	//false -- 누구나 가질 수 있는 상태 즉 signal
//
//	hMutex = CreateMutex(NULL, FALSE, NULL);   //"MyMux라고 생성가능"
//
//	//HANDLE CreateMutexA(
//	//	LPSECURITY_ATTRIBUTES lpMutexAttributes,  //security
//	//	BOOL				  bInitialOwner,       //True: 
//	//	LPCSTR				  lpName          //mutex name -- 여러 process가 공유할 때 사용
//	//);
//	//HANDLE OpenMutex(DWORD fdwAccess, BOOL fInherit, LPTSTR lpszName)	
//	//또는 CreateMutex()               // 동일한 이름으로 생성시 open으로 동작
//
//	HANDLE hThreads[NUMBER_OF_THREADS];
//	unsigned int dwThreadIDS[NUMBER_OF_THREADS];
//	for (int i = 0; i < NUMBER_OF_THREADS; i++)
//	{
//		hThreads[i] = (HANDLE)_beginthreadex(NULL, 0, ThreadFunc, NULL, CREATE_SUSPENDED, &dwThreadIDS[i]);
//	}
//	// 스케줄러에 쓰레드가 레디가 된것을 통보
//	for (int i = 0; i < NUMBER_OF_THREADS; i++)
//	{
//		ResumeThread(hThreads[i]);
//	}
//	WaitForMultipleObjects(NUMBER_OF_THREADS, hThreads, TRUE, INFINITE);  //20개 쓰레드가 다 완료 될 때까지 기다림 
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
//	//Mytex 가 signal 일때까지 기다리고 누군가 signal들어오는 순간에 non-signal 로 바뀜
//	WaitForSingleObject(hMutex, INFINITE);
//	GlobalVar += 10;
//
//	Sleep(500);
//	_tprintf(TEXT("Globalvar: %d\n"), GlobalVar);
//	ReleaseMutex(hMutex);
//	return 0;
//}

//critical section과의 차이점 --  서로 다른 프로세스가 있는데 한개의 파일을 읽으려고 할 경우 critical section으로는 동일 프로세스에서만 공유가능 
//서로 다른 프로세스에서는 불가능 

//뮤택스에 참조 가능하기 때문에 서로 다른 프로세스도 사용가능 --> 위에 mutex의 이름을 주고 openMutex, CreateMutex 를 사용하면 된다.
//동일한 이름이란게 위에 NULL에 이름 붙여주고  먼저createMutex 생성하고 이미 mutex가 있으니까 openMutex로 들어간다는 말이네


//semahore    // 2개 이상의 일정 수의 쓰레드를 수용 가능 

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
//		//Thread 생성
//		aThread[i] = (HANDLE)_beginthreadex(
//			NULL,
//			0,
//			ThreadProc,
//			NULL,
//			0,
//			&ThreadID[i]);
//		
//		//생성 안됐을 때 애러 처리
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
//	//		_In_ DWORD nCount,                              //기다릴 이벤트 수
//	//		_In_reads_(nCount) CONST HANDLE * lpHandles,    //기다릴 오브젝트들
//	//		_In_ BOOL bWaitAll,                             //모두 기다리는지 하나만 기다리는지 (false)
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
//		dwWaitResult = WaitForSingleObject(ghSemahore, 0L);   //0 -> 바로 넘김 
//
//		switch (dwWaitResult)
//		{
//		case WAIT_OBJECT_0:
//			printf("Thread %d :enter succeeded\n", GetCurrentThreadId());
//			bContinue = FALSE;
//
//			Sleep(1500);
//
//			if (!ReleaseSemaphore(ghSemahore, 1, NULL))      //1 -> 1씩 증가시킴, NULL former count
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
//	hEvent = CreateEvent(NULL, FALSE, TRUE, TEXT("MyEvent"));  //ACL , 자동이벤트 , 초기상태 : ON ,이벤트명
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
