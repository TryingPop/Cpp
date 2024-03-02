#include <vector>

/*
��¥ : 2024. 3. 2
�̸� : �輺��
���� : ���簢������ �����
	������ ���� �迭 arr�� �Ű������� �־�����
	arr�� ���� ������ �� ���ٸ�
	���� ���� ���� ���� ����������
	�� ���� ���� 0�� �߰��ϰ�

	���� ���� �� ���ٸ� ���� ����
	���� ���� ���������� �� ���� ���� 0�� �߰���
	������ �迭�� return�ϴ� solution �Լ� ����
*/

using namespace std;

vector<vector<int>> solution(vector<vector<int>> _arr) 
{

	vector<vector<int>> answer = _arr;
	int r = answer.size();
	int c = answer[0].size();

	if (r < c) answer.resize(c, vector<int>(c, 0));
	else if (c < r)
	{

		for (int i = 0; i < r; i++)
		{

			answer[i].resize(r, 0);
		}
	}

	return answer;
}