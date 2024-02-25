#include <vector>
#include <map>

/*
��¥ : 2024. 2. 25
�̸� : �輺��
���� : �������� k���� �� �̱�
	���� �迭 arr, ���� k�� �־�����
	�տ������� �ϳ��� Ž���� ��,
	arr�� ���� �ٸ� k���� ���Ҹ� ������� �̾� ����
	�迭�� ��ȯ�ϴ� solution �Լ��� ����
	���� k���� �ȵ� �� -1�� ä���
*/

using namespace std;

vector<int> solution(vector<int> _arr, int _k)
{

	vector<int> answer;

	map<int, int> m;

	for (int i = 0; i < _arr.size(); i++)
	{

		if (m.count(_arr[i])) continue;

		// �ߺ� ������ ���
		m.insert({ _arr[i], 0 });
		answer.push_back(_arr[i]);

		// _k ä��� Ż��
		if (answer.size() == _k) break;
	}

	// ������ �κ� -1�� ä���
	for (int i = answer.size(); i < _k; i++)
	{

		answer.push_back(-1);
	}

	return answer;
}