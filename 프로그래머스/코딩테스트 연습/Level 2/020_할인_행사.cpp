/*
��¥ : 2024. 6. 27
�̸� : �輺��
���� : �������
    ���ϴ� ��ǰ�� ��Ÿ���� ���ڿ� �迭 want��
    ���ϴ� ��ǰ�� ������ ��Ÿ���� ���� �迭 number,
    ��Ʈ���� �����ϴ� ��ǰ�� ��Ÿ���� ���ڿ� �迭 discount�� �־�����

    ���ϴ� ��ǰ�� ������ �����ϴ� ��¥�� 10�� �������� ��ġ�ϴ�
    ��� ����� ���� return �ϴ� solution �Լ��� ����

    want�� ���̿� number�� ���̴� ����,
    number�� ���ҵ��� ���� �׻� 10�̰� ���ҵ��� �ڿ����̴�

    �׸��� discount�� ���̴� 10�̻� 10�� �����̴�

    parameter
    { "banana", "apple", "rice", "pork", "pot" }, { 3, 2, 2, 2, 1 }, { "chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", "pot", "banana", "apple", "banana" }



    return
    3


    sol
    3 ~ 12��, 4 ~ 13, 5 ~ 14���� ������ �����Ѵ�
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

    // �����̵� ������
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