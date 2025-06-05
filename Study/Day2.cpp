/* Day2-example1
#include <iostream>
using namespace std;

// ��ü ���� ���α׷��� : C# VS C++

class Monster
{
public:
// ��ӱ��������� ����Ҹ��� : �ʼ� => �������÷����� ����
// �����ڿ� �Ҹ��ڰ� ��� �ʼ������� �ʿ���
	Monster() { cout << "���� ������"<<endl; }
	virtual ~Monster() { cout << "����(����)�Ҹ���" << endl; }
public:
	void Move() { cout << "�����δ�" << endl; }
};

// ���
// public ��� : ��� ��� ��� ����
// private ��� : ��� ����� �Ⱦ��� ��� - ����� �� ���� ���� ������, ���� ��
//		=> public�� �� ǥ�� �ʿ�
class Slime : public Monster 
{
public:
	Slime() { cout << "������ ������" << endl; }
	virtual ~Slime() { cout << "������ (����)�Ҹ���" << endl; }
public:
	void Split() { cout << "�п��Ѵ�" << endl; }
};

int main()
{
	Monster* slime = new Slime();
	delete slime;
}
*/

/* Day2-example2
#include <iostream>
using namespace std;

class Skill 
{
	virtual void Execute() 
	{
		cout << "��ų ���� ���ð��� ����" << endl;
	}
};

class Fireball : public Skill 
{
public:
	// override �� �ڿ� ����
	virtual void Execute() override
	{
		Skill::Execute();
		cout << "���̾ ��ų ���" << endl;
	}
};

int main()
{
	Skill* skill = new Fireball();
	//Fireball* fireball = dynamic_cast<Fireball*>(skill); // C#�� as = dynamic_cast
	skill->Execute();
}
*/

/* Day2-example3 �߻��Լ�
#include <iostream>
using namespace std;

class Item abstract
{
public:
	virtual void Use() = 0; // ���� ���� �Լ�
};

class Potion : public Item
{
public:
	virtual void Use() override
	{
		cout << "���� ���" << endl;
	}
};

int main()
{

};
*/

/* Day2-example4 ���ø�
// ���ø� : ����ڰ� ������ �ڷ����� �Լ�, Ŭ������ ������ �ð��� �����ϴ� ����
//		=> C# �� ���׸����� <T>�� ���
//		=> C++�� template<typename T>�� ���
// 
#include <iostream>
using namespace std;

// ���ø� ���
template<typename T>
void Swap(T& left, T& right)
{
	T temp = left;
	left = right;
	right = temp;
}

int main()
{
	
};
*/

/* Day2-example5
#include <iostream>
using namespace std;

// C#�� ��������Ʈ vs C++ �Լ� ������
// �Լ� ������ (Fucntion Pointer)
//	=> �Լ��� �ּҸ� �����ϴ� ����
//

int Add(int left, int right) { return left + right; }
int Sub(int left, int right) { return left - right; }

int main()
{
	int(*funcptr)(int, int); // �Լ� ������ ����

	funcptr = Add; // �Լ��� �ּҸ� ����
	cout << "�Լ��������� �ּ� : " << funcptr << endl;
	cout << funcptr(10, 20) << endl;

	funcptr = Sub;
	cout << "�Լ��������� �ּ� : " << funcptr << endl;
	cout << funcptr(10, 20) << endl;

	// �Լ� �������� ��� �Լ��� �������� �������� => delete�� ����
	// �� nullptr�� ���ִ� ���� ����
	funcptr = nullptr;
	cout << "�Լ��������� �ּ� : " << funcptr << endl;
};

*/

/* Day2-example6
#include <iostream>
using namespace std;

// �ڷ��� ������
typedef int MyType;
typedef unsigned int uint;

int main()
{
	int value = 10;

	MyType value2 = 20; // ��ǻ� int�� ������
	value = value2;

	uint value3 = 10; // ��ǻ� unsigned int
};
*/

/* Day2-example 7
#include <iostream>
using namespace std;

// �ڷ��� ������ + �Լ������� = ������ ��������Ʈó�� ���
typedef int (*Func)(int, int);
int Add(int left, int right) { return left + right; }

int main()
{
	Func funcptr = nullptr;
	funcptr = Add;
	cout << funcptr(10, 20) << endl;
	cout << "�ּҰ� : " << &funcptr << endl;

	funcptr = nullptr;
	cout << "�ּҰ� : " << &funcptr << endl;
};
*/

/* Day2-example 8
#include <iostream>
using namespace std;

// ������ ������
// ��������� �ڷ����̳� Ŭ������ �����ڸ� �������Ͽ� ���
// 

struct Point 
{
	int x;
	int y;
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}

	// ������ ������
	// ��ȯ�� operator�����ڱ�ȣ(�Ű��������){�Լ�����}
	Point operator-(Point other)
	{
		return Point(this->x - other.x, this->y - other.y);
	}
};

// ������ ������
// �����Լ��� ���۵� ����
Point operator+(Point left, Point right) 
{
	return Point(left.x + right.x, left.y + right.y);
}

int main()
{
	int value = 10 + 20;

	Point point1 = Point(2, 3);
	Point point2 = Point(3, 4);

	Point add = point1 + point2;
};
*/

/* Day2-example9 �ڷᱸ��
// C#�� �ڷᱸ�� : List, Dictionary, Stack, Queue, LinkedList => Generic
// C++�� �ڷᱸ�� : STL(Standard Template Library)
//		=> vector, map(����Ž��Ʈ�����), stack, queue

#include <iostream>
#include <vector> // C++ vector
#include <map> // C++ map
#include <stack> // C++ stack
#include <queue> // C++ queue

using namespace std;

int main()
{
	// C# List = C++ vector
	vector<int> vec = vector<int>();
	// vector<int*> vec_h = vector<int*>(); // ������
	
	// vector ��ɾ�
	vec.push_back(1); // �ڿ� ���̱�
	vec.push_back(2); // �ڿ� ���̱�
	vec.pop_back(); // �ں��� �����

	cout << vec[0] << endl; // ���

	cout << "====================================================" << endl;

	// C# Dictionary = C++ map
	map<string, int> m = map<string, int>();
	m["name1"] = 10; // �߰�
	m["name2"] = 20;
	m["name3"] = 30;

	cout << m["name1"] << endl; // Ž��
	cout << "====================================================" << endl;

	// C# Stack = C++ Stack
	stack<int> sta = stack<int>();
	sta.push(1); // �߰�
	sta.push(2);
	
	sta.top(); // ������ ���� Ȯ�� = stack.peek()

	// ������ = stack.pop
	while (sta.size() > 0) {
		cout << sta.top() << endl;
		sta.pop();
	}

	cout << "====================================================" << endl;

	// C# Queue = C++ queue
	queue<int>q = queue<int>();
	q.push(1); // �߰� queue.Enqueue();
	q.push(2);
	q.push(3);
	
	q.front(); // queue.Peek();

	while (q.size() > 0) // ������ queue.Dequeue();
	{
		cout << q.front() << endl;
		q.pop();
	}
};
*/

/* Day2-example 10 : ���� */
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>

using namespace std;

/*************************************************************************************
 * �ݺ��� (Iterator)
 *
 * �ڷᱸ���� ����Ǿ� �ִ� ��ҵ��� �ݺ��ϰ� ���� ��ҿ� ���� ������ �����ϴ� ��ü
 * �ݺ����� ���� ������ ù��° ��Һ��� ������ ����� ���� ���(�����)���� ����
 * C++�� ��� �ڷᱸ���� �ݺ��⸦ ����
 * C++�� �˰������ �ݺ��⸦ ���� �����ϱ� ������ �ڷᱸ�� ������ �����ϰ� ���۰���
 *************************************************************************************/


 // <�ݺ��� ���뵵>
 // �ݺ��⸦ ����ϴ� ��� �ڷᱸ�������� ���α����� �����ϰ� �˰����� ���밡��
 // 
 //  �˰���          �ݺ���          �ڷᱸ��
 // ��������������������                        ��������������������
 // ��  ����  �� ������                ������ �� ����Ʈ ��
 // ��������������������   ��                ��   ��������������������
 // ��������������������   ��   ��������������������   ��   ��������������������
 // ��  ����  �� ���������� �� �ݺ��� �� ���������� ��  Ʈ��  ��
 // ��������������������   ��   ��������������������   ��   ��������������������
 //    ....      ��                ��      ....
 // ��������������������   ��                ��   ��������������������
 // ��  Ž��  �� ������                ������ �� ���̺� ��
 // ��������������������                        ��������������������


// <�ݺ���>
// �ڷᱸ���� ����Ǿ� �ִ� ��ҵ��� �ݺ��ϰ� ���� ��ҿ� ���� ������ �����ϴ� ��ü
//
//      �ݺ���                     �ݺ���                     �ݺ���
//      ��                          ��                          ��          
// ���������������������������������� �������� ���������������������������������� �������� ����������������������������������
// ��1��2��3��4��5��6��7��8��        ��1��2��3��4��5��6��7��8��        ��1��2��3��4��5��6��7��8��
// ���������������������������������� �������� ���������������������������������� �������� ����������������������������������


// <�ݺ��� ����>
// �ݺ����� ���� ������ ù��° ��Һ��� ������ ����� ���� ���(�����)���� ����
//
//  begin()             end()
//  ��                   ��              
// ����������  ����������  ����������
// ��1���������榢2���������榢3�� ��  X
// ����������  ����������  ����������


// <�ڷᱸ���� �ݺ���>
// C++�� ��� �ڷᱸ���� �ݺ��⸦ ������
// 
// ��������Ʈ �ݺ��� : index�� �ϳ��� ������Ű�� �ݺ�
//  �ݺ���                       �ݺ���                       �ݺ���
//  ��                            ��                            ��          
// ��������������������������������������        ��������������������������������������        ��������������������������������������
// ��1��2��3�� �� �� �� �� �� �� -������ ��1��2��3�� �� �� �� �� �� �� -������ ��1��2��3�� �� �� �� �� �� ��
// ��������������������������������������        ��������������������������������������        ��������������������������������������
//
// ���Ḯ��Ʈ �ݺ��� : next Node�� �̵��ϸ� �ݺ�
//  �ݺ���                            �ݺ���                            �ݺ���
//  ��                                 ��                                 ��          
// ����������  ����������  ����������        ����������  ����������  ����������        ����������  ����������  ����������
// ��1���������榢2���������榢3�� �� -������ ��1���������榢2���������榢3�� �� -������ ��1���������榢2���������榢3�� ��
// ����������  ����������  ����������        ����������  ����������  ����������        ����������  ����������  ����������


// <�ݺ��� �����>
// �ݺ��� ��ü�� �ڷᱸ������ �����Ͽ� �ڷᱸ���� �����͵��� Ȯ�ΰ���
void main222()
{
	vector<int> v = vector<int>();
	list<int> l = list<int>();
	map<int, string> m = map<int, string>();
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
		l.push_back(i);
		m[i] = "������";
	}

	// �ݺ���
	vector<int>::iterator iter = v.begin();

	// �� begin()
	//������������������������������������������
	//��0��1��2��3��4��5��6��7��8��9��
	//������������������������������������������

	// �ݺ��Ⱑ ����Ű�� ������ Ȯ��
	cout << *iter << endl;


	//       ��
	//������������������������������������������
	//��0��1��2��3��4��5��6��7��8��9��
	//������������������������������������������
	// �ݺ��⸦ �������� �̵�
	iter++;
	iter++;
	iter++;

	cout << *iter << endl;


	//     ��
	//������������������������������������������
	//��0��1��2��3��4��5��6��7��8��9��
	//������������������������������������������
	// �ݺ��⸦ �������� �̵�
	iter--;

	cout << *iter << endl;

	// ��� �ڷᱸ���� �ݺ��⸦ ���ؼ� ������ �����ϰ� ��
	for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++)
	{
		cout << *iter << endl;
	}

	for (list<int>::iterator iter = l.begin(); iter != l.end(); iter++)
	{
		cout << *iter << endl;
	}

	for (map<int, string>::iterator iter = m.begin(); iter != m.end(); iter++)
	{
		cout << iter->first << ", " << iter->second << endl;
	}
}

// C++ ǥ�� �˰���
// �ݺ��⸦ ����Ͽ� � �ڷᱸ������ �����ϰ� ���۽�ų �� �ִ� ���
void main()
{
	vector<int> v = vector<int>();
	list<int> l = list<int>();

	for (int i = 0; i < 5; i++)
	{
		v.push_back(i);
		l.push_back(i);
	}

	reverse(v.begin(), v.end());
	reverse(l.begin(), l.end());

	stable_sort(v.begin(), v.end());
	stable_sort(l.begin(), l.end());

	fill(v.begin(), v.end(), 999);
	fill(l.begin(), l.end(), 999);
}

