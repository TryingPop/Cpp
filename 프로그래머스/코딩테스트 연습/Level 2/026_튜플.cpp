/*
날짜 : 2024. 7. 3
이름 : 배성훈
내용 : 튜플
    셀 수 있는 수량의 순서있는 열거 또는 어떤 순서를 
    따르는 요소들의 모음을 튜플이라 한다

    튜플은 중복된 원소가 있을 수 있다
    원소에 정해진 순서가 있으며, 원소의 순서가 다르면 서로 다른 튜플이다
    튜플의 원소 개수는 유한하다

    원소의 개수가 n개이고, 중복되는 원소가 없는 튜플 { a1, a2, ..., an }을
     다음과 같이 튜플을 표현하는 집합으로 변환한다

    {{a1},{a1,a2},...,{a1,a2,...,an}}
    으로 문자열로 변환해 주어진다
    해당 집합의 순서는 바뀔 수 있다
    {{a1,a2},{a1}...,{a1,a2,a3,a4,a5}}

    특정 튜플을 표현하는 집합이 담긴 문자열 s가 매개변수로 주어질 때,
    s가 표현하는 튜플을 배열에 담아 return 하도록 solution 함수를 구현


    parameter
    "{{1,2,3},{2,1},{1,2,4,3},{2}}"


    return
    { 2, 1, 3, 4 }
*/

#if first
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool MyComp(vector<int> _vec1, vector<int> _vec2)
{


    return _vec1.size() < _vec2.size();
}

void ReadString(string& _str, vector<vector<int>>& _ele)
{

    /*

    문자열의 원소 읽기
    성능향상 한다면 여기서 바로 결론 도출도 가능하다
    */
    bool first = false;
    bool second = false;
    int num = 0;
    vector<int> vec;
    for (const char c : _str)
    {

        if (c == '{')
        {

            if (first) second = true;
            else first = true;

            continue;
        }

        if (c == '}')
        {

            if (second)
            {

                second = false;
                vec.push_back(num);
                num = 0;
                _ele.push_back(vec);
                vec.clear();
            }
            else first = false;

            continue;
        }

        if (c == ',')
        {

            if (second)
            {

                vec.push_back(num);
                num = 0;
            }

            continue;
        }

        num = num * 10 + c - '0';
    }
}



vector<int> solution(string s)
{

    vector<int> answer;

    vector<vector<int>> ele;
    ReadString(s, ele);

    sort(ele.begin(), ele.end(), MyComp);

    unordered_map<int, bool> use;
    answer.reserve(ele.size());

    for (int i = 0; i < ele.size(); i++)
    {

        for (int j = 0; j < ele[i].size(); j++)
        {

            if (use.count(ele[i][j])) continue;
            use[ele[i][j]] = true;
            answer.push_back(ele[i][j]);
        }
    }
    return answer;
}
#else
#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

void ReadString(const string& _str, unordered_map<int, int>& _tuple)
{

    /*

    튜플 원소와 인덱스 찾아
    _tuple에 원소, idx를 저장한다
    */
    bool first = false;
    bool second = false;
    int num = 0;
    vector<int> vec;
    vec.reserve(500);

    for (const char c : _str)
    {

        if (c == '{')
        {

            if (first) second = true;
            else first = true;

            continue;
        }

        if (c == '}')
        {

            if (second)
            {

                second = false;
                vec.push_back(num);
                num = 0;

                int idx = vec.size();
                for (int i = 0; i < idx; i++)
                {

                    if (_tuple.count(vec[i])) _tuple[vec[i]] = min(_tuple[vec[i]], idx);
                    else _tuple[vec[i]] = idx;
                }

                vec.clear();
            }
            else first = false;

            continue;
        }

        if (c == ',')
        {

            if (second)
            {

                vec.push_back(num);
                num = 0;
            }

            continue;
        }

        num = num * 10 + c - '0';
    }
}



vector<int> solution(string s)
{

    vector<int> answer;

    unordered_map<int, int> tuple;  // 원소, idx + 1
    ReadString(s, tuple);

    answer.resize(tuple.size());
    for (const pair<int, int> ele : tuple)
    {

        int idx = ele.second - 1;
        answer[idx] = ele.first;
    }

    return answer;
}
#endif