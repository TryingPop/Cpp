/*
날짜 : 2024. 7. 11
이름 : 배성훈
내용 : k진수에서 소수 개수 구하기
	양의 정수 n이 주어진다
	이 숫자를 k진수로 바꿨을 때,
	변환된 수 안에 아래 조건에 맞는 소수가 몇 개인지 알아볼려고 한다

	0P0 처럼 소수 양쪽에 0이 있는 경우
	P0 처럼 소수 오른쪽에만 0이 있고 왼쪽에는 아무것도 없는 경우
	0P 처럼 소수 왼쪽에만 0이 있고 오른쪽에는 아무것도 없는 경우
	P처럼 소수 양쪽에 아무것도 없는 경우

	단, P는 각 자릿수에 0을 포함하지 않는 10진법 소수이다

	정수 n과 k가 매개변수로 주어질 때,
	n을 k진수로 바꿨을 때,
	변환된 수 안에서 찾을 수 있는 
	위 조건에 맞는 소수의 개수를
	return 하는 solution 함수 구현
	수가 같아도 위치가 다르면 모두 따로 세어야 한다

	n은 100만 이하의 자연수
	k는 3이상 10 이하의 정수


	parameter
	437674, 3


	return
	3


	sol
	437674를 3진법으로 바꾸면
	211020101011
	이고 211, 2, 11이 있다
*/

#include <string>
#include <vector>

using namespace std;
typedef unsigned long long ull;

inline string ChangeN(int _n, int _k)
{

    /*

    n을 k진법으로 바꾼뒤 끝에 0 추가
    문제 끝에 반례처리하기 싫어서 0추가
    */
    string ret = "";
    ret.reserve(20);
    while (_n)
    {

        ret.push_back('0' + (_n % _k));
        _n /= _k;
    }



    /*

    역순으로 저장했기에 문자열을 뒤집어야 한다
    */

    int l = 0;
    int r = ret.size() - 1;
    while (l < r)
    {

        char temp = ret[l];
        ret[l] = ret[r];
        ret[r] = temp;
        l++, r--;
    }

    // 0 인경우나 끝에 따로 반례처리 안해도된다
    ret.push_back('0');

    return ret;
}

#if first
// 에라토스 테네스의 체 이론
inline bool IsPrime(ull _n)
{

    if (_n < 2) return false;

    for (ull i = 2; i * i <= _n; i++)
    {

        if (_n % i) continue;

        return false;
    }

    return true;
}
#else

inline ull GetMul(ull _n, ull _m, ull _mod)
{

    ull ret = 0;

    while (_m)
    {

        if (_m & 1) ret = (ret + _n) % _mod;

        _m >>= 1;
        _n = (_n + _n) % _mod;
    }

    return ret;

}

inline ull GetPow(ull _n, ull _exp, ull _mod)
{

    ull ret = 1;

    while (_exp)
    {

        if (_exp & 1) ret = GetMul(ret, _n, _mod);

        _exp >>= 1;
        _n = GetMul(_n, _n, _mod);
    }

    return ret;
}

inline bool Miller_Rabin(ull _n, ull _a)
{

    if (_n <= 1) return false;
    if (_n == 2) return true;

    if (_n == _a) return true;

    ull d = _n - 1;
    while (true)
    {

        ull temp = GetPow(_a, d, _n);
        if (temp == _n - 1) return true;
        else if (temp != 1) return false;

        if ((d & 1) == 1) return temp == 1 || temp == _n - 1;
        d >>= 1;
    }

    ull x = GetPow(_a, d, _n);
    return x == _n - 1 || x == 1;
}

bool IsPrime(ull _n)
{

    /*

    Miller Rabin 알고리즘으로 찾기
    chk는 int 범위 안에서 소수판정에 쓰이는 집합
    long long 범위면 chk 집합이 달라져야하는데,
    일단 제출해보고 안되면 long long에 맞는 집합으로 바꾼다
    */
    vector<int> chk = { 2, 7, 61 };

    for (int num : chk)
    {

        if (!Miller_Rabin(_n, num)) return false;
    }

    return true;
}
#endif

int solution(int _n, int _k)
{

    int answer = 0;

    string changeN = ChangeN(_n, _k);

    /*

    개수 찾기
    */
    ull num = 0;
    for (const char c : changeN)
    {


        if (c == '0')
        {

            if (IsPrime(num)) answer++;
            num = 0;
        }
        else num = num * 10 + c - '0';
    }

    return answer;
}