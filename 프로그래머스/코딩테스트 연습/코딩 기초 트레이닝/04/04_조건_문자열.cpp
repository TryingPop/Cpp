#include <string>

/*
��¥ : 2024. 2. 10
�̸� : �輺��
���� : ���� ���ڿ�
	���ڿ��� ���� �� ���� ũ�⸦ ��
	ineq �� '<', '>' �� �ϳ�
	eq�� '=' �� '!'�� �ϳ�

	ineq�� eq�� �̾� �ٿ��� ��, <=, >=�� �״�� �ǹ��̰� <!�� >! �� <, > ������ �ǹ�
	n, m �� ineq�� eq�� ������ 1 �ƴϸ� 0�� ����
*/

using namespace std;

int solution(string _ineq, string _eq, int _n, int _m)
{

	int answer = 0;

	if (_ineq == "<") 
	{

		if (_eq == "=") answer = _n <= _m;
		else answer = _n < _m;
	}
	else 
	{

		if (_eq == "=") answer = _n >= _m;
		else answer = _n > _m;
	}
	return answer;
}