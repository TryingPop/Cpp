/*
��¥ : 2024. 7. 24
�̸� : �輺��
���� : 2 x n Ÿ�ϸ�
	���� ���̰� 2�̰� ���� ���̰� 1�� ���簢�� ����� Ÿ���� �ִ�
	�� ���簢�� Ÿ���� �̿��Ͽ� ���� ���̰� 2�̰� ���α��̰� n��
	�ٴ��� ���� ä����� �Ѵ�

	Ÿ���� ä��� ����� 2������ �ִ�
	Ÿ���� ���η� ��ġ�ϴ� ���
	Ÿ���� ���η� ��ġ�ϴ� ���

	���簢���� ���� ���� n�� �Ű������� �־��� ��,
	�� ���簢���� ä��� ����� ����
	return �ϴ� solution �Լ� ����

	���α��� n�� 6�� ������ �ڿ���
	����� ���� ������ �� �����Ƿ� 1'000'000'007�� ����
	�������� return

	parameter
	4

	
	return
	5


	sol
	==,
	||||,
	|=|,
	=||,
	||=

	�� �ִ�
*/

#include <vector>
#include <cmath>

#define MOD 1'000'000'007

using namespace std;

int solution(int _n)
{

	int answer;

#if first

	/*
	
	dp ���
	*/
	vector<int> dp(max(_n + 1, 2), 0);
	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i <= _n; i++)
	{

		dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
	}

	answer = dp[_n];
#else

	/*
	
	���� �������� �ʰ� ���� ���ϴ°�(dp)
	*/
	int b = 1;
	int c = 1;

	for (int i = 2; i <= _n; i++)
	{

		int temp = (b + c) % MOD;
		b = c;
		c = temp;
	}

	answer = c;
#endif
	return answer;
}