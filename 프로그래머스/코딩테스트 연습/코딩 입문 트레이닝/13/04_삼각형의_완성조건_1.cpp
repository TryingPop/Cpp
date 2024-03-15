#include <vector>

/*
��¥ : 2024. 3. 15
�̸� : �輺��
���� : �ﰢ���� �ϼ����� 1
	���� �� ���� �ﰢ���� ����� ���ؼ���
	���� ������ �����ؾ��Ѵ�

	���� �� ���� ���̴� �ٸ� �κ��� ������ �պ���
	�۾ƾ� �Ѵ�

	�ﰢ���� ������ ���̰� ��� �迭 sides�� �Ű�������
	�־��� ��, �� ������ �ﰢ���� ���� �� �ִٸ� 1��
	���� �� ���ٸ� 2�� return �ϴ� solution �Լ� ����
*/

using namespace std;

int solution(vector<int> _sides)
{

	int answer;

	// �����ؼ� �ϰų� ��Ȳ �����°ɷ� �ص� �ǳ�
	// ������ Ȯ���ϴ� ���Ʈ ������ �ߴ�
	bool possible = _sides[0] < _sides[1] + _sides[2];
	possible &= _sides[1] < _sides[2] + _sides[0];
	possible &= _sides[2] < _sides[0] + _sides[1];

	answer = possible ? 1 : 2;
	return answer;
}