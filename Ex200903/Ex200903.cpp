// Ex200903.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "Ex200903.h"


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
    LoadStringW(hInstance, IDC_EX200903, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_EX200903));    //리소스 파일 로딩

    MSG msg;



    // 기본 메시지 루프입니다:
    while (GetMessage(&msg, nullptr, 0, 0)) //이벤트가 일어나면 큐에 하나씩 쌓이고 GetMessage로 큐에 있는것을 빠져나오게한다.
    {
       

        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))        //단축키 적용하려는 함수 
        {
            TranslateMessage(&msg);                         //키보드를 누르거나 때면 WM_CHAR 메세지를 발생시킨다. 
            DispatchMessage(&msg);                          //WinProc에 던져준다. 
        }
    }

    return (int) msg.wParam;
    
}
//MFC -- blocking   -- realtime 으로 blocking 없애야한다. 


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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_EX200903));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_EX200903);
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

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      100, 200, 400, 300, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

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
int mx, my;
int count = 0;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_KEYDOWN:
    {
        WCHAR Str[32];
        wsprintf(Str, TEXT("KEYDOWN %d \n"), count++);
        OutputDebugString(Str);
    }
    break;
    case WM_KEYUP:
    {
        WCHAR Str[32];
        static int ct = 0;
        wsprintf(Str, TEXT("KEYUP: %d \n"), count++);
        OutputDebugString(Str);
    }
    break;
    case WM_CHAR:
    {
        WCHAR Str[32];
        static int ct = 0;
        wsprintf(Str, TEXT(" CHAR :%d \n"), count++);
        OutputDebugString(Str);
    }
    case WM_MOUSEMOVE: 
    {
        int x = LOWORD(lParam);
        int y = HIWORD(lParam);

        /*WCHAR str[32];
        wsprintf(str, TEXT("%d %d \n"), x, y);
        OutputDebugString(str);*/

        mx = x;
        my = y;
        //프로그래머가 특정 메세지를 발생 시킬 수 있다. --WM_PAINT  만약 없다면 화면 자동 갱신이 안일어남 -WM_PAINT가 발생하지 않아서 
        InvalidateRect(hWnd, NULL, TRUE);
    }
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            //RECT r;             //사가형의 lefttop, right bottom 
            //SIZE s;             //가로세로 길이  (width, height)(horizontal, vertical)
            //POINT p;            //좌표     //--> 이 3개 구조체는 꼭 알아두기!

            HDC hdc = BeginPaint(hWnd, &ps);       //포인터변수로 받는다. 
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...  --> 앞으로 해야 할 일 
            RECT rt;
            GetClientRect(hWnd, &rt);          //window창 좌상을 0,0
           /* RECT rt2;
            GetWindowRect(hWnd, &rt2); */     //모니터의 좌상을 0,0
            WCHAR str[32] = TEXT("호랑이");
            int len = wcslen(str);
            //strlen()  -- 아스키코드의 len  wcslen - 유니코드 
                 
            //DrawText(hdc, str, wcslen(str), &rt, DT_LEFT);         
            //DrawText(hdc, str, wcslen(str), &rt, DT_CENTER);
            //DrawText(hdc, str, wcslen(str), &rt, DT_RIGHT);
            ////
            ////DrawText(hdc, str, wcslen(str), &rt, DT_SINGLELINE | DT_VCENTER);//vertical 쓸때는 singleline이 필요
            ////// | 는 window에서 많이 사용 
            //DrawText(hdc, str, wcslen(str), &rt, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
            //DrawText(hdc, str, wcslen(str), &rt, DT_RIGHT | DT_SINGLELINE | DT_VCENTER);
            //DrawText(hdc, str, wcslen(str), &rt, DT_LEFT | DT_SINGLELINE | DT_VCENTER);

            //DrawText(hdc, str, wcslen(str), &rt, DT_SINGLELINE | DT_BOTTOM);
            //DrawText(hdc, str, wcslen(str), &rt, DT_SINGLELINE | DT_BOTTOM | DT_CENTER);
            //DrawText(hdc, str, wcslen(str), &rt, DT_SINGLELINE | DT_BOTTOM | DT_RIGHT);
            

            wsprintf(str, TEXT("%d %d"), mx,my);
            TextOut(hdc, mx, my, str, wcslen(str));



            //wsprintf(str, TEXT("MouseX:%d MouseY:%d"), mx, my);
            //TextOut(hdc, 100, 200, str, wcslen(str));
            //TextOut(hdc, mx, my, str, wcslen(str));
            


            //ZeroMemory(str, sizeof(str));          //MemSet,ZeroMemory -> 메모리 초기화
            //화면 깜박거림 -- doublebuffering 으로 해결 가능 (그래픽카드에 바로 그리지 않고 메로리에 그린후 그래픽카드에 복사)



            EndPaint(hWnd, &ps);
            //메모리 할당했으니 해제 해주는 함수 
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
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



//솔루션탐색기  -> 리소스 파일 -> ~.rc -> Menu -> IDC~~ ->  커맨드 UI 바꿔줌 
//                                     -> Accelerator -> IDC ~~ ->  커맨드 설정해줌