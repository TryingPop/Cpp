/*
��¥ : 2024. 7. 30
�̸� : �輺��
���� : �� �� ���ϱ�
	������ȣ : 1330��

	���� ������
*/

#include <iostream>

using namespace std;

int main(void)
{

	int a, b;
	cin >> a >> b;

	if (a < b) cout << '<';
	else if (a == b) cout << '=' << '=';
	else cout << '>';

	return 0;
}