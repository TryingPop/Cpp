/*
날짜 : 2024. 6. 27
이름 : 배성훈
내용 : 할인행사
    원하는 제품을 나타내는 문자열 배열 want와
    원하는 제품의 수량을 나타내는 정수 배열 number,
    마트에서 할인하는 제품을 나타내는 문자열 배열 discount가 주어진다

    원하는 제품과 수량이 할인하는 날짜와 10일 연속으로 일치하는
    모든 경우의 수를 return 하는 solution 함수를 구현

    want의 길이와 number의 길이는 같고,
    number의 원소들의 합은 항상 10이고 원소들은 자연수이다

    그리고 discount의 길이는 10이상 10만 이하이다

    parameter
    { "banana", "apple", "rice", "pork", "pot" }, { 3, 2, 2, 2, 1 }, { "chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", "pot", "banana", "apple", "banana" }



    return
    3


    sol
    3 ~ 12일, 4 ~ 13, 5 ~ 14일이 조건을 만족한다
*/

#if !first
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

inline bool ChkAllZero(unordered_map<string, int>& _chk, vector<string>& _key)
{

    for (string& key : _key)
    {

        if (_chk[key]) return false;
    }

    return true;
}

int solution(vector<string> _want, vector<int> _number, vector<string> _discount) {
    int answer = 0;

    unordered_map<string, int> cnt;
    for (int i = 0; i < _want.size(); i++)
    {

        cnt[_want[i]] = _number[i];
    }

    for (int i = 0; i < 10; i++)
    {

        cnt[_discount[i]] -= 1;
    }

    if (ChkAllZero(cnt, _want)) answer++;

    for (int i = 10; i < _discount.size(); i++)
    {

        cnt[_discount[i]]--;
        cnt[_discount[i - 10]]++;

        if (ChkAllZero(cnt, _want)) answer++;
    }
    return answer;
}
#else
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> _want, vector<int> _number, vector<string> _discount) {
    int answer = 0;

    unordered_map<string, int> cnt;
    for (int i = 0; i < _want.size(); i++)
    {

        cnt[_want[i]] = _number[i];
    }

    // 슬라이딩 윈도우
    for (int i = 0; i < 10; i++)
    {

        cnt[_discount[i]] -= 1;
    }

    int ret = 0;
    for (string& key : _want)
    {

        int cur = cnt[key];
        if (cur > 0) ret += cur;
    }

    if (!ret) answer++;

    for (int i = 10; i < _discount.size(); i++)
    {

        if (cnt[_discount[i]] > 0) ret--;
        cnt[_discount[i]]--;

        if (cnt[_discount[i - 10]] >= 0) ret++;
        cnt[_discount[i - 10]]++;

        if (!ret) answer++;
    }
    return answer;
}
#endif