#include <vector>

/*
��¥ : 2024. 2. 28
�̸� : �輺��
���� : �迭�� ���� �����ϱ�
	���� �迭 arr�� delete_list�� �ִ�
	arr�� ���� �� delete_list�� ���Ҹ� ��� �����ϰ�
	���� ���ҵ��� ������ arr�� �ִ� ������ ������ �迭��
	return�ϴ� solution �Լ��� ����
*/

using namespace std;

vector<int> solution(vector<int> _arr, vector<int> _delete_list)
{

	vector<int> answer;

	for (const int i : _arr)
	{

		bool chk = true;
		for (const int j : _delete_list)
		{

			if (i == j)
			{

				chk = false;
				break;
			}
		}

		if (chk) answer.emplace_back(i);
	}
	return answer;
}