#include <iostream>
#include <string>

/*
��¥ : 2024. 3. 9
�̸� : �輺��
���� : �����ﰢ�� ����ϱ�
	'*'�� ���̿� �ʺ� 1�̶�� �� ��,
	'*'�� �̿��� ���� �̵ �ﰢ���� �׸����� �Ѵ�

	���� n�� �־����� ���̿� �ʺ� n�� 
	���� �̵ �ﰢ���� ����ϴ� �ڵ带 �ۼ�
*/

using namespace std;

int main(void)
{

	int n;
	string temp;

	cin >> n;
	temp.reserve(n);

	for (int i = 0; i < n; i++)
	{

		temp.push_back('*');
		cout << temp << '\n';
	}
	
	return 0;
}