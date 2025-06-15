#include "Game.h"
#include "RenderManager.h"
#include "TimeManager.h"
#include "InputManager.h"

using namespace std;

float startX;
float startY;

Game::Game()
{

}

Game::~Game()
{

}

void Game::Start(HINSTANCE hInstance, HWND hWnd)
{
	// hDC = GetDC(hWnd); // â�� �׸� �׸���
	RENDER->Start(hWnd);
	TIME->Start();
}

void Game::End()
{
	// ReleaseDC(hWnd, hDC); // �׸��� ����
	RENDER->End();
	TIME->End();
}

void Game::Input()
{
	GMAE_INPUT->CheckInput();
}

bool isLeft = false;
void Game::Update()
{
	TIME->CheckTime(); // �ð� ����
	// �ڿ������� �̵�
	if (GMAE_INPUT->GetKey(VK_UP)) // vritual key
	{
		y -= 100 * DT;
	}
	if (GMAE_INPUT->GetKey(VK_DOWN))
	{
		y += 100 * DT;
	}	
	if (GMAE_INPUT->GetKey(VK_LEFT))
	{
		x -= 100 * DT;
	}	
	if (GMAE_INPUT->GetKey(VK_RIGHT))
	{
		x += 100 * DT;
	}

	/* Ű �Է¿� ���� ��ĭ�� �̵�
	if (GMAE_INPUT->GetKeyUp(VK_UP)) // vritual key
	{
		y -= 100;
	}
	if (GMAE_INPUT->GetKeyUp(VK_DOWN))
	{
		y += 100;
	}	
	if (GMAE_INPUT->GetKeyUp(VK_LEFT))
	{
		x -= 100;
	}	
	if (GMAE_INPUT->GetKeyUp(VK_RIGHT))
	{
		x += 100;
	}
	*/
	/* DeltaTime���� �̵�
	if (isLeft) {
		x -= 100 * DT;
		if (x < 0) {
			isLeft = false;
		}
	}
	else
	{
		x += 100 * DT;
		if (x > 500) {
			isLeft = true;
		}
	}
	*/

	/* �ð����� ���ϴ� ���� : ��ǻ���� ���ɿ� ���� �������� �޶���
	 *  Time.DeltaTime�� Ȱ���� �ʿ�
	if (isLeft) {
		x -= 0.1f;
		if (x < 0) {
			isLeft = false;
		}
	}
	else
	{
		x += 0.1f;
		if (x > 500) {
			isLeft = true;
		}
	}
	
	*/
	/*
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
	*/
	
}
        
void Game::Render()
{
	/*
	RENDER->BeginDraw();
	RENDER->Rect(x + 000, y + 000, x + 100, y + 100); // �簢�� �׸���
	wstring fpsText = L"FPS : " + to_wstring(FRAME);
	RENDER->Text(fpsText, 1000, 0); // ���� ����
	wstring dtText = L"DT : " + to_wstring(DT);
	RENDER->Text(dtText, 1000, 0); // ���� ����

	RENDER->EndDraw();
	*/
	/*
	// �ܻ��� ���ֱ� ���� ����� �׷��� ������, �״�� �����ϸ� �������� �͵� ���� ���̰� ��
	// => �����Ÿ� ���� = ��ŷ
	// �ذ� �� : ���� ���۸�
	// �� ���� ȭ���� ����Ͽ� �ٸ� ȭ�鿡 �׸� ��
	// ����� �����Ͽ� �ٿ��ֱ�
	// RenderManager::GetInstance()->Rectacgle(x, y, x + 100, y + 100);
	// RENDER->Rectacgle(x, y, x + 100, y + 100);*/
	/*
	RENDER->BeginDraw();

	RENDER->Rectacgle(x, y, x + 100, y + 100);
	RENDER->Rectacgle(x + 100, y + 100, x + 200, y + 200);
	RENDER->Rectacgle(x + 200, y + 200, x + 300, y + 300);

	RENDER->EndDraw();
	*/
	// Rectangle(hDC, 100, 100, 200, 200); // ��� �簢���� �׸��� ��
	// ��, ������ �ʴ� ��� �ܻ��� ����
	// Rectangle(hDC, x, y, x + 100, y + 100); // ��� �簢���� ��ġ�� �����Ͽ� �׸� => ������ �ǽð����� �׷����� ��. 
	// ���� ���۸� : �ܻ��� ���� �ʵ��� �ϴ� ���
	// RanderManager::GetInstance()->Text(); 
	// // �̱������� ��� ����
	// = RENDER->Text();

	RENDER->BeginDraw(); // �׸��� �� �۾�

	// �������쿡 ���ϴ� �׸� �׸���
	RENDER->Rect(x + 000, y + 000, x + 100, y + 100);
	wstring fpsText = L"FPS : " + to_wstring(FRAME);
	RENDER->Text(fpsText,1000,0);
	wstring dtText = L"FPS : " + to_wstring(DT);
	RENDER->Text(dtText, 1100, 0);

	RENDER->EndDraw(); // �׸��� �� �۾� - �����쿡 ����ϱ�

}