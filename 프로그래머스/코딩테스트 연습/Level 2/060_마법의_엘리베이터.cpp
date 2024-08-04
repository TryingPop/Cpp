/*
��¥ : 2024. 8. 4
�̸� : �輺��
���� : ������ ����������
	������ ������������ ��ư�� Ư���ϴ�
	������ ���������Ϳ��� -1, +1, -100, +100 ��� ����
	���밪�� 10^c(c >= 0 �� ����) ������ �������� ���� ��ư�� �ִ�

	������ ������������ ��ư�� ������ ���� �� ���� ��ư�� 
	���� �ִ� ���� ���� ������ �̵��ϰ� �ȴ�
	
	��, ���������Ͱ� ��ġ�� �ִ� ���� ��ư�� ���� ���� ����� 0���� ������
	���������ʹ� �������� �ʴ´�

	�ּ����� ��ư�� ���� 0������ �̵��Ϸ��� �Ѵ�
	���� ������ ��Ÿ���� storey�� �־����� ��,
	0������ ���� ���� �ʿ��� ������ ���� �ּҰ���
	return �ϴ� solution �Լ� ����

	storey�� 1�� ������ �ڿ���

	parameter
	16


	return
	6


	sol
	+1�� 4������ 20���� �� ��
	-10�� 2�� ���� 0������ ���°� �ּ��̴�
*/

#include <vector>

using namespace std;
#if first
inline int DFS(int _val)
{

	if (_val == 0) return 0;

	int cur = _val % 10;
	int next = _val / 10;

	int ret = DFS(next) + cur;

	if (next || cur > 5)
	{

		int chk = DFS(next + 1) + (10 - cur);
		if (chk < ret) ret = chk;
	}

	return ret;
}
#endif
int solution(int _storey)
{

#if first
	/*
	
	���Ʈ ����
	*/
	int answer = DFS(_storey);
#else

	/*
	
	Greedy
	*/
	int answer = 0;

	while (_storey)
	{

		int cur = _storey % 10;
		_storey /= 10;

		if (cur < 5)
		{

			answer += cur;
		}
		else if (5 < cur)
		{

			answer += 10 - cur;
			_storey++;
		}
		else
		{

			answer += 5;
			int next = _storey % 10;
			if (next >= 5) _storey++;
		}
	}
#endif
	return answer;
}

#include <iostream>

int main(void)
{

	int n;
	cin >> n;

	cout << solution(n);
}