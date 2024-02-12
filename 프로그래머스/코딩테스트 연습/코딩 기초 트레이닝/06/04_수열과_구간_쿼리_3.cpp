#include <vector>

/*
��¥ : 2024. 2. 12
�̸� : �輺��
���� : ������ ���� ���� 3
	���� �迭 arr�� 2���� ���� �迭 queries�� �־�����
	queries�� ���� query�� [i, j] ���̴�
	�� query���� arr[i]�� arr[j]�� �ٲ۴�

	������ ��Ģ�� ���� queries�� ó���� ����
	arr�� return �ϴ� solution �Լ��� ����

	c++���� ��ü������ swap�Լ��� �ִ�
*/

using namespace std;

vector<int> solution(vector<int> _arr, vector<vector<int>> _queries)
{

	vector<int> answer;
	answer = _arr;

	// query�� &query�� ǥ���ص� �ǰ� �׳� query�� �ᵵ �ȴ�
	// ������ Ŭ�����̹Ƿ� �ּҸ� �����Ѵ�
	for (const vector<int> query : _queries)
	{

		// int temp = answer[query[0]];
		// answer[query[0]] = answer[query[1]];
		// answer[query[1]] = temp;
		swap(answer[query[0]], answer[query[1]]);
	}

	return answer;
}