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

	RECT rect;
	GetWindowRect(hWnd, &rect); // window�� �簢�� ũ�⸦ �������� �Լ�
	this->winSizeX = rect.right - rect.left;
	this->winSizeY = rect.bottom - rect.top;
	
	this->hDC = GetDC(hWnd);  // Get�� ����Ͽ� ������ �׸��� ��������
	this->hBackDC = CreateCompatibleDC(hDC); // hDC�� ������ ����� ȭ�� ����

	// this->hBitmap = CreateCompatibleBitmap(hDC, 2000, 1200);
	this->hBitmap = CreateCompatibleBitmap(hDC, winSizeX, winSizeX);

	SelectObject(hBackDC, hBitmap); // ���� ������ �׸��ǿ� ���ο� �̹��� ���

	// HBITMAP hOldBitmap = (HBITMAP)(SelectObject(hBackDC, hBitmap));
	// DeleteObject(hOldBitmap);

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

/// <summary>
/// ���������� �׸����� �����
/// </summary>
void RenderManager::End()
{
	DeleteObject(hBitmap);
	DeleteObject(hBackDC);
	ReleaseDC(hWnd, hDC);
}

/// <summary>
/// ���������� �׸��� �����
/// </summary>
void RenderManager::BeginDraw()
{
	PatBlt(hBackDC, 0, 0, winSizeX, winSizeY, WHITENESS); // ȭ���� �Ͼ������ ĥ�ϱ�
}

/// <summary>
/// ���������� �׸��� ����Ʈ �����쿡 ���
/// </summary>
void RenderManager::EndDraw()
{
	// hDC(������ ������)���ٰ� ó�� ��ġ(0,0)���� ������(winSizeX, winSizeY)��ŭ hBackDC(������ ������)�� ��ġ(0,0)���� ����(SRCCOPY)
	BitBlt(hDC, 0, 0, winSizeX, winSizeY, hBackDC, 0, 0, SRCCOPY);
}

/// <summary>
/// �ڿ� ���� �׸��ǿ� �簢�� �׸���
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
/// �ڿ� ���� �׸��ǿ� ���� ����
/// </summary>
/// <param name="str"></param>
/// <param name="x"></param>
/// <param name="y"></param>
void RenderManager::Text(wstring str, float x, float y)
{
	// ��׸���(hBackDC)�� ��ġ(x, y)�� ���� �迭(str.c_str())�� ������(str.size())��ŭ ����
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
	Rectangle(hBackDC, startX, startY, endX, endY); // �簢�� �׸���
}

void RenderManager::Text(wstring str, float x, float y)
{
	TextOutW(hBackDC, x, y, str.c_str(), str.size());
}
*/