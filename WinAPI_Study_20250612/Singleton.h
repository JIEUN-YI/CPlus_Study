#pragma once

template <typename T> // �Ϲ�ȭ�� ����
class Singleton
{
protected:
	Singleton() {};			 // ������
	virtual ~Singleton() {}; // ����Ҹ���
public:
	static T* GetInstance() 
	{
		static T* instance = new T();
		return instance;
	}
};
