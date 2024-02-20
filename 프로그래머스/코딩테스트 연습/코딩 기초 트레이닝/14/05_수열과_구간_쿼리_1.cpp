#include <vector>

/*
��¥ : 2024. 2. 20
�̸� : �輺��
���� : ������ ���� ���� 1
	���� �迭 arr�� 2���� ���� �迭 queries�� �־�����
	queries�� ���Ҵ� ���� �ϳ��� query�� ��Ÿ����,
	{ s, e } ���Դϴ�

	�� query���� ������� s <= i <= e�� ��� i�� ���� arr[i]�� 1�� ���Ѵ�
	�� ��Ģ�� ���� queries�� ó���� ������ arr�� return�ϴ� solution �Լ� ����
*/

using namespace std;

vector<int> solution(vector<int> _arr, vector<vector<int>> _queries)
{

	vector<int> answer;

	answer = _arr;

	for (const vector<int> query : _queries)
	{

		for (int i = query[0]; i <= query[1]; i++)
		{

			answer[i] += 1;
		}
	}

	return answer;
}