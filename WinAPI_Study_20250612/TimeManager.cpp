#include "TimeManager.h"
#include <chrono>
#include "InputManager.h"

using namespace std;

void TimeManager::Start()
{
	fps = 1;
	deltaTime = 1;
	prevTime = chrono::high_resolution_clock::now();
	curTime = chrono::high_resolution_clock::now();
}

void TimeManager::End()
{

}

void TimeManager::CheckTime()
{
	// ���� �����ӿ��� ���� �����ӱ��� �ɸ� �ð��� ����
	curTime = chrono::high_resolution_clock::now();
	chrono::duration<float> delta = curTime - prevTime;

	deltaTime = delta.count();
	fps = 1 / deltaTime;

	prevTime = curTime;
}
