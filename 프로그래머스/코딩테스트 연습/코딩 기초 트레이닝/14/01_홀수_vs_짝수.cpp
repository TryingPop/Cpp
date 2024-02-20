#include <vector>

/*
��¥ : 2024. 2. 21
�̸� : �輺��
���� : Ȧ�� vs ¦��
	���� ����Ʈ num_list�� �־�����
	���� ù ��° ���Ҹ� 1�� ���Ҷ�� �� ��,
	Ȧ�� ��° ���ҵ��� �հ� ¦�� ��° ���ҵ��� �� �� ū ���� return �ϵ��� solution �Լ��� ����
	�� ���� ���� ��� �� ���� return
*/

using namespace std;

int solution(vector<int> _num_list)
{

	int answer;

	int odd = 0, even = 0;
	for (int i = 0; i < _num_list.size(); i++)
	{

		if (i & 1) even += _num_list[i];
		else odd += _num_list[i];
	}

	answer = even < odd ? odd : even;

	return answer;
}