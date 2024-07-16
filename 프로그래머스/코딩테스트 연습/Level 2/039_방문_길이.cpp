/*
날짜 : 2024. 7. 16
이름 : 배성훈
내용 : 방문 길이
	게임 캐릭터를 4가지 명령어를 통해 움직이려 한다
	명령어는 다음과 같다
	
	U: 위쪽으로 한 칸 이동
	D: 아래쪽으로 한 칸 이동
	R: 오른쪽으로 한 칸 이동
	L: 왼쪽으로 한 칸 이동

	캐릭터는 좌표평면의 (0, 0) 위치에서 시작한다
	좌표평면의 경계는 왼쪽 위 (-5, 5), 왼쪽 아래 (-5, -5),
	오른쪽 위 (5, 5), 오른쪽 아래 (5, -5)로 이루어진 사각형 맵이다

	우리는 캐릭터가 지나간 길 중 캐릭터가 
	처음 걸어본 길의 길이를 구하려고 한다

	단 좌표평면의 경계를 넘어가는 명령어는 무시한다

	명령어가 문자열 매개변수 dirs로 주어질 때,
	게임 캐릭터가 걸어본 길이를 구하여 return 하는 solution 함수 구현

	dirs는 'U', 'D', 'R', 'L'로 이뤄져 있다
	dirs의 길이는 500 이하이다


	parameter
	"LULLLLLLU"


	return
	7


	sol
	7, 8번 명령은 맵을 벗어나므로 무시하고
	나머지 경로로의 이동은 새로운 길이므로 7이다
*/

#include <string>

#define MAX 5
#define LEN (MAX * 2)

using namespace std;

bool visitR[LEN + 1][LEN];
bool visitC[LEN][LEN + 1];

inline void Init(string& _dirs) 
{

	/*
	
	방문 처리 초기화
	정사각형에 상한과 하한의 절댓값 y값이 같으므로 
	상하 대칭해도 이상없다 위는 -1, 아래는 +1연산을 한다
	*/
	for (int i = 0; i < LEN; i++)
	{

		for (int j = 0; j <= LEN; j++)
		{

			visitR[j][i] = false;
			visitC[i][j] = false;
		}
	}

	/*
	
	명령어 숫자로 변경
	동 : 0, 서 : 1, 남 : 2, 북 : 3
	*/
	for (char& dir : _dirs)
	{

		if (dir == 'R') dir = 0;
		else if (dir == 'L') dir = 1;
		else if (dir == 'D') dir = 2;
		else if (dir == 'U') dir = 3;
	}
}

inline bool ChkInvalidPos(pair<int, int>& _pos)
{

	if (_pos.first < 0 || _pos.second < 0
		|| _pos.first > LEN || _pos.second > LEN) return true;

	return false;
}

int solution(string _dirs)
{

	int answer = 0;

	Init(_dirs);

	pair<int, int> cur(MAX, MAX);

	for (const int op : _dirs)
	{

		pair<int, int> next;
		int r, c;
		
		if (op & 2)
		{

			// 상하 이동
			if (op & 1) next.first = cur.first - 1;
			else next.first = cur.first + 1;

			next.second = cur.second;

			// 유효한 명령어인지 확인
			if (ChkInvalidPos(next)) continue;

			if (op & 1) r = next.first;
			else r = cur.first;

			c = cur.second;

			// 이동
			cur = next;

			if (visitC[r][c]) continue;

			visitC[r][c] = true;
			answer++;
		}
		else 
		{
			// 좌우 이동
			if (op & 1) next.second = cur.second - 1;
			else next.second = cur.second + 1;

			next.first = cur.first;

			// 유효한 명령어인지 확인
			if (ChkInvalidPos(next)) continue;

			if (op & 1) c = next.second;
			else c = cur.second;

			r = cur.first;

			// 이동
			cur = next;

			// 지나온 길인지 확인
			if (visitR[r][c]) continue;

			visitR[r][c] = true;
			answer++;
		}
	}

	return answer;
}