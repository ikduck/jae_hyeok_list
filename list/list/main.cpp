// *** List_v0.3
#include <iostream>

using namespace std;

// vector은 추가 삭제가 힘들다
// 컴퓨터한테는 메모리를 할당하는 작업, 할당한것을 지우는 것이 제일 힘든 작업임

// 컴퓨터는 단순한 작업만 좋아함

// list 사전 설명
/*
	list 추가 삭제를 하지않고 주소값을 이어서 사용함
	다양한 오브젝트를 담아놓고 사용할수 있다.
	
	단방향 -> back() 주소만 있음
	양방향 -> front() back() 주소가 다있음
*/

// 배열처럼 직접접근이 안되기 때문에 재귀함수나 iterater을 사용해서 간접접근을 해야한다.

struct List
{
	// List* front; 가 있으면 양방향 없으면 단방향
	List* Front;
	int	Value;
	List* Back;
};

// 전방선언과 같은 위치에 넣어두는게 매너임
void push_back(List* _Current, const int& _Value);
void pop_back(List* _Current);

void insert(List* _Current, const int _Where, const int& _Value);
void erase(List* _Current, const int _Where);

void OutputA(List* _Current);
void OutputB(List* _Current);


// push_front pop_back 은 클래스구조로 다시만들어야해서 안함
// NumberList의 값을 반환형태로 줘야함

List* End = nullptr;

int main(void)
{
	List* NumberList = new List;

	NumberList->Front = nullptr;
	NumberList->Value = 0;
	NumberList->Back = nullptr;

	for (int i = 0; i < 10; ++i)
	{
		// *** 10회 추가
		push_back(NumberList, i * 10 + 10 );
	}

	insert(NumberList, 2, 15);
	OutputA(NumberList);


	erase(NumberList, 2);
	// for (int i = 0; i < 10; ++i)
	OutputA(NumberList);

	system("pause");
	system("cls");

	OutputB(End);

	pop_back(NumberList);
	OutputA(NumberList);

	return 0;
}

void push_back(List* _Current, const int& _Value)
{
	if (_Current->Back == nullptr)
	{
		List* Temp = new List;
		
		Temp->Front = _Current;
		Temp->Value = _Value;
		Temp->Back = nullptr;

		_Current->Back = Temp;

		End = Temp;
	}
	else
	{
		push_back(_Current->Back, _Value);
	}
}

void pop_back(List* _Current)
{
	if (_Current->Back == nullptr)
	{
		End = _Current->Front;

		// 마지막 값을 가리키던 주소값이 쓰레기값이되서 없애줘야함
		_Current->Front->Back = nullptr;

		delete _Current;
		_Current = nullptr;

	}
	else
	{
		pop_back(_Current->Back);
	}
}

void insert(List* _Current, const int _Where, const int& _Value)
{
	if (_Where == 1)
	{
		List* Temp = new List;

		Temp->Front = _Current;
		Temp->Value = _Value;
		Temp->Back = _Current->Back;

		_Current->Back = Temp;

	}
	else
	{
		insert(_Current->Back, _Where + (-1), _Value);
	}
}

// erase에서 사용
// 구조체에 적어주면 필요없어짐
// List* Front = nullptr;

void erase(List* _Current, const int _Where)
{
	// 스택 구조상 문제가 터지면 이전 함수에서 

	// 안됨
	/*
	if (_Where == 1)
	{
		// List* Temp = _Next;
		// _Next = _Next->Back;

		// 구조체여서 그런지 Temp->Back과 _Current->Back의 주소값(&)이 달라서 터짐

		List* Temp = new list;  // 를 사용하면 해결할수 있음

		// 현재값을 지워서 문제가 발생
		delete Temp;
		Temp = nullptr;
	}
	// 문제가 한두가지가 아니다!
	*/ 

	// 첫 번째와 마지막 값을 
	if (_Where == 0)
	{
		// 됨 
		/*
		List* Temp = _Next->Back;
		_Next->Back = _Next->Back->Back;

		delete Temp;
		Temp = nullptr;
		*/
	
		// Front->Back = _Current->Back;
		
		// 순서에 문제없음
		_Current->Back->Front = _Current->Front;
		_Current->Front->Back = _Current->Back;

		delete _Current;
		_Current = nullptr;
		
	}
	else
	{
		// Front = _Current;
		erase(_Current->Back, _Where + (-1));
	}
}

void OutputA(List* _Current)
{
	// 출력 후 호출 하면 내림차순
	// 출력
	cout << _Current->Value << endl;

	// 호출
	if (_Current->Back != nullptr)
		OutputA(_Current->Back);

	// 호출 후 출력 하면 오름차순
	/*
	// 호출
	if (_Current->Back != nullptr)
		Output(_Current->Back);

	// 출력
	cout << _Current->Value << endl;
	*/
}

void OutputB(List* _Current)
{
	cout << _Current->Value << endl;

	if (_Current->Front != nullptr)
		OutputB(_Current->Front);

}