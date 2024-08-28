/*
날짜 : 2024. 8. 28
이름 : 배성훈
내용 : 광물 캐기
	마인은 곡괭이로 광산에서 광석을 캐려고 한다
	마인은 다이아몬드 곡괭이, 철 곡괭이, 돌 곡괭이를
	각각 0개에서 5개까지 가지고 있으며,

	곡괭이로 광물을 캘 때는 피로도가 소모된다
	각 곡괭이로 광물을 캘 때의 피로도는 다음과 같다

		
	곡괭이	/	광물		다이아몬드		철		돌
		다이아몬드			1				1		1
		철					5				1		1
		돌					25				5		1

	각 곡괭이는 종류에 상관없이 광물 5개를 캔 후에는
	더 이상 사용할 수 없다

	마인은 다음과 같은 규칙을 지키면서 최소한의 피로도로 광물을 캐려고 한다

	사용할 수 있는 곡괭이 중 아무거나 하나를 선택해 광물을 캔다
	한 번 사용하기 시작한 곡괭이는 사용할 수 없을 때까지 사용한다
	광물은 주어진 순서대로만 캘 수 있다
	광산에 있는 모든 광물을 캐거나, 더 사용할 곡괭이가 없을 때까지 광물을 캔다

	즉, 곡괭이를 하나 선택해서 광물 5개를 연속으로 캐고,
	다음 곡괭이를 선택해서 광물 5개를 연속으로 캐는 과정을 반복하며,
	더 사용할 곡괭이가 없거나 광산에 있는 모든 광물을 캘 때까지 과정을 반복하면 된다

	마인이 갖고 있는 곡괭이의 개수를 나타내는 picks와 
	광물의 순서를 나타내는 문자열 배열 minerals가 매개변수로 주어질 때,
	마인이 작업을 끝내기까지 필요한 최소한의 피로도를 
	return 하는 solution 함수 구현

	picks는 { dia, iron, stone }과 같은 구조로 이루어져 있다
	dia, iron, stone은 5 이하의 음이아닌 정수
	dia는 다이아몬드 곡괭이의 수를 의미한다
	iron은 철 곡괭이의 수를 의미한다
	stone은 돌 곡괭이의 수를 의미한다
	곡괭이는 치ㅗ소 1개 이상 갖고 있다

	minerals의 길이는 5 이상 50이하
	minerals는 다음 3개의 문자열로 이루어져 있으며 각각의 의미는 다음과 같다
	diamond : 다이아몬드, iron : 철, stone : 돌


	parameter
	{ 1, 3, 2 }, { "diamond", "diamond", "diamond", "iron", "iron", "diamond", "iron", "stone" }


	return
	12


	sol
	diamond 곡괭이, iron 곡괭이 순으로 곡괭이를 사용하면
	12의 피로도가 나오고
	그 이하로 나오는 경우의 수는 없다
*/	

#include <string>
#include <vector>

#define Min(X, Y)	(((X) < (Y)) ? (X) : (Y))

using namespace std;

inline int GetScore(int _type, string& _m)
{

	/*
	
	광물을 곡괭이별로 피로도를 구해 반환
	type: 곡괭이 종류
	0 : 다이아몬드, 1 : 철, 2 : 돌
	*/
	int ret;
	if (_m[0] == 'd') ret = 25;
	else if (_m[0] == 'i') ret = 5;
	else ret = 1;

	if (_type == 0) ret = 1;
	else if (_type == 1) ret /= 5;

	if (ret == 0) ret++;
	return ret;
}

inline int GetRangeScore(int _s, int _type, vector<string>& _minerals)
{

	/*
	
	해당 구간의 곡괭이별 피로도를 구한다
	type : 곡괭이 종류
	0 : 다이아몬드, 1 : 철, 2 : 돌

	s : 시작 구간
	*/

	int ret = 0;
	// 5개 범위가 벗어나는지 확인
	int e = Min(_s * 5 + 5, _minerals.size());

	for (int i = _s * 5; i < e; i++)
	{

		ret += GetScore(_type, _minerals[i]);
	}

	return ret;
}

inline int DFS(int _s, vector<int>& _picks, vector<string>& _minerals)
{

	/*
	
	구간별로 곡괭이를 사용해가며 구한다
	3^(50 / 5) 경우의 수다
	*/

	// 광물을 다 캔 경우
	if (_minerals.size() < _s * 5) return 0;

	// 나올 수 없는 아주 큰 피로도
	int ret = 10'000;

	for (int i = 0; i < 3; i++)
	{

		// 곡괭이 다썼는지 확인
		if (_picks[i] == 0) continue;

		// 곡괭이 type i인 쓰고 최소 피로도를 구한다
		_picks[i]--;
		int chk = GetRangeScore(_s, i, _minerals);
		chk += DFS(_s + 1, _picks, _minerals);

		if (chk < ret) ret = chk;
		_picks[i]++;
	}

	if (ret == 10'000) ret = 0;
	return ret;
}

int solution(vector<int> _picks, vector<string> _minerals)
{

	/*
	
	DFS, 브루트포스
	*/
	int answer = DFS(0, _picks, _minerals);
	return answer;
}