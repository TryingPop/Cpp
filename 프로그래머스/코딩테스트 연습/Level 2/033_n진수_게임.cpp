/*
��¥ : 2024. 7. 10
�̸� : �輺��
���� : n���� ����
	���� 0���� �����ؼ� ���ʴ�� ���Ѵ�
	ù ��° ����� 0, �� ��° ����� 1, ...
	�� �����Ѵ�

	�׸��� �� �ڸ��� �̻���ʹ� ���� �� �ڸ��� ��� ���Ѵ�
	10�� ��� �ش� ������ ����� 1�� �а�,
	���� ����� 0�� �д´�

	���� n��, �̸� ���� ������ ���� t, ���ӿ� �����ϴ� �ο� m,
	Ʃ���� ���� p�� �־��� ��,

	Ʃ�갡 ���ؾ��ϴ� ���� t���� ���� ���� ���ʴ�� ��Ÿ�� ���ڿ�
	��, 10 ~ 15�� ���� �빮�� A ~ F�� ��Ÿ���� return �ϴ� solution �Լ� ����


	prameter
	2, 4, 2, 1


	return
	"0111"


	sol
	2���̼� �����ϰ� Ʃ�갡 ���� �Ѵ�
	0���� �����ؼ� Ʃ��� 0�� ��ģ��		-> 0

	���� ����� 1�� ��ģ��

	�׸��� 2�ε� 2�����̹Ƿ� 10�̵ǰ� �� �ڸ� ���̴�
	�׷��� Ʃ��� ���� 1�� ��ģ��			-> 01

	���� ����� 10�� ���� 0�� ��ģ��

	�׸��� �ٽ� Ʃ�� ���ʰ� 3 = 11�̴�
	Ʃ��� ���� 1�� ��ģ��					-> 11

	���� ����� 11�� ���� 1�� ��ģ��

	�ٽ� Ʃ���� ���ʰ� 4 = 100�̴�
	Ʃ��� �� ���� 1�� ��ģ��				-> 100
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

string nTs = "0123456789ABCDEF";

int NumToString(int _num, int _n, string& _str)
{

    /*

    ���� num�� n���� ���ڷ� �ٲ� �������� _str�� �����Ѵ�
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
    // 1000�� 100���̼� ��ģ�ٸ� ���ƾ� 10�����̰�
    // 10���� 2�������� ��ȯ�ص� 20�ڸ��� ���� �ʴ´�
    str.reserve(20);

    // �ùķ��̼� ���� ����ã��
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