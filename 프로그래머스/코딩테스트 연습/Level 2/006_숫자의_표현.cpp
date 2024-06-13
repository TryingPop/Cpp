/*
날짜 : 2024. 6. 13
이름 : 배성훈
내용 : 숫자의 표현
    자연수 n이 매개변수로 주어질 때,
    연속된 자연수들의 합으로 n을 표현하는 방법의 수를 
    return 하는 solution 함수를 구현

    n은 1만 이하의 자연수

    parameter
    15


    return
    4
*/

#include <string>
#include <vector>

using namespace std;

int solution(int _n) 
{

    int answer = 0;

#if first
    // 누적합 + 이분 탐색
    // O(N log N)
    vector<int> sum(_n + 1, 0);
    for (int i = 1; i <= _n; i++)
    {

        // 0에서 idx까지의 합
        sum[i] = sum[i - 1] + i;
    }

    for (int i = 0; i <= _n; i++)
    {

        int l = i + 1;
        int r = _n;

        // i + 1 부터 k? 까지 누적합이 n이 되는지 확인
        // k가 존재하는지 이분 탐색으로 찾는다
        int find = _n + sum[i];
        while (l <= r)
        {

            int mid = (l + r) >> 1;

            if (find < sum[mid]) r = mid - 1;
            else if (find > sum[mid]) l = mid + 1;
            else
            {

                // 존재하면 더 탐색안하고 끊는다
                answer++;
                break;
            }
        }
    }
#else

    // 투 포인터
    int chk = 0;
    int l = 1;
    int r = 0;

    while (r <= _n)
    {

        if (chk < _n) chk += ++r;
        else if (_n < chk) chk -= l++;
        else
        {

            answer++;
            chk -= l++;
        }
    }

    while (l <= r)
    {

        chk -= l++;
        if (chk == _n) answer++;
    }
#endif
    return answer;
}