/*
날짜 : 2024. 9. 17
이름 : 배성훈
내용 : 아날로그 시계
    시침, 분침, 초침이 있는 아날로그시계가 있다
    시계의 시침은 12시간마다, 분침은 60분마다, 초침은 60초마다
    시계를 한 바퀴 돈다

    따라서 시침, 분침, 초침이 움직이는 속도는 일정하며 각각 다르다
    이 시계에는 초침이 시침 / 분침과 겹칠 때마다 알람이 울리는 기능이 있다

    특정 시간 동안 알람이 울린 횟수를 알고 싶다

    알람이 울리는 횟수를 센 시간을 타나내는 정수 h1, m1, s1, h2, m2, s2가
    매개변수로 주어질 때, 알람이 울리는 횟수를 return 하는 solution 함수 구현

    h1, h2는 0 이상 23 이하인 정수
    m1, m2는 0 이상 59 이하인 정수
    s1, s2는 0 이상 59 이하인 정수

    h1시 m1시 s1초부터 h2시 m2분 s2초까지
    알람이 울리는 횟수를 센다는 의미이다

    h1시 m1시 s1초 < h2시 m2분 s2초
    시간이 23시 59분 59초를 초과하여 
    0시 0분 0초로 돌아가는 경우는 주어지지 않는다


    parameter
    0, 0, 0, 23, 59, 59


    return
    2852


    sol
    초침, 분침, 시침이 일치하는 경우는 모두 12를 가리키는 
    정각인 경우 밖에 없다

    그래서 초침과 분침이 만나는 경우 59 * 24 + 719 * 2 - 2
    2852개 존재한다
*/

#include <vector>
#include <algorithm>

#define ll long long
#define MUL 42'421

using namespace std;

int BinarySearch(ll _s, vector<ll>& _meet)
{

    /*

    이분 탐색
    이하인 갯수 찾는다
    */
    int l = 0;
    int r = _meet.size();

    while (l <= r)
    {

        int mid = (l + r) >> 1;
        if (_meet[mid] <= _s) l = mid + 1;
        else r = mid - 1;
    }

    return l;
}

int solution(int _h1, int _m1, int _s1, int _h2, int _m2, int _s2)
{

    /*

    수학, 이분 탐색
    */
    int answer = 0;

    vector<ll> meet;
    meet.reserve(2880);

    // 시침과 초침이 일치
    for (ll i = 1; i < 1438; i++)
    {

        if (i == 719) continue;
        meet.push_back(60 * 720 * 59 * i);
    }

    // 분침과 초침이 일치
    for (ll i = 0; i <= 24 * 59; i++)
    {

        meet.push_back(60 * 719 * 60 * i);
    }

    sort(meet.begin(), meet.end());

    ll t1 = 1LL * _h1 * 60 * 60 * MUL
        + 1LL * _m1 * 60 * MUL
        + 1LL * _s1 * MUL;

    ll t2 = 1LL * _h2 * 60 * 60 * MUL
        + 1LL * _m2 * 60 * MUL
        + 1LL * _s2 * MUL;

    int chk2 = BinarySearch(t2, meet);
    int chk1 = BinarySearch(t1 - 1, meet);
    answer = chk2 - chk1;

    return answer;
}