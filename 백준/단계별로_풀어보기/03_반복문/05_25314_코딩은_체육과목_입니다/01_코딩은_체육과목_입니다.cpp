/*
��¥ : 2024. 8. 2
�̸� : �輺��
���� : �ڵ��� ü������ �Դϴ�
	������ȣ : 25314��
*/

#include <iostream>
#include <string>

#define fastio cin.tie(NULL);		\
			cout.tie(NULL);			\
			ios_base::sync_with_stdio(false)
using namespace std;

const string LONG = "long ";

int main(void)
{

	int n;
	fastio;

	cin >> n;
	n /= 4;

	for (int i = 0; i < n; i++)
	{

		cout << LONG;
	}

	cout << "int";

	return 0;
}