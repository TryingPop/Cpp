/*
��¥ : 2023. 1. 31
�̸� : �輺��
���� : ���� �������� �ʱ�ȭ
	��ü�� ��ȯ�ϵ�, ���������� ��ȯ���� �ʴ� ���
*/

#include <iostream>
using namespace std;

class SoSimple {

private:
	int num;

public:
	SoSimple(int n) 
		: num(n) { }

	SoSimple(const SoSimple& copy)
		: num(copy.num) {

		cout << "Called by SoSimple(const SoSimple& copy)" << endl;
	}

	SoSimple& AddNum(int n) {

		num += n;
		return *this;
	}

	void ShowData() {

		cout << "num: " << num << endl;
	}
};

SoSimple SimpleFuncObj(SoSimple ob) {

	cout << "retrun ����" << endl;
	return ob;
}

int main(void) 
{

	SoSimple obj(7);
	SimpleFuncObj(obj).AddNum(30).ShowData();	// SimpleFuncObj �� ���� ob ���� �������� ȣ�� 1��
												// SimpleFuncObj ��ȯ���� ���� ���� ȣ�� 1��
												// ��ȯ �ÿ� �ӽ� ��ü�� �����ȴ�
	obj.ShowData();
	return 0;
}