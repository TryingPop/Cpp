/*
��¥ : 2024. 7. 16
�̸� : �輺��
���� : �湮 ����
	���� ĳ���͸� 4���� ��ɾ ���� �����̷� �Ѵ�
	��ɾ�� ������ ����
	
	U: �������� �� ĭ �̵�
	D: �Ʒ������� �� ĭ �̵�
	R: ���������� �� ĭ �̵�
	L: �������� �� ĭ �̵�

	ĳ���ʹ� ��ǥ����� (0, 0) ��ġ���� �����Ѵ�
	��ǥ����� ���� ���� �� (-5, 5), ���� �Ʒ� (-5, -5),
	������ �� (5, 5), ������ �Ʒ� (5, -5)�� �̷���� �簢�� ���̴�

	�츮�� ĳ���Ͱ� ������ �� �� ĳ���Ͱ� 
	ó�� �ɾ ���� ���̸� ���Ϸ��� �Ѵ�

	�� ��ǥ����� ��踦 �Ѿ�� ��ɾ�� �����Ѵ�

	��ɾ ���ڿ� �Ű����� dirs�� �־��� ��,
	���� ĳ���Ͱ� �ɾ ���̸� ���Ͽ� return �ϴ� solution �Լ� ����

	dirs�� 'U', 'D', 'R', 'L'�� �̷��� �ִ�
	dirs�� ���̴� 500 �����̴�


	parameter
	"LULLLLLLU"


	return
	7


	sol
	7, 8�� ����� ���� ����Ƿ� �����ϰ�
	������ ��η��� �̵��� ���ο� ���̹Ƿ� 7�̴�
*/

#include <string>

#define MAX 5
#define LEN (MAX * 2)

using namespace std;

bool visitR[LEN + 1][LEN];
bool visitC[LEN][LEN + 1];

inline void Init(string& _dirs) 
{

	/*
	
	�湮 ó�� �ʱ�ȭ
	���簢���� ���Ѱ� ������ ���� y���� �����Ƿ� 
	���� ��Ī�ص� �̻���� ���� -1, �Ʒ��� +1������ �Ѵ�
	*/
	for (int i = 0; i < LEN; i++)
	{

		for (int j = 0; j <= LEN; j++)
		{

			visitR[j][i] = false;
			visitC[i][j] = false;
		}
	}

	/*
	
	��ɾ� ���ڷ� ����
	�� : 0, �� : 1, �� : 2, �� : 3
	*/
	for (char& dir : _dirs)
	{

		if (dir == 'R') dir = 0;
		else if (dir == 'L') dir = 1;
		else if (dir == 'D') dir = 2;
		else if (dir == 'U') dir = 3;
	}
}

inline bool ChkInvalidPos(pair<int, int>& _pos)
{

	if (_pos.first < 0 || _pos.second < 0
		|| _pos.first > LEN || _pos.second > LEN) return true;

	return false;
}

int solution(string _dirs)
{

	int answer = 0;

	Init(_dirs);

	pair<int, int> cur(MAX, MAX);

	for (const int op : _dirs)
	{

		pair<int, int> next;
		int r, c;
		
		if (op & 2)
		{

			// ���� �̵�
			if (op & 1) next.first = cur.first - 1;
			else next.first = cur.first + 1;

			next.second = cur.second;

			// ��ȿ�� ��ɾ����� Ȯ��
			if (ChkInvalidPos(next)) continue;

			if (op & 1) r = next.first;
			else r = cur.first;

			c = cur.second;

			// �̵�
			cur = next;

			if (visitC[r][c]) continue;

			visitC[r][c] = true;
			answer++;
		}
		else 
		{
			// �¿� �̵�
			if (op & 1) next.second = cur.second - 1;
			else next.second = cur.second + 1;

			next.first = cur.first;

			// ��ȿ�� ��ɾ����� Ȯ��
			if (ChkInvalidPos(next)) continue;

			if (op & 1) c = next.second;
			else c = cur.second;

			r = cur.first;

			// �̵�
			cur = next;

			// ������ ������ Ȯ��
			if (visitR[r][c]) continue;

			visitR[r][c] = true;
			answer++;
		}
	}

	return answer;
}