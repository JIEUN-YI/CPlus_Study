#pragma once
#include "framework.h"

class Game
{
public:
	void Start(HINSTANCE hInstance, HWND hWnd);	// ���� ���� ó��
	void End();		// ���� ���� ó��
	void Input();	// ���� �Է�
	void Update();	// ���� ����
	void Render();	// ���� �׸���

private:
	HINSTANCE hInstance; // ���α׷� �ڵ�
	HWND hWnd; // ������ �ڵ�

	float x = 0;
	float y = 0;
};



