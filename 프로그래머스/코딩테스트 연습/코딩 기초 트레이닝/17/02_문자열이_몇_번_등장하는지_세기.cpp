#include <string>
#include <vector>

/*
��¥ : 2024. 2. 23
�̸� : �輺��
���� : ���ڿ��� �� �� �����ϴ��� ����
	���ڿ� myString�� pat�� �־�����
	myString���� pat�� �����ϴ� Ƚ���� 
	return �ϴ� solution �Լ� ����
*/
using namespace std;

int solution(string _myString, string _pat)
{

	int answer = 0;

	int i = 0;
	while (true)
	{

		i = _myString.find(_pat, i);

		if (i == string::npos) break;

		answer++;
		i++;
	}

	return answer;
}