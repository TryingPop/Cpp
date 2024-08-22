/*
��¥ : 2024. 8. 22
�̸� : �輺��
���� : �Ÿ��α� Ȯ���ϱ�
    �ڷγ� ���̷��� ���� ������ ���� �����ڵ��� �Ÿ��� �ּ� ��⸦ �ؾ��Ѵ�
    �Ʒ� ��Ģ���� ���ǿ� �Ÿ��� �ΰ� �ɵ��� �ȳ��� �ϰ� �ִ�

    1. ������ 5���̸�, �� ������ 5 x 5 ũ���̴�
    2. �Ÿ��α⸦ ���Ͽ� �����ڵ� ������ ����ư �Ÿ��� 2 ���Ϸ� ������ �ȵȴ�
    3. �����ڰ� �ɾ��ִ� �ڸ� ���̰� ��Ƽ������ ���� ���� ��쿡�� ���

    5���� ������ ���� ��
    �Ÿ��α⸦ �� ��Ű�� �ִ��� Ȯ���ϰ� �ʹ�

    �����ڵ��� ������ ���� ������ ���Ǻ��� ���� 
    2���� ���ڿ� �迭 places�� �Ű������� �־��� ��,
    �� ���Ǻ��� �Ÿ��α⸦ ��Ű�� ������ 1��,
    �� ���̶� ��Ű�� �ʰ� ������ 0�� �迭�� ��� 
    return �ϴ� solution �Լ� ����

    places�� ���� ���̴� 5,
    places�� ���� ���̵� 5,
    places�� ���Ҵ� P, O, X �� �̷���� ���ڿ�

    places������ ���̵� 5�̴�
    P�� �����ڰ� �ɾ��ִ� �ڸ��� �ǹ��ϰ�,
    O�� �����̺��� �ǹ��ϰ�,
    X�� ��Ƽ���� �ǹ��Ѵ�

    �Է����� �־����� 5���� ������ ũ��� ��� 5 x 5�̴�

    return �� ������
    1���� ���� �迭�� 5���� ���Ҹ� ��� return

    places�� ��� �ִ� 5���� ������ ������� �Ÿ��α� �ؼ� ���θ� 
    ���ʴ�� �迭�� ��´�

    �� ���� ���� ��� �����ڰ� �Ÿ��α⸦ ��Ű�� ������ 1��
    �Ѹ��̶� ��Ű�� �ʰ� ������ 0�� ��´�


    parameter
    {   { "POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP" }, 
        { "POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP" }, 
        { "PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX" }, 
        { "OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO" }, 
        { "PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP" } }

    
    return
    { 1, 0, 1, 1, 1 }


    sol
    2��°�� ��� ���� ����
        P   O   O   P   X
        O   X   P   X   P
        P   X   X   X   O
        O   X   X   X   O
        O   O   O   P   P
    0, 0�� 2, 0�� ����� �Ÿ��α⸦ ��Ű�� �ʰ� �ִ�
    �̿ܿ��� 1, 2�� 0, 3 ��� �׸���
    4, 3�� 4, 4 �����ڵ� �Ÿ��α⸦ ��Ű�� �ʰ� �ִ�
*/

#include <string>
#include <vector>

using namespace std;

inline bool ChkInvalidPos(int _r, int _c)
{

    /*

    ��ȿ�� ��ǥ���� Ȯ��
    */
    return _r < 0 || _c < 0 || _r >= 5 || _c >= 5;
}

inline bool Find(vector<string>& _board)
{

    /*

    1ĭ �̵��� ���� ���� ������Ų��
    ���� 2�� �̻� �����Ǹ� �Ÿ� 2 �����̹Ƿ� �Ÿ��α⸦ ��Ű�� ���Ѵ�
    */

    vector<vector<int>> chk(5, vector<int>(5, 0));
    vector<int> dirR = { 0, -1, 0, 1, 0 };
    vector<int> dirC = { 0, 0, -1, 0, 1 };

    for (int r = 0; r < 5; r++)
    {

        for (int c = 0; c < 5; c++)
        {

            // P�� �ƴϸ� Ž�� X
            if (_board[r][c] != 'P') continue;

            for (int i = 0; i < 5; i++)
            {

                int nextR = r + dirR[i];
                int nextC = c + dirC[i];

                if (ChkInvalidPos(nextR, nextC)
                    || _board[nextR][nextC] == 'X') continue;

                chk[nextR][nextC]++;
                if (chk[nextR][nextC] == 2) return false;
            }
        }
    }

    return true;
}

vector<int> solution(vector<vector<string>> places)
{

    /*

    �ֵ�Ȥ
    */
    vector<int> answer;

    for (vector<string>& board : places)
    {

        if (Find(board)) answer.push_back(1);
        else answer.push_back(0);
    }
    return answer;
}