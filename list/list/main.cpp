// *** List_v0.2
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

struct List
{
	// List* front;
	int	Value;
	List* Back;
};

void AddObject(List* _Next, const int& _Value);
void Output(List* _Next);

void insert(List* _Next, const int& _Value, const int& _where);
void erase(List* _Next, const int& _where);

int main(void)
{
	List* NumberList = new List;

	NumberList->Value = 0;
	NumberList->Back = nullptr;

	for (int i = 0; i < 10; ++i)
	{
		// *** 10회 추가
		AddObject(NumberList, i * 10 + 10 );
	}

	// for (int i = 0; i < 10; ++i)
	Output(NumberList);

	return 0;
}

void AddObject(List* _Next, const int& _Value)
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
		AddObject(_Next->Back, _Value);
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

void insert(List* _Next, const int& _Value, const int& _where)
{

}

void erase(List* _Next, const int& _where)
{

}
