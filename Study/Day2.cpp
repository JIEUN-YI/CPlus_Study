/* Day2-example1
#include <iostream>
using namespace std;

// 객체 지향 프로그래밍 : C# VS C++

class Monster
{
public:
// 상속구조에서의 가상소멸자 : 필수 => 가비지컬렉터의 부재
// 생성자와 소멸자가 모두 필수적으로 필요함
	Monster() { cout << "몬스터 생성자"<<endl; }
	virtual ~Monster() { cout << "몬스터(가상)소멸자" << endl; }
public:
	void Move() { cout << "움직인다" << endl; }
};

// 상속
// public 상속 : 모든 기능 사용 가능
// private 상속 : 모든 기능을 안쓰게 상속 - 상속을 할 일이 거의 없지만, 존재 함
//		=> public을 꼭 표현 필요
class Slime : public Monster 
{
public:
	Slime() { cout << "슬라임 생성자" << endl; }
	virtual ~Slime() { cout << "슬라임 (가상)소멸자" << endl; }
public:
	void Split() { cout << "분열한다" << endl; }
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
		cout << "스킬 재사용 대기시간을 진행" << endl;
	}
};

class Fireball : public Skill 
{
public:
	// override 가 뒤에 붙음
	virtual void Execute() override
	{
		Skill::Execute();
		cout << "파이어볼 스킬 사용" << endl;
	}
};

int main()
{
	Skill* skill = new Fireball();
	//Fireball* fireball = dynamic_cast<Fireball*>(skill); // C#의 as = dynamic_cast
	skill->Execute();
}
*/

/* Day2-example3 추상함수
#include <iostream>
using namespace std;

class Item abstract
{
public:
	virtual void Use() = 0; // 순수 가상 함수
};

class Potion : public Item
{
public:
	virtual void Use() override
	{
		cout << "포션 사용" << endl;
	}
};

int main()
{

};
*/

/* Day2-example4 템플릿
// 템플릿 : 사용자가 지정한 자료형의 함수, 클래스를 컴파일 시간에 생성하는 구문
//		=> C# 의 제네릭으로 <T>를 사용
//		=> C++은 template<typename T>을 사용
// 
#include <iostream>
using namespace std;

// 템플릿 사용
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

// C#의 델리게이트 vs C++ 함수 포인터
// 함수 포인터 (Fucntion Pointer)
//	=> 함수의 주소를 저장하는 변수
//

int Add(int left, int right) { return left + right; }
int Sub(int left, int right) { return left - right; }

int main()
{
	int(*funcptr)(int, int); // 함수 포인터 선언

	funcptr = Add; // 함수의 주소를 설정
	cout << "함수포인터의 주소 : " << funcptr << endl;
	cout << funcptr(10, 20) << endl;

	funcptr = Sub;
	cout << "함수포인터의 주소 : " << funcptr << endl;
	cout << funcptr(10, 20) << endl;

	// 함수 포인터의 경우 함수를 삭제하지 않음으로 => delete는 안함
	// 단 nullptr은 해주는 것이 좋음
	funcptr = nullptr;
	cout << "함수포인터의 주소 : " << funcptr << endl;
};

*/

/* Day2-example6
#include <iostream>
using namespace std;

// 자료형 재정의
typedef int MyType;
typedef unsigned int uint;

int main()
{
	int value = 10;

	MyType value2 = 20; // 사실상 int와 동일함
	value = value2;

	uint value3 = 10; // 사실상 unsigned int
};
*/

/* Day2-example 7
#include <iostream>
using namespace std;

// 자료형 재정의 + 함수포인터 = 일종의 델리게이트처럼 사용
typedef int (*Func)(int, int);
int Add(int left, int right) { return left + right; }

int main()
{
	Func funcptr = nullptr;
	funcptr = Add;
	cout << funcptr(10, 20) << endl;
	cout << "주소값 : " << &funcptr << endl;

	funcptr = nullptr;
	cout << "주소값 : " << &funcptr << endl;
};
*/

/* Day2-example 8
#include <iostream>
using namespace std;

// 연산자 재정의
// 사용자정의 자료형이나 클래스의 연산자를 재정의하여 사용
// 

struct Point 
{
	int x;
	int y;
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}

	// 연산자 재정의
	// 반환형 operator연산자기호(매개변수목록){함수내용}
	Point operator-(Point other)
	{
		return Point(this->x - other.x, this->y - other.y);
	}
};

// 연산자 재정의
// 전역함수로 제작도 가능
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

/* Day2-example9 자료구조
// C#의 자료구조 : List, Dictionary, Stack, Queue, LinkedList => Generic
// C++의 자료구조 : STL(Standard Template Library)
//		=> vector, map(이진탐색트리기반), stack, queue

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
	// vector<int*> vec_h = vector<int*>(); // 힙영역
	
	// vector 명령어
	vec.push_back(1); // 뒤에 붙이기
	vec.push_back(2); // 뒤에 붙이기
	vec.pop_back(); // 뒤부터 지우기

	cout << vec[0] << endl; // 출력

	cout << "====================================================" << endl;

	// C# Dictionary = C++ map
	map<string, int> m = map<string, int>();
	m["name1"] = 10; // 추가
	m["name2"] = 20;
	m["name3"] = 30;

	cout << m["name1"] << endl; // 탐색
	cout << "====================================================" << endl;

	// C# Stack = C++ Stack
	stack<int> sta = stack<int>();
	sta.push(1); // 추가
	sta.push(2);
	
	sta.top(); // 위에서 부터 확인 = stack.peek()

	// 꺼내기 = stack.pop
	while (sta.size() > 0) {
		cout << sta.top() << endl;
		sta.pop();
	}

	cout << "====================================================" << endl;

	// C# Queue = C++ queue
	queue<int>q = queue<int>();
	q.push(1); // 추가 queue.Enqueue();
	q.push(2);
	q.push(3);
	
	q.front(); // queue.Peek();

	while (q.size() > 0) // 꺼내기 queue.Dequeue();
	{
		cout << q.front() << endl;
		q.pop();
	}
};
*/

/* Day2-example 10 : 수업 */
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>

using namespace std;

/*************************************************************************************
 * 반복기 (Iterator)
 *
 * 자료구조에 저장되어 있는 요소들을 반복하고 개별 요소에 대해 접근을 제공하는 객체
 * 반복기의 시작 범위는 첫번째 요소부터 마지막 요소의 다음 요소(빈공간)으로 정의
 * C++의 모든 자료구조는 반복기를 제공
 * C++의 알고리즘들은 반복기를 통해 구현하기 때문에 자료구조 종류와 무관하게 동작가능
 *************************************************************************************/


 // <반복기 사용용도>
 // 반복기를 사용하는 경우 자료구조종류와 내부구조에 무관하게 알고리즘을 적용가능
 // 
 //  알고리즘          반복기          자료구조
 // ┌────────┐                        ┌────────┐
 // │  정렬  │ ──┐                ┌─→ │ 리스트 │
 // └────────┘   │                │   └────────┘
 // ┌────────┐   │   ┌────────┐   │   ┌────────┐
 // │  반전  │ ──┼─→ │ 반복기 │ ──┼─→ │  트리  │
 // └────────┘   │   └────────┘   │   └────────┘
 //    ....      │                │      ....
 // ┌────────┐   │                │   ┌────────┐
 // │  탐색  │ ──┘                └─→ │ 테이블 │
 // └────────┘                        └────────┘


// <반복기>
// 자료구조에 저장되어 있는 요소들을 반복하고 개별 요소에 대해 접근을 제공하는 객체
//
//      반복기                     반복기                     반복기
//      ↓                          ↓                          ↓          
// ┌─┬─┬─┬─┬─┬─┬─┬─┐ ←이전─ ┌─┬─┬─┬─┬─┬─┬─┬─┐ ←이전─ ┌─┬─┬─┬─┬─┬─┬─┬─┐
// │1│2│3│4│5│6│7│8│        │1│2│3│4│5│6│7│8│        │1│2│3│4│5│6│7│8│
// └─┴─┴─┴─┴─┴─┴─┴─┘ ─다음→ └─┴─┴─┴─┴─┴─┴─┴─┘ ─다음→ └─┴─┴─┴─┴─┴─┴─┴─┘


// <반복기 범위>
// 반복기의 시작 범위는 첫번째 요소부터 마지막 요소의 다음 요소(빈공간)으로 정의
//
//  begin()             end()
//  ↓                   ↓              
// ┌─┬─┐  ┌─┬─┐  ┌─┬─┐
// │1│───→│2│───→│3│ │  X
// └─┴─┘  └─┴─┘  └─┴─┘


// <자료구조와 반복기>
// C++의 모든 자료구조는 반복기를 제공함
// 
// 순차리스트 반복기 : index를 하나씩 증가시키며 반복
//  반복기                       반복기                       반복기
//  ↓                            ↓                            ↓          
// ┌─┬─┬─┬─┬─┬─┬─┬─┬─┐        ┌─┬─┬─┬─┬─┬─┬─┬─┬─┐        ┌─┬─┬─┬─┬─┬─┬─┬─┬─┐
// │1│2│3│ │ │ │ │ │ │ -다음→ │1│2│3│ │ │ │ │ │ │ -다음→ │1│2│3│ │ │ │ │ │ │
// └─┴─┴─┴─┴─┴─┴─┴─┴─┘        └─┴─┴─┴─┴─┴─┴─┴─┴─┘        └─┴─┴─┴─┴─┴─┴─┴─┴─┘
//
// 연결리스트 반복기 : next Node를 이동하며 반복
//  반복기                            반복기                            반복기
//  ↓                                 ↓                                 ↓          
// ┌─┬─┐  ┌─┬─┐  ┌─┬─┐        ┌─┬─┐  ┌─┬─┐  ┌─┬─┐        ┌─┬─┐  ┌─┬─┐  ┌─┬─┐
// │1│───→│2│───→│3│ │ -다음→ │1│───→│2│───→│3│ │ -다음→ │1│───→│2│───→│3│ │
// └─┴─┘  └─┴─┘  └─┴─┘        └─┴─┘  └─┴─┘  └─┴─┘        └─┴─┘  └─┴─┘  └─┴─┘


// <반복기 사용방법>
// 반복기 객체를 자료구조에서 생성하여 자료구조의 데이터들을 확인가능
void main222()
{
	vector<int> v = vector<int>();
	list<int> l = list<int>();
	map<int, string> m = map<int, string>();
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
		l.push_back(i);
		m[i] = "데이터";
	}

	// 반복기
	vector<int>::iterator iter = v.begin();

	// ↓ begin()
	//┌─┬─┬─┬─┬─┬─┬─┬─┬─┬─┐
	//│0│1│2│3│4│5│6│7│8│9│
	//└─┴─┴─┴─┴─┴─┴─┴─┴─┴─┘

	// 반복기가 가리키는 데이터 확인
	cout << *iter << endl;


	//       ↓
	//┌─┬─┬─┬─┬─┬─┬─┬─┬─┬─┐
	//│0│1│2│3│4│5│6│7│8│9│
	//└─┴─┴─┴─┴─┴─┴─┴─┴─┴─┘
	// 반복기를 다음으로 이동
	iter++;
	iter++;
	iter++;

	cout << *iter << endl;


	//     ↓
	//┌─┬─┬─┬─┬─┬─┬─┬─┬─┬─┐
	//│0│1│2│3│4│5│6│7│8│9│
	//└─┴─┴─┴─┴─┴─┴─┴─┴─┴─┘
	// 반복기를 이전으로 이동
	iter--;

	cout << *iter << endl;

	// 모든 자료구조에 반복기를 통해서 동작을 가능하게 함
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

// C++ 표준 알고리즘
// 반복기를 사용하여 어떤 자료구조인지 무관하게 동작시킬 수 있는 기능
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

