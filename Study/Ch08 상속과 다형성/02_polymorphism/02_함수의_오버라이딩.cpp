/*
��¥ : 2023. 2. 8
�̸� : �輺��
���� : �Լ��� �������̵��� ��������
	�����Ϸ��� �������� �������̵��� �Լ��� ������ Ű���� ���� ȣ���Ѵٰ� ��������
	�� ���, �����Ͱ� ����Ű�� Ŭ������ �´� �Լ��� ȣ���Ѵ�
*/

#include<iostream>
using namespace std;

class First {

public:
	void MyFunc() {

		cout << "FirstFunc" << endl;
	}
};

class Second : public First {

public:
	void MyFunc() {
		
		cout << "SecondFunc" << endl;
	}
};

class Third : public Second {

public:
	void MyFunc() {

		cout << "ThirdFunc" << endl;
	}
};

int main(void)
{
	
	Third* tptr = new Third();
	Second* sptr = tptr;
	First* fptr = sptr;

	fptr->MyFunc();	// First
	sptr->MyFunc();	// Second
	tptr->MyFunc();	// Third
	return 0;
}