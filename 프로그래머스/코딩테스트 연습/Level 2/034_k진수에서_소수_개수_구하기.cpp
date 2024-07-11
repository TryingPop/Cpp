/*
��¥ : 2024. 7. 11
�̸� : �輺��
���� : k�������� �Ҽ� ���� ���ϱ�
	���� ���� n�� �־�����
	�� ���ڸ� k������ �ٲ��� ��,
	��ȯ�� �� �ȿ� �Ʒ� ���ǿ� �´� �Ҽ��� �� ������ �˾ƺ����� �Ѵ�

	0P0 ó�� �Ҽ� ���ʿ� 0�� �ִ� ���
	P0 ó�� �Ҽ� �����ʿ��� 0�� �ְ� ���ʿ��� �ƹ��͵� ���� ���
	0P ó�� �Ҽ� ���ʿ��� 0�� �ְ� �����ʿ��� �ƹ��͵� ���� ���
	Pó�� �Ҽ� ���ʿ� �ƹ��͵� ���� ���

	��, P�� �� �ڸ����� 0�� �������� �ʴ� 10���� �Ҽ��̴�

	���� n�� k�� �Ű������� �־��� ��,
	n�� k������ �ٲ��� ��,
	��ȯ�� �� �ȿ��� ã�� �� �ִ� 
	�� ���ǿ� �´� �Ҽ��� ������
	return �ϴ� solution �Լ� ����
	���� ���Ƶ� ��ġ�� �ٸ��� ��� ���� ����� �Ѵ�

	n�� 100�� ������ �ڿ���
	k�� 3�̻� 10 ������ ����


	parameter
	437674, 3


	return
	3


	sol
	437674�� 3�������� �ٲٸ�
	211020101011
	�̰� 211, 2, 11�� �ִ�
*/

#include <string>
#include <vector>

using namespace std;
typedef unsigned long long ull;

inline string ChangeN(int _n, int _k)
{

    /*

    n�� k�������� �ٲ۵� ���� 0 �߰�
    ���� ���� �ݷ�ó���ϱ� �Ⱦ 0�߰�
    */
    string ret = "";
    ret.reserve(20);
    while (_n)
    {

        ret.push_back('0' + (_n % _k));
        _n /= _k;
    }



    /*

    �������� �����߱⿡ ���ڿ��� ������� �Ѵ�
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

    // 0 �ΰ�쳪 ���� ���� �ݷ�ó�� ���ص��ȴ�
    ret.push_back('0');

    return ret;
}

#if first
// �����佺 �׳׽��� ü �̷�
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

    Miller Rabin �˰������� ã��
    chk�� int ���� �ȿ��� �Ҽ������� ���̴� ����
    long long ������ chk ������ �޶������ϴµ�,
    �ϴ� �����غ��� �ȵǸ� long long�� �´� �������� �ٲ۴�
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

    ���� ã��
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