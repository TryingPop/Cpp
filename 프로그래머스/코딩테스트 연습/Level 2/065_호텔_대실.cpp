/*
날짜 : 2024. 8. 9
이름 : 배성훈
내용 : 호텔 대실
	호텔을 운영 중인 코니는 최소한의 객실만을 사용하여
	예약 손님들을 받으려고 한다

	한 번 사용한 객실은 퇴실 시간을 기준으로 10분간 청소를 하고
	다음 손님들이 사용할 수 있다

	예약 시각이 문자열 형태로 담긴 
	2차원 배열 book_time이 매개변수로 주어질 때,
	코니에게 필요한 최소 객실의 수를 
	return 하는 solution 함수를 구현

	book_time의 길이는 1'000이하의 자연수
	book_time의 원소는 { "HH:MM", "HH:MM" } 형태이고
	{ 대실 시작 시간, 대실 종료 시각 } 이다

	시각은 HH:MM형태로 24시간 표기법을 따르며 00:00 에서 23:59까지 주어진다
	예약시각이 자정을 넘기는 경우는 없고, 시작 시각은 항상 종료시각보다 빠르다

	
	parameter
	{ { "15:00", "17:00" }, { "16:40", "18:20" }, { "14:20", "15:20" },
	  { "14:10", "19:20" }, { "18:20", "21:20" } }


	return
	3


	sol
	1번 객실 : 14:10 ~ 19:20
	2번 객실 : 14:20 ~ 15:20 & 16:40 ~ 18:20
	3번 객실 : 15:00 ~ 17:00 & 18:20 ~ 21:20

	을 할당하면 된다
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
	객실을 예약 시간 시작 순서로 정렬해
	해당 객실에 최대한 많은 방을 할당할 수 있게 한다
	*/
	int answer = 0;

	sort(book_time.begin(), book_time.end(), MyComp);

#if first

	// N^2 인 느린 경우
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