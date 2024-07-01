/*
��¥ : 2024. 7. 1
�̸� : �輺��
���� : ����� ����
	2���� ��� arr1�� arr2�� �Է¹޾�,
	arr1�� arr2�� ���� ����� ��ȯ�ϴ� �Լ�
	solution �Լ� ����

	arr1, arr2�� ��� ���� ���̴� 
	2�̻� 100 ���ϴ�

	arr1, arr2�� ���Ҵ� -10 �̻� 20������ �ڿ���

	���� �� �ִ� �迭�� �־�����


	parameter
	{ { 1, 4 }, { 3, 2 }, { 4, 1 } }, { { 3, 3 }, { 3, 3 } }


	return
	{ { 15, 15 }, { 15, 15 }, { 15, 15 } }
*/

#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> _arr1, vector<vector<int>> _arr2)
{

	vector<vector<int>> answer;
	answer.resize(_arr1.size());

	for (int i = 0; i < _arr1.size(); i++)
	{

		answer[i].reserve(_arr2[0].size());

		for (int j = 0; j < _arr2[0].size(); j++)
		{

			int val = 0;
			for (int mid = 0; mid < _arr1[0].size(); mid++)
			{

				val += _arr1[i][mid] * _arr2[mid][j];
			}

			answer[i].push_back(val);
		}
	}

	return answer;
}