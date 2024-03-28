#include <string>
#include <vector>

/*
��¥ : 2024. 3. 28
�̸� : �輺��
���� : A�� B �����
	���ڿ� before�� after�� �Ű������� �־��� ��,
	before�� ������ �ٲپ� after�� ���� �� ������ 1��,
	���� �� ������ 0�� return �ϵ��� solution �Լ� ����

	before�� after�� ���̴� �׻� ����
	before�� after�� �ҹ��ڷθ� �̷���� �ִ�
*/

using namespace std;

int solution(string _before, string _after)
{

	int answer = 1;

	// ���ĺ� ����
	vector<int> cnt(26, 0);

	for (int i = 0; i < _before.length(); i++) 
	{

		// before�� +, after�� - 
		// ���ĺ� ������ ���ٸ� ��� 0
		// �� ��츸 before�� �ٲپ� after�� �ٲ� �� �ִ�
		cnt[_before[i] - 'a']++;
		cnt[_after[i] - 'a']--;
	}

	for (int i = 0; i < 26; i++)
	{

		if (!cnt[i]) continue;
		answer = 0;
		break;
	}

	return answer;
}