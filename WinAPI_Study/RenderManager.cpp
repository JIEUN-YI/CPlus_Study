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
	
	this->hDC = GetDC(hWnd);  // Get을 사용하여 가져오기
	this->hBackDC = CreateCompatibleDC(hDC); // hDC와 동일한 백버퍼 화면 생성

	this->hBitmap = CreateCompatibleBitmap(hDC, 2000, 1200);

	HBITMAP hOldBitmap = (HBITMAP)(SelectObject(hBackDC, hBitmap));
	DeleteObject(hOldBitmap);

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

void RenderManager::End()
{
	DeleteObject(hBitmap);
	DeleteObject(hBackDC);
	ReleaseDC(hWnd, hDC);
}

void RenderManager::BeginDraw()
{
	PatBlt(hBackDC, 0, 0, 2000, 1200, WHITENESS); // 화면을 하얀색으로 칠하기
}

void RenderManager::EndDraw()
{
	BitBlt(hDC, 0, 0, 2000, 1200, hBackDC, 0, 0, SRCCOPY);
}


void RenderManager::Rectacgle(int startX, int startY, int endX, int endY)
{
	Rectangle(hBackDC, startX, startY, endX, endY);
}

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