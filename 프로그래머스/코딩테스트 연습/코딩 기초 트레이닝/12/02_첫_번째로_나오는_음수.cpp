#include <vector>

/*
��¥ : 2024. 2. 18
�̸� : �輺��
���� : ù ��°�� ������ ����
	���� ����Ʈ num_list�� �־��� ��,
	ù ��°�� ������ ������ �ε����� return �ϵ��� 
	solution �Լ��� �ϼ�
	������ ���ٸ� -1�� return
*/

using namespace std;

int solution(vector<int> _num_list)
{

	int answer = -1;

	for (int i = 0; i < _num_list.size(); i++)
	{

		if (_num_list[i] < 0) 
		{ 

			answer = i; 
			break;
		}
	}

	return answer;
}