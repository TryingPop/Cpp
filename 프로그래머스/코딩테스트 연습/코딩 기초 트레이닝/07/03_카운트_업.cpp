#include <vector>

/*
��¥ : 2024. 2. 13
�̸� : �輺��
���� : ī��Ʈ ��
	���� start_num�� end_num�� �־��� ��,
	start_num���� end_num������ ���ڸ� ���ʷ� ���� ����Ʈ�� return�ϵ���
	solution �Լ��� ����ÿ�
*/

using namespace std;

vector<int> solution(int _start_num, int _end_num)
{

	vector<int> answer;
	answer.reserve(_end_num - _start_num + 1);

	for (int i = _start_num; i <= _end_num; i++)
	{

		answer.push_back(i);
	}

	return answer;
}