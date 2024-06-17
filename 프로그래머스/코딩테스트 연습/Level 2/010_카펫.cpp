/*
��¥ : 2024. 6. 17
�̸� : �輺��
���� : ī��
	�߾ӿ� ��������� ĥ���� �ְ�,
	�׵θ� 1���� �������� ĥ���� �ִ� ���ڸ���� ī���� �����Ѵ�

	������� �������� ��ĥ�� ������ ������ ���������,
	��ü ī���� ũ��� ������� ���Ѵ�

	���� ������ ���� brown, ����� ������ ���� yellow��
	�Ű������� �־��� ��,

	ī���� ����, ���� ũ�⸦ ������� �迭�� ���
	return �ϵ��� solution �Լ��� ����

	���������� ���� 8 �̻� 5'000 ������ �ڿ���
	����� ������ ���� 1 �̻� 2'000'000 ������ �ڿ���
	ī���� ���� ���̴� ���� ���� �̻��̴�

	parameter
	24, 24


	return
	8, 6
*/

#include <vector>

using namespace std;

vector<int> solution(int _brown, int _yellow)
{

	vector<int> answer;

	int sum = _brown + _yellow;
	for (int h = 1; h * h <= sum; h++)
	{

		if (sum % h) continue;

		int w = sum / h;

		int outline = 2 * (w + h) - 4;
		if (outline != _brown) continue;

		answer.push_back(w);
		answer.push_back(h);

		break;
;	}

	return answer;
}