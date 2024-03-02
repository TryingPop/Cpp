#include <vector>

/*
��¥ : 2024. 3. 2
�̸� : �輺��
���� : Ư���� ������ �迭 2
	n * n ũ���� ������ �迭 arr�� �Ű������� �־�����
	arr�� ������ �����ϸ� 1, �ƴ϶�� 0��
	return�ϴ� solution �Լ� ����
	
	0 <= i, j < n�� ���� i,j�� ����
		arr[i][j] = arr[j][i]
*/

using namespace std;

int solution(vector<vector<int>> _arr)
{

	int answer = 1;

	// arr�� ũ�⸦ �����´�
	// arr �ȿ� �ִ� vector<int>�� ����
	int n = _arr.size();

	for (int i = 0; i < n; i++)
	{

		// n * n ���ʹ�
		for (int j = i + 1; j < n; j++)
		{

			if (_arr[i][j] == _arr[j][i]) continue;

			answer = 0;
			break;
		}
	}

	return answer;
}