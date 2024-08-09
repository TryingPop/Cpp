/*
��¥ : 2024. 8. 9
�̸� : �輺��
���� : ȣ�� ���
	ȣ���� � ���� �ڴϴ� �ּ����� ���Ǹ��� ����Ͽ�
	���� �մԵ��� �������� �Ѵ�

	�� �� ����� ������ ��� �ð��� �������� 10�а� û�Ҹ� �ϰ�
	���� �մԵ��� ����� �� �ִ�

	���� �ð��� ���ڿ� ���·� ��� 
	2���� �迭 book_time�� �Ű������� �־��� ��,
	�ڴϿ��� �ʿ��� �ּ� ������ ���� 
	return �ϴ� solution �Լ��� ����

	book_time�� ���̴� 1'000������ �ڿ���
	book_time�� ���Ҵ� { "HH:MM", "HH:MM" } �����̰�
	{ ��� ���� �ð�, ��� ���� �ð� } �̴�

	�ð��� HH:MM���·� 24�ð� ǥ����� ������ 00:00 ���� 23:59���� �־�����
	����ð��� ������ �ѱ�� ���� ����, ���� �ð��� �׻� ����ð����� ������

	
	parameter
	{ { "15:00", "17:00" }, { "16:40", "18:20" }, { "14:20", "15:20" },
	  { "14:10", "19:20" }, { "18:20", "21:20" } }


	return
	3


	sol
	1�� ���� : 14:10 ~ 19:20
	2�� ���� : 14:20 ~ 15:20 & 16:40 ~ 18:20
	3�� ���� : 15:00 ~ 17:00 & 18:20 ~ 21:20

	�� �Ҵ��ϸ� �ȴ�
*/

#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

inline int ReadTime(string& _time)
{

	int h = (_time[0] - '0') * 10 + _time[1] - '0';
	int m = (_time[3] - '0') * 10 + _time[4] - '0';

	return h * 60 + m;
}

inline bool MyComp(vector<string>& _f, vector<string>& _b)
{

	return _f[0] < _b[0];
}

int solution(vector<vector<string>> book_time)
{

	/*
	
	Greedy
	������ ���� �ð� ���� ������ ������
	�ش� ���ǿ� �ִ��� ���� ���� �Ҵ��� �� �ְ� �Ѵ�
	*/
	int answer = 0;

	sort(book_time.begin(), book_time.end(), MyComp);

#if first

	// N^2 �� ���� ���
	int use = 0;
	int end = book_time.size();
	vector<bool> visit(end, false);

	while (use < end)
	{

		answer++;
		int curTime = 0;
		for (int i = 0; i < end; i++)
		{

			if (visit[i] || ReadTime(book_time[i][0]) < curTime) continue;
			visit[i] = true;
			use++;
			curTime = ReadTime(book_time[i][1]);
		}
	}
#else

	// N log N
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < book_time.size(); i++)
	{

		int curTime = ReadTime(book_time[i][0]);
		while (pq.size() && pq.top() <= curTime)
		{

			pq.pop();
		}

		pq.push(ReadTime(book_time[i][1]) + 10);
		if (answer < pq.size()) answer = pq.size();
	}
#endif
	return answer;
}