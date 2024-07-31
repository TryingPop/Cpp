/*
날짜 : 2024. 7. 31
이름 : 배성훈
내용 : 삼각 달팽이
	정수 n이 매개변수로 주어진다
	길이와 높이가 n인 삼각형 맨 위 꼭짓점부터
	반시계 방향으로 달팽이 채우기를 진행한 후,
	첫 행부터 마지막 행까지 모두 순서대로 합친 새로운 배열을
	return 하는 solution 함수 구현

	n은 1 이상 1'000 이하의 정수

	parameter
	4


	return
	{ 1, 2, 9, 3, 10, 8, 4, 5, 6, 7 }


	sol

	초기 삼각형의 인덱스는 다음과 같다
					0
				1		2
			3		4		5
		6		7		8		9


	달팽이 모양으로 번호를 부여하면
					1
				2		9
			3		10		8
		4		5		6		7
	이다

	그래서 { 1, 2, 9, 3, 10, 8, 4, 5, 6, 7 }이 정답이다
*/

#include <vector>

#define pii pair<int, int>

using namespace std;

inline int PosToInt(const pii& _pos)
{

	/*
	
	좌표를 결과의 인덱스로 변형
	*/
	return (_pos.first * _pos.first + _pos.first) / 2 + _pos.second;
}

inline void MoveByType(pii& _pos, int _type)
{

	/*
	
	타입별 좌표 이동
	type 0 : 왼쪽 아래 방향(/)
	type 1 : 오른쪽 방향 (-)
	type 2 : 왼쪽 위 방향 (\)
	*/

	switch (_type)
	{

	case 0:
		_pos.first++;
		return;

	case 1:
		_pos.second++;
		return;

	case 2:
		_pos.first--;
		_pos.second--;
		return;

	default:
		return;
	}
}

inline void LastMoveByType(pii& _pos, int _type)
{

	/*
	
	값 대입하고 좌표이동을 후 연산하기에
	마지막 부분에 조절이 필요하다
	*/
	switch (_type)
	{

	case 0:
		_pos.first--;
		_pos.second++;
		return;

	case 1:
		_pos.first -= 1;
		_pos.second -= 2;
		return;

	case 2:
		_pos.first += 2;
		_pos.second += 1;
		return;

	default:
		return;
	}
}

inline void FillRet(pii& _pos, int _type, int _s, int _n, vector<int>& _ret)
{

	/*
	
	시뮬레이션
	삼각달팽이 모양으로 한칸씩 이동한다
	왼쪽 아래 -> 오른쪽 -> 왼쪽 위 순서로 반복되어
	타입에 따라 재귀로 구현
	*/

	// 남은 길이가 0이면 탈출
	if (_n == 0) return;

	for (int i = 0; i < _n; i++)
	{

		int idx = PosToInt(_pos);
		_ret[idx] = _s++;

		MoveByType(_pos, _type);
	}

	LastMoveByType(_pos, _type);

	FillRet(_pos, (_type + 1) % 3, _s, _n - 1, _ret);
}

vector<int> solution(int _n)
{

	/*

	시뮬레이션, 구현
	달팽이 모양으로 한칸씩 이동하며 값을 채워 넣는다
	*/

	vector<int> answer((_n * _n + _n) / 2);
	pii pos(0, 0);

	FillRet(pos, 0, 1, _n, answer);

	return answer;
}