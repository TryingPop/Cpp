/*
��¥ : 2024. 8. 22
�̸� : �輺��
���� : ���� ���
	������ȣ : 2839��

	����, dp, �׸��� ������
*/

#include <iostream>
#include <vector>

#define Min(X, Y)	(((X) < (Y)) ? (X) : (Y))
using namespace std;

int main(void)
{

#if first

	int n, m, ret = -1;
	cin >> n;
	// gcd(3, 5) = 1�̹Ƿ�
	// ������ �� k ���� ū m���� a * 3 + b * 5 = m ���·� ǥ�������ϴ�
	// �հ������ �غ��� 8���� ��� ���� ǥ������
	// 8 ~ 22 ������ ã��, �׸��� �˰������� 8 +15 �� 8���� + 5 ¥�� * 3�� ������ �ּ��̹Ƿ�
	// 23 �̻��� ���ڴ� 8 ~ 23������ ����� ã�´�
	int chkArr[15] = { 2, 3, 2, 3, 4, 3, 4, 3, 4, 5, 4, 5, 4, 5, 6 };

	if (n <= 7)
	{

		// 8 �̸� �ݷ�ó��
		if (n == 3 || n == 5) ret = 1;
		else if (n == 6) ret = 2;
	}
	else 
	{

		n -= 8;
		m = n / 15;
		n %= 15;

		ret = 3 * m + chkArr[n];
	}

	cout << ret;
#else

	int n;
	cin >> n;
	vector<int> arr(5'005, -1);
	arr[0] = 0;
	arr[3] = 1;

	for (int i = 5; i <= n; i++)
	{

		if (arr[i - 3] > -1 && arr[i - 5] > -1) arr[i] = Min(arr[i - 3], arr[i - 5]) + 1;
		else if (arr[i - 3] > -1) arr[i] = arr[i - 3] + 1;
		else if (arr[i - 5] > -1) arr[i] = arr[i - 5] + 1;
	}

	cout << arr[n];
#endif
	return 0;
}