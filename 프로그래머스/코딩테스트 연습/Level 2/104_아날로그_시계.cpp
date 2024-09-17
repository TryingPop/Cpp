/*
��¥ : 2024. 9. 17
�̸� : �輺��
���� : �Ƴ��α� �ð�
    ��ħ, ��ħ, ��ħ�� �ִ� �Ƴ��α׽ð谡 �ִ�
    �ð��� ��ħ�� 12�ð�����, ��ħ�� 60�и���, ��ħ�� 60�ʸ���
    �ð踦 �� ���� ����

    ���� ��ħ, ��ħ, ��ħ�� �����̴� �ӵ��� �����ϸ� ���� �ٸ���
    �� �ð迡�� ��ħ�� ��ħ / ��ħ�� ��ĥ ������ �˶��� �︮�� ����� �ִ�

    Ư�� �ð� ���� �˶��� �︰ Ƚ���� �˰� �ʹ�

    �˶��� �︮�� Ƚ���� �� �ð��� Ÿ������ ���� h1, m1, s1, h2, m2, s2��
    �Ű������� �־��� ��, �˶��� �︮�� Ƚ���� return �ϴ� solution �Լ� ����

    h1, h2�� 0 �̻� 23 ������ ����
    m1, m2�� 0 �̻� 59 ������ ����
    s1, s2�� 0 �̻� 59 ������ ����

    h1�� m1�� s1�ʺ��� h2�� m2�� s2�ʱ���
    �˶��� �︮�� Ƚ���� ���ٴ� �ǹ��̴�

    h1�� m1�� s1�� < h2�� m2�� s2��
    �ð��� 23�� 59�� 59�ʸ� �ʰ��Ͽ� 
    0�� 0�� 0�ʷ� ���ư��� ���� �־����� �ʴ´�


    parameter
    0, 0, 0, 23, 59, 59


    return
    2852


    sol
    ��ħ, ��ħ, ��ħ�� ��ġ�ϴ� ���� ��� 12�� ����Ű�� 
    ������ ��� �ۿ� ����

    �׷��� ��ħ�� ��ħ�� ������ ��� 59 * 24 + 719 * 2 - 2
    2852�� �����Ѵ�
*/

#include <vector>
#include <algorithm>

#define ll long long
#define MUL 42'421

using namespace std;

int BinarySearch(ll _s, vector<ll>& _meet)
{

    /*

    �̺� Ž��
    ������ ���� ã�´�
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

    ����, �̺� Ž��
    */
    int answer = 0;

    vector<ll> meet;
    meet.reserve(2880);

    // ��ħ�� ��ħ�� ��ġ
    for (ll i = 1; i < 1438; i++)
    {

        if (i == 719) continue;
        meet.push_back(60 * 720 * 59 * i);
    }

    // ��ħ�� ��ħ�� ��ġ
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