/*
날짜 : 2024. 8. 30
이름 : 배성훈
내용 : 과제 진행하기
	과제를 받은 루는 다음과 같은 순서대로 
	과제를 하려고 계획을 세웠다

	과제는 시작하기로 한 시각이 되면 시작한다

	새로운 과제를 시작할 시가깅 되었을 때,
	기존에 진행 중이던 과제가 있다면
	진행 중이던 과제를 멈추고 새로운 과제를 시작한다

	진행 중이던 과제를 끝냈을 때,
	잠시 멈춘 과제가 있다면, 멈춰둔 과제를 이어서 진행한다
	
	만약 과제를 끝낸 시간에 새로 시작해야 되는 과제와
	멈춰둔 과제가 모두 있다면 새로 시작해야 하는 과제부터 진행한다

	멈춰둔 과제가 여러 개일 경우, 가장 최근에 멈춘 과제부터 시작한다

	과제 계획을 담은 이차원 문자열 배열 plans가 매개변수로 주어질 때,
	과제를 끝낸 순서대로 이름을 배열에 담아 return 하는 solution 함수 구현

	plans의 길이는 1000 이하

	plans의 원소는 { name, start, playtime }의 구조로 이루어져 있다
	name : 과제의 이름, start : 과제의 시작 시각, playtime : 과제를 마치는데 걸리는 시각
	을 의미하고
	과제의 이름은 중복된게 없고 알파벳 소문자로만 이루어져 있다

	과제의 시작 시간은 hh:mm 형태이고 00:00 ~ 23:59 사이의 시간만 있다
	00:00, ..., 23:59 순서로 실행하면 된다

	과제를 마치는 시간은 숫자형태인 문자열이며 숫자로 바꿨을 때 100 이하의 자연수이다

	배열은 시간순으로 정렬되어 있지 않다

	진행중이던 과제가 끝나는 시각과 새로운 과제를 시작해야하는 시각이 같은 경우
	진행 중이던 과제는 끝난것으로 판단한다

	parameter
	{ { "korean", "11:40", "30" }, { "english", "12:10", "20" }, 
	  { "math", "12:30", "40" } }


	return
	{ "korean", "english", "math" }


	sol
	시작 시각이 가장 빠른 korean부터 시작한다
	12:10분에 korean은 완료되고

	english를 실행한다
	12:30분에 english는 완료되고

	math를 실행한다

	그래서 korean, english, math 순으로 끝난단
*/

#include <string>
#include <vector>
#include <algorithm>
#include <stack>

#define NUM(X) (X - '0')
#define INF 123'456

using namespace std;

struct HW
{

	/*
	
	과제를 담을 자료구조
	기존에는 문자열들이기에 숫자로 변환할 수 있는건 숫자로 변환한다
	*/
	string name;
	int start;		// 00:00에서 몇 분 흘렀는지 숫자로 변환
	int playtime;

	HW(string& _name, int _start, int _playtime)
		: name(_name), start(_start), playtime(_playtime) { }
};

inline bool MyComp(const vector<string>& _f, const vector<string>& _b)
{

	/*
	
	문자열 길이가 같으면 숫자처럼 비교한다
	*/
	return _f[1] < _b[1];
}

inline int GetStart(const string& _start)
{

	/*
	
	시간 계산
	*/
	int h = NUM(_start[0]) * 10 + NUM(_start[1]);
	int m = NUM(_start[3]) * 10 + NUM(_start[4]);

	return h * 60 + m;
}

inline int GetPlayTime(const string& _playtime)
{

	/*
	
	string을 숫자로 바꾼다
	*/
	int ret = 0;
	for (const char c : _playtime)
	{

		ret = ret * 10 + c - '0';
	}

	return ret;
}

inline void GetHW(vector<vector<string>>& _plans, vector<HW>& _hw)
{

	/*
	
	HW 자료구조로 변환한다
	*/
	_hw.reserve(_plans.size());
	for (vector<string>& p : _plans)
	{

		_hw.push_back(HW(p[0], GetStart(p[1]), GetPlayTime(p[2])));
	}
}

inline void GetRet(vector<HW>& _hw, vector<string>& _ret)
{

	/*
	
	숙제 시뮬레이션
	*/

	// 바로 앞 과제 저장하는 스택 자료구조
	stack<HW> stk;

	int s = 0;
	for (int i = 0; i < _hw.size(); i++)
	{

		// 다음 과제 시작 시간 없는 경우 INF
		int e = i + 1 == _hw.size() ? INF : _hw[i + 1].start;

		s = _hw[i].start;

		// 다음 시간까지 남은 시간
		int playtime = e - s;

		if (playtime < _hw[i].playtime)
		{

			// 시간이 부족해 현재 과제를 못 끝내는 경우
			_hw[i].playtime -= playtime;
			stk.push(_hw[i]);
			continue;
		}

		// 현재 과제를 끝낼 만큼 시간이 있는 경우
		playtime -= _hw[i].playtime;
		_ret.push_back(_hw[i].name);

		// 남은 과제 있는지 확인하고 남은 과제 최대한 실행
		while (playtime > 0 && stk.size())
		{

			HW& hw = stk.top();
			if (hw.playtime <= playtime)
			{

				playtime -= hw.playtime;
				stk.pop();
				_ret.push_back(hw.name);
				continue;
			}

			hw.playtime -= playtime;
			playtime = 0;
		}
	}

	// 남은 문제들 푼다
	// 여기서는 충분히 크게 e 값을 잡아 실제로 안쓰인다
	while (stk.size())
	{

		HW& hw = stk.top();
		_ret.push_back(hw.name);
		stk.pop();
	}
}

vector<string> solution(vector<vector<string>> _plans)
{

	/*
	
	스택, 정렬 문제
	*/
	vector<string> answer;
	answer.reserve(_plans.size());

	// 시작 시간 순으로 정렬
	sort(_plans.begin(), _plans.end(), MyComp);

	// 입력된 plans는 문자열로 이뤄져 있으므로
	// 숫자로 변환 가능한 것들은 숫자로 변환한 자료구조로 바꾼다
	vector<HW> hw;
	GetHW(_plans, hw);

	// 결과 연산
	GetRet(hw, answer);

	return answer;
}