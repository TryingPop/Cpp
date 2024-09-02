/*
날짜 : 2024. 9. 2
이름 : 배성훈
내용 : N-Queen
	가로, 세로 길이가 n이 정사각형으로된 체스판이 있다
	체스판 위의 n개의 퀸이 서로를 공격할 수 없도록 배치하고 싶다

	체스판의 가로 세로 의 길이 n이 매개변수로 주어질 때,
	n개의 퀸이 조건에 만족하도록 배치할 수 있는
	방법의 수를 return 하는 solution 함수 구현

	퀸(Queen)은 가로, 세로, 대각선으로 이동할 수 있다
	n은 12 이하의 자연수이다

	parameter
	4


	return
	2


	sol
	X를 빈공간, Q를 퀸 배치라 할 때
	다음 방법으로 배치하면 된다
		X	X	Q	X
		Q	X	X	X
		X	X	X	Q
		X	Q	X	X
	그러면 퀸들은 서로 공격하지 못한다

	마찬가지로 다음과 같이 배치해도 된다
		X	Q	X	X
		X	X	X	Q
		Q	X	X	X
		X	X	Q	X
	
	이외의 경우는 없다
*/

#include <vector>

using namespace std;

vector<bool> ldia, rdia, h;

inline int DFS(int _depth, int _n)
{

	/*
	
	경우의 수를 찾는다
	*/

	// 퀸 n개를 채운 경우
	if (_depth == _n) return 1;
	int ret = 0;

	for (int i = 0; i < _n; i++)
	{

		// 세로, 좌대각(/), 우대각(\) 빈공간 확인
		if (h[i] || ldia[_depth + i] || rdia[_n - 1 + i - _depth]) continue;
		h[i] = true;
		ldia[_depth + i] = true;
		rdia[_n - 1 + i - _depth] = true;

		ret += DFS(_depth + 1, _n);

		h[i] = false;
		ldia[_depth + i] = false;
		rdia[_n - 1 + i - _depth] = false;
	}

	return ret;
}

int solution(int _n)
{

	/*
	
	백트래킹
	*/
	ldia.resize(2 * _n - 1, false);
	rdia.resize(2 * _n - 1, false);
	h.resize(_n, false);

	int answer = DFS(0, _n);

	return answer;
}