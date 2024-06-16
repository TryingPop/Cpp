/*
��¥ : 2023. 2. 15
�̸� : �輺��
���� : �̴ϼȶ�����
	�̴ϼȶ������� ����ϸ� ������ ���Ǵ� ����

	�̴ϼȶ������� �̿��ϸ� ����� ���ÿ� �ʱ�ȭ�� �̷����� ���·� ���̳ʸ� �ڵ尡 �����ȴ�

	�������� ��ü�κп��� ���Կ����� ���� �ʱ�ȭ�� �����ϸ�,
	����� �ʱ�ȭ�� ���� ������ ���忡�� �����ϴ� ���·� ���̳ʸ� �ڵ尡 �����ȴ�

	�׷��� �̴ϼȶ������� �̿��ؼ� �ʱ�ȭ�� �����ϸ�,
	�Լ��� ȣ��Ƚ���� ���� �� �־
	�׸��� �ʱ�ȭ�� ������ �ܼ�ȭ ��ų �� �־ �ణ�� ��������� ����� �� �ִ�
*/

#include <iostream>
using namespace std;

class AAA {

private:
	int num;

public:
	AAA(int n = 0)
		: num(n) { 

		cout << "AAA(int n = 0)" << endl;
	}

	AAA(const  AAA& ref)
		: num(ref.num) { 

		cout << "AAA(const AAA& ref)" << endl;
	}

	AAA& operator=(const AAA& ref) {

		num = ref.num;
		cout << "operator=(const AAA& ref)" << endl;
		return *this;
	}
};

class BBB {

private:
	AAA mem;

public:
	BBB(const AAA& ref) 
		: mem(ref) { }
};

class CCC {

private:
	AAA mem;

public:
	CCC(const AAA& ref) {

		mem = ref;
	}
};

int main(void)
{

	AAA obj1(12);	// AAA(int n = 0)
	cout << "*********************" << endl;

	BBB obj2(obj1);	// AAA(const AAA& ref)
					// ���� �����ڸ� ȣ��
	cout << "*********************" << endl;

	CCC obj3(obj1);	// AAA(int n = 0)
					// operator=(const AAA& ref)
	return 0;
}