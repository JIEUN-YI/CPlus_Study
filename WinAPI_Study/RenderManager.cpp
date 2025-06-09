#include "RenderManager.h"
#include "framework.h"

void RenderManager::Start(HWND hWnd)
{
	this->hWnd = hWnd;
	this->hDC = hDC;

	// 货肺款 弊覆魄 积己
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