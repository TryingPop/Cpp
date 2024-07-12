/*
날짜 : 2024. 7. 12
이름 : 배성훈
내용 : 게임 맵 최단거리
	게임 맵의 상태 maps가 매개변수로 주어질 때,
	캐릭터가 상대 팀 진영에 도착하기 위해서 
	지나가야 하는 칸의 개수의 최솟값을
	return 하는 solution 함수 구현

	단, 상대팀 진영에 도착할 수 없을 때는 -1을 return

	maps는 n x m 크기의 게임 맵의 상태가 들어있는 2차원 배열로,
	n과 m은 각각 1이상 100 이하의 자연수 이다

	단, n, m 모두 1인 경우는 주어지지 않는다
	maps는 0과 1로만 이루어져 있으며, 0은 벽이 있는자리
	1은 벽이 없는 자리를 나타낸다

	캐릭터는 좌측 상단 (1, 1)위치에 있으며
	상대방 진영은 게임 맵의 우측 하단인 (n, m) 위치에 있다

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

	다음 경로로 가면 11칸만에 도착한다
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