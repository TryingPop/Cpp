#include <string>
#include <vector>
#define MUL 26

/*
��¥ : 2024. 3. 26
�̸� : �輺��
���� : �˾��� 1
	���ڿ� �迭 babbling�� �Ű������� �־��� ��,
	babbling���� aya, ye, woo, ma �� ���� ������ �ִ�
	�� ���� ����� ������ �ܾ��� ������ return�ϵ���
	solution �Լ��� ����

	babbling�� �� ���ڿ����� aya, ye, woo, ma��
	���� �ִ� 1������ �����Ѵ�

	���ڿ��� ���ĺ� �ҹ��ڷθ� �̷���� �ִ�
*/

using namespace std;

int solution(vector<string> _babbling)
{

	int answer = 0;

	// ���ڸ� ���ڷ� ���� �ذ�
	int i1 = 'a' * MUL * MUL + 'y' * MUL + 'a';
	int i2 = 'y' * MUL + 'e';
	int i3 = 'w' * MUL * MUL + 'o' * MUL + 'o';
	int i4 = 'm' * MUL + 'a';

	for (const string str : _babbling)
	{

		int calc = 0;
		for (const char c : str)
		{

			if (20'000 < calc) break;

			calc = calc * MUL + c;

			if (calc == i1 || calc == i2 || calc == i3 || calc == i4) calc = 0;
		}

		if (!calc) answer++;
	}

	return answer;
}