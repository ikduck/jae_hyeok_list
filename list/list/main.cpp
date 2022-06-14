// *** List_v0.3
#include <iostream>

using namespace std;

// vector�� �߰� ������ �����
// ��ǻ�����״� �޸𸮸� �Ҵ��ϴ� �۾�, �Ҵ��Ѱ��� ����� ���� ���� ���� �۾���

// ��ǻ�ʹ� �ܼ��� �۾��� ������

// list ���� ����
/*
	list �߰� ������ �����ʰ� �ּҰ��� �̾ �����
	�پ��� ������Ʈ�� ��Ƴ��� ����Ҽ� �ִ�.
	
	�ܹ��� -> back() �ּҸ� ����
	����� -> front() back() �ּҰ� ������
*/

// �迭ó�� ���������� �ȵǱ� ������ ����Լ��� iterater�� ����ؼ� ���������� �ؾ��Ѵ�.

struct List
{
	// List* front;
	int	Value;
	List* Back;
};

// erase���� ���
// ����ü�� �����ָ� �ʿ����
List* Front = nullptr;

// ���漱��� ���� ��ġ�� �־�δ°� �ų���
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
		// *** 10ȸ �߰�
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
	// �ȵ� �־ȵǴ��� �𸣰���....
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
		// �� 
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
	// ��� �� ȣ�� �ϸ� ��������
	// ���
	cout << _Next->Value << endl;

	// ȣ��
	if (_Next->Back != nullptr)
		Output(_Next->Back);

	// ȣ�� �� ��� �ϸ� ��������
	/*
	// ȣ��
	if (_Next->Back != nullptr)
		Output(_Next->Back);

	// ���
	cout << _Next->Value << endl;
	*/
}