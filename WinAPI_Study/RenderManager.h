#pragma once
#include "Singleton.h"
#include "framework.h"

class RenderManager : public Singleton<RenderManager>// 그려주는 작업을 진행 - 싱글톤
{
public:
	void Start(HWND hWnd);
	void End();

	void BeginDraw(); // 새로운 그림판에 준비
	void EndDraw(); // 게임 화면으로 복사

	void Rectacgle(int startX, int startY, int endX, int endY);

private:
	HWND hWnd;
	HDC hDC;
	HDC hBackDC;
	HBITMAP hBitmap;
};

#define RENDER RenderManager :: GetInstance()

