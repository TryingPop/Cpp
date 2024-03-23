#include <vector>

/*
��¥ : 2024. 3. 23
�̸� : �輺��
���� : �ﰢ���� �ϼ����� 2
	���� �� ���� �ﰢ���� ����� ���ؼ���
	���� �� ���� ���̴� �ٸ� �κ��� ������
	�պ��� �۾ƾ��Ѵ�

	�ﰢ���� �� ���� ���̰� ��� �迭
	sides�� �Ű������� �־��� ��,

	������ �� ���� �� �� �ִ�
	������ ������ return �ϵ���
	solution �Լ��� ����

	sides�� ������ ũ��� 1 �̻� 1000 ������ �ڿ����̴�
*/

using namespace std;

bool ChkTriangle(int _a, int _b, int _c)
{

	// �ﰢ���� �Ǵ��� Ȯ��
	if (_a + _b <= _c || _b + _c <= _a || _c + _a <= _b) return false;
	return true;
}

int solution(vector<int> _sides)
{

	int answer = 0;
	for (int i = 1; i <= 2'000; i++)
	{

		if (ChkTriangle(_sides[0], _sides[1], i)) answer++;
	}

	return answer;
}