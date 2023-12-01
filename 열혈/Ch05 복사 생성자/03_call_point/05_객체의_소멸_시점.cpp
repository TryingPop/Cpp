/*
��¥ : 2023. 1. 31
�̸� : �輺��
���� : ��ü�� �Ҹ� ����
	
*/

#include <iostream>
using namespace std;

class SoSimple {

private:
	int num;

public:
	SoSimple(int n)
		: num(n) { 

		cout << "New Object: " << this << endl;
	}

	SoSimple(const SoSimple& copy)
		: num(copy.num) { 

		cout << "New Copy obj: " << this << endl;
	}

	~SoSimple() {

		cout << "Destroy obj: " << this << endl;
	}
};

SoSimple SimpleFuncObj(SoSimple ob) {

	cout << "Param ADR: " << &ob << endl;
	return ob;	// ��ȯ �� ���� >> ���� �Ҹ� �����̴�
}

int main(void) 
{

	SoSimple obj(7);
	SimpleFuncObj(obj);

	cout << endl;
	SoSimple tempRef = SimpleFuncObj(obj);	// ��ȯ ���� tempRef��� �̸��� ���ΰ� ��
											// tempRef�� ���� �����Ǵ°� �ƴϴ�
	cout << "Return Obj" << &tempRef << endl;
	return 0;
}