/*
날짜 : 2024. 7. 8
이름 : 배성훈
내용 : 타겟 넘버
    n개의 음이아닌 정수들이 있다
    이 정수들을 순서를 바꾸지 않고
    적절히 더하거나 빼서 타겟 넘버를 만들려고 한다

    사용할 수 있는 숫자가 담긴 배열 numbers,
    타겟 넘버 target이 매개변수로 주어질 때

    숫자를 적절히 더하고 빼서 타겟 넘버를 만드는 방법의 수를
    return 하는 solution 함수 구현


    parameter
    { 1, 1, 1, 1, 1 }, 3


    return
    5


    sol
    -1 +1 +1 +1 +1 = 3
    +1 -1 +1 +1 +1 = 3
    +1 +1 -1 +1 +1 = 3
    +1 +1 +1 -1 +1 = 3
    +1 +1 +1 +1 -1 = 3

    이렇게 5가지 만들 수 있다
*/

#if first

#include <string>
#include <vector>

using namespace std;

int DFS(vector<int>& _num, int& _target, int _depth = 0, int _val = 0)
{

    /*

    target을 만족하는 서로 다른 부호의 개수 반환
    DFS로 안하고 0 ~ 1000 크기의 배열 2개로 해결해도 된다
    */
    int len = _num.size();
    if (_depth == len) return _target == _val;

    int ret = 0;

    ret += DFS(_num, _target, _depth + 1, _val - _num[_depth]);
    ret += DFS(_num, _target, _depth + 1, _val + _num[_depth]);

    return ret;
}

int solution(vector<int> _numbers, int _target) {
    int answer = 0;

    answer = DFS(_numbers, _target);
    return answer;
}
#elif !second
#include <vector>

using namespace std;

int solution(vector<int> _numbers, int _target)
{

    int answer = 0;

    int len = 1 << _numbers.size();
    for (int state = 0; state < len; state++)
    {

        int cur = 0;
        for (int i = 0; i < _numbers.size(); i++)
        {

            if ((1 << i) & state) cur += _numbers[i];
            else cur -= _numbers[i];
        }

        if (cur == _target) answer++;
    }

    return answer;
}

#else
#include <vector>

#define ADD 1'000   // 음수 부분 고려
#define MAX 2'000   // 50 * 40

using namespace std;

int solution(vector<int> _numbers, int _target) {
    int answer = 0;

    // dfs로도 가능하지만
    // 2^20승 많다
    // dp로 40'000에 해결할 생각
    vector<int> cur(MAX + 1, 0);
    vector<int> next(MAX + 1, 0);

    cur[ADD] = 1;
    for (const int num : _numbers)
    {

        for (int i = 0; i <= MAX; i++)
        {

            if (!cur[i]) continue;

            int chk = i - num;
            if (0 <= chk) next[chk] += cur[i];

            chk = i + num;
            if (chk <= MAX) next[chk] += cur[i];

            cur[i] = 0;
        }

        cur.swap(next);
    }

    answer = cur[ADD + _target];
    return answer;
}
#endif