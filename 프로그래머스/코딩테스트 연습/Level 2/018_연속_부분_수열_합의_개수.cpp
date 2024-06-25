/*
��¥ : 2024. 6. 25
�̸� : �輺��
���� : ���� �κ� ���� ���� ����
	���� ������ ���� elements�� ������� �־��� ��,
	���� ������ ���� �κ� ���� ������ ���� �� �ִ� ���� ������
	return �ϴ� solution �Լ� ����

	parameter
	{ 7, 9, 1, 1, 4 }


	return
	18


	sol
	���� 1�� { 1, 4, 7, 9 } 4������ ����
	���� 2�� { 2, 5, 10, 11, 16 } 5������ ����
	���� 3�� { 6, 11, 12, 17, 20 } 5������ ����
	���� 4�� { 13, 15, 18, 21 } 4������ ����
	���� 5�� { 22 } 1������ ����

	�ߺ��� { 11 } 1���� �����ϸ� ��ü�� 18���̴�
*/

#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> _elements)
{

	int answer = 0;

	int len = _elements.size();
	_elements.resize(len * 2);

	for (int i = 0; i < len; i++)
	{

		_elements[i + len] = _elements[i];
	}

	unordered_map<int, bool> use;

	for (int i = 0; i < len; i++)
	{

		int cur = 0;
		for (int j = 0; j < len; j++)
		{

			cur += _elements[i + j];
			if (use[cur]) continue;

			use[cur] = true;
			answer++;
		}
	}

	return answer;
}