/*
��¥ : 2024. 8. 2
�̸� : �輺��
���� : A + B - 7
	������ȣ : 11021��

	����, ����, ��Ģ���� ������
*/

#include <iostream>
#include <string>

#define fastio	cin.tie(NULL);		\
				cout.tie(NULL);		\
				ios_base::sync_with_stdio(false)

#define endl '\n'

using namespace std;

const string CASE = "Case #";
const string AND = ": ";

int main(void)
{

	int test, a, b;
	fastio;
	
	cin >> test;

	for (int i = 1; i <= test; i++)
	{

		cin >> a >> b;
		cout << CASE << i << AND << a + b << endl;
	}

	return 0;
}