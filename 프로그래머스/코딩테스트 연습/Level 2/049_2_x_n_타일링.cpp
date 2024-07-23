/*
날짜 : 2024. 7. 24
이름 : 배성훈
내용 : 2 x n 타일링
	가로 길이가 2이고 세로 길이가 1인 직사각형 모양의 타일이 있다
	이 직사각형 타일을 이용하여 세로 길이가 2이고 가로길이가 n인
	바닥을 가득 채우려고 한다

	타일을 채우는 방법은 2가지가 있다
	타일을 가로로 배치하는 경우
	타일을 세로로 배치하는 경우

	직사각형의 가로 길이 n이 매개변수로 주어질 때,
	이 직사각형을 채우는 방법의 수를
	return 하는 solution 함수 구현

	가로길이 n은 6만 이하의 자연수
	경우의 수가 많아질 수 있으므로 1'000'000'007로 나눈
	나머지를 return

	parameter
	4

	
	return
	5


	sol
	==,
	||||,
	|=|,
	=||,
	||=

	이 있다
*/

#include <vector>
#include <cmath>

#define MOD 1'000'000'007

using namespace std;

int solution(int _n)
{

	int answer;

#if first

	/*
	
	dp 방법
	*/
	vector<int> dp(max(_n + 1, 2), 0);
	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i <= _n; i++)
	{

		dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
	}

	answer = dp[_n];
#else

	/*
	
	따로 저장하지 않고 정답 구하는거(dp)
	*/
	int b = 1;
	int c = 1;

	for (int i = 2; i <= _n; i++)
	{

		int temp = (b + c) % MOD;
		b = c;
		c = temp;
	}

	answer = c;
#endif
	return answer;
}