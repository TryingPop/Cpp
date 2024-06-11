/*
��¥ : 2024. 6. 12
�̸� : �輺��
���� : ���� ��ȯ �ݺ��ϱ�
	0�� 1�� �̷���� � ���ڿ� x�� ���� ������ȯ�� ������ ���� �����Ѵ�
	
	1. x�� ��� 0�� �����Ѵ�
	2. x�� ���̸� c��� �ϸ�, c�� 2�������� ǥ���� ���ڿ��� �ٲ۴�

	0�� 1�� �̷���� ���ڿ� s�� �Ű������� �־��� ��,
	s�� "1"�� �� ������ ����ؼ� s�� ������ȯ�� ������ ��,
	���� ��ȯ Ƚ���� ��ȯ �������� ���ŵ� ��� 0�� ������
	���� �迭�� ��� return �ϴ� solution �Լ��� ����

	parameter
	"110010101001"
	
	return
	3, 8
*/

#include <vector>
#include <string>

using namespace std;

vector<int> solution(string _s)
{

	vector<int> answer(2, 0);

	int len = _s.length();
	while (len)
	{

		// 0 ����
		int remove = 0;
		for (int i = 0; i < len; i++)
		{

			if (_s[i] = '1') continue;
			remove++;
		}

		len -= remove;

		// 0�� ������ ���ڿ��� ���̸� 2���� ��ȯ
		int nextLen = 0;

		// ���������� ����
		while (len)
		{

			if (len & 1) _s[nextLen++] = '1';
			else _s[nextLen++] = '0';

			len >>= 1;
		}

		// �������� ����������
		for (int i = 0; i < nextLen; i++)
		{

			int other = nextLen - 1 - i;
			if (other <= i) break;

			char temp = _s[i];
			_s[i] = _s[other];
			_s[other] = temp;
		}

		// ��� ����
		len = nextLen;
		answer[0]++;
		answer[1] += remove;
	}

	return answer;
}