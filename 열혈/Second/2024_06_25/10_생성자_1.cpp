/*
��¥ : 2024. 6. 25
�̸� : �輺��
���� : �������� ����
	���� p168 ~ 170

	��ü�� �����ϰ� ��ü�� ������� �ʱ�ȭ�� ��������
	InitMembers��� �̸��� �Լ��� �����ϰ� ȣ���Ͽ���

	���������� �������� private ���������� ��¿ �� ���� ���̴�
	�׷��� �̴� ���� �����Ѱ� �ƴϴ�

	�̷��� ������ �ذ����ִ°� �������̴�
	�����ڸ� �̿��ϸ� ��ü ������ ���ÿ� �ʱ�ȭ�� �� �ְ� �Ѵ�

	�����ڴ� Ŭ������ �̸��� �Լ��� �̸��� �����ϴ�
	��ȯ���� ����Ǿ� ���� ������, ������ ��ȯ���� �ʴ´�

	�̷��� ������ �Լ��� ������ ������(constructor)�� �Ѵ�
	�׸��� �����ڴ� ��ü ������ �� �ѹ� ȣ��ȴ�

	�����ڵ� �Լ��� �����̴� �����ε� �� �� �ְ�,
	�Ű������� ����Ʈ ���� ������ �� �ִ�
*/

#include <iostream>

using namespace std;

class SimpleClass
{

private:
	int num1;
	int num2;

public:
#if !first
	SimpleClass()
	{

		num1 = 0;
		num2 = 0;
	}

	SimpleClass(int n)
	{

		num1 = n;
		num2 = 0;
	}

	SimpleClass(int n1, int n2)
	{

		num1 = n1;
		num2 = n2;
	}
#else

	// �����ڸ� �������� ���� �߻��ϴ� ���� ������ ����
	// ���Ǻ� �������� �ߴ�
	SimpleClass(int n1 = 0, int n2 = 0)
	{

		num1 = n1;
		num2 = n2;
	}
#endif
	void ShowData() const
	{

		cout << num1 << ' ' << num2 << endl;
	}
};

int main(void)
{

	// 1��¥���� �Ұ�ȣ�� �ʿ����
	SimpleClass sc1;
	sc1.ShowData();

	SimpleClass sc2(100);
	sc2.ShowData();

	SimpleClass sc3(100, 200);
	sc3.ShowData();

	return 0;
}