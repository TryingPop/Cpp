#include <string>
/*
��¥ : 2024. 2. 27
�̸� : �輺��
���� : ���� �κ�
	�Ǽ� flo�� �Ű������� �־��� ��,
	flo�� ���� �κ��� return �ϵ��� solution �Լ��� ����
*/

using namespace std;

int solution(double flo)
{

	// int answer = (int)flo;
	int answer = 0;

	string strFlo = to_string(flo);
	for (const char c : strFlo)
	{

		if (c == '.') break;
		answer = answer * 10 + c - '0';
	}

	return answer;
}