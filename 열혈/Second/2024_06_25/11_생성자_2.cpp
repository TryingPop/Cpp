/*
��¥ : 2024. 6. 25
�̸� : �輺��
���� : ������ 
	���� p171 ~ 173

	new Ű���带 �̿��� ��ü�� ����������
	�Ű������� ���� ��� �Ұ�ȣ�� �ᵵ�ǰ� �Ƚᵵ �ȴ�
	(class �̸�)* (���� �̸�) = new (class �̸�);
	(class �̸�)* (���� �̸�) = new (class �̸�)();

	�� �� ����Ѵ�
	MyClass* myClass = new MyClass;
	MyClass* myClass = new MyClass();
	�� �� �����ϴ�

	(class �̸�) (������)()�� �ȵǴ� ������ �Ʒ� �������� Ȯ���� �� �ִ�
	���� �Լ��� ���� ������ ���������� �������������������ε� ���� �����ϴ�
	�Ʒ��� Simple sc1()�� �Լ��� ���� ���� �ش��Ѵ�
	void�� �������� ȣ�⹮���� �����ع�����, �����Ϸ��� �̷��� ������ ������ ��,
	��ü���������� �Լ��� �������������� ������ �� ���� �ȴ�

	�׷��� (Ŭ���� �̸�) (���� �̸�)() ������ ��ü������ �ƴ�,
	�Լ��� �������𿡸� ���ȴ�
*/

#include <iostream>
using namespace std;

class SimpleClass
{

private:
	int num1;
	int num2;

public:
	SimpleClass(int n1 = 0, int n2 = 0)
	{

		num1 = n1;
		num2 = n2;
	}

	void ShowData() const
	{

		cout << num1 << ' ' << num2 << endl;
	}
};

int main(void)
{

	SimpleClass sc1();			// �Լ��� ���� ����
	SimpleClass mysc = sc1();
	mysc.ShowData();
	return 0;
}

SimpleClass sc1()
{

	SimpleClass sc(20, 30);
	return sc;
}