/*
��¥ : 2024. 7. 3
�̸� : �輺��
���� : Ʃ��
    �� �� �ִ� ������ �����ִ� ���� �Ǵ� � ������ 
    ������ ��ҵ��� ������ Ʃ���̶� �Ѵ�

    Ʃ���� �ߺ��� ���Ұ� ���� �� �ִ�
    ���ҿ� ������ ������ ������, ������ ������ �ٸ��� ���� �ٸ� Ʃ���̴�
    Ʃ���� ���� ������ �����ϴ�

    ������ ������ n���̰�, �ߺ��Ǵ� ���Ұ� ���� Ʃ�� { a1, a2, ..., an }��
     ������ ���� Ʃ���� ǥ���ϴ� �������� ��ȯ�Ѵ�

    {{a1},{a1,a2},...,{a1,a2,...,an}}
    ���� ���ڿ��� ��ȯ�� �־�����
    �ش� ������ ������ �ٲ� �� �ִ�
    {{a1,a2},{a1}...,{a1,a2,a3,a4,a5}}

    Ư�� Ʃ���� ǥ���ϴ� ������ ��� ���ڿ� s�� �Ű������� �־��� ��,
    s�� ǥ���ϴ� Ʃ���� �迭�� ��� return �ϵ��� solution �Լ��� ����


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

    ���ڿ��� ���� �б�
    ������� �Ѵٸ� ���⼭ �ٷ� ��� ���⵵ �����ϴ�
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

    Ʃ�� ���ҿ� �ε��� ã��
    _tuple�� ����, idx�� �����Ѵ�
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

    unordered_map<int, int> tuple;  // ����, idx + 1
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