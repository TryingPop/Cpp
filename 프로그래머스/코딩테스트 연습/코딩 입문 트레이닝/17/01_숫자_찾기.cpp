#include <string>

/*
��¥ : 2024. 3. 19
�̸� : �輺��
���� : ���� ã��
	���� num�� k�� �Ű������� �־��� ��,
	num�� �̷�� ���� �߿� k�� ������,
	num�� �� ���ڰ� �ִ� �ڸ�����
	return �ϰ� ������ -1�� return �ϴ� solution �Լ� ����
*/

using namespace std;

int solution(int _num, int _k) 
{

	int answer = -1;

	string numStr = to_string(_num);
	char find = _k + '0';

	for (int i = 0; i < numStr.length(); i++)
	{

		if (numStr[i] != find) continue;

		answer = i + 1;
		break;
	}

	return answer;
}