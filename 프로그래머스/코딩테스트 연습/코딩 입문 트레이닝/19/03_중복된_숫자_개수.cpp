#include <vector>

/*
��¥ : 2024. 3. 21
�̸� : �輺��
���� : �ߺ��� ���� ����
	������ ��� �迭 array�� ���� n��
	�Ű������� �־��� ��,

	array�� n�� �� �� �ִ�����
	return �ϵ��� solution �Լ��� ����
*/

using namespace std;

int solution(vector<int> _array, int _n)
{

	int answer = 0;

	for (const int i : _array)
	{

		if (i == _n) answer++;
	}

	return answer;
}