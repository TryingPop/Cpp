#include <vector>

/*
��¥ : 2024. 2. 25
�̸� : �輺��
���� : �� �迭�� �߰�, �����ϱ�
	�� �迭 X�� �ִ�
	���̰� ���� ���� �迭 arr��
	bool �迭 flag�� �Ű������� �־��� ��,

	flag�� ���ʴ�� ��ȸ�Ͽ�
	flag[i]�� true��, X�ڿ� arr[i]�� arr[i] * 2�� �߰��ϰ�,
	flag[i]�� false��, X���� ������ arr[i]���� ���Ҹ� ������ ��
	X�� return�ϴ� solution �Լ��� ����
*/

using namespace std;

vector<int> solution(vector<int> _arr, vector<bool> _flag)
{

	vector<int> answer;

	for (int i = 0; i < _flag.size(); i++)
	{

		if (_flag[i])
		{

			// 2�� �߰�
			for (int j = 0; j < _arr[i]; j++)
			{

				answer.push_back(_arr[i]);
				answer.push_back(_arr[i]);
			}
		}
		else
		{

			// ����
			for (int j = 0; j < _arr[i]; j++) 
			{

				answer.pop_back();
			}
		}
	}
	return answer;
}