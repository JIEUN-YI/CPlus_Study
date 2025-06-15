#pragma once
#include "Singleton.h"
#include <chrono>

using namespace std;

// Time.DeltaTime�� ���� ����� ���� ���� Ŭ���� ����
class TimeManager : public Singleton<TimeManager>
{
public :
	void Start();
	void End();

	void CheckTime();

private:
	int fps;				// Frame per Seconds : 1�ʴ� �׷��� ȭ�� ��
	float deltaTime;		// 1������ �� �ҿ�� �ð� = �����ð� - Unity���� ���� : ���� ���� ����ϴ� WINAPI

	chrono::high_resolution_clock::time_point prevTime; // ���� �ð�
	chrono::high_resolution_clock::time_point curTime;	// ���� �ð�

public :
	int GetFPS() { return fps; }
	float GetDT(){return deltaTime;}


};

#define TIME TimeManager::GetInstance()
#define FRAME TimeManager::GetInstance()->GetFPS()
#define DT TimeManager::GetInstance()->GetDT()

