/*
날짜 : 2024. 9. 4
이름 : 배성훈
내용 : 혼자서 하는 틱택토
	틱택토는 두 사람이 하는 게임으로 처음에
	3 x 3의 빈칸으로 이루어진 게임판에 선공이 "O", 후공이 "X"를 번갈아 가면서
	빈칸에 표시하는 게임이다

	가로, 세로, 대각선으로 3개가 같은 표시가 만들어지면 같은 표시를
	만든 사람이 승리하고 게임이 종료되며
	9칸이 모두 차서 더 이상 표시를 할 수 없는 겨웅에는 무승부로 게임이 종료 된다

	할 일이 없어 한가한 머쓱이는 두 사람이 하는 게임인
	틱택토를 다음과 같이 혼자서 하려고 한다

	혼자서 선공과 후공을 맡는다
	틱택토 게임을 시작한 후 "O"와 "X"를 혼자서 번갈아 가면서
	표시를 하면서 진행한다

	틱택토는 단순한 규칙으로 게임이 금방 끝나기에 머쓱이는
	한 게임이 종료되면 다시 3 x 3빈칸을 그린 뒤 다시 게임을 반복한다
	그렇게 틱택토 수 십 판을 했더니 머쓱이는 게임 도중에
	다음과 같이 규칙을 어기는 실수를 했을 수도 있다

	"O"를 표시할 차례인데 "X"를 표시하거나 
	반대로 "X"를 표시할 차례인데 "O"를 표시한다

	선공이나 후공이 승리해서 게임이 종료 되었으므에도 그 게임을 진행한다

	게임 도중 게임판을 본 어느 순간 머쓱이는 본인이 실수를 했는지 의문이 생겼다
	혼자서 틱택토를 했기에 게임하는 과정을 지켜본 사람이 없어 이를 알 수 없다
	그러나 게임판만 봤을 때 실제로 틱택토 규칙을 지켜서 진행했을 때
	나올 수 있는 상황인지는 판단할 수 있을 것 같고 문제가 없다면
	이어서 하려고 한다

	머쓱이가 혼자서 게임을 진행하다 의문이 생긴 틱택토 게임판 정보를 담고 있는 
	문자열 배열 board가 매개변수로 주어질 때,
	이 게임판이 규칙을 지켜서 틱택토를 진행했을 때 나올 수 있는 게임 상황이면
	1을 아니라면 0을 return 하는 solution 함수 구현

	board의 길이와 board[i]의 길이는 3이다
	board의 원소는 모두 "O", "X", "."으로만 이루어져 있다
	"."은 빈칸을 의미한다


	paramter
	{ "O.X", ".O.", "..X" }


	return
	1


	sol
	맵을 보면
		O	.	X
		.	O	.
		.	.	X

	형태이다
	2행 2열 O -> 1행 3열 X -> 1행 1열 O -> 3행 3열 X
	로 진행하면 규칙을 지켜서 진행한 택택토이고
	나올 수 있는 상황이다
*/

#include <string>
#include <vector>

using namespace std;

inline int Count(const vector<string>& _board)
{

	/*
	
	O, X 개수 가능한지 판별
	*/

	int o = 0, x = 0;
	for (int r = 0; r < 3; r++)
	{

		for (int c = 0; c < 3; c++)
		{

			if (_board[r][c] == 'O') o++;
			else if (_board[r][c] == 'X') x++;
		}
	}

	return o - x;
}

inline bool ChkWin(const vector<string>& _board, const char _mark)
{

	/*
	
	mark가 이기는지 확인
	*/

	// 가로, 세로
	for (int i = 0; i < 3; i++)
	{

		// 가로
		if (_board[i][0] == _mark
			&& _board[i][1] == _mark
			&& _board[i][2] == _mark) return true;

		// 세로
		if (_board[0][i] == _mark
			&& _board[1][i] == _mark
			&& _board[2][i] == _mark) return true;
	}

	// 대각
	if (_board[0][0] == _mark
		&& _board[1][1] == _mark
		&& _board[2][2] == _mark) return true;

	if (_board[2][0] == _mark
		&& _board[1][1] == _mark
		&& _board[0][2] == _mark) return true;

	return false;
}

inline int ChkPossible(const vector<string>& _board)
{

	/*
	
	가능한지 판별
	개수차, 승패 판정만으로 충분하다
	*/

	int cnt = Count(_board);
	if (cnt < 0 || cnt > 1) return 0;

	bool wO = ChkWin(_board, 'O');
	bool wX = ChkWin(_board, 'X');

	if (wO && !wX && cnt == 1) return 1;
	else if (!wO && wX && cnt == 0) return 1;
	else if (!wO && !wX) return 1;

	return 0;
}

int solution(vector<string> _board)
{

	/*
	
	게임이론?
	*/
	int answer = ChkPossible(_board);
	return answer;
}