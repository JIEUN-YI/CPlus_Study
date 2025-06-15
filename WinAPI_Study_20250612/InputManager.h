#pragma once
#include "Singleton.h"
class InputManager : public Singleton<InputManager>
{
public :
	void Start();
	void End();

	void CheckInput();	// Ű �Է� Ȯ��
	bool GetKey(int key); // Ű ���� int������ �޾�, Ű�� ������ �ִ� �� ���� Ȯ��
	bool GetKeyDown(int key); // Ű ���� int������ �޾�, Ű�� ���� ������ ���� Ȯ��
	bool GetKeyUp(int key); // Ű ���� int������ �޾�, Ű�� �� ���� ���� Ȯ��

private :
	bool prevKeys[255];	// ���� Ű �Է� ����
	bool curKeys[255];	// ���� Ű �Է� ����
};

#define GMAE_INPUT InputManager::GetInstance()

