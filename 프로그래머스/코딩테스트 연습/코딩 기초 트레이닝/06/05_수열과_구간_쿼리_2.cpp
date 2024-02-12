#include <vector>

// #define MAX 1'000'001
/*
��¥ : 2024. 2. 12
�̸� : �輺��
���� : ������ ���� ���� 2
	���� �迭 arr�� 2���� ���� �迭 queries�� �־�����
	queries�� ���Ҵ� ������ query�� ��Ÿ���� [s, e, k] ���̴�
	�� query���� s <= i <= e�� ��� i�� ���� k���� ũ�鼭 ���� ���� arr[i]�� ã���ÿ�
*/

using namespace std;

vector<int> solution(vector<int> _arr, vector<vector<int>> _queries)
{

	vector<int> answer;
	answer.reserve(_queries.size());

	const int MAX = 1'000'001;

	for (const vector<int> query : _queries)
	{

		int min = MAX;

		for (int i = query[0]; i <= query[1]; i++) 
		{

			min = _arr[i] > query[2] && _arr[i] < min ? _arr[i] : min;
		}

		if (min == MAX) answer.push_back(-1);
		else answer.push_back(min);
	}

	return answer;
}