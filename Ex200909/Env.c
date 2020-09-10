#include <stdio.h>
#include <tchar.h>	
#include <Windows.h>	
//#include <strsafe.h>	
#include <stdlib.h>	

//void GetEnv()
//{ 
//	PTSTR pEnvBlock = GetEnvironmentStrings();            
//	//환경블럭 내용을 가져와서 문자열 블럭으로 메모리에 생성 후 그 포인터를 반환
//														  
//
//	TCHAR szName[MAX_PATH];
//	TCHAR szValue[MAX_PATH];
//
//	PTSTR pszCurrent = pEnvBlock;
//	HRESULT hr = S_OK;
//	PCTSTR pszPos = NULL;
//	int current = 0;
//
//	ZeroMemory(szName, MAX_PATH);          //메모리 0으로 초기화
//	ZeroMemory(szValue, MAX_PATH);
//
//	while (pszCurrent != NULL)
//	{
//		if (*pszCurrent != TEXT('='))
//		{
//			pszPos = _tcschr(pszCurrent, TEXT('='));       //TEMP = sgsggs, '=' 의 위치 가져오기
//			pszPos++;
//			size_t cbNameLength = (size_t)pszPos - (size_t)pszCurrent - sizeof(TCHAR); //이름의 길이 
//			hr = StringCbCopyN(szName, MAX_PATH, pszCurrent, cbNameLength);   //이름부분만 복사 
//
//			if (FAILED(hr))
//				break;
//			hr = StringCbCopyN(szValue, MAX_PATH, pszPos, _tcslen(pszPos) + 1);   //값부분만 복사 
//
//			if (SUCCEEDED(hr))
//				_tprintf(TEXT("[%u] %s = %s\n"), current, szName, szValue);
//			else {
//				if (hr == STRSAFE_E_INSUFFICIENT_BUFFER)
//				{
//					//문자열이 잘려도 그대로 출력 
//					_tprintf(TEXT("[%u] %s =%s\n"), current, szName, szValue);
//				}
//				else
//				{
//					_tprintf(TEXT("[%u] %s = ???\n"), current, szName);
//					break;
//				}
//			}
//		}
//		else 
//		{
//			_tprintf(TEXT("[%u] %s\n"), current, szName);
//		}
//		current++;
//
//		//문자열 끝으로 이동 
//		while (*pszCurrent != TEXT('\0'))
//			pszCurrent++;
//
//		pszCurrent++;
//		if (*pszCurrent == TEXT('\0'))
//			break;
//
//	}
//	FreeEnvironmentStrings(pEnvBlock);     //환경블럭 내용 문자열 블럭 해제
//}
//
//int _tmain(int argc, TCHAR* argv[])
//{
//	GetEnv();
//
//	return 0;
//}

//regedit에 저장되어 있는 환경변수 있는 환경변수들을 가져오는 것


//특정한 환경변수를 긁어오는 함수 
//void PrintEnvironmentVariable(PCTSTR pszVariableName)
//{
//	PTSTR pszValue = NULL;
//
//	DWORD dwResult = GetEnvironmentVariable(pszVariableName, pszValue, 0);  //특정 변수, 특정변수 포인터주소 , 길이 
//																			//길이를 모르기 때문에 0 , 변수를 주면 알아서 길이 체크해서 리턴해줌
//
//	if (dwResult != 0)
//	{
//		DWORD size = dwResult * sizeof(TCHAR);
//		pszValue = (PTSTR)malloc(size);
//		GetEnvironmentVariable(pszVariableName, pszValue, size);
//		_tprintf(TEXT("%s=%s \n"), pszVariableName, pszValue);
//		free(pszValue);
//	}
//	else
//		_tprintf(TEXT("%s =<unknown value>\n"), pszVariableName);
//}
//
//int _tmain(int argc, TCHAR* argv[])
//{
//	PrintEnvironmentVariable(TEXT("JAVA_HOME"));
//
//	return 0;
//}