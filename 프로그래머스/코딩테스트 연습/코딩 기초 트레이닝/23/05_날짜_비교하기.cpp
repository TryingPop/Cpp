#include <vector>

/*
��¥ : 2024. 2. 29
�̸� : �輺��
���� : ��¥ ���ϱ�
	���� �迭 date1, date2�� �־�����
	date�� { yyyy, mm, dd }�� �̷���� �ִ�
	���⼭ yyyy�� �⵵, mm�� ��, dd�� ���� �ǹ��Ѵ�

	date1�� date2���� �ռ��� ��¥��� 1��
	�ƴϸ� 0�� return�ϴ� solution �Լ��� ����
*/

using namespace std;
int solution(vector<int> _date1, vector<int> _date2) 
{

	int answer = 0;

	for (int i = 0; i < 3; i++) 
	{

		if (_date1[i] != _date2[i])
		{

			answer = _date1[i] < _date2[i];
			break;
		}
	}

	return answer;
}