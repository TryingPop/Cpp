#include <vector>

/*
��¥ : 2024. 2. 21
�̸� : �輺��
���� : 1�� �����
	������ ���� ��, ¦����� ������ ������
	Ȧ����� 1�� ���� ������ ������
	�������� 1�� �ȴ�
	�������� ��� ����Ʈ num_list�� �־��� ��,
	num_list�� ��� ���Ҹ� 1�� ����� ���ؼ� 
	������ ������ Ƚ���� return�ϵ��� solution �Լ��� ����
*/

using namespace std;

int solution(vector<int> _num_list)
{

	int answer = 0;

	for (int i : _num_list)
	{

		while (i != 1)
		{

			i /= 2;
			answer++;
		}
	}

	return answer;
}