#include <string>

/*
��¥ : 2024. 3. 28
�̸� : �輺��
���� : ������ ���ϱ�
	�������� �ǹ��ϴ� �� ���� ���ڿ� 
	bin1�� bin2�� �Ű������� �־��� ��,
	�� �������� �� ���ڿ��� return �ϵ��� solution �Լ� ����

	bin1�� bin2�� ���̴� 10�����̴�
	0�� �����ϰ�� 0���� �������� �ʴ´�
*/

using namespace std;

int sToi(string& _str) 
{

	int ret = 0;
	for (int i = _str.length() - 1; i >= 0; i--)
	{

		if (_str[i] == '1') ret |= 1 << i;
	}

	return ret;
}

string solution(string _bin1, string _bin2)
{

	string answer;
	// ������ �������� 10�ڸ� + 10�ڸ� <= 11�ڸ�
	answer.reserve(11);

	int b1 = sToi(_bin1);
	int b2 = sToi(_bin2);

	int add = b1 + b2;
	bool start = false;
	for (int i = 10; i >= 0; i--)
	{

		if (!start)
		{

			if ((1 << i) & add) 
			{ 
				
				answer.push_back('1'); 
				start = true;
			}

			continue;
		}

		if ((1 << i) & add) answer.push_back('1');
		else answer.push_back('0');
	}

	if (answer.empty()) answer.push_back('0');
	return answer;
}