#include <vector>

/*
��¥ : 2024. 2. 26
�̸� : �輺��
���� : �迭�� ���̿� ���� �ٸ� �����ϱ�
	���� �迭 arr�� ���� n�� �Ű������� �־�����
	arr�� ���̰� Ȧ�����
	arr�� ��� ¦�� ��ġ�� n�� ���� �迭��,

	arr�� ���̰� ¦�����
	arr�� ��� Ȧ�� ��ġ�� n�� ���� �迭��

	return�ϴ� solution �Լ��� ����
*/

using namespace std;

vector<int> solution(vector<int> _arr, int _n)
{

	vector<int> answer;

	answer = _arr;
	int s = (_arr.size() + 1) & 1;

	for (int i = s; i < answer.size(); i += 2)
	{

		answer[i] += _n;
	}

	return answer;
}