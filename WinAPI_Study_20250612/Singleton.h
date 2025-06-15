#pragma once

template <typename T> // 일반화로 제작
class Singleton
{
protected:
	Singleton() {};			 // 생성자
	virtual ~Singleton() {}; // 가상소멸자
public:
	static T* GetInstance() 
	{
		static T* instance = new T();
		return instance;
	}
};
