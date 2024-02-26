#include <vector>
#include <string>

/*
��¥ : 2024. 2. 26
�̸� : �輺��
���� : ���ڿ� ����
	���ڿ� �迭 strArr�� �־�����
	strArr�� ���ҵ��� ���̰� ���� ���ڿ��鳢��
	�׷����� ������ �� ���� ������ ���� �׷��� ũ�⸦
	return �ϴ� solution �Լ��� ����
*/

using namespace std;

int solution(vector<string> _strArr)
{

	int answer = 0;

	int temp[31]{ 0, };

	for (const string str : _strArr)
	{

		int size = str.length();
		temp[size]++;
	}

	for (int i = 1; i <= 30; i++) 
	{

		if (answer < temp[i]) answer = temp[i];
	}

	return answer;
}