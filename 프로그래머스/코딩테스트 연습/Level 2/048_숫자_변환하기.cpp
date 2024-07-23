/*
��¥ : 2024. 7. 24
�̸� : �輺��
���� : ���� ��ȯ�ϱ�
	�ڿ��� x�� y�� ��ȯ�Ϸ��� �Ѵ�
	����� �� �ִ� ������ ������ ����

	x�� n�� ���Ѵ�
	x�� 2�� ���Ѵ�
	x�� 3�� ���Ѵ�

	�ڿ��� x, y, n�� �Ű������� �־��� ��,
	x�� y�� ��ȯ�ϱ� ���� �ʿ��� �ּ� ����Ƚ����
	return �ϴ� solution �Լ� ����

	x�� y�� ���� �� ���ٸ� -1�� return

	parameter
	10, 40, 5


	return
	2


	sol
	10�� 2�� ���� 20
	20�� 2�� ���� 40
	���°� ������ ��Ʈ��
*/

#include <vector>
#include <queue>

#define NOT_VISIT -1

using namespace std;

inline bool ChkNext(int _next, int _e, const vector<int>& _visit)
{

	/*
	
	�湮 ���߰� ��ȿ���� Ȯ��
	*/
	return (_next <= _e && _visit[_next] == NOT_VISIT);
}

inline int BFS(int _s, int _e, int _add)
{

	/*
	
	s���� e�� ���� �ּ� ���� BFS�� ã�´�
	*/
	queue<int> q;
	vector<int> visit(_e + 1, NOT_VISIT);

	q.push(_s);
	visit[_s] = 0;

	while (q.size()) 
	{

		int node = q.front();
		q.pop();

		int cur = visit[node];
		int next = node + _add;
		if (ChkNext(next, _e, visit))
		{

			q.push(next);
			visit[next] = cur + 1;
		}

		next = node * 2;
		if (ChkNext(next, _e, visit))
		{

			q.push(next);
			visit[next] = cur + 1;
		}

		next = node * 3;
		if (ChkNext(next, _e, visit))
		{

			q.push(next);
			visit[next] = cur + 1;
		}
	}

	return visit[_e];
}

int solution(int _x, int _y, int _n)
{

	int answer = BFS(_x, _y, _n);

	return answer;
}