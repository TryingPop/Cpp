/*
��¥ : 2023. 1. 31
�̸� : �輺��
���� : �ӽð�ü
	�ӽð�ü�� ����

	Ŭ���� �ܺο��� ��ü�� ����Լ��� ȣ���ϱ� ���� �ʿ��� ���� ���� �� ���� �� �ϳ�
		- ��ü�� �ٿ��� �̸�
		- ��ü�� ���� ��
		- ��ü�� �ּ� ��
*/

#include <iostream>
using namespace std;

class Temporary {

private:
	int num;

public:
	Temporary(int n)
		: num(n) {

		cout << "create obj: " << num << endl;
	}

	~Temporary() {

		cout << "destroy obj: " << num << endl;
	}

	void ShowTempInfo() {

		cout << "My name is " << num << endl;
	}
};

int main(void)
{

	Temporary(100);	// �ӽð�ü�� �������
	// ���⼭ �ӽð�ü�� �ٷ� ����
	cout << "********** after make!" << endl << endl;

	Temporary(200).ShowTempInfo();	// �ӽð�ü�� ������ ��ġ�� �ӽð�ü�� ���� ���� ��ȯ�ȴ�
									// �׷��� ��ü�� ���������� �޼ҵ尡 ����
	// ShowTempInfo ���� �޸𸮿��� �����ȴ�
	cout << "********** after make!" << endl << endl;

	const Temporary& ref = Temporary(300);	// ���� ���� ��ȯ�Ǿ� �̸� �����ڸ� �̿��� �����ϴ� ��
	// �����ϰ� �־ Temporary(300)�� ��ó�� ���⼭ �������� �ʴ´� �ٸ� �����Լ��� ������ �����ȴ�
	cout << "********** after make!" << endl << endl;
	return 0;
}