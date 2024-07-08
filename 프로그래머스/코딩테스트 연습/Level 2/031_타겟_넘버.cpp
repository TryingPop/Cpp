/*
��¥ : 2024. 7. 8
�̸� : �輺��
���� : Ÿ�� �ѹ�
    n���� ���̾ƴ� �������� �ִ�
    �� �������� ������ �ٲ��� �ʰ�
    ������ ���ϰų� ���� Ÿ�� �ѹ��� ������� �Ѵ�

    ����� �� �ִ� ���ڰ� ��� �迭 numbers,
    Ÿ�� �ѹ� target�� �Ű������� �־��� ��

    ���ڸ� ������ ���ϰ� ���� Ÿ�� �ѹ��� ����� ����� ����
    return �ϴ� solution �Լ� ����


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

    �̷��� 5���� ���� �� �ִ�
*/

#if first

#include <string>
#include <vector>

using namespace std;

int DFS(vector<int>& _num, int& _target, int _depth = 0, int _val = 0)
{

    /*

    target�� �����ϴ� ���� �ٸ� ��ȣ�� ���� ��ȯ
    DFS�� ���ϰ� 0 ~ 1000 ũ���� �迭 2���� �ذ��ص� �ȴ�
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

#define ADD 1'000   // ���� �κ� ���
#define MAX 2'000   // 50 * 40

using namespace std;

int solution(vector<int> _numbers, int _target) {
    int answer = 0;

    // dfs�ε� ����������
    // 2^20�� ����
    // dp�� 40'000�� �ذ��� ����
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