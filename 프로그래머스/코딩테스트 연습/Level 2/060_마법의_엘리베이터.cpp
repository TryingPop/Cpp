/*
날짜 : 2024. 8. 4
이름 : 배성훈
내용 : 마법의 엘리베이터
	마법의 엘리베이터의 버튼은 특별하다
	마법의 엘리베이터에는 -1, +1, -100, +100 등과 같이
	절대값이 10^c(c >= 0 인 정수) 형태인 정수들이 적힌 버튼이 있다

	마법의 엘리베이터의 버튼을 누르면 현재 층 수에 버튼에 
	적혀 있는 값을 더한 층으로 이동하게 된다
	
	단, 엘리베이터가 위치해 있는 층과 버튼의 값을 더한 결과가 0보다 작으면
	엘리베이터는 움직이지 않는다

	최소한의 버튼을 눌러 0층으로 이동하려고 한다
	현재 층수를 나타내는 storey가 주어졌을 때,
	0층으로 가기 위해 필요한 마법의 돌의 최소값을
	return 하는 solution 함수 구현

	storey는 1억 이하의 자연수

	parameter
	16


	return
	6


	sol
	+1을 4번눌러 20층을 간 뒤
	-10을 2번 눌러 0층으로 가는게 최소이다
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
	
	브루트 포스
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