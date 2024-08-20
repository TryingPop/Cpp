/*
날짜 : 2024. 8. 20
이름 : 배성훈
내용 : 테이블 해시 함수
	완호가 관리하는 어떤 데이터베이스의 한 테이블은 
	모두 정수 타입인 컬럼들로 이루어져 있다

	테이블은 2차원 행렬로 표현할 수 있으며
	열은 컬럼을 나타내고 행은 튜플을 나타낸다

	첫 번째 컬럼은 기본키로서 모든 튜플에 대해 
	그 값이 중복되지 않도록 보장된다

	완호는 이 테이블에 대한 해시 함수를 다음과 같이 정의했다

	1. 해시 함수는 col, row_begin, row_end를 입력으로 받는다

	2. 테이블의 튜플을 col 번째 컬럼의 값을 
	기준으로 오름차순 정렬을 하되, 
	만약 그 값이 동일하면 기본키인 첫 번째 컬럼의 값을 기준으로
	내림차순 정렬한다

	3. 정렬된 데이터에서 S_i를 i번째 행의 튜플에 대해
	각 컬럼의 값을 i로 나눈 나머지들의 합으로 정의

	4. row_begin <= i <= row_end인 모든 S_i를 누적하여
	bitwise XOR한 값을 해시 값으로서 반환한다

	테이블의 데이터 data와 해시함수에 대한
	입력 col, row_begin, row_end이 주어졌을 때
	테이블의 해시 값을 return 하도록 solution 함수를 구현

	data의 길이는 2500이하의 자연수,
	data의 원소 길이는 500 이하의 자연수

	data[i][j]의 값은 100만 이하의 자연수
	data[i][j]는 i + 1 번째 튜플의 j + 1 번째 컬럼의 값을 의미한다

	col은 data의 원소의 길이 이하인 자연수
	1 <= row_begin <= row_end <= data의 길이가 성립


	parameter
	{ { 2, 2, 6 }, {1, 5, 10 }, { 4, 2, 9 }, { 3, 8, 3 } }, 2, 2, 3


	return
	4


	sol
	조건에 따라 정렬하면
	{ 4, 2, 9 }, { 2, 2, 6 }, { 1, 5, 10 }, { 3, 8, 3 }
	순으로 정렬된다

	그리고 Si는 2 ~ 3까지이므로
	S2 = (2 mod 2) + (2 mod 2) + (6 mode 2) = 0
	S3 = (1 mod 3) + (5 mod 3) + (10 mode 3) = 4

	그리고 정답은 S2 ^ S3 = 4가된다
*/

#include <vector>
#include <algorithm>

using namespace std;

int comp;

bool MyComp(vector<int>& _f, vector<int>& _b)
{

	/*
	
	정렬 기준, col을 전역변수에 담는다
	*/

	if (_f[comp] == _b[comp]) return _b[0] < _f[0];
	return _f[comp] < _b[comp];
}

int solution(vector<vector<int>> _data, int _col, int _row_begin, int _row_end)
{

	/*
	
	정렬, 구현
	*/

	int answer = 0;
	comp = _col - 1;

	sort(_data.begin(), _data.end(), MyComp);

	vector<int> si;
	si.reserve(_row_end - _row_begin + 1);

	for (int r = _row_begin; r <= _row_end; r++)
	{

		int add = 0;
		for (int num : _data[r - 1])
		{

			// Si 구하기
			add += num % r;
		}

		si.push_back(add);
	}

	// 마지막 xor연산
	for (int num : si)
	{

		answer ^= num;
	}

	return answer;
}