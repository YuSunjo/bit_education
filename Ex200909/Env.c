#include <stdio.h>
#include <tchar.h>	
#include <Windows.h>	
//#include <strsafe.h>	
#include <stdlib.h>	

//void GetEnv()
//{ 
//	PTSTR pEnvBlock = GetEnvironmentStrings();            
//	//ȯ��� ������ �����ͼ� ���ڿ� ������ �޸𸮿� ���� �� �� �����͸� ��ȯ
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
//	ZeroMemory(szName, MAX_PATH);          //�޸� 0���� �ʱ�ȭ
//	ZeroMemory(szValue, MAX_PATH);
//
//	while (pszCurrent != NULL)
//	{
//		if (*pszCurrent != TEXT('='))
//		{
//			pszPos = _tcschr(pszCurrent, TEXT('='));       //TEMP = sgsggs, '=' �� ��ġ ��������
//			pszPos++;
//			size_t cbNameLength = (size_t)pszPos - (size_t)pszCurrent - sizeof(TCHAR); //�̸��� ���� 
//			hr = StringCbCopyN(szName, MAX_PATH, pszCurrent, cbNameLength);   //�̸��κи� ���� 
//
//			if (FAILED(hr))
//				break;
//			hr = StringCbCopyN(szValue, MAX_PATH, pszPos, _tcslen(pszPos) + 1);   //���κи� ���� 
//
//			if (SUCCEEDED(hr))
//				_tprintf(TEXT("[%u] %s = %s\n"), current, szName, szValue);
//			else {
//				if (hr == STRSAFE_E_INSUFFICIENT_BUFFER)
//				{
//					//���ڿ��� �߷��� �״�� ��� 
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
//		//���ڿ� ������ �̵� 
//		while (*pszCurrent != TEXT('\0'))
//			pszCurrent++;
//
//		pszCurrent++;
//		if (*pszCurrent == TEXT('\0'))
//			break;
//
//	}
//	FreeEnvironmentStrings(pEnvBlock);     //ȯ��� ���� ���ڿ� �� ����
//}
//
//int _tmain(int argc, TCHAR* argv[])
//{
//	GetEnv();
//
//	return 0;
//}

//regedit�� ����Ǿ� �ִ� ȯ�溯�� �ִ� ȯ�溯������ �������� ��


//Ư���� ȯ�溯���� �ܾ���� �Լ� 
//void PrintEnvironmentVariable(PCTSTR pszVariableName)
//{
//	PTSTR pszValue = NULL;
//
//	DWORD dwResult = GetEnvironmentVariable(pszVariableName, pszValue, 0);  //Ư�� ����, Ư������ �������ּ� , ���� 
//																			//���̸� �𸣱� ������ 0 , ������ �ָ� �˾Ƽ� ���� üũ�ؼ� ��������
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