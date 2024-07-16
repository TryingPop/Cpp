/*
날짜 : 2024. 7. 16
이름 : 배성훈
내용 : 땅따먹기
	게임의 땅은 N행 4열로 이루어져 있다
	모든 칸에는 점수가 쓰여있다

	1행 땅을 밟으며 한 행씩 내려올 때,
	각 행의 4칸 중 한 칸만 밟으면서 내려와야 한다
	
	단, 땅따먹기 게임에서는 한 행씩 내려올 때
	같은 열을 연속해서 밟을 수 없는 특수 규칙이 있다

	마지막 행까지 모두 내려왔을 때,
	얻을 수 있는 점수의 최대값을 
	return 하는 solution 함수 구현

	행의 개수 N : 10만 이하의 자연수
	열의 개수는 4개, 땅은 2차원 배열로 주어진다

	점수는 100 이하의 자연수


	prameter
	{ { 1, 2, 3, 5 }, { 5, 6, 7, 8 }, { 4, 3, 2, 1 } }


	return
	16

	
	sol
	5 -> 7 -> 4 순으로 내려오면 된다
*/

#include <vector>

using namespace std;

int solution(vector<vector<int>> _land)
{

	int answer = 0;

	/*
	
	이전 최대 값을 메모해두고 푼다
	그리고 최대값은 최대가 되는 경로로 내려온 경우에 존재한다
	O(row * col * col)
	*/
	int row = _land.size();
	int col = _land[0].size();

	vector<int> cur(col, 0);
	vector<int> next(col, 0);

	for (int r = 0; r < row; r++)
	{

		// 다음열을 밟았을 때 최대값 찾기
		for (int c = 0; c < col; c++)
		{

			for (int i = 0; i < col; i++)
			{

				if (i == c) continue;
				int chk = cur[c] + _land[r][c];
				if (next[i] < chk) next[i] = chk;
			}
		}

		// 다음을 현재로 수정
		for (int c = 0; c < col; c++)
		{

			cur[c] = next[c];
			next[c] = 0;
		}
	}

	for (int i = 0; i < col; i++)
	{

		answer = answer < cur[i] ? cur[i] : answer;
	}

	return answer;
}