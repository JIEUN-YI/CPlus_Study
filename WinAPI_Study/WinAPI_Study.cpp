// WinAPI_Study.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h" // WinAIP에서 필요로 하는 추가 기능들
#include "WinAPI_Study.h" // Win AIP에 기능 포함
// 게임 추가
#include "Game.h"

#define MAX_LOADSTRING 100 // 글자 수 제한 = 타이틀과 윈도우 글자수 최대 100 글자

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
HWND hWnd;                                      // 윈도우 인스턴스 핸들
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

/// <summary>
/// main() 역할
/// </summary>
/// <param name="hInstance"> 프로그램의 핸들(= 모든 대상을 다루기 위한 ID값) </param>
/// <param name="hPrevInstance"> 이전에 실행된 프로그램의 핸들 </param>
/// <param name="lpCmdLine"> 프로그램 시작 시 주어지는 추가 정보 </param>
/// <param name="nCmdShow"></param>
/// <returns></returns>
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance, // 사용x
                     _In_ LPWSTR    lpCmdLine, // 사용x
                     _In_ int       nCmdShow)
{
    // 더 이상 사용하지 않는다는 의미의 코드
    // 사용하지 않는 매개 변수 정의 : 기존의 (구)프로그램을 지원하기위해 그대로 둔 경우
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    // 리소스의 String Table에서 ID(IDS_APP_TITLE)에 맞는 문자열 로딩
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING); 
    LoadStringW(hInstance, IDC_WINAPISTUDY, szWindowClass, MAX_LOADSTRING); 
    MyRegisterClass(hInstance); // 윈도우 설정

    // 애플리케이션 초기화를 수행합니다: 윈도우 창 생성
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    // 단축키 목록 불러오기 IDC_WINAPISTUDY를 리소스 뷰에서 확인 가능
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINAPISTUDY));
    /*
    // 기본 메시지 루프입니다:
    // 게임으로 제작하기 부적합
    //  1. 그리기 작업이 실시간으로 진행 x
    //  2. 누르고 있는 경우 바로 반응해서 그려야하는데 그려지지 않음
    //  => 동시 입력이 아님 / 키보드의 입력을 기다리는 방식

    while (GetMessage(&msg, nullptr, 0, 0)) // 메세지가 끝날 때까지 반복하다가 끝나는 방식
    {
        // TranslateAccelerator() 단축키를 사용하는지를 확인
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) // 단축키가 없다면 메세지 처리
        {
            // 큐와 유사하게 사용
            TranslateMessage(&msg); // 메세지를 꺼내고
            DispatchMessage(&msg); // 메세지를 삭제
    }
    */
    Game game;
    game.Start(hInst, hWnd);
    MSG msg;
    while (true) // 메세지가 끝날 때까지 반복하다가 끝나는 방식
    {
        // 메세지가 없으면 게임처리, 있으면 메세지 처리
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))// 메세지가 있으면
        {
            if (msg.message == WM_QUIT) break;

            // TranslateAccelerator() 단축키를 사용하는지를 확인
            if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) // 단축키가 없다면 메세지 처리
            {
                // 큐와 유사하게 사용
                TranslateMessage(&msg); // 메세지를 꺼내고
                DispatchMessage(&msg); // 메세지를 삭제
            }
        }
        else
        {
            // 메세지가 없으면
            game.Input();
            game.Update();
            game.Render();
        }
    }
    game.End();
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

    wcex.style          = CS_HREDRAW | CS_VREDRAW;  // 클래스의 스타일
    wcex.lpfnWndProc    = WndProc;                  // 메세지를 받는 함수 지정
    wcex.cbClsExtra     = 0;                        // 
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;                // 윈도우 클래스에 인스턴스 할당
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINAPISTUDY)); // 프로그램 아이콘
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));  // 프로그램 작은사이즈 아이콘
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);                        // 마우스 커서 아이콘
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);                              // 배경 색상
    wcex.lpszMenuName = nullptr; // MAKEINTRESOURCEW(IDC_WINAPISTUDY);              메뉴 설정
    wcex.lpszClassName  = szWindowClass;                                         // 

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

   HWND hWnd 
       = CreateWindowW(         // 윈도우 창 제작
           szWindowClass,       // 윈도우 클래스 이름
           szTitle,             // 윈도우 타이틀 이름
           WS_OVERLAPPEDWINDOW, // 윈도우 스타일 WhinUser.h에서 확인해서 명령어 추가가능
           // 윈도우 창의 크기
           CW_USEDEFAULT,       // 윈도우 시작 X 위치
           0,                   // 윈도우 시작 Y 위치
           CW_USEDEFAULT,       // 윈도우 가로 크기
           0,                   // 윈도우 세로 크기
           nullptr,             // 부모 윈도우 창
           nullptr,             // 메뉴 핸들
           hInstance,           // 프로그램 핸들
           nullptr);            

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow); // 창을 보여주고
   UpdateWindow(hWnd); // 내용을 업데이트

   return TRUE;
}

/* 마우스를 이용하여 선 그리기 위한 변수
int startX; // 시작 X, Y
int startY;
int endX; // 종료 X, Y
int endY;

bool isDrag; // 드래그 여부
*/
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
/// <summary>
/// 
/// </summary>
/// <param name="hWnd"> 메세지가 어느 윈도우 창이 선택됐는지 구분</param>
/// <param name="message"> 메세지의 종류 </param>
/// <param name="wParam"> 메세지의 추가 정보1 </param>
/// <param name="lParam"> 메세지의 추가 정보2 </param>
/// <returns></returns>
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
        /* 마우스를 이용하여 사각형 그리기 위한 클릭 시
    case WM_LBUTTONDOWN: // 왼쪽 마우스 버튼 클릭 시
        // lParam = 총 8자리
        startX = LOWORD(lParam); // 뒤의 네자리로 x좌표
        startY = HIWORD(lParam); // 앞의 네자리로 y좌표
        InvalidateRect(hWnd, nullptr, false); // 클릭하면 윈도우를 다시 그리기 
        // false = 안지우고 다시 그리기 - true = 지우고 다시 그리기
        break;
        */
        /* 키보드를 이용하여 사각형 그리기 위한 클릭 시
        // 윈도우에서는 위에서부터 그리기 시작 = 높이(y) 반전
    case WM_KEYDOWN: // 키를 눌렀을 때 - 키 입력
        switch (wParam) // 버튼 종류에 따라 움직이는 범위를 수정가능
        {
        case VK_LEFT:
        case 'A':
        case 'a':
            startX -= 10;
            break;
        case VK_RIGHT:
        case 'D':
        case 'd':
            startX += 10;
            break;
        case VK_UP:
        case 'W':
        case 'w':
            startY -= 10;
            break;
        case VK_DOWN:
        case 'S':
        case 's':
            startY += 10;
            break;
        }
        InvalidateRect(hWnd, nullptr, true); // 클릭하면 윈도우를 다시 그리기 
        break;
        */
        /* 마우스 드래그로 그리기
    case WM_LBUTTONDOWN:
        isDrag = true; // 드래그 변수를 사용
        startX = LOWORD(lParam); // 위치 지정
        startY = HIWORD(lParam);
        endX = LOWORD(lParam);
        endY = HIWORD(lParam);
        break;
    case WM_MOUSEMOVE: // 마우스 움직임
        if (isDrag) // 드래그 중 일때 
        {
            endX = LOWORD(lParam); // 끝점의 위치를 변동하며
            endY = HIWORD(lParam);
            InvalidateRect(hWnd, nullptr, true); // 클릭하면 윈도우를 다시 그리기 
        }
        break;
    case WM_LBUTTONUP:
        isDrag = false; // 마우스를 떼면 드래그 중지
        break;
        */
    case WM_PAINT: // 창에 그리기
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps); // 일종의 그림판
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            /*
            Rectangle(hdc, 100, 100, 200, 200); // 픽셀로 (위치)위-아래 (크기)왼쪽-오른쪽
            TextOutW(hdc, 0, 0, L"안녕하세요", 5); // 한글 표시 시 L 필요
            */
            /* 기본 선 그러짐
            MoveToEx(hdc, 400, 100, nullptr); // 선의 시작위치
            LineTo(hdc, 0, 0); // 선을 그리기
            */
            /* 마우스로 클릭으로 사각형그리기 
            Rectangle(hdc, startX, startY, startX + 100, startY + 100);
            */
            /* 마우스 드래그앤 드롭으로 그리기 
            Rectangle(hdc, startX, startY, endX, endY);*/
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY: // 창 종료
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
