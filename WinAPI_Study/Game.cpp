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
	// �ܻ��� ���ֱ� ���� ����� �׷��� ������, �״�� �����ϸ� �������� �͵� ���� ���̰� ��
	// => �����Ÿ� ���� = ��ŷ
	// �ذ� �� : ���� ���۸�
	// �� ���� ȭ���� ����Ͽ� �ٸ� ȭ�鿡 �׸� ��
	// ����� �����Ͽ� �ٿ��ֱ�
	// RenderManager::GetInstance()->Rectacgle(x, y, x + 100, y + 100);
	// RENDER->Rectacgle(x, y, x + 100, y + 100);
	RENDER->BeginDraw();

	RENDER->Rectacgle(x, y, x + 100, y + 100);
	RENDER->Rectacgle(x + 100, y + 100, x + 200, y + 200);
	RENDER->Rectacgle(x + 200, y + 200, x + 300, y + 300);

	RENDER->EndDraw();
	
	// Rectangle(hDC, x, y, x+100, y+100);
}
