#include <vector>

/*
��¥ : 2024. 3. 19
�̸� : �輺��
���� : n�� ��� ����
	���� n�� ���� �迭 numlist��
	�Ű������� �־��� ��,

	numlist���� n�� ����� �ƴ� ������
	������ �迭�� return �ϵ���
	solution �Լ��� ����
*/

using namespace std;

vector<int> solution(int _n, vector<int> _numlist) 
{

	vector<int> answer;
	answer.reserve(_numlist.size());

	for (const int i : _numlist)
	{

		if (i % _n) continue;
		answer.push_back(i);
	}

	return answer;
}