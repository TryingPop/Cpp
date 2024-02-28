#include <string>
#include <vector>

/*
��¥ : 2024. 2. 28
�̸� : �輺��
���� : �� ���� ��
	0 �̻��� �� ������ ���ڿ� a, b�� �־��� ��,
	a + b�� ���� ���ڿ��� 
	return�ϴ� solution �Լ��� ����

	a, b�� ���̴� 10������ �� �� �ִ�
	a, b�� ���ڷθ� �̷���� �ְ�
	�տ� 0���� �����ϴ� ���� 0���̴�
*/

using namespace std;

string solution(string _a, string _b)
{

	string answer;

	string min = _a.length() < _b.length() ? _a : _b;
	string max = _a.length() < _b.length() ? _b : _a;

	int lenMin = min.length();
	int lenMax = max.length();

	answer.reserve(lenMax + 1);

	int lenR = lenMax - lenMin;

	for (int i = 0; i < lenR; i++)
	{

		// �պκ� �׳� ä���
		answer.push_back(max[i]);
	}

	for (int i = 0; i < lenMin; i++)
	{

		// ���ڸ� ���ϱ� ����
		int calc = min[i] + max[i + lenR] - '0';
		answer.push_back(calc);
	}

	for (int i = lenMax - 1; i > 0; i--)
	{

		// �ش� ��ġ�� ���� 10 �̻��ΰ� ����
		if (answer[i] > '9') 
		{ 

			answer[i] -= 10; 
			answer[i - 1] += 1;
		}
	}

	// �� ���ڸ� �ڸ��� �÷��� �ϴ��� Ȯ��
	if (answer[0] > '9')
	{

		answer[0] -= 10;
		answer.insert(answer.begin(), '1');
	}

	return answer;
}