/*
��¥ : 2024. 7. 31
�̸� : �輺��
���� : �ﰢ ������
	���� n�� �Ű������� �־�����
	���̿� ���̰� n�� �ﰢ�� �� �� ����������
	�ݽð� �������� ������ ä��⸦ ������ ��,
	ù ����� ������ ����� ��� ������� ��ģ ���ο� �迭��
	return �ϴ� solution �Լ� ����

	n�� 1 �̻� 1'000 ������ ����

	parameter
	4


	return
	{ 1, 2, 9, 3, 10, 8, 4, 5, 6, 7 }


	sol

	�ʱ� �ﰢ���� �ε����� ������ ����
					0
				1		2
			3		4		5
		6		7		8		9


	������ ������� ��ȣ�� �ο��ϸ�
					1
				2		9
			3		10		8
		4		5		6		7
	�̴�

	�׷��� { 1, 2, 9, 3, 10, 8, 4, 5, 6, 7 }�� �����̴�
*/

#include <vector>

#define pii pair<int, int>

using namespace std;

inline int PosToInt(const pii& _pos)
{

	/*
	
	��ǥ�� ����� �ε����� ����
	*/
	return (_pos.first * _pos.first + _pos.first) / 2 + _pos.second;
}

inline void MoveByType(pii& _pos, int _type)
{

	/*
	
	Ÿ�Ժ� ��ǥ �̵�
	type 0 : ���� �Ʒ� ����(/)
	type 1 : ������ ���� (-)
	type 2 : ���� �� ���� (\)
	*/

	switch (_type)
	{

	case 0:
		_pos.first++;
		return;

	case 1:
		_pos.second++;
		return;

	case 2:
		_pos.first--;
		_pos.second--;
		return;

	default:
		return;
	}
}

inline void LastMoveByType(pii& _pos, int _type)
{

	/*
	
	�� �����ϰ� ��ǥ�̵��� �� �����ϱ⿡
	������ �κп� ������ �ʿ��ϴ�
	*/
	switch (_type)
	{

	case 0:
		_pos.first--;
		_pos.second++;
		return;

	case 1:
		_pos.first -= 1;
		_pos.second -= 2;
		return;

	case 2:
		_pos.first += 2;
		_pos.second += 1;
		return;

	default:
		return;
	}
}

inline void FillRet(pii& _pos, int _type, int _s, int _n, vector<int>& _ret)
{

	/*
	
	�ùķ��̼�
	�ﰢ������ ������� ��ĭ�� �̵��Ѵ�
	���� �Ʒ� -> ������ -> ���� �� ������ �ݺ��Ǿ�
	Ÿ�Կ� ���� ��ͷ� ����
	*/

	// ���� ���̰� 0�̸� Ż��
	if (_n == 0) return;

	for (int i = 0; i < _n; i++)
	{

		int idx = PosToInt(_pos);
		_ret[idx] = _s++;

		MoveByType(_pos, _type);
	}

	LastMoveByType(_pos, _type);

	FillRet(_pos, (_type + 1) % 3, _s, _n - 1, _ret);
}

vector<int> solution(int _n)
{

	/*

	�ùķ��̼�, ����
	������ ������� ��ĭ�� �̵��ϸ� ���� ä�� �ִ´�
	*/

	vector<int> answer((_n * _n + _n) / 2);
	pii pos(0, 0);

	FillRet(pos, 0, 1, _n, answer);

	return answer;
}