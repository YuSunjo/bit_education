//#include <stdio.h>
//#include <tchar.h>	
//#include <Windows.h>
//#include <stdlib.h>	
//
//void ExpandEnvStrings(void)
//{
//	DWORD chValue = ExpandEnvironmentStrings(TEXT("'%USERPROFILE%'"), NULL, 0 );
//
//	PTSTR pszBuffer = new TCHAR[chValue];
//	chValue = ExpandEnvironmentStrings(TEXT("'%USERPROFILE%'"), pszBuffer, chValue);
//
//	_tprintf(TEXT("USERPROFILE =%s\n"), pszBuffer);
//
//	delete[] pszBuffer;
//}
//
//int _tmain(void)
//{
//	ExpandEnvStrings();
//
//	return 0;
//}

//#include <stdio.h>
//#include <tchar.h>	
//#include <Windows.h>
//
//void SetEnvVariable(void)
//{
//	SetEnvironmentVariable(TEXT("TEXTNAME"), TEXT("TEXTVALUE"));
//	SetEnvironmentVariable(TEXT("TEMP"), TEXT("NEWTEMP"));
//
//}
//
//void PrintEnvironmentVariable(PCTSTR pszVariableName)
//{
//	PTSTR pszValue = NULL;
//	DWORD dwRESULT = GetEnvironmentVariable(pszVariableName, pszValue, 0);
//
//	if (dwRESULT != 0)
//	{
//		DWORD size = dwRESULT * sizeof(TCHAR);
//		pszValue = (PTSTR)malloc(size);
//		GetEnvironmentVariable(pszVariableName,pszValue, size);
//
//
//		_tprintf(TEXT("%s = %s\n"), pszVariableName, pszValue);
//		free(pszValue);
//	}
//	else 
//		_tprintf(TEXT("%s = <unknown vlaue\n"), pszVariableName);
//}
//
//int _tmain(int argc, TCHAR* argv[])
//{
//	SetEnvVariable();
//	PrintEnvironmentVariable(TEXT("TEXTNAME"));
//	PrintEnvironmentVariable(TEXT("TEMP"));
//	return 0;
//}
//
