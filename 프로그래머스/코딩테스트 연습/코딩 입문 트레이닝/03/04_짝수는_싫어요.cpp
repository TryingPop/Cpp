#include <vector>

/*
��¥ : 2024. 3. 8
�̸� : �輺��
���� : ¦���� �Ⱦ��
	���� n�� �Ű������� �־��� ��,
	n ������ Ȧ���� ������������ ���� �迭�� 
	return�ϴ� solution �Լ� ����
*/

using namespace std;

vector<int> solution(int _n)
{

	vector<int> answer;
	answer.reserve((_n + 1) / 2);

	for (int i = 1; i <= _n; i += 2) 
	{

		answer.push_back(i);
	}

	return answer;
}