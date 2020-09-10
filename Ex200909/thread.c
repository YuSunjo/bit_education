//thread »ý¼º  - _beginthreadex
//

//#include <process.h>	
//#include <Windows.h>
//#include <tchar.h>	
//#include <stdio.h>	
//
//unsigned WINAPI ThreadFunction(void* para)
//{
//	int* num = (int*)para;
//	*num = 10;
//	
//}
//int _tmain(void) {
//
//	HANDLE hThread;
//	unsigned threadID;
//
//	int num = 0;
//	hThread = (HANDLE)_beginthreadex(NULL, 0, ThreadFunction, (void*)&num, 0, &threadID);
//	if (0 == hThread)
//	{
//		puts("_beginthreadex() error");
//		return -1;
//	}
//	Sleep(1000);
//	printf("num :%d\n", num);
//
//}

