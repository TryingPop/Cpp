#include <iostream>

/*
��¥ : 2024. 2. 8
�̸� : �輺��
���� : Ȧ¦ ����ϱ�
	������ ����
*/

using namespace std;

int main4(void)
{

	int n;
	cin >> n;

	// if (n % 2 == 0) cout << "is even";
	// else cout << "is odd";

	// ��Ʈ ����
	cout << n << " is " << ((n & 1) ? "even" : "odd");
	return 0;
}