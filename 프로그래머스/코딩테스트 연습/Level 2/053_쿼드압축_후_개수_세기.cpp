/*
날짜 : 2024. 7. 28
이름 : 배성훈
내용 : 쿼드압축 후 개수 세기
	0과 1로 이루어진 2^n x 2^n 크기의 2차원 정수 배열 arr이 있다
	arr을 쿼드 트리와 같은 방식으로 압축하고자 한다

	압축하고자 하는 특정 영역을 S라 하자

	만약 S 내부에 있는 모든 수가 같은 값이라면
	S를 해당 수 하나로 압축시킨다

	그렇지 않다면 S를 정확히 4개의 균일한 정사각형 영역으로 쪼갠 뒤,
	각 정사각형 영역에 대한 같은 방식의 압축을 시도한다

	arr이 매개변수로 주어진다
	위와 같은 방식으로 arr을 압축했을 때,
	배열에 최종적으로 남는 0의 개수와 1의 개수를 배열에 담아서
	return 하는 solution 함수 구현

	arr의 행의 개수는 1 이상 1024 이하이고,
	2의 거듭 제곱수 형태를 하고 있다

	arr의 열의 개수는 행의 개수와 같은 정사각형 배열이다
	arr의 모든 값은 0 또는 1이다

	parameter
	{ { 1, 1, 0, 0 },
	  { 1, 0, 0, 0 },
	  { 1, 0, 0, 1 },
	  { 1, 1, 1, 1 } }


	return
	{ 4, 9 }


	sol
	모든 원소가 같지 않으므로 4등분 한다

	1 1	| 0 0
	1 0	| 0 0
	---- ----
	1 0 | 0 1
	1 1 | 1 1

	그러면 왼쪽 위, 왼쪽 아래, 오른쪽 아래를 보면 
	1, 0 으로 통일되어져 있지 않아 그대로 된다

	오른쪽 위는 0으로 모두 같아 0으로 합쳐진다
	그래서
	1 1 |
	1 0 | 0
	---- -----
	1 0 | 0 1
	1 1 | 1 1

	세면 0은 4개, 1은 9개가 나온다
*/

#include <vector>

#define ll long long

using namespace std;

// 1천만 이상 자리에 1의 개수 포함시킨다
const ll ONE = 10'000'000;
// 1천만 미만 자리에 1의 개수 포함시킨다
const ll ZERO = 1;

inline bool ChkNum(ll _num1, ll _num2, ll _num3, ll _num4, ll _chk)
{

	/*
	
	num1 ~ num4가 chk랑 같은지 확인
	*/
	return _num1 == _chk && _num2 == _chk && _num3 == _chk && _num4 == _chk;
}

inline ll DNC(vector<vector<int>>& _board, int _r, int _c, int _size)
{

	/*
	
	1의 개수는 1천만 이상 자리에 있다
	0의 개수는 1천만 미만의 자리의 값
	*/
	if (_size == 1)
	{

		// 탈출 코드
		if (_board[_r][_c] == 1) return ONE;
		else return ZERO;
	}

	// 분할
	int midSize = _size >> 1;

	ll num1 = DNC(_board, _r, _c, midSize);
	ll num2 = DNC(_board, _r + midSize, _c, midSize);
	ll num3 = DNC(_board, _r, _c + midSize, midSize);
	ll num4 = DNC(_board, _r + midSize, _c + midSize, midSize);

	// 정복
	if (ChkNum(num1, num2, num3, num4, ONE)) return ONE;
	else if (ChkNum(num1, num2, num3, num4, ZERO)) return ZERO;

	return num1 + num2 + num3 + num4;
}

vector<int> solution(vector<vector<int>> _arr)
{

	/*
	
	분할 정복
	*/
	vector<int> answer(2);
	int size = _arr.size();

	ll ret = DNC(_arr, 0, 0, size);

	answer[0] = ret % ONE;
	answer[1] = ret / ONE;

	return answer;
}