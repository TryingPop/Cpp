/*
��¥ : 2024. 7. 14
�̸� : �輺��
���� : ���� ����
	������ ���ĺ� ���� 'A', 'E', 'I', 'O', 'U' ���� ����Ͽ� ���� �� �ִ�,
	���� 5������ ��� �ܾ ���ϵǾ� �ִ�

	�������� ù ��° �ܾ�� "A"�̰�
	�� ������ "AA"�̴�
	������ �ܾ�� "UUUUU"�̴�

	�ܾ� �ϳ� word�� �Ű������� �־��� ��,
	�� �ܾ �������� �� ��° �ܾ�����
	return �ϵ��� solution �Լ��� ����

	word�� ���̴� 1 �̻� 5����
	word�� ���ĺ� �빮�� 'A', 'E', 'I', 'O', 'U'�θ� �̷���� �ִ�


	parameter
	"I"


	return
	1563
*/

#include <string>
#include <vector>

#define MAX 5

using namespace std;

vector<char> v;

inline bool DFS(int _depth, string& _cur, string& _find, int& _ret)
{

	/*
	
	6^6 < 100��
	���ڿ� �ϳ��� �̾���̸� Ž��
	*/

	_ret++;								// ���� ����
	if (_cur == _find) return true;		// ã���� ����
	if (_depth == 5) return false;		// ���� �ʰ��ϸ� ����

	_cur.push_back(v[0]);
	if (DFS(_depth + 1, _cur, _find, _ret)) return true;	// ã�� ��� �ٷ� Ż��

	for (int i = 1; i < v.size(); i++)
	{

		_cur.back() = v[i];
		if (DFS(_depth + 1, _cur, _find, _ret)) return true;	// ã�� ��� �ٷ� Ż��
	}

	_cur.pop_back();
	return false;
}

int solution(string _word)
{

	int answer = -1;
	v = { 'A', 'E', 'I', 'O', 'U' };
	string temp = "";

	DFS(0, temp, _word, answer);

	return answer;
}