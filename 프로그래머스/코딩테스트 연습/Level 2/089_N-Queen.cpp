/*
��¥ : 2024. 9. 2
�̸� : �輺��
���� : N-Queen
	����, ���� ���̰� n�� ���簢�����ε� ü������ �ִ�
	ü���� ���� n���� ���� ���θ� ������ �� ������ ��ġ�ϰ� �ʹ�

	ü������ ���� ���� �� ���� n�� �Ű������� �־��� ��,
	n���� ���� ���ǿ� �����ϵ��� ��ġ�� �� �ִ�
	����� ���� return �ϴ� solution �Լ� ����

	��(Queen)�� ����, ����, �밢������ �̵��� �� �ִ�
	n�� 12 ������ �ڿ����̴�

	parameter
	4


	return
	2


	sol
	X�� �����, Q�� �� ��ġ�� �� ��
	���� ������� ��ġ�ϸ� �ȴ�
		X	X	Q	X
		Q	X	X	X
		X	X	X	Q
		X	Q	X	X
	�׷��� ������ ���� �������� ���Ѵ�

	���������� ������ ���� ��ġ�ص� �ȴ�
		X	Q	X	X
		X	X	X	Q
		Q	X	X	X
		X	X	Q	X
	
	�̿��� ���� ����
*/

#include <vector>

using namespace std;

vector<bool> ldia, rdia, h;

inline int DFS(int _depth, int _n)
{

	/*
	
	����� ���� ã�´�
	*/

	// �� n���� ä�� ���
	if (_depth == _n) return 1;
	int ret = 0;

	for (int i = 0; i < _n; i++)
	{

		// ����, �´밢(/), ��밢(\) ����� Ȯ��
		if (h[i] || ldia[_depth + i] || rdia[_n - 1 + i - _depth]) continue;
		h[i] = true;
		ldia[_depth + i] = true;
		rdia[_n - 1 + i - _depth] = true;

		ret += DFS(_depth + 1, _n);

		h[i] = false;
		ldia[_depth + i] = false;
		rdia[_n - 1 + i - _depth] = false;
	}

	return ret;
}

int solution(int _n)
{

	/*
	
	��Ʈ��ŷ
	*/
	ldia.resize(2 * _n - 1, false);
	rdia.resize(2 * _n - 1, false);
	h.resize(_n, false);

	int answer = DFS(0, _n);

	return answer;
}