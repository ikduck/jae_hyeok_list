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
	// List* front;
	int	Value;
	List* Back;
};

// erase에서 사용
// 구조체에 적어주면 필요없음
List* Front = nullptr;

// 전방선언과 같은 위치에 넣어두는게 매너임
void push_back(List* _Next, const int& _Value);

void insert(List* _Next, const int _Where, const int& _Value);
void erase(List* _Next, const int _Where);

void Output(List* _Next);

int main(void)
{
	List* NumberList = new List;

	NumberList->Value = 0;
	NumberList->Back = nullptr;

	for (int i = 0; i < 10; ++i)
	{
		// *** 10회 추가
		push_back(NumberList, i * 10 + 10 );
	}

	insert(NumberList, 2, 15);
	Output(NumberList);


	erase(NumberList, 2);
	// for (int i = 0; i < 10; ++i)
	Output(NumberList);

	return 0;
}

void push_back(List* _Next, const int& _Value)
{
	if (_Next->Back == nullptr)
	{
		List* Temp = new List;
		Temp->Value = _Value;
		Temp->Back = nullptr;

		_Next->Back = Temp;
	}
	else
	{
		push_back(_Next->Back, _Value);
	}
}

void insert(List* _Next, const int _Where, const int& _Value)
{
	if (_Where == 1)
	{
		List* Temp = new List;

		Temp->Value = _Value;
		Temp->Back = _Next->Back;

		_Next->Back = Temp;

	}
	else
	{
		insert(_Next->Back, _Where + (-1), _Value);
	}
}


void erase(List* _Next, const int _Where)
{
	// 안됨 왜안되는지 모르겟음....
	/*
	if (_Where == 1)
	{
		List* Temp = _Next;
		_Next = _Next->Back;

		delete Temp;
		Temp = nullptr;
	}
	*/
	
	if (_Where == 0)
	{
		// 됨 
		/*
		List* Temp = _Next->Back;
		_Next->Back = _Next->Back->Back;

		delete Temp;
		Temp = nullptr;
		*/
	
		Front->Back = _Next->Back;

		delete _Next;
		_Next = nullptr;
		
	}
	else
	{
		Front = _Next;
		erase(_Next->Back, _Where + (-1));
	}
}

void Output(List* _Next)
{
	// 출력 후 호출 하면 내림차순
	// 출력
	cout << _Next->Value << endl;

	// 호출
	if (_Next->Back != nullptr)
		Output(_Next->Back);

	// 호출 후 출력 하면 오름차순
	/*
	// 호출
	if (_Next->Back != nullptr)
		Output(_Next->Back);

	// 출력
	cout << _Next->Value << endl;
	*/
}