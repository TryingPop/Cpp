#include <vector>

/*
��¥ : 2024. 2. 18
�̸� : �輺��
���� : �迭 �����ϱ�
	���� �迭 arr�� query�� �־�����
	query�� ��ȸ�ϸ鼭 ���� �۾��� �ݺ�
	¦�� �ε��������� arr���� query[i]�� �ε����� �����ϰ� �迭�� query[i]�� �ε��� �޺κ��� �߶� ������
	Ȧ�� �ε��������� arr���� query[i]�� �ε����� �����ϰ� �迭�� query[i]�� �ε��� �պκ��� �߶� ������

	�� �۾��� ��ģ �� ���� arr�� �κ� �迭�� return �ϴ� solution �Լ� �ϼ�
*/

using namespace std;

vector<int> solution(vector<int> _arr, vector<int> _query)
{

	vector<int> answer = _arr;

	int s = 0, e = _arr.size() - 1;
	for (int i = 0; i < _query.size(); i++)
	{

		/*
		if (i & 1) answer.erase(answer.begin(), answer.begin() + _query[i]);
		else if (_query[i] < answer.size() - 1) answer.erase(answer.begin() + _query[i] + 1, answer.end());
		*/

		int calc = s + _query[i];
		if (i & 1) s = calc;
		else if (e > calc) e = calc;
	}

	for (int i = s; i <= e; i++)
	{

		answer.push_back(_arr[i]);
	}

	if (answer.empty()) answer.push_back(-1);
	return answer;
}