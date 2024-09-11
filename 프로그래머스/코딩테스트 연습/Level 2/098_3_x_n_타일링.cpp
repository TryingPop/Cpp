/*
날짜 : 2024. 9. 11
이름 : 배성훈
내용 : 3 x n 타일링
	가로 길이가 2이고 세로의 길이가 1인 직사각형 모양의 타일이 있다
	이 직사각형 타일을 이용하여 세로의 길이가 3이고
	가로의 길이가 n인 바닥을 가득 채우려고 한다
	타일을 채울 때는 다음과 같은 2가지 방법이 있다

	타일을 가로로 배치하는 경우
	타일을 세로로 배치하는 경우

	직사각형의 가로의 길이 n이 매개변수로 주어질 때,
	이 직사각형을 채우는 방법의 수를 return하는 solution 함수 구현

	가로의 길이 n은 5'000이하의 자연수
	경우의 수가 많아질 수 있으므로 1'000'000'007로 나눈 나머지를 return

	parameter
	4


	return
	11
*/

#include <vector>

#define ll long long
#define MOD 1'000'000'007

using namespace std;

int solution(int _n)
{

    /*

    dp 문제
    만들수 있는 모형으로 접근해도 되고
    크기가 작아 해당 위치의 비트마스킹으로도 접근해도 된다

    여기서는 비트마스킹으로 접근했다
    */
    vector<vector<ll>> dp(_n + 1, vector<ll>(1 << 3, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= _n; i++)
    {

        dp[i][0] = (dp[i - 1][1] + dp[i - 1][4] + dp[i - 1][7]) % MOD;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][6]) % MOD;
        dp[i][2] = dp[i - 1][5];
        dp[i][3] = dp[i - 1][4];
        dp[i][4] = (dp[i - 1][0] + dp[i - 1][3]) % MOD;
        dp[i][5] = dp[i - 1][2];
        dp[i][6] = dp[i - 1][1];
        dp[i][7] = dp[i - 1][0];
    }

    int answer = dp[_n][0];
    return answer;
}
}