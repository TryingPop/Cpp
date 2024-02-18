#include<vector>

/*
��¥ : 2024. 2. 18
�̸� : �輺��
���� : �迭 ����� 3
	���� �迭 arr�� 2���� ������ ��� �迭 intervals�� �־�����
	intervals�� �׻� { { a1, b1 }, { a2, b2 } } �� �÷� �־����� �� ������ �󱸰�
	�̶� �迭 arr�� ù ��° ������ �ش��ϴ� �迭�� �� ��° ������ �ش��ϴ� �迭�� �յڷ� �ٿ�
	���ο� �迭�� ����� return �ϴ� solution �Լ� �ϼ��ϱ�
*/

using namespace std;

vector<int> solution(vector<int> _arr, vector<vector<int>> _intervals)
{

	vector<int> answer;
	for (const vector<int> interval : _intervals)
	{

		for (int i = interval[0]; i <= interval[1]; i++) 
		{

			answer.push_back(_arr[i]);
		}
	}

	return answer;
}