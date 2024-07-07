/*
��¥ : 2024. 7. 7
�̸� : �輺��
���� : �̴ϼȶ������� �̿��� ������ ����
	���� p183 ~ 184

	const ������ ���������� �����ڵ� ����� ���ÿ� �ʱ�ȭ�� �̷����� �Ѵ�
	�̴ϼȶ������� �̿��ϸ� �����ڵ� ��������� ����� �� �ִ�

	�����ڸ� ��������� �����ϴ� ��찡 ���� ���� �ƴϴ�
*/

#include <iostream>

using namespace std;

class AAA
{

public:
	AAA()
	{

		cout << "empty object" << endl;
	}

	void ShowYourName()
	{

		cout << "I'm class AAA" << endl;
	}
};

class BBB
{

private:
	AAA& ref;
	const int& num;

public:
	BBB(AAA& r, const int& n)
		: ref(r), num(n)
	{ 
		
		// Empty constructor body 
	}

	void ShowYourName()
	{

		ref.ShowYourName();
		cout << "and" << endl;
		cout << "I ref num " << num << endl;
	}
};

int main(void)
{

	AAA obj1;
	BBB obj2(obj1, 20);
	obj2.ShowYourName();

	return 0;
}