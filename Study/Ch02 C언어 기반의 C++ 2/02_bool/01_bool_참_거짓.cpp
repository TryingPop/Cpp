/*
��¥ : 2023. 1. 23
�̸� : �輺��
���� : true and false
	���� ����
*/

#include <iostream>

using namespace std;

// C���� ǥ�� �ϴ� ���
#define TRUE	1
#define FALSE	0

int main(void) 
{

	int num = 10;
	int i = 0;

	cout << "true : " << true << endl;		// 1�� ǥ��
	cout << "false : " << false << endl;	// 0���� ǥ��

	while (true) {

		
		cout << i++ << ' ';
		// i++�� i++�� ������ �ڵ�� �״��� �ڵ� ���̿��� 
		// i �� �����Ѵٰ� �����ϸ� �ȴ�
		// ��, �ּ� �ڸ����� ���

		if (i > num) {

			break;
		}
	}

	cout << endl;

	// ũ��(���� : ����Ʈ)�� Ȯ��
	cout << "sizeof 1 : " << sizeof(1) << endl;				// 4
	cout << "sizeof 0 : " << sizeof(0) << endl;				// 4
	cout << "sizeof true : " << sizeof(true) << endl;		// 1
	cout << "sizeof false : " << sizeof(false) << endl;		// 1

	return 0;
}