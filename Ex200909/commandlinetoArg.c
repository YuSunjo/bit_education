//#include <stdio.h>
//#include <tchar.h>	
//#include <Windows.h>	
//
//BOOL CommandLine(void)
//{
//	int nArgs;
//	BOOL retVal;
//	LPTSTR* szArglist;
//
//	szArglist = CommandLineToArgvW(GetCommandLine(), &nArgs);
//	//szArglist = CommandLineToArgvW(GetCommandLine(), &nArgs);
//
//	if (szArglist == NULL)
//	{
//		_tprintf(TEXT("ERROR\n"));
//		retVal = FALSE;
//
//	}
//	else
//	{
//		_tprintf(TEXT("input args: \n"));
//		for (int i = 0; i < nArgs; i++)
//			_tprintf(TEXT("%d: %s \n\n"), i, szArglist[i]);
//
//		retVal = TRUE;
//	}
//	LocalFree(szArglist);
//
//	return retVal;
//}
////exe파일을 실행시킬 경우 인자를 넣을 수 있음  or 속성 -> 디버깅 -> 명령인수 
//
//int _tmain(int argc, TCHAR* argv[])
//{
//	if (CommandLine())
//	{
//		_tprintf(TEXT("SUCCED.\n\n"));
//
//	}
//	for (int i = 0; i < argc; i++)
//	{
//		_tprintf(TEXT("%d : %s \n\n"), i, argv[i]);
//	}
//	return 0;
//}