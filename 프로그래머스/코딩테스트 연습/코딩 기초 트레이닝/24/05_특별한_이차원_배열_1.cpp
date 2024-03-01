#include <vector>

/*
��¥ : 2024. 3. 1
�̸� : �輺��
���� : Ư���� ������ �迭 1
	���� n�� �Ű������� �־�����

	n * n ũ���� ������ �迭 arr��
		arr[i][j] (0 <= i, j < n)
		i == j, arr[i][j] = 1
		i != j, arr[i][j] = 0

	return �ϴ� solution �Լ� ����
*/
using namespace std;

vector<vector<int>> solution(int _n)
{

#if first
	vector<vector<int>> answer;
	vector<int> temp(_n, 0);
	
	for (int i = 0; i < _n; i++)
	{

		temp[i] = 1;
		answer.push_back(temp);
		temp[i] = 0;
	}

	return answer;
#elif second
	vector<vector<int>> answer(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++)
	{

		answer[i][i] = 1;
	}

	return answer;
#endif
}