/*
��¥ : 2024. 7. 17
�̸� : �輺��
���� : �ֽİ���
	�� ������ ��ϵ� �ֽİ����� ��� �迭 prices�� �Ű������� �־��� ��,
	������ �������� ���� �Ⱓ�� �� �������� return �ϵ��� solution �Լ� ����

	prices�� �� ������ 1 �̻� 10'000 ������ �ڿ���

	prices�� ���̴� 2 �̻� 100'000����


	parameter
	{ 1, 2, 3, 2, 3 }


	return
	{ 4, 3, 1, 1, 0 }


	sol
	1�� ������ 1�� ������ ������ �������� �ʴ´�
	2�� ������ ���� 2�� ������ ������ �������� �ʴ´�
	3�� ������ 3�� 1�� �ڿ� ������ ��������
	4�� ������ 2�� 1�ʰ� ������ �������� �ʴ´�
	5�� ������ 3�� 0�ʰ� ������ �������� �ʴ´�
*/

#include <vector>

using namespace std;


vector<int> solution(vector<int> _prices)
{

	int end = _prices.size() - 1;
	vector<int> answer(end + 1, 0);

	vector<int> stack;
#if back


	for (int i = end; i >= 0; i--)
	{

		while (stack.size() && _prices[stack.back()] >= _prices[i])
		{

			stack.pop_back();
		}

		if (stack.empty()) answer[i] = end - i;
		else answer[i] = stack.back() - i;
	}
#else

	for (int i = 0; i <= len; i++)
	{

		while (stack.size() && _prices[i] < _prices[stack.back()])
		{

			int idx = stack.back();
			stack.pop_back();

			answer[idx] = i - idx;
		}
		
		stack.push_back(i);
	}

	while (stack.size())
	{

		int idx = stack.back();
		stack.pop_back();

		answer[idx] = len - idx;
	}
#endif

	return answer;

}
