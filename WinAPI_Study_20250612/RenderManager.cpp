#include "RenderManager.h"


/* 20250608
void RenderManager::Start(HWND hWnd)
{
	this->hWnd = hWnd;
	this->hDC = GetDC(hWnd);

	// 새로운 그림판 생성
	this->hBackDC = CreateCompatibleDC(hDC);
	this->hBitmap = CreateCompatibleBitmap(hDC, 2000, 1200);

	HBITMAP holdBitmap = (HBITMAP)(SelectObject(hBackDC, hBitmap));
	DeleteObject(holdBitmap);
}
void RenderManager::End()
{
	DeleteObject(hBackDC);
	DeleteObject(hBitmap);
	ReleaseDC(hWnd, hDC);
}
void RenderManager::BeginDraw()
{
	PatBlt(hBackDC, 0, 0, 2000, 1200, WHITENESS);
}
void RenderManager::EndDraw()
{
	BitBlt(hDC, 0, 0, 2000, 1200, hBackDC, 0, 0, SRCCOPY);
}
void RenderManager::Rectacgle(int startX, int startY, int endX, int endY)
{
	Rectangle(hBackDC, startX, startY, endX, endY);
}
*/
/* 20250612 */

void RenderManager::Start(HWND hWnd)
{
	this->hWnd;

	RECT rect;
	GetWindowRect(hWnd, &rect); // window의 사각형 크기를 가져오는 함수
	this->winSizeX = rect.right - rect.left;
	this->winSizeY = rect.bottom - rect.top;
	
	this->hDC = GetDC(hWnd);  // Get을 사용하여 원래의 그림판 가져오기
	this->hBackDC = CreateCompatibleDC(hDC); // hDC와 동일한 백버퍼 화면 생성

	// this->hBitmap = CreateCompatibleBitmap(hDC, 2000, 1200);
	this->hBitmap = CreateCompatibleBitmap(hDC, winSizeX, winSizeX);

	SelectObject(hBackDC, hBitmap); // 새로 제작한 그림판에 새로운 이미지 사용

	// HBITMAP hOldBitmap = (HBITMAP)(SelectObject(hBackDC, hBitmap));
	// DeleteObject(hOldBitmap);

	/*
	// 윈도우 화면 사이즈 확인
	RECT rect;
	GetWindowRect(hWnd, &rect);
	this->winSizeX = rect.right - rect.left;
	this->winSizeY = rect.bottom - rect.top;

	this->hDC = GetDC(hWnd);  // Get을 사용하여 가져오기
	this->hBackDC = CreateCompatibleDC(hDC); // hDC와 동일한 백버퍼 화면 생성
	this->hBitmap = CreateCompatibleBitmap(hDC, winSizeX, winSizeY);

	SelectObject(hBackDC, hBitmap);
	*/
}

/// <summary>
/// 끝날때에는 그림판을 지우기
/// </summary>
void RenderManager::End()
{
	DeleteObject(hBitmap);
	DeleteObject(hBackDC);
	ReleaseDC(hWnd, hDC);
}

/// <summary>
/// 백윈도우의 그림을 지우기
/// </summary>
void RenderManager::BeginDraw()
{
	PatBlt(hBackDC, 0, 0, winSizeX, winSizeY, WHITENESS); // 화면을 하얀색으로 칠하기
}

/// <summary>
/// 백윈도우의 그림을 프론트 윈도우에 출력
/// </summary>
void RenderManager::EndDraw()
{
	// hDC(보여줄 윈도우)에다가 처음 위치(0,0)부터 사이즈(winSizeX, winSizeY)만큼 hBackDC(복사할 윈도우)의 위치(0,0)부터 복사(SRCCOPY)
	BitBlt(hDC, 0, 0, winSizeX, winSizeY, hBackDC, 0, 0, SRCCOPY);
}

/// <summary>
/// 뒤에 있을 그림판에 사각형 그리기
/// </summary>
/// <param name="startX"></param>
/// <param name="startY"></param>
/// <param name="endX"></param>
/// <param name="endY"></param>
void RenderManager::Rect(float startX, float startY, float endX, float endY)
{
	Rectangle(hBackDC, startX, startY, endX, endY);
}

/// <summary>
/// 뒤에 있을 그림판에 글자 쓰기
/// </summary>
/// <param name="str"></param>
/// <param name="x"></param>
/// <param name="y"></param>
void RenderManager::Text(wstring str, float x, float y)
{
	// 백그림판(hBackDC)에 위치(x, y)에 문자 배열(str.c_str())로 사이즈(str.size())만큼 쓰기
	TextOutW(hBackDC, x, y, str.c_str(), str.size());
}

/*
void RenderManager::Rectacgle(int startX, int startY, int endX, int endY)
{
	Rectangle(hBackDC, startX, startY, endX, endY);
}
*/
/*
void RenderManager::Rect(float startX, float startY, float endX, float endY)
{
	Rectangle(hBackDC, startX, startY, endX, endY); // 사각형 그리기
}

void RenderManager::Text(wstring str, float x, float y)
{
	TextOutW(hBackDC, x, y, str.c_str(), str.size());
}
*/