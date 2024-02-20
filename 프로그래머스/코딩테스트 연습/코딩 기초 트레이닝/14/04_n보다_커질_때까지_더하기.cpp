#include <vector>

/*
��¥ : 2024. 2. 20
�̸� : �輺��
���� ; n���� Ŀ�� ������ ���ϱ�
	���� �迭 numbers�� ���� n�� �Ű������� �־�����
	numbers�� ���Ҹ� �տ������� �ϳ��� ���ϴٰ�
	�� ���� n���� Ŀ���� ���� �̶����� ���ߴ� ���ҵ��� ����
	return �ϴ� solution �Լ��� ����
*/

using namespace std;

int solution(vector<int> _numbers, int _n)
{

	int answer = 0;

	for (const int add : _numbers) 
	{

		answer += add;
		if (answer > _n) break;
	}

	return answer;
}