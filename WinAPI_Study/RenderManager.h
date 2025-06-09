#pragma once
#include "Singleton.h"
#include "framework.h"

class RenderManager : public Singleton<RenderManager>// �׷��ִ� �۾��� ���� - �̱���
{
public:
	void Start(HWND hWnd);
	void End();

	void BeginDraw(); // ���ο� �׸��ǿ� �غ�
	void EndDraw(); // ���� ȭ������ ����

	void Rectacgle(int startX, int startY, int endX, int endY);

private:
	HWND hWnd;
	HDC hDC;
	HDC hBackDC;
	HBITMAP hBitmap;
};

#define RENDER RenderManager :: GetInstance()

