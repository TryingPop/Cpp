/*
��¥ : 2023. 2. 17
�̸� : �輺��
���� : �� ��ȯ ������
	�ӽð�ü���� �ڵ� �� ��ȯ�� �� ��ȯ ������
*/

#include<iostream>
using namespace std;

class Number {

private:
	int num;

public:
	Number(int n = 0)
		: num(n) { 
	
		cout << "Number(int n = 0)" << endl;
	}

	Number& operator=(const Number& ref) {

		cout << "operator=()" << endl;
		num = ref.num;
		return *this;
	}

	void showNumber() {

		cout << num << endl;
	}
};

int main(void)
{

	Number num;			// Number(int n = 0);

	num = 30;			// Number(int n = 0);
						// operator=()
						// ���⼭ ������ ���� ������ ����ȴ�
						// num = Number(30);
						// num.operator(Number(30))
						// A�� ��ü�� �;� �� ��ġ�� B�� ������(�Ǵ� ��ü)�� ���� ���,
						// B�� �����͸� ���ڷ� ���޹޴� A���� Ŭ������ ������ ȣ���� ���ؼ�
						// A�� �ӽð�ü�� �����Ѵ�

	num.showNumber();	// 30
	return 0;
}