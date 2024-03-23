#include <vector>
#include <string>

/*
��¥ : 2024. 3. 23
�̸� : �輺��
���� : �ܰ�� ����
	���ĺ��� ��� �迭 speel��
	�ܰ�� ���� dic�� �Ű������� �־��� ��,

	speel�� ��� ���ĺ��� �ѹ����� ��� �����
	�ܾ dic�� �����Ѵٸ� 1,
	�������� �ʴ´ٸ� 2�� return �ϵ���
	solution �Լ� ����

	spell�� ������ ũ��� 1�̴�
	spell�� ���Ҹ� ��� �����
	�ܾ ������ �Ѵ�
*/

using namespace std;

int solution(vector<string> _spell, vector<string> _dic)
{

	int answer = 2;

	vector<int> cnt(26, 0);

	for (const string str : _dic)
	{

		for (const char c : str)
		{

			// ����� �ܾ� ���
			int idx = c - 'a';
			cnt[idx]++;
		}

		bool exsist = true;
		for (const string c : _spell)
		{

			// ������ �ܾ ��� 1������ 
			// ����ߴ��� Ȯ��
			int idx = c[0] - 'a';
			if (cnt[idx] != 1) exsist = false;
			cnt[idx] = 0;
		}

		if (!exsist) continue;
		// �߰��� ��� 1���ϰ� ����
		answer = 1;
		break;
	}

	return answer;
}