/*
��¥ : 2024. 7. 15
�̸� : �輺��
���� : �ڿ� �ִ� ū �� ã��
	������ �̷���� �迭 numbers�� �ִ�
	�迭�� �� ���ҵ鿡 ���� �ڽź��� �ڿ� �ִ� ���� �߿���
	�ڽź��� ũ�鼭 ���� ������ �ִ� ���� �� ū����� �Ѵ�

	���� �迭 numbers�� �Ű������� �־��� ��,
	��� ���ҿ� ���� �� ū������ ���ʷ� ���� �迭��
	return�ϴ� solution �Լ� ����
	�� �� ū���� �������� �ʴ� ���Ҵ� -1�� ��´�

	parameter
	{ 2, 3, 3, 5 }


	return
	{ 3, 5, 5, -1 }



	sol
	3�� �ε����� 5�� �������� �ִ�
	�ش� ������ �ڿ� �ִ� ���Ҵ� �����Ƿ� -1�� ��´�

	2�� �ε����� 3�� ��� �ڿ� �ڱ⺸�� ū ���� ����� ū ���� 5�� �ִ�
	�׷��� 5�� ����

	1�� �ε����� 3�� ��� �ڿ� �ڱ⺸�� ū ���� ����� ū ���� 5�� �ִ�
	�׷��� 5�� ����

	0�� �ε����� 2�� ��� �ڿ� �ڱ⺸�� ū ���� ����� ū ���� 3�� �ִ�
	�׷��� 3�� ����
*/

#include <vector>

using namespace std;

vector<int> solution(vector<int> _numbers)
{

	vector<int> answer(_numbers.size(), -1);
	vector<int> stack(_numbers.size(), 0);

	int len = 0;
	for (int i = _numbers.size() - 1; i >= 0; i--) 
	{

		while (len && _numbers[i] >= stack[len - 1])
		{

			len--;
		}

		if (len) answer[i] = stack[len - 1];

		stack[len++] = _numbers[i];
	}

	return answer;
}