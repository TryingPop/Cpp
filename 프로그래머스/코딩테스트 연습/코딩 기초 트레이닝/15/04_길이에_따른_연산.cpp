#include <vector>

/*
��¥ : 2024. 2. 21
�̸� : �輺��
���� : ���̿� ���� ����
	������ ��� ����Ʈ num_list�� �־��� ��,
	����Ʈ�� ���̰� 11 �̻��̸�
	����Ʈ�� �ִ� ��� ������ ����
	10 �����̸� ��� ������ ����
	return �ϵ��� solution �Լ��� ����
*/

using namespace std;

int solution(vector<int> _num_list)
{

	int answer;
	if (_num_list.size() > 10)
	{

		answer = 0;
		for (const int i : _num_list)
		{

			answer += i;
		}
	}
	else 
	{

		answer = 1;
		for (const int i : _num_list)
		{

			answer *= i;
		}
	}

	return answer;
}