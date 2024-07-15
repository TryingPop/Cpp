/*
��¥ : 2024. 7. 15
�̸� : �輺��
���� : ������ũ �ڸ���
	������ũ�� �� �������� �߶� ������ �� ������ ������������ �Ѵ�
	������ũ���� �������� ���ε��� �Ϸķ� �÷��� �ֽ��ϴ�

	ö���� ������ ������ũ�� �����ϰ� ���������� �ϴµ�,
	������ũ�� ũ�⺸�� ������ũ ���� �÷��� ���ε��� ������ �� ������ ����

	�߷��� �������� ũ��� ������ ������ ������ �������
	�� ������ ������ �������� ������ �ö󰡸� �����ϰ� ������ ���̶� �����Ѵ�

	������ũ�� �÷��� ���ε��� ��ȣ�� ������ 
	���� �迭 topping�� �Ű������� �־��� ��,

	������ũ�� �����ϰ� �ڸ��� ����� ����
	return �ϴ� solution �Լ� ����

	topping�� ���Ҵ� 1�� ������ �ڿ���

	parameter
	{ 1, 2, 1, 3, 1, 4, 1, 2 }


	return
	2


	sol
	1 2 1 3  / 1 4 1 2
	�̷��� �ڸ��� ���� 3���� ������ �������� 
	�����ϰ� �ڸ���

	1 2 1 3 1 / 4 1 2
	�̷��� �ڸ��� ���� 3���� ������ �������� 
	�����ϰ� �ڸ���

	�� 2������ �ִ�
*/

#include <vector>
#include <algorithm>

#define MAX 10'001

using namespace std;

int solution(vector<int> _topping)
{

	int answer = 0;

	vector<bool> use(MAX, false);				// ���� ���� ����
	vector<int> r(_topping.size() + 1, 0);		// ������ ������ ����

	for (int i = _topping.size() - 1; i >= 0; i--)
	{

		r[i] = use[_topping[i]] ? r[i]: r[i] + 1;
		use[_topping[i]] = true;
	}

	fill(use.begin(), use.end(), false);
	int l = 0;

	for (int i = 0; i < _topping.size(); i++)
	{

		l = use[_topping[i]] ? l : l + 1;
		use[_topping[i]] = true;

		if (l == r[i + 1]) answer++;
		else if (l < r[i + 1]) break;
	}

	return answer;
}