#pragma once
// ��� ���Ͽ����� Ŭ������ �޼���� �����͸� ���� �ۼ�
//		=> ��� ������ ��ϸ� Ȯ���Ͽ� Ŭ������ ����� Ȯ�� ����
class Player
{
	// �Լ��� ������Ͽ��� �켱 ���� ��
	// ��Ŭ��->���� �۾� �� �����͸� or ctrl+.
	// Player.cpp���� �Լ� �ۼ�
public:
	void Jump();
	void Attack();

private:
	int jumpSpeed;
};

