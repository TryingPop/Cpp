#include <vector>

/*
��¥ : 2024. 2. 13
�̸� : �輺��
���� : ������ ���� ���� 4
	���� �迭 arr�� 2���� ���� �迭 queries�� �־�����
	queries�� ���Ҵ� ���� �ϳ��� query�� ��Ÿ����
	{ s, e, k }���̴�

	�� query���� ������� s <= i <= e�� ��� i�� ���� i�� k�� ����̸�
	arr[i]�� 1�� ���Ѵ�

	�� ��Ģ�� ���� queries�� ó���� ������ arr�� ��ȯ�ϴ� soltuion �Լ� �����
*/

using namespace std;

vector<int> solution(vector<int> _arr, vector<vector<int>> _queries)
{

	vector<int> answer;
	answer.reserve(_arr.size());
	answer = _arr;

	for (vector<int> query : _queries)
	{

		for (int i = query[0]; i <= query[1]; i++)
		{

			if (i % query[2] == 0) 
			{

				answer[i] += 1;
			}
		}
	}

	return answer;
}