#include <string>

/*
��¥ : 2024. 3. 15
�̸� : �輺��
���� : ��Ʈ�� ��Ʈ
	���ڿ� "Z"�� �������� ���еǾ� ��� ���ڿ��� �־��� ��,
	���ڿ��� �ִ� ���ڸ� ���ʴ�� ���Ϸ��� �Ѵ�

	�� �� "Z"�� ������ �ٷ� ���� ���ߴ� ���ڸ� ���ٴ� ��
	���ڿ� "Z"�� �̷���� ���ڿ� s�� �־��� ��,

	�ش� ��Ģ�� ������ ���� return �ϴ� solution �Լ� ����

	"Z"�� ���ڴ� �������� ���еǾ��� �ִ�
	"Z"�� �������� �ʰ� �����ؼ� "Z"�� ������ �ʴ´�
	���� 0�� �����ϰ�� 0���� �����ϴ� ���ڴ� ����
	�������� �����ϰų� �������� ������ ������ �����ؼ�
	������ ������ �ʴ´�
*/

using namespace std;

int solution(string _s)
{

	int answer = 0;

	int before = 0;
	int calc;
	bool plus = true;

	for (const char c : _s) 
	{

		if (c == ' ')
		{

			// ���� �߰� �� ���� �ֱ�
			calc = plus ? calc : -calc;
			answer += calc;
			before = calc;
			calc = 0;
			plus = true;
		}
		else if (c == '-') plus = false;
		else if (c == 'Z') answer -= before;
		else calc = calc * 10 + c - '0';
	}

	if (calc != 0)
	{

		calc = plus ? calc : -calc;
		answer += calc;
	}

	return answer;
}