#include <string>
#include <vector>

/*
��¥ : 2024. 3. 22
�̸� : �輺��
���� : ĳ������ ��ǥ
	up, down, left, right�� 4���� ����Ű�� ������,
	���� Ű�� ������ ������ġ���� ����
	{ 0, 1 }, { 0, -1 }, { -1, 0 }, { 1, 0 }
	�� �̵��մϴ�

	ĳ���ʹ� �׻� { 0, 0 } ���� �����ϰ�
	�Է��� ����Ű�� �迭 keyinput��
	���� ũ�� board�� �Ű������� �־�����

	���� ������ ����� Ű �Է��� ������ ��,
	Ű �Է��� ��� ���� �ڿ� ĳ������ ��ǥ { x, y }��
	return �ϴ� solution �Լ� ����

	board�� { a, b }�� �����̸�,
	a, b�� ��� Ȧ���̴�

	������� board = { 5, 3 } �ΰ��
	x�� ������ -2 ~ 2�����̰�, y�� ������ -1 ~ 1�����̴�
*/

using namespace std;

vector<int> solution(vector<string> _keyinput, vector<int> _board)
{

	vector<int> answer;
	answer.reserve(2);

	// ���� Ű
	const string UP = "up";
	const string DOWN = "down";
	const string LEFT = "left";
	const string RIGHT = "right";

	int x = 0;
	int y = 0;

	// ��輱 Ȯ�ο� ����
	int supX = _board[0] / 2;
	int supY = _board[1] / 2;

	for (const string s : _keyinput)
	{

		// Ű�Է¿� ���� ��ǥ�̵�
		if (s == UP) y++;
		else if (s == DOWN) y--;
		else if (s == LEFT) x--;
		else if (s == RIGHT) x++;

		// ��輱�� ����� �̵��� ��� Ű �Է� ����
		if (x > supX) x = supX;
		else if (x < -supX) x = -supX;

		if (y > supY) y = supY;
		else if (x < -supY) y = -supY;
	}

	answer.push_back(x);
	answer.push_back(y);

	return answer;
}