#pragma once
#include "framework.h"

class Game
{
public:
	Game();			 // ���� ������
	virtual ~Game(); // ���� �Ҹ���

	void Start(HINSTANCE hInstance, HWND hWnd);	// ���� ���� ó��
	void End();		// ���� ���� ó��
	void Input();	// ���� �Է�
	void Update();	// ���� ����
	void Render();	// ���� �׸���

private:
	HINSTANCE hInstance; // ���α׷� �ڵ�
	HWND hWnd; // ������ �ڵ�
	HDC hDC;

	float x = 0;
	float y = 0;
};



