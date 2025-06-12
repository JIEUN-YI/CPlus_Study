#include "RenderManager.h"


/* 20250608
void RenderManager::Start(HWND hWnd)
{
	this->hWnd = hWnd;
	this->hDC = GetDC(hWnd);

	// ���ο� �׸��� ����
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
	
	this->hDC = GetDC(hWnd);  // Get�� ����Ͽ� ��������
	this->hBackDC = CreateCompatibleDC(hDC); // hDC�� ������ ����� ȭ�� ����

	this->hBitmap = CreateCompatibleBitmap(hDC, 2000, 1200);

	HBITMAP hOldBitmap = (HBITMAP)(SelectObject(hBackDC, hBitmap));
	DeleteObject(hOldBitmap);

	/*
	// ������ ȭ�� ������ Ȯ��
	RECT rect;
	GetWindowRect(hWnd, &rect);
	this->winSizeX = rect.right - rect.left;
	this->winSizeY = rect.bottom - rect.top;

	this->hDC = GetDC(hWnd);  // Get�� ����Ͽ� ��������
	this->hBackDC = CreateCompatibleDC(hDC); // hDC�� ������ ����� ȭ�� ����
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
	PatBlt(hBackDC, 0, 0, 2000, 1200, WHITENESS); // ȭ���� �Ͼ������ ĥ�ϱ�
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
	Rectangle(hBackDC, startX, startY, endX, endY); // �簢�� �׸���
}

void RenderManager::Text(wstring str, float x, float y)
{
	TextOutW(hBackDC, x, y, str.c_str(), str.size());
}
*/