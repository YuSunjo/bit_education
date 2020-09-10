//#include <windows.h>
//#include <tchar.h>	        //유니코드, 멀티바이트 코드 무엇을 쓰든지 확인해서 바꿔주는 메크로 
//
//#define MAX_LOADSTRING 100	
//
//TCHAR szTitle[MAX_LOADSTRING] = TEXT("Sample");
//TCHAR szWindowClass[MAX_LOADSTRING] = TEXT("Bit");
//
//HWND hWnd;
//
//void MakeEdit(void) {
//
//	//함수의 인자는 구글링해서 보기 
//	HWND testEdit = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("EDIT"), NULL,
//		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
//		10, 10, 200, 22, NULL, NULL, NULL, NULL);    //뒤에서 4번째가 문제 
//
//	
//
//	if (testEdit == NULL) {
//		LPTSTR p_error_message;
//		/*DWORD error_code = GetLastError();
//		TCHAR error_string[64];
//		wsprintf(error_string, TEXT("%d"), error_code);
//		MessageBox(hWnd, error_string, TEXT("ERROR"), MB_OK);*/
//
//		//GetLastError오류 코드 값에 대한 설명을 에러 코드를 문자열 형태로 저장(p_error_message에)
//		FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER |
//			FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, NULL, GetLastError(),
//			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT)
//			// MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US)
//			,(LPTSTR)&p_error_message, 0, NULL);
//
//		MessageBox(hWnd, p_error_message, TEXT("ERROR"), MB_OK);
//		free(p_error_message);
//	}
//	
//}
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
//{
//	switch (msg) {
//	case WM_LBUTTONDOWN:
//		MakeEdit();
//		return 0;
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		return 0;
//	}
//	return DefWindowProc(hwnd, msg, wParam, lParam);
//}
//
//ATOM MyRegisterClass(HINSTANCE hInstance)
//{
//	WNDCLASSEX wcex;
//	wcex.cbSize = sizeof(WNDCLASSEX);
//	wcex.style = CS_HREDRAW | CS_VREDRAW;
//	wcex.lpfnWndProc = WndProc;
//	wcex.cbClsExtra = 0;	
//	wcex.cbWndExtra = 0;
//	wcex.hInstance = hInstance;
//	wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
//	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
//	wcex.lpszMenuName = 0;
//	wcex.lpszClassName = szWindowClass;
//	wcex.hIconSm = 0;
//
//	return RegisterClassEx(&wcex);
//}
//
//HWND InitInstance(HINSTANCE hInstance, int nCmdShow)
//{
//	HWND hWnd;
//	hWnd = CreateWindowEx(0, szWindowClass, szTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0,
//		CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);
//
//	if (!hWnd)
//	{
//		return 0;
//	}
//
//	ShowWindow(hWnd, nCmdShow);
//	
//
//	return hWnd;
//}
//
//int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrev, LPTSTR lpCmdLine, int nShowCmd)
//{
//	MyRegisterClass(hInst);
//	HWND hwnd = InitInstance(hInst, nShowCmd);
//	if (hwnd == 0) {
//		return FALSE;
//	}
//	MSG Message;
//	while (GetMessage(&Message, NULL, 0, 0)) {
//		TranslateMessage(&Message);
//		DispatchMessage(&Message);
//
//	}
//	return 0;
//}
//


//#include <stdio.h>	
//#include <Windows.h>	
//#include <WinUser.h>	
//#include <tchar.h>
//
//int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrev, LPTSTR lpCmdLine, int nShowCmd)
//{
//	TCHAR temp[50];
//	TCHAR printString[500];
//	//LPTSTR ptr; 
//	//이제 이거 사용 
//	/*T메크로형
//		LPTSTR = LPSTR = char*
//		LPCTSTR = LPCSTR = const char**/
//
//
//
//	wsprintf(temp, TEXT("HELLO\n"));        //L"dasdf"  -- 유니코드 
//	CharLower(temp);
//	wsprintf(printString, temp);
//	wsprintf(temp, TEXT("HELLO\n"));
//	CharUpper(temp);
//	_tcscat(printString, temp);                  //유니코드 환경 - wcscat 
//
//	MessageBox(0, printString, TEXT("알림"), MB_OK);
//
//	return 0;
//}