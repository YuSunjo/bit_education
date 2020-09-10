// Ex0904.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "Ex0904.h"
#include <time.h>   


#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,                 // 응용 프로그램의 고유 아이디   중요!!
                     _In_opt_ HINSTANCE hPrevInstance,          //
                     _In_ LPWSTR    lpCmdLine,                  //
                     _In_ int       nCmdShow)                   // 윈도우의 초기 상태 지정 
{
    srand((unsigned)time(NULL));
    //UNREFERENCED_PARAMETER(hPrevInstance);
    //UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_EX0904, szWindowClass, MAX_LOADSTRING);

    struct ST {
        int size;
        int a;
        int b;
    };
    ST st;
    st.size = sizeof(ST);                 //자기 사이즈를 들고 다니는 경우가 많다.   --최적화 입장에서 ..



    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;          //WndProc 설정
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;          //
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_EX0904));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = CreateSolidBrush(RGB(0xcc, 0xcc, 0xcc)); //(HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_EX0904);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    RegisterClassExW(&wcex);

    //instance
    hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

    HWND hWnd = CreateWindowW(
        szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, 
        CW_USEDEFAULT, 0, 
        nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    ShowWindow(hWnd, SW_SHOWDEFAULT);                   //SW_SHOWDEFAULT  이것도 디버깅 하면 10 -> 즉 ncmdSHow는 default값
    UpdateWindow(hWnd);                                 //WM_PAINT를 띄워주는 역할 invalidate()(큐안에들어감)하고 비슷한데 updatewindow는 
                                                        //큐안에 안들어감  while문 안에 들어가기전에 로딩화면 초기화 해주는 역할 


    //HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_EX0904));

    MSG msg;

    // 기본 메시지 루프입니다:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        //if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))         
        {
            //TranslateMessage(&msg);         

            DispatchMessage(&msg);
        }
    }
    //bool done = FALSE;
    //while (!done)
    //{
    //    if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))                 //noneblocking 메세지 큐에 메세지전달
    //    {
    //        if (msg.message == WM_QUIT)                               //메세지가 종료였다면 true로 while문 빠져나감 
    //            done = TRUE;
    //        else {
    //            TranslateMessage(&msg);                               //
    //            DispatchMessage(&msg);
    //        }
    //    }
    //    else {

    //        //변수 갱신만 전문적으로 하는 함수 
    //        //그리기와 관련된 함수                   rendering 함수  ---> InvalidateRect() 함수  

    //        /*WCHAR Str[32];
    //        static int ct = 0;
    //        wsprintf(Str, TEXT("Realtime: %d\n"), ct++);
    //        OutputDebugString(Str);   */                   //2가지 루틴이있다. 
    //    }
    //}

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
//ATOM MyRegisterClass(HINSTANCE hInstance)
//{
//   
//}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
//BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
//{
//   
//}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
HWND hBtn1,hBtn2,hBtn3;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
    {
        //MessageBox(0, TEXT("WM_CREATE"), TEXT("WMCREATE"), MB_OK);
        hBtn1 = CreateWindowW(
            TEXT("BUTTON"),                               //예약어 COMBOBOX, EDIT 등의 종류 
            TEXT("호랑이1"),
            WS_VISIBLE | WS_CHILD | WS_BORDER,   // BS_DEFPUSHBUTTON,   --> 윈도우의 스타일 설정
            0, 0,                              //윈도우 위치 
            100, 50,                             //모양 크기    
            hWnd,                                //부모 
            (HMENU)1000,                         //어떤걸 눌렀는지 식별해주는 번호   --> wParam
            hInst,                               //인스턴스 전달 
            NULL);                               //

       hBtn2 = CreateWindowW(
            TEXT("BUTTON"), TEXT("호랑이2"),
            WS_VISIBLE | WS_CHILD | WS_BORDER,   
            0, 50, 100, 50,                                 
            hWnd,                               
            (HMENU)2000,                         
            hInst, NULL);

       hBtn3 = CreateWindowW(
            TEXT("BUTTON"), TEXT("호랑이3"),
            WS_VISIBLE | WS_CHILD | WS_BORDER,
            0, 100, 100, 50,
            hWnd,
            (HMENU)3000,
            hInst, NULL);
    }
    break;
    case WM_LBUTTONDOWN: 
    {
        MessageBox(hWnd, TEXT("hello"), TEXT("h"), MB_OK);
    }
    break;
    case WM_TIMER : 
    {
        switch (wParam) {
        case 123:
        {
            WCHAR Str[32];
            static int ct = 0;
            wsprintf(Str, TEXT("fisrt Timer: %d\n"), rand()%100);
            OutputDebugString(Str);
        }
        break;
        case 456: 
        {
            WCHAR Str[32];
            static int ct = 0;
            wsprintf(Str, TEXT("second Timer: %d\n"), ct++);
            OutputDebugString(Str);
        }
        break;
        }

    }
    break;
    case WM_COMMAND:
    {
        switch (wParam)
        {
        case 1000:
        {
            //ShowWindow(hBtn3, false);
            //EnableWindow(hBtn3, false);
            //SetWindowText(hBtn3, TEXT("고양이"));
            //MessageBox(hWnd, TEXT("id :1000 "), TEXT("h"), MB_OK);
            HANDLE hTimer = (HANDLE)SetTimer(hWnd, 123, 1000, NULL);          //1초는 1000ms -> WM_TIMER을 발생시킴 

        }
        break;
        case 2000:
        {
            //ShowWindow(hBtn3, true);
            EnableWindow(hBtn3, true);
            //SetWindowText(hBtn3, TEXT("독수리"));
            //MessageBox(hWnd, TEXT("id: 2000 "), TEXT("h"), MB_OK);
            //KillTimer(hWnd, 123);
            HANDLE hTimer = (HANDLE)SetTimer(hWnd, 456, 1000, NULL);
        }
        break;
        case 3000:
        {
            KillTimer(hWnd, 123);
            KillTimer(hWnd, 456);
        }
        break;
        }
    }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        //MessageBox(0, TEXT("WM_DESTORY"), TEXT("DESTROY"), MB_OK);                 //0은 부모가 없는 것  
        PostQuitMessage(0);                                               //destory 메세지 발생시킨후에 PeekMessage가quitMessage를 발생시킴 
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}


//1. 윈도우 생성  2. 메세지 처리 