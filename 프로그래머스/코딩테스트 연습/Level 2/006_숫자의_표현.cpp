/*
��¥ : 2024. 6. 13
�̸� : �輺��
���� : ������ ǥ��
    �ڿ��� n�� �Ű������� �־��� ��,
    ���ӵ� �ڿ������� ������ n�� ǥ���ϴ� ����� ���� 
    return �ϴ� solution �Լ��� ����

    n�� 1�� ������ �ڿ���

    parameter
    15


    return
    4
*/

#include <string>
#include <vector>

using namespace std;

int solution(int _n) 
{

    int answer = 0;

#if first
    // ������ + �̺� Ž��
    // O(N log N)
    vector<int> sum(_n + 1, 0);
    for (int i = 1; i <= _n; i++)
    {

        // 0���� idx������ ��
        sum[i] = sum[i - 1] + i;
    }

    for (int i = 0; i <= _n; i++)
    {

        int l = i + 1;
        int r = _n;

        // i + 1 ���� k? ���� �������� n�� �Ǵ��� Ȯ��
        // k�� �����ϴ��� �̺� Ž������ ã�´�
        int find = _n + sum[i];
        while (l <= r)
        {

            int mid = (l + r) >> 1;

            if (find < sum[mid]) r = mid - 1;
            else if (find > sum[mid]) l = mid + 1;
            else
            {

                // �����ϸ� �� Ž�����ϰ� ���´�
                answer++;
                break;
            }
        }
    }
#else

    // �� ������
    int chk = 0;
    int l = 1;
    int r = 0;

    while (r <= _n)
    {

        if (chk < _n) chk += ++r;
        else if (_n < chk) chk -= l++;
        else
        {

            answer++;
            chk -= l++;
        }
    }

    while (l <= r)
    {

        chk -= l++;
        if (chk == _n) answer++;
    }
#endif
    return answer;
}