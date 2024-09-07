/*
��¥ : 2024. 9. 7
�̸� : �輺��
���� : ���̽�ƽ
	���̽�ƽ���� ���ĺ� �̸��� �ϼ��Ͻÿ�
	�� ó���� A�θ� �̷���� �ִ�
	�ϼ��ؾ� �ϴ� �̸��� ���̸�ŭ A�� ä���� �ִ�

	���̽�ƽ�� ���� �����̸� ���� ���ĺ�����
	
	���̽�ƽ�� �Ʒ��� �����̸� ���� ���ĺ����� �� �� �ִ�
	A�� Z�� ����

	���̽�ƽ�� �������� �����̸� Ŀ���� �������� �̵��Ѵ� 
	Ŀ���� ó���� �ִ� ��쿡 ���� ���������� ����

	���̽�ƽ�� ���������� �����̸� Ŀ���� ���������� �̵��Ѵ�
	Ŀ���� ������ ��ġ�� �ִ� ��� ó�� ��ġ�� ����

	������� �ϴ� �̸� name�� �Ű������� �־��� ��,
	�̸��� ���� ���̽�ƽ ���� Ƚ���� �ּڰ��� 
	return �ϴ� solution �Լ� ����

	name�� ���ĺ� �빮�ڷθ� �̷���� �ִ�
	name�� ���̴� 1 �̻� 20 ���ϴ�

	parameter
	JAN

	
	return
	23


	sol
	�ʱ⿡ ���´� name�� ���̸�ŭ A�� �ְ� Ŀ���� ó���� ����Ű�� �ִ�
		AAA
		|

	ó�� ���ڸ� ���� 9ȸ �̵��ؼ� J�� �ٲ۴� 
		JAA
		|

	Ŀ���� �������� 1ȸ �̵��Ѵ�
		JAA
		  |

	�׸��� A�� N���� �ٲ۴�
	���� 13ȸ �ű��, �Ʒ��� 13ȸ �Ű� N���� �ٲ۴�
		JAN

	�׷��� 9 + 1 + 13 = 23���� �ּҰ� �ȴ�
*/

#include <string>

#define Min(X, Y)	((X < Y) ? X : Y)

using namespace std;

inline int MinMove(char _dst)
{

	/*
	
	�� �Ʒ� �̵� Ȯ��
	*/
	int chk1 = _dst - 'A';
	int chk2 = 1 + 'Z' - _dst;
	return Min(chk1, chk2);
}

inline int MinDis(int _s, int _e, int _len)
{

	/*
	
	���������� �� ���� �� ����� �� Ȯ��
	*/
	if (_len <= _s) _s -= _len;
	if (_len <= _e) _e -= _len;

	return Min(Min(_s, _len - _s), Min(_e, _len - _e));
}

int solution(string _name)
{

	/*
	
	�׸���
	���ڿ��� ���̸� N
	�ð����⵵�� O(N^2)
	*/
	int answer = 1'000'000;

	int len = _name.length();
	
	_name.reserve(len << 1);
	_name += _name;

	for (int s = 0; s < len; s++)
	{

		int move = 0;
		int cnt = 0;

		for (int i = 0; i < len; i++)
		{

			if (_name[s + i] == 'A') continue;

			move = i;
			cnt += MinMove(_name[s + i]);
		}

		cnt += move;
		cnt += MinDis(s, s + move, len);

		answer = Min(answer, cnt);
	}

	return answer;
}