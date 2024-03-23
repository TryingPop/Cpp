#include <vector>

/*
날짜 : 2024. 3. 23
이름 : 배성훈
내용 : 안전지대
	지뢰가 있는 지역과 지뢰에 인접한 위, 아래, 
	좌, 우,	대각선 칸을 모두 위험지역으로 분류

	지뢰는 2차원 배열 board에 1로 표시되어 있고
	board에는 지뢰가 매설된 지역 1과,
	지뢰가 없는 지역 0만 존재

	지뢰가 매설된 지역의 지도 board가 매개변수로
	주어질 때, 안전한 지역의 칸 수를
	return 하는 solution 함수 구현
*/

using namespace std;

bool ChkValidPos(int _r, int _c, int _row, int _col)
{

	if (_r < 0 || _c < 0 || _r >= _row || _c >= _col) return false;
	return true;
}

void ChangeVal(int* _answer, int* _val)
{

	if (*_val != 0) return;

	// *_answer--;
	// 로하니 제대로 작동안한다;
	// 이거 때문에 엄청나게 틀렸다;
	*_answer = *_answer - 1;
	*_val = 2;
}

int solution(vector<vector<int>> _board)
{

	int answer;

	int row = _board.size();
	int col = _board[0].size();

	answer = row * col;

	for (int r = 0; r < row; r++) 
	{

		for (int c = 0; c < col; c++)
		{

			if (_board[r][c] != 1) continue;

			// 해당 폭탄 확인했다고 변경
			_board[r][c] = 2;
			answer--;

			// 상하좌우 위험지역 지역 유효한지 보고
			// 
			if (ChkValidPos(r - 1, c, row, col))
				ChangeVal(&answer, &_board[r - 1][c]);

			if (ChkValidPos(r + 1, c, row, col))
				ChangeVal(&answer, &_board[r + 1][c]);

			if (ChkValidPos(r, c - 1, row, col))
				ChangeVal(&answer, &_board[r][c - 1]);

			if (ChkValidPos(r, c + 1, row, col))
				ChangeVal(&answer, &_board[r][c + 1]);

			// 대각선
			if (ChkValidPos(r - 1, c - 1, row, col))
				ChangeVal(&answer, &_board[r - 1][c - 1]);

			if (ChkValidPos(r - 1, c + 1, row, col))
				ChangeVal(&answer, &_board[r - 1][c + 1]);

			if (ChkValidPos(r + 1, c - 1, row, col))
				ChangeVal(&answer, &_board[r + 1][c - 1]);

			if (ChkValidPos(r + 1, c + 1, row, col))
				ChangeVal(&answer, &_board[r + 1][c + 1]);
		}
	}

	return answer;
}

