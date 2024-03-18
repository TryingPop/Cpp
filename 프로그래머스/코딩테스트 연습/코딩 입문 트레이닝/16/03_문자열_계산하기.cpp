#include <string>

/*
��¥ : 2024. 3. 18
�̸� : �輺��
���� : ���ڿ� ����ϱ�
	my_string�� 3 + 5 ó�� ���ڿ��� �� ����
	���ڿ� my_string�� �Ű������� �־��� ��,
	������ ����� ���� return �ϴ� solution �Լ��� ����

	�����ڴ� +�� -�� �־�����
	0���� �����ϴ� ���ڴ� �־����� �ʴ´�
	���۰� ���� ������ �־����� �ʴ´�
	my_string�� ����� ����� ���밪 10�� ����
	�߰� ��갪�� ���밪 10�� ����
	my_string�� ��� �ϳ��� �����ڰ� ����
	���ڿ� �����ڴ� 1���� �������� ����
*/

using namespace std;

int solution(string _my_string)
{

	int answer = 0;

	int calc = 0;
	bool isDigit = true;
	bool plus = true;

	for (const char c : _my_string)
	{

		if (c == ' ')
		{

			if (isDigit)
			{

				isDigit = false;
				answer += plus ? calc : -calc;
				calc = 0;
			}
			else isDigit = true;
		}
		else if (c == '+') plus = true;
		else if (c == '-') plus = false;
		else calc = calc * 10 + c - '0';
	}

	if (calc != 0) answer += plus ? calc : -calc;
	
	return answer;
}