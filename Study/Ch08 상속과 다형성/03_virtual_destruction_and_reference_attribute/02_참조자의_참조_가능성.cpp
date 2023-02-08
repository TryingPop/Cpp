/*
��¥ : 2023. 2. 8
�̸� : �輺��
���� : �������� ���� ���ɼ�
	������ó�� �����ڵ� ��ü�� ����, ���� ����ϴ� ��ü�� ������ �� �ִ�
*/

#include <iostream>
using namespace std;

class First {

public:
	void FirstFunc() {

		cout << "FirstFunc()" << endl;
	}

	virtual void SimpleFunc() {

		cout << "First's SimpleFunc()" << endl;
	}
};

class Second : public First {

public:
	void SecondFunc() {
		
		cout << "SecondFunc()" << endl;
	}

	virtual void SimpleFunc() {

		cout << "Second's SimpleFunc()" << endl;
	}
};

class Third : public Second {

public:
	void ThirdFunc() {

		cout << "ThirdFunc()" << endl;
	}

	virtual void SimpleFunc() {

		cout << "Third's SimpleFunc()" << endl;
	}
};

// First�� ������������ ����ϴ� Ŭ������ ��ü�� ������ ����̵Ǵ� ������� ����
// �׸��� ���ڷ� ���޵Ǵ� ��ü�� ���� �ڷ����� ������� �Լ� ��������
// First Ŭ������ ���ǵ� �Լ��� ȣ�� ����
void GoodFunc(First first) { }


int main(void)
{

	Third obj;
	obj.FirstFunc();
	obj.SecondFunc();
	obj.ThirdFunc();
	obj.SimpleFunc();		// Third
	
	Second& sref = obj;
	sref.FirstFunc();
	sref.SecondFunc();
	// sref.ThirdFunc();
	sref.SimpleFunc();		// Third

	First& fref = obj;
	fref.FirstFunc();
	fref.SimpleFunc();		// Third
}