#include <string>
#include <vector>

/*
��¥ : 2024. 3. 1
�̸� : �輺��
���� : ���ǿ� �°� ���� ��ȯ�ϱ� 3
	���� �迭 arr�� �ڿ��� k�� �־�����
	k�� Ȧ����� arr�� ��� ���ҿ� k�� ���ϰ�
	k�� ¦����� arr�� ��� ���ҿ� k�� ���Ѵ�

	�̷��� ��ȯ�� ��ģ ���� arr�� return�ϴ�
	solution �Լ��� ����
*/

using namespace std;

vector<int> solution(vector<int> _arr, int _k)
{

	vector<int> answer;
	answer.reserve(_arr.size());

	for (int i : _arr)
	{

		if (_k & 1) answer.push_back(i * _k);
		else answer.push_back(i + _k);
	}

	return answer;
}