/*
��¥ : 2024. 7. 12
�̸� : �輺��
���� : ���� �� �ִܰŸ�
	���� ���� ���� maps�� �Ű������� �־��� ��,
	ĳ���Ͱ� ��� �� ������ �����ϱ� ���ؼ� 
	�������� �ϴ� ĭ�� ������ �ּڰ���
	return �ϴ� solution �Լ� ����

	��, ����� ������ ������ �� ���� ���� -1�� return

	maps�� n x m ũ���� ���� ���� ���°� ����ִ� 2���� �迭��,
	n�� m�� ���� 1�̻� 100 ������ �ڿ��� �̴�

	��, n, m ��� 1�� ���� �־����� �ʴ´�
	maps�� 0�� 1�θ� �̷���� ������, 0�� ���� �ִ��ڸ�
	1�� ���� ���� �ڸ��� ��Ÿ����

	ĳ���ʹ� ���� ��� (1, 1)��ġ�� ������
	���� ������ ���� ���� ���� �ϴ��� (n, m) ��ġ�� �ִ�

	parameter
	{ { 1, 0, 1, 1, 1 }, 
	  { 1, 0, 1, 0, 1 }, 
	  { 1, 0, 1, 1, 1 }, 
	  { 1, 1, 1, 0, 1 }, 
	  { 0, 0, 0, 0, 1 } }


	return
	11


	sol
	parameter
	{ { 2, 0, 0, 0, 0 },
	  { 2, 0, 0, 0, 0 },
	  { 2, 0, 2, 2, 2 },
	  { 2, 2, 2, 0, 2 },
	  { 0, 0, 0, 0, 2 } }

	���� ��η� ���� 11ĭ���� �����Ѵ�
*/

#include <vector>
#include <queue>

using namespace std;

#define mp make_pair

using namespace std;

inline bool ChkInvalidPos(int _r, int _c, int _row, int _col)
{

    if (_r < 0 || _c < 0 || _r >= _row || _c >= _col) return true;
    return false;
}

int solution(vector<vector<int>> _maps)
{
    
    int answer = 0;

    vector<vector<bool>> visit;
    int row = _maps.size();
    int col = _maps[0].size();
    visit.assign(row, vector<bool>(col, false));

    queue<pair<int, int>> q;
    q.push(mp(0, 0));
    visit[0][0] = true;

    vector<int> dirR = { -1, 0, 1, 0 };
    vector<int> dirC = { 0, -1, 0, 1 };

    while (q.size())
    {

        pair<int, int> node = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {

            int nextR = node.first + dirR[i];
            int nextC = node.second + dirC[i];

            if (ChkInvalidPos(nextR, nextC, row, col) || visit[nextR][nextC]) continue;
            visit[nextR][nextC] = true;

            if (_maps[nextR][nextC])
            {

                _maps[nextR][nextC] = _maps[node.first][node.second] + 1;
                q.push(mp(nextR, nextC));
            }
        }
    }

    if (_maps[row - 1][col - 1] == 1) answer = -1;
    else answer = _maps[row - 1][col - 1];

    return answer;
}