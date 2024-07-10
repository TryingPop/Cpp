/*
날짜 : 2024. 7. 10
이름 : 배성훈
내용 : n진수 게임
	숫자 0부터 시작해서 차례대로 말한다
	첫 번째 사람은 0, 두 번째 사람은 1, ...
	로 진행한다

	그리고 두 자리수 이상부터는 순간 한 자리씩 끊어서 말한다
	10의 경우 해당 차례의 사람이 1로 읽고,
	다음 사람이 0을 읽는다

	진법 n과, 미리 구할 숫자의 개수 t, 게임에 참가하는 인원 m,
	튜브의 순서 p가 주어질 때,

	튜브가 말해야하는 숫자 t개를 공백 없이 차례대로 나타낸 문자열
	단, 10 ~ 15는 각각 대문자 A ~ F로 나타내어 return 하는 solution 함수 구현


	prameter
	2, 4, 2, 1


	return
	"0111"


	sol
	2명이서 게임하고 튜브가 먼저 한다
	0부터 시작해서 튜브는 0을 외친다		-> 0

	다음 사람은 1을 외친다

	그리고 2인데 2진법이므로 10이되고 두 자리 수이다
	그래서 튜브는 앞의 1을 외친다			-> 01

	다음 사람은 10의 남은 0을 외친다

	그리고 다시 튜브 차례고 3 = 11이다
	튜브는 앞의 1을 외친다					-> 11

	다음 사람은 11의 남은 1을 외친다

	다시 튜브의 차례고 4 = 100이다
	튜브는 맨 앞의 1을 외친다				-> 100
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

string nTs = "0123456789ABCDEF";

int NumToString(int _num, int _n, string& _str)
{

    /*

    숫자 num을 n진법 문자로 바꿔 역순으로 _str에 저장한다
    */

    _str.clear();
    int len = 0;
    while (_num > 0)
    {

        _str[len++] = nTs[_num % _n];
        _num /= _n;
    }

    if (!len)
    {

        _str.push_back('0');
        len = 1;
    }

    return len;
}

string solution(int _n, int _t, int _m, int _p) 
{

    string answer = "";
    answer.reserve(_t);

    _p--;
    string str = "";
    // 1000번 100명이서 외친다면 많아야 10만번이고
    // 10만은 2진법으로 변환해도 20자리를 넘지 않는다
    str.reserve(20);

    // 시뮬레이션 돌려 정답찾기
    int cur = 0;
    for (int i = 0; ; i++)
    {

        int len = NumToString(i, _n, str);
        for (int j = len - 1; j >= 0; j--)
        {

            if (cur == _p)
            {

                answer.push_back(str[j]);
                _t--;
                if (!_t) break;
            }
            cur = cur == _m - 1 ? 0 : cur + 1;
        }

        if (!_t) break;
    }

    return answer;
}