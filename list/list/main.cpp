// *** List_v0.2
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
		// *** 10ȸ �߰�
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

void insert(List* _Next, const int& _Value, const int& _where)
{

}

void erase(List* _Next, const int& _where)
{

}
