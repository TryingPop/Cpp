/*
날짜 : 2024. 6. 22
이름 : 배성훈
내용 : 멀리 뛰기
    한번에 1칸 또는 2칸을 뛸 수 있다
    멀리뛰기에 사용될 칸의 수 n이 주어질 때,
    끝에 도달하는 방법이 몇 가지인지 알아내
    1234567를 나눈 나머지를 리턴하는 solution 함수를 구현

    parameter
    4


    return
    5
*/

#include <string>
#include <vector>
#include <iostream>

typedef long long ll;

using namespace std;

#if first
const int MOD = 1'234'567;
int maxDepth;
vector<int> dp(2'001, -1);

int DFS(int _n)
{

    if (_n == maxDepth) return 1;
    else if (_n > maxDepth) return 0;

    int& ret = dp[_n];
    if (ret > -1) return ret;
    ret = 0;

    ret = DFS(_n + 1);
    ret = (ret + DFS(_n + 2)) % MOD;

    return ret;
}

ll solution(int _n) {

    maxDepth = _n;
    ll answer = DFS(0);

    return answer;
}
#else

const int MOD = 1'234'567;

ll solution(int _n) {

    ll answer = 1, before = 0, next;

    for (int i = 0; i < _n; i++)
    {

        next = (answer + before) % MOD;
        before = answer;
        answer = next;
    }

    return answer;
}

#endif