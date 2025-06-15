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
	// GAME_INPUT->CheckInput();
}
bool isLeft = false;
void Game::Update()
{
	/*
	TIME->CheckTime();

	if (GMAE_INPUT->GetKey(VK_UP))
	{
		y -= 300 * DT;
	}
	if (GMAE_INPUT->GetKey(VK_DOWN))
	{
		y += 300 * DT;
	}	
	if (GMAE_INPUT->GetKey(VK_LEFT))
	{
		x -= 300 * DT;
	}	
	if (GMAE_INPUT->GetKey(VK_RIGHT))
	{
		x += 300 * DT;
	}
	*/
	/*
	if (isLeft) {
		x -= 300*DT;
		if (x < 0) {
			isLeft = false;
		}
	}
	else
	{
		x += 300*DT;
		if (x > 500) {
			isLeft = true;
		}
	}
	*/
	/**/
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
	/*
	RENDER->BeginDraw();
	RENDER->Rect(x + 000, y + 000, x + 100, y + 100); // 사각형 그리기
	wstring fpsText = L"FPS : " + to_wstring(FRAME);
	RENDER->Text(fpsText, 1000, 0); // 글자 쓰기
	wstring dtText = L"DT : " + to_wstring(DT);
	RENDER->Text(dtText, 1000, 0); // 글자 쓰기

	RENDER->EndDraw();
	*/
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