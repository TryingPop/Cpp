/*
��¥ : 2024. 7. 2
�̸� : �輺��
���� : ��ɰ���
	��� ���� �۾��� ���� �߿� �ִ�
	�� ����� ������ 100%�� �� ���񽺿� �ݿ��� �� �ִ�

	�׸��� �� ����� ���߼ӵ��� ��� �ٸ��� ������
	�ڿ� �ִ� ����� �տ� �ִ� ��ɺ��� ���� ���ߵ� �� �ְ�,
	�� �� �ڿ� �ִ� ����� �տ� �ִ� ����� ������ �� �Բ� �����ȴ�

	���� �����Ǿ�� �ϴ� ������� �۾��� ������ ���� �����迭
	progresses�� �� �۾��� ���� �ӵ��� ���� �����迭 speeds��
	�־��� ��, �� �������� �� ���� ����� �����Ǵ����� return�ϴ� solution �Լ� ����

	�۾��� ������ 100�� �����̴�
	�۾� ������ 100 �̸��� �ڿ���, �۾��ӵ��� 100 ������ �ڿ���

	������ �Ϸ翡 �� ���� �� �� ������, �Ϸ��� ���� �̷�����


	parameter
	{ 93, 30, 55 }, { 1, 30, 5 }


	return
	{ 2, 1 }



	sol
	ù ��° ����� 7�� �ڿ� �ϼ��ǰ�
	�� ��° ����� 3�� �ڿ� �ϼ��ȴ�
	�ݸ� �� ��° ����� 9�ϵڿ� �ϼ��ȴ�
*/

#include <vector>

using namespace std;

vector<int> solution(vector<int> _progresses, vector<int> _speeds)
{

	vector<int> answer;

	int len = _progresses.size();

	vector<int>& remain = _progresses;

	for (int i = 0; i < len; i++)
	{

		int r = 100 - _progresses[i];
		int val = r / _speeds[i];
		if (r % _speeds[i]) val++;

		remain[i] = val;
	}

	int idx = 0;
	while (idx < len)
	{

		int val = remain[idx++];
		int cnt = 1;

		while (idx < len && remain[idx] <= val)
		{

			idx++;
			cnt++;
		}

		answer.push_back(cnt);
	}

	return answer;
}