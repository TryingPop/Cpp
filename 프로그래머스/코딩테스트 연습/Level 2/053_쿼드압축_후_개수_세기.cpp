/*
��¥ : 2024. 7. 28
�̸� : �輺��
���� : ������� �� ���� ����
	0�� 1�� �̷���� 2^n x 2^n ũ���� 2���� ���� �迭 arr�� �ִ�
	arr�� ���� Ʈ���� ���� ������� �����ϰ��� �Ѵ�

	�����ϰ��� �ϴ� Ư�� ������ S�� ����

	���� S ���ο� �ִ� ��� ���� ���� ���̶��
	S�� �ش� �� �ϳ��� �����Ų��

	�׷��� �ʴٸ� S�� ��Ȯ�� 4���� ������ ���簢�� �������� �ɰ� ��,
	�� ���簢�� ������ ���� ���� ����� ������ �õ��Ѵ�

	arr�� �Ű������� �־�����
	���� ���� ������� arr�� �������� ��,
	�迭�� ���������� ���� 0�� ������ 1�� ������ �迭�� ��Ƽ�
	return �ϴ� solution �Լ� ����

	arr�� ���� ������ 1 �̻� 1024 �����̰�,
	2�� �ŵ� ������ ���¸� �ϰ� �ִ�

	arr�� ���� ������ ���� ������ ���� ���簢�� �迭�̴�
	arr�� ��� ���� 0 �Ǵ� 1�̴�

	parameter
	{ { 1, 1, 0, 0 },
	  { 1, 0, 0, 0 },
	  { 1, 0, 0, 1 },
	  { 1, 1, 1, 1 } }


	return
	{ 4, 9 }


	sol
	��� ���Ұ� ���� �����Ƿ� 4��� �Ѵ�

	1 1	| 0 0
	1 0	| 0 0
	---- ----
	1 0 | 0 1
	1 1 | 1 1

	�׷��� ���� ��, ���� �Ʒ�, ������ �Ʒ��� ���� 
	1, 0 ���� ���ϵǾ��� ���� �ʾ� �״�� �ȴ�

	������ ���� 0���� ��� ���� 0���� ��������
	�׷���
	1 1 |
	1 0 | 0
	---- -----
	1 0 | 0 1
	1 1 | 1 1

	���� 0�� 4��, 1�� 9���� ���´�
*/

#include <vector>

#define ll long long

using namespace std;

// 1õ�� �̻� �ڸ��� 1�� ���� ���Խ�Ų��
const ll ONE = 10'000'000;
// 1õ�� �̸� �ڸ��� 1�� ���� ���Խ�Ų��
const ll ZERO = 1;

inline bool ChkNum(ll _num1, ll _num2, ll _num3, ll _num4, ll _chk)
{

	/*
	
	num1 ~ num4�� chk�� ������ Ȯ��
	*/
	return _num1 == _chk && _num2 == _chk && _num3 == _chk && _num4 == _chk;
}

inline ll DNC(vector<vector<int>>& _board, int _r, int _c, int _size)
{

	/*
	
	1�� ������ 1õ�� �̻� �ڸ��� �ִ�
	0�� ������ 1õ�� �̸��� �ڸ��� ��
	*/
	if (_size == 1)
	{

		// Ż�� �ڵ�
		if (_board[_r][_c] == 1) return ONE;
		else return ZERO;
	}

	// ����
	int midSize = _size >> 1;

	ll num1 = DNC(_board, _r, _c, midSize);
	ll num2 = DNC(_board, _r + midSize, _c, midSize);
	ll num3 = DNC(_board, _r, _c + midSize, midSize);
	ll num4 = DNC(_board, _r + midSize, _c + midSize, midSize);

	// ����
	if (ChkNum(num1, num2, num3, num4, ONE)) return ONE;
	else if (ChkNum(num1, num2, num3, num4, ZERO)) return ZERO;

	return num1 + num2 + num3 + num4;
}

vector<int> solution(vector<vector<int>> _arr)
{

	/*
	
	���� ����
	*/
	vector<int> answer(2);
	int size = _arr.size();

	ll ret = DNC(_arr, 0, 0, size);

	answer[0] = ret % ONE;
	answer[1] = ret / ONE;

	return answer;
}