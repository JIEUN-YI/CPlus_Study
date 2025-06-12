/*
#include "InputManager.h"
#include "framework.h"


void InputManager::Start()
{

}


void InputManager::End()
{

}

void InputManager::CheckInput()
{
	for (int key = 0; key < 255; key++)
	{
		prevKeys[key] = curKeys[key];
		curKeys[key] = GetAsyncKeyState(key) & 0x8000;
	}
}

bool InputManager::GetKey(int key)
{
	return prevKeys[key] == true && curKeys[key] == true; // ������ ��
}

bool InputManager::GetKeyDown(int key)
{
	return prevKeys[key] == false && curKeys[key] == true; // ������ ����
}

bool InputManager::GetKeyUp(int key)
{
	return prevKeys[key] == true && curKeys[key] == false; // ���� ����
}
*/