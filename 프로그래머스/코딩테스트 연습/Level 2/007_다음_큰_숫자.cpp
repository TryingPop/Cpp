/*
��¥ : 2024. 6. 14
�̸� : �輺��
���� : ���� ū ����
	�ڿ��� n�� �־����� ��,
	n�� ���� ū ���ڴ� ������ ���� �����Ѵ�
	���� 1. n�� ���� ū ���ڴ� n���� ū �ڿ���
	���� 2. n�� ����ū ���ڿ� n�� �������� ��ȯ���� ��
		1�� ������ ����
	���� 3. n�� ���� ū ���ڴ� ���� ������ �����ϴ� ���� ��
		���� �������̴�

	�ڿ��� n�� �Ű������� �־��� ��, n�� ���� ū ���ڸ�
	return �ϴ� solution �Լ��� ����

	parameter
	78

	return
	83
*/

#include <string>
#include <vector>

using namespace std;

void NextBinaryNum(vector<int>& _binaryNum)
{

    // ���ǿ� �´� �������� �������� ã���ش�
    int find = 0;           // 1�� ����
    bool chk2 = true;       // 0�� �߰��ؼ� Ż��
    bool chk1 = false;      // ó�� 0���� �ƴ��� Ȯ��

    for (int i = 0; i < _binaryNum.size(); i++)
    {

        if (chk1 && _binaryNum[i] == 0)
        {

            _binaryNum[i] = 1;
            chk2 = false;
            find--;
            break;
        }

        if (_binaryNum[i] == 1)
        {

            chk1 = true;
            find++;
        }

        _binaryNum[i] = 0;
    }

    if (chk2)
    {

        _binaryNum.push_back(1);
        find--;
    }

    for (int i = 0; i < _binaryNum.size(); i++)
    {

        if (!find) break;
        find--;
        _binaryNum[i] = 1;
    }
}

int solution(int _n) {
    int answer = 0;

    // ������ (�������� ����)
    vector<int> bn;
    bn.reserve(20);

    while (_n)
    {

        if (_n & 1) bn.push_back(1);
        else bn.push_back(0);

        _n >>= 1;
    }

    // ���� �� ã�� Greedy
    NextBinaryNum(bn);

    // �������� ����� �������� �������� ��ȯ
    for (int i = 0; i < bn.size(); i++)
    {

        if (bn[i]) answer |= 1 << i;
    }
    return answer;
}