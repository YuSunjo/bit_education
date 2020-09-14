// Bitmap.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "Bitmap.h"
#include "resource.h"

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

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_BITMAP, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDB_BITMAP1));

    MSG msg;

    // 기본 메시지 루프입니다:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_BITMAP));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_BITMAP);                //이것을 바꿔도 됨 IDR_MENU1 첫번째 
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

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
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   HWND hWnd;
   HMENU hMenu = LoadMenu(hInstance, MAKEINTRESOURCE(IDR_MENU1));          //menu 넣기 2번째 

   hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, nullptr, nullptr);   //뒤에서 세번째 hmenu

   if (!hWnd)
   {
      return FALSE;
   }
   SetMenu(hWnd, hMenu);                                                   //menu 넣기 3번째
   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

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
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
  //  //PAINTSTRUCT ps;
  //  HDC hdcDisplay, hdcClient;
  //  static int cxClient, cyClient;

  //  switch (message)
  //  {
  //  //case WM_MOVE:
  //  //{
  //  //    InvalidateRect(hWnd, 0, TRUE);
  //  //   return 0;
  //  //}
  //  case WM_MOUSEMOVE:
  //  {
  //      if (GetCapture() == hWnd)
  //      {
  //          POINT pt;
  //          GetCursorPos(&pt);
  //          hdcDisplay = CreateDC(TEXT("DISPLAY"), 0, 0, 0);
  //          hdcClient = GetDC(hWnd);
  //          StretchBlt(hdcClient, 0, 0, 100, 100, hdcDisplay, pt.x, pt.y, 100, 100, SRCCOPY);
  //          DeleteDC(hdcDisplay);
  //          ReleaseDC(hWnd, hdcClient);
  //      }
  //  }
  //  case WM_LBUTTONDOWN:
  //      SetCapture(hWnd);
  //      return 0;
  //  case WM_LBUTTONUP:
  //      if (GetCapture() == hWnd)
  //      {
  //          ReleaseCapture();
  //      }
  //      return 0;
  //  case WM_SIZE:
  //  {
  //      cxClient = LOWORD(lParam);
  //      cyClient = HIWORD(lParam);
  //  }
  //  return 0;
  ///*  case WM_ERASEBKGND:
  //      return TRUE;
  //  */
  //  case WM_COMMAND:
  //      {
  //          int wmId = LOWORD(wParam);
  //          // 메뉴 선택을 구문 분석합니다:
  //          switch (wmId)
  //          {
  //          case IDM_ABOUT:
  //              DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
  //              break;
  //          case IDM_EXIT:
  //              DestroyWindow(hWnd);
  //              break;
  //          default:
  //              return DefWindowProc(hWnd, message, wParam, lParam);
  //          }
  //      }
  //      break;
  //  /*case WM_PAINT:
  //      {
  //          hdcDisplay = CreateDC(TEXT("DISPLAY"), 0, 0, 0);
  //          hdcClient = BeginPaint(hWnd, &ps);
  //          BitBlt(hdcClient, 0, 0, cxClient, cyClient, hdcDisplay, 0, 0, SRCCOPY);
  //          DeleteDC(hdcDisplay);
  //          EndPaint(hWnd, &ps);
  //      return 0;
  //         
  // 
  //      }
  //      break;*/
  //  case WM_DESTROY:
  //      PostQuitMessage(0);
  //      break;
  //  default:
  //      return DefWindowProc(hWnd, message, wParam, lParam);
  //  }
  //  return 0;


    //switch (message)
    //{
    //case WM_LBUTTONDOWN:
    //{
    //    HDC hdc = GetDC(hWnd);

    //    HDC memDC = CreateCompatibleDC(hdc);                 //메모리상에 DC 구현 
    //    HBITMAP hBitmap = LoadBitmap(GetModuleHandle(0), MAKEINTRESOURCE(IDB_BITMAP1));

    //    BITMAP bm; 
    //    //bit map 정보 추출
    //    GetObject(hBitmap, sizeof(bm), &bm);
    //    //메모리 DC에 비트맵 선택
    //    SelectObject(memDC, hBitmap);
    //    //비트맵 출력
    //    TextOut(memDC, 5, 5, TEXT("LoadBitmap으로 출력"), 15);
    //    //메모리 DC -> 화면 DC
    //    POINTS pt = MAKEPOINTS(lParam);
    //    BitBlt(hdc, pt.x, pt.y, bm.bmWidth, bm.bmHeight, memDC, 0, 0, SRCCOPY);

    //    DeleteDC(memDC);
    //    ReleaseDC(hWnd, hdc);
    //    DeleteObject(hBitmap);
    //    
    //}
    //return 0;
    //case WM_RBUTTONDOWN:
    //{
    //    HDC hdc = GetDC(hWnd);
    //    HDC memDC = CreateCompatibleDC(hdc);
    //    HBITMAP hBitmap = (HBITMAP)LoadImage(0, TEXT("라이언.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
    //    //리로스에서 로드할 경우 

    //    BITMAP bm;
    //    GetObject(hBitmap, sizeof(bm), &bm);

    //    SelectObject(memDC, hBitmap);
    //    TextOut(memDC, 5, 5, TEXT("LoadIMAGE으로 출력"), 13);
    //    POINTS pt = MAKEPOINTS(lParam);
    //    BitBlt(hdc, pt.x, pt.y, bm.bmWidth, bm.bmHeight, memDC, 0, 0, SRCCOPY);

    //    DeleteDC(memDC);
    //    ReleaseDC(hWnd, hdc);
    //    DeleteObject(hBitmap);

    //}
    //return 0;
    //case WM_DESTROY:
    //    PostQuitMessage(0);
    //    return 0;
    //}
    //return DefWindowProc(hWnd, message, wParam, lParam);


    //동적으로 메뉴를 생기게 했다가 없앴다가 하는 코드 
    /*static HMENU hMenu = 0;
    switch (message)
    {
    case WM_LBUTTONDOWN:
        if (hMenu == 0)
        {
            hMenu = GetMenu(hWnd);
            SetMenu(hWnd, 0);
        }
        return 0;
    case WM_RBUTTONDOWN:
        if (hMenu != 0)
        {
            SetMenu(hWnd, hMenu);
            hMenu = 0;
        }
        return 0;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hWnd, message, wParam, lParam);*/


    //
    //static HMENU hMenu = 0;
    //switch (message)
    //{
    //case WM_LBUTTONDOWN:
    //{
    //    HMENU h = GetMenu(hWnd);
    //    HMENU hPopup = CreateMenu();
    //    
    //    AppendMenu(hPopup, MF_STRING, 5001, TEXT("Bbb"));
    //    AppendMenu(hPopup, MF_SEPARATOR, 5002, TEXT(""));
    //    AppendMenu(hPopup, MF_STRING | MF_POPUP, (UINT)hPopup, TEXT("추가메뉴"));
    //    //직접 추가한 경우에 메뉴바를 다시 그려야 한다. 
    //    DrawMenuBar(hWnd);
    //}
    //return 0;
    //case WM_RBUTTONDOWN:
    //{
    //    HMENU h = GetMenu(hWnd);
    //    HMENU hSub = GetSubMenu(h, 0);
    //    RemoveMenu(hSub, ID_MENU1_TEST2, MF_BYCOMMAND);
    //}
    //return 0;
    //case WM_DESTROY:
    //    PostQuitMessage(0);
    //    return 0;
    //}
    //return DefWindowProc(hWnd, message, wParam, lParam);


    
    // 메뉴 기능 추가
    static int submenu1 = ID_MENU1_TEST1;
    static int submenu2 = ID_MENU2_TEST4;
        
    switch (message)
    {
    case WM_INITMENUPOPUP:
        {
            HMENU hMenu = (HMENU)wParam;
            CheckMenuItem(hMenu, ID_MENU1_TEST1, submenu1 == ID_MENU1_TEST1 ? MF_CHECKED : MF_UNCHECKED);
            CheckMenuItem(hMenu, ID_MENU1_TEST2, submenu1 == ID_MENU1_TEST2 ? MF_CHECKED : MF_UNCHECKED);
            CheckMenuItem(hMenu, ID_MENU1_TEST3, submenu1 == ID_MENU1_TEST3 ? MF_CHECKED : MF_UNCHECKED);

            EnableMenuItem(hMenu, ID_MENU2_TEST4, submenu2 == ID_MENU2_TEST4 ? MF_GRAYED : MF_ENABLED);
            EnableMenuItem(hMenu, ID_MENU2_TEST5, submenu2 == ID_MENU2_TEST5 ? MF_GRAYED : MF_ENABLED);
            EnableMenuItem(hMenu, ID_MENU2_TEST6, submenu2 == ID_MENU2_TEST6 ? MF_GRAYED : MF_ENABLED);
        }
        return 0;
    case WM_COMMAND:
    {
        switch (LOWORD(wParam))
        {
        case ID_MENU1_TEST1:
        {
            SetWindowText(hWnd, TEXT("ID_MENU1_TEST1"));
            submenu1 = ID_MENU1_TEST1;
            break;
        }
        case ID_MENU1_TEST2:
        {
            SetWindowText(hWnd, TEXT("ID_MENU1_TEST2"));
            submenu1 = ID_MENU1_TEST2;
            break;
        }
        case ID_MENU1_TEST3:
        {
            SetWindowText(hWnd, TEXT("ID_MENU1_TEST3"));
            submenu1 = ID_MENU1_TEST3;
            break;
        }
        case ID_MENU2_TEST4:
        {
            SetWindowText(hWnd, TEXT("ID_MENU2_TEST4"));
            submenu2 = ID_MENU2_TEST4;
            break;
        }
        case ID_MENU2_TEST5:
        {
            SetWindowText(hWnd, TEXT("ID_MENU2_TEST5"));
            submenu2 = ID_MENU2_TEST5;
            break;
        }
        case ID_MENU2_TEST6:
        {
            SetWindowText(hWnd, TEXT("ID_MENU2_TEST6"));
            submenu2 = ID_MENU2_TEST6;
            break;
        }


        }

    }
    return 0;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
   
    return DefWindowProc(hWnd, message, wParam, lParam);

    
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



//메뉴 부착 방법
