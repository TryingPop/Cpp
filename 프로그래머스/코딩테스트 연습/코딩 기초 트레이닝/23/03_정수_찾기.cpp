#include <vector>

/*
��¥ : 2024. 2. 29
�̸� : �輺��
���� : ���� ã��
	���� ����Ʈ num_list�� ã������ ���� n�� �־��� ��,
	num_list�ȿ� n�� ������ 1�� ������ 0��
	return�ϴ� solution �Լ��� ����
*/

using namespace std;

int solution(vector<int> _num_list, int _n)
{

	int answer = 0;

	for (const int num : _num_list)
	{

		if (num != _n) continue;

		answer = 1;
		break;
	}

	return answer;
}