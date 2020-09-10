// Ex200907.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "Ex200907.h"
#include <time.h>
#include <iostream>
#define _PI 3.141592f

float degreeToRadian(float degree) {
    return _PI * degree / 180.0f;
}


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
    LoadStringW(hInstance, IDC_EX200907, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_EX200907));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_EX200907));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_EX200907);
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
      CW_USEDEFAULT, 0, 800, 600, nullptr, nullptr, hInstance, nullptr);

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
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
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
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...

            //MoveToEx(hdc, 10, 10, NULL);          //선의 시작지점 
            //LineTo(hdc, 200, 400);                //선을 그려주고 다른 한점을 나타낸다. 
            //LineTo(hdc, 400, 200);

            //화면 중앙 센터에 정삼각형을 그린다. 
            //반지름은 200픽셀이라고 한다. 
            //MoveToEx(hdc, 0+400, 0+300, NULL);
            //RECT rt;
            //GetClientRect(hWnd, &rt);
            //// 만약 윈도우 창의 크기가 바뀌어도 코드를 수정 할 필요가 없다. 
            //float PosX = rt.right / 2.0f, PosY = rt.bottom / 2.0f;
            //MoveToEx(hdc, 200 * cosf(degreeToRadian(-90.0f))+PosX, 200 * sinf(degreeToRadian(-90.0f))+PosY,NULL);
            //LineTo(hdc, 200 * cosf(degreeToRadian(-(90.0f+ 120.0f)))+ PosX, 200 * sinf(degreeToRadian(-210.0f))+ PosY);
            //LineTo(hdc, 200 * cosf(degreeToRadian(-330.0f))+ PosX, 200*sinf(degreeToRadian(-330.0f))+ PosY);
            //LineTo(hdc, 200 * cosf(degreeToRadian(-90.0f)) + PosX, 200 * sinf(degreeToRadian(-90.0f)) + PosY);
            //위에 코드도 반복문으로 가능 

            /*MoveToEx(hdc, 200 * cosf(degreeToRadian(0.0f)) + PosX, 200 * sinf(degreeToRadian(0.0f)) + PosY, NULL);

            int k = 6;
            for (size_t i = 1; i <= k; i++)
            {
                LineTo(hdc, 
                    200 * cosf(degreeToRadian( (360.0f / k)*i)) + PosX, 
                    200 * sinf(degreeToRadian( (360.0f / k)*i)) + PosY
                );
            }*/
            /*int lineNum = 3;
            for (size_t i = 1; i <= lineNum; i++)
            {
                LineTo(hdc,
                    200.0f * cosf(degreeToRadian(360.0f / lineNum * i)) + PosX,
                    200.0f * sinf(degreeToRadian(360.0f / lineNum * i)) + PosY
                    );
            }*/

            
            /*MoveToEx(hdc, 200 * cosf(degreeToRadian(0.0f)) + PosX, 200 * sinf(degreeToRadian(0.0f)) + PosY, NULL);
            for (int i = 0.0f; i < 360; i++)
            {
                LineTo(hdc, 200 * cosf(degreeToRadian(i)) + PosX, 200 * sinf(degreeToRadian(i)) + PosY);
            }*/


            //Rectangle(hdc, 100, 100, 200, 300);        // 좌 상 우 하
            //Ellipse(hdc, 200, 300, 400, 500);

            //주소가 리턴되는데 타입을 모른다. 보통 이런식으로 쓴다음에 밑에처럼 타입캐스팅해준다.
            /*void* func() {
                return
            }*/
            //메모리할당했을경우 1번이랑 2번이 있다. 근데 2번은 1번에 종속되어 있을 경우 반드시 2번부터 해제해주어야한다.  

            //HPEN MyPen, OldPen; 
            //MyPen = CreatePen(PS_SOLID, 5, RGB(0, 0, 255));     //펜type, 굵기 , 색
            //OldPen = (HPEN)SelectObject(hdc, MyPen);   //펜을 몇가지 사용 할 경우에 백업용     //타입을 맞춰주려고 타입캐스팅 한 것 

            //HBRUSH MyBrush, OldBrush;
            //MyBrush = CreateSolidBrush(RGB(255, 255, 0));
            //OldBrush = (HBRUSH)SelectObject(hdc, MyBrush);

            //Rectangle(hdc, 100, 200, 300, 400);

            ///*MoveToEx(hdc, 10, 10, NULL);
            //LineTo(hdc, 200, 400);*/

            //SelectObject(hdc, OldPen);         //
            //DeleteObject(MyPen);               //createpen하고 짝

            //SelectObject(hdc, OldBrush);        
            //DeleteObject(MyBrush);
        
           /* POINT pts[] = {
                {60,10}, {160,10}, {210,60}
            };
            Polyline(hdc, pts, 3);     */       // hdc,  pts의 주소, 개수 
            

            ////sin그래프 만들기
            //POINT pts[360];
            //#define NUM 360
            //for (int i = 0; i < NUM; i++)
            //{
            //   // pts[i] = { 10*(i)*0.0f +400 , 100* sinf(degreeToRadian( (i)+0.0f)) +300 };
            //    pts[i].x = (i)  + 400;
            //    pts[i].y = 100 * sinf(degreeToRadian(((360.0f/NUM)*i) )) + 300;
            //}
            //포인터로 하기
            int NUM = 360;
            POINT *pts = new POINT[NUM];
            //#define NUM 360
            
            for (int i = 0; i < NUM; i++)
            {
                // pts[i] = { 10*(i)*0.0f +400 , 100* sinf(degreeToRadian( (i)+0.0f)) +300 };
                pts[i].x = (i)+400;
                pts[i].y = 100 * sinf(degreeToRadian(((360.0f / NUM) * i))) + 300;
            }
            Polyline(hdc, pts, 360);
            //메모리 해제해주기 
            delete []pts;

            //답
            //
            /*POINT pts[12+1] = { 0, };
            Polyline(hdc, pts, 13);*/
            /*pts[0].x = -60; pts[0].y = 100*sinf(degreeToRadian(-180.0f));
            pts[1].x = -60; pts[0].y = sinf(degreeToRadian(-150.0f));
            pts[2].x = -60; pts[0].y = sinf(degreeToRadian(-120.0f));
            pts[3].x = -60; pts[0].y = sinf(degreeToRadian(-90.0f));
            pts[4].x = -60; pts[0].y = sinf(degreeToRadian(-60.0f));
            pts[5].x = -60; pts[0].y = sinf(degreeToRadian(-30.0f));
            ....*/
            /*for (int i = -6; i <= 6; i++) 
            {
                ptr[i + 6].x = i * 20 + 400;
                ptr[i + 6].y = sinf(degreeToRadian(i * 30) * 100) + 300;

            }*/


            /*POINT pts[5] = {
                {-180 + 400 , 100*sinf(degreeToRadian(-180)) + 300},
                {-90 + 400 , 100 * sinf(degreeToRadian(-90)) + 300},
                {0 + 400 , 100 * sinf(degreeToRadian(0)) + 300},
                {90 + 400 , 100 * sinf(degreeToRadian(90)) + 300},
                {180 + 400 , 100 * sinf(degreeToRadian(180)) + 300}

            };
            Polyline(hdc, pts, 5);*/
           

            EndPaint(hWnd, &ps);
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
