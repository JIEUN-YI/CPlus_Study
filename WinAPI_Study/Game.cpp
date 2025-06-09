#include "Game.h"
#include "RenderManager.h"

float startX;
float startY;

void Game::Start(HINSTANCE hInstance, HWND hWnd)
{
	this->hInstance = hInstance;
	this->hWnd = hWnd;
	RENDER->Start(hWnd);
}


void Game::End()
{
	RENDER->End();
}

void Game::Input()
{

}

void Game::Update()
{
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		x -= 0.1f;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		x += 0.1f;
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		y -= 0.1f;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		y += 0.1f;
	}
}

void Game::Render()
{
	// 잔상을 없애기 위해 지우고 그려야 하지만, 그대로 진행하면 지워지는 것도 눈에 보이게 됨
	// => 깜빡거림 현상 = 블링킹
	// 해결 법 : 더블 버퍼링
	// 두 개의 화면을 사용하여 다른 화면에 그린 후
	// 결과를 복사하여 붙여넣기
	// RenderManager::GetInstance()->Rectacgle(x, y, x + 100, y + 100);
	// RENDER->Rectacgle(x, y, x + 100, y + 100);
	RENDER->BeginDraw();

	RENDER->Rectacgle(x, y, x + 100, y + 100);
	RENDER->Rectacgle(x + 100, y + 100, x + 200, y + 200);
	RENDER->Rectacgle(x + 200, y + 200, x + 300, y + 300);

	RENDER->EndDraw();
	
	// Rectangle(hDC, x, y, x+100, y+100);
}
