/*
��¥ : 2024. 6. 22
�̸� : �輺��
���� : �ָ� �ٱ�
    �ѹ��� 1ĭ �Ǵ� 2ĭ�� �� �� �ִ�
    �ָ��ٱ⿡ ���� ĭ�� �� n�� �־��� ��,
    ���� �����ϴ� ����� �� �������� �˾Ƴ�
    1234567�� ���� �������� �����ϴ� solution �Լ��� ����

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