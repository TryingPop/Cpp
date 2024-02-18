#include <vector>

/*
��¥ : 2024. 2. 18
�̸� : �輺��
���� : 2�� ����
	���� �迭 arr�� �־�����
	�迭 ���� 2�� ��� ���Ե� ���� ���� ���ӵ� �κ� �迭��
	return �ϴ� solution �Լ��� �ϼ�
	��, arr�� 2�� ���� ��� { -1 }�� return
*/
using namespace std;

vector<int> solution(vector<int> _arr) 
{

	vector<int> answer;

	int s = -1;
	int e = -1;

	for (int i = 0; i < _arr.size(); i++) 
	{

		if (_arr[i] == 2) 
		{

			if (s == -1) s = i;
			else e = i;
		}
	}

	if (s != -1)
	{

		if (e == -1) answer.push_back(2);

		else
		{

			for (int i = s; i <= e; i++) 
			{

				answer.push_back(_arr[i]);
			}
		}
	}
	else answer.push_back(-1);

	return answer;
}