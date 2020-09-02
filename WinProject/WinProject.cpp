int APIENTRY wWinMain()
{
    MyRegisterClass(hInstance);                    //등록하기 위한 함수 
    if (!InitInstance (hInstance, nCmdShow))            
    {
        return FALSE;
    }
    while (GetMessage(&msg, nullptr, 0, 0))
    {  }
}
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    wcex.lpfnWndProc    = WndProc;
}
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd = CreateWindow();
   return TRUE;
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
        DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
    }
}
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{}
