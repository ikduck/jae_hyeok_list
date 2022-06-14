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
	// List* front; �� ������ ����� ������ �ܹ���
	List* Front;
	int	Value;
	List* Back;
};

// ���漱��� ���� ��ġ�� �־�δ°� �ų���
void push_back(List* _Current, const int& _Value);
void pop_back(List* _Current);

void insert(List* _Current, const int _Where, const int& _Value);
void erase(List* _Current, const int _Where);

void OutputA(List* _Current);
void OutputB(List* _Current);


// push_front pop_back �� Ŭ���������� �ٽø������ؼ� ����
// NumberList�� ���� ��ȯ���·� �����

List* End = nullptr;

int main(void)
{
	List* NumberList = new List;

	NumberList->Front = nullptr;
	NumberList->Value = 0;
	NumberList->Back = nullptr;

	for (int i = 0; i < 10; ++i)
	{
		// *** 10ȸ �߰�
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

		// ������ ���� ����Ű�� �ּҰ��� �����Ⱚ�̵Ǽ� ���������
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

// erase���� ���
// ����ü�� �����ָ� �ʿ������
// List* Front = nullptr;

void erase(List* _Current, const int _Where)
{
	// ���� ������ ������ ������ ���� �Լ����� 

	// �ȵ�
	/*
	if (_Where == 1)
	{
		// List* Temp = _Next;
		// _Next = _Next->Back;

		// ����ü���� �׷��� Temp->Back�� _Current->Back�� �ּҰ�(&)�� �޶� ����

		List* Temp = new list;  // �� ����ϸ� �ذ��Ҽ� ����

		// ���簪�� ������ ������ �߻�
		delete Temp;
		Temp = nullptr;
	}
	// ������ �ѵΰ����� �ƴϴ�!
	*/ 

	// ù ��°�� ������ ���� 
	if (_Where == 0)
	{
		// �� 
		/*
		List* Temp = _Next->Back;
		_Next->Back = _Next->Back->Back;

		delete Temp;
		Temp = nullptr;
		*/
	
		// Front->Back = _Current->Back;
		
		// ������ ��������
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
	// ��� �� ȣ�� �ϸ� ��������
	// ���
	cout << _Current->Value << endl;

	// ȣ��
	if (_Current->Back != nullptr)
		OutputA(_Current->Back);

	// ȣ�� �� ��� �ϸ� ��������
	/*
	// ȣ��
	if (_Current->Back != nullptr)
		Output(_Current->Back);

	// ���
	cout << _Current->Value << endl;
	*/
}

void OutputB(List* _Current)
{
	cout << _Current->Value << endl;

	if (_Current->Front != nullptr)
		OutputB(_Current->Front);

}