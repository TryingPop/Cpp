/*
날짜 : 2024. 8. 18
이름 : 배성훈
내용 : 수식 최대화
	숫자들과 3 가지의 연산문자 +, -, * 가 주어진다
	연산자의 우선순위를 자유롭게 재정의하여 가장 큰 숫자를 찾아야한다

	단 연산자의 우선순위를 새로 정의할 때,
	같은 우선순위의 연산자는 없어야 한다

	+ > - > * 또는 - > * > + 등과 같이 연산자의 우선순위를 정의할 수 있으나
	+,* > - 또는 * > +-와 같이 2개 이상의 연산자가 동일한 순위를 가지도록
	연산자의 우선순위를 정의할 수 없다

	만약 계산된 결과가 음수라면 해당 숫자의 절댓값으로 변환하여 제출하며
	제출한 숫자가 가장 큰 참가자를 우승자로 선정하며,
	우승자가 제출한 숫자를 우승상금으로 지급한다

	참가자에게 주어진 연산 수식이 담긴 문자열 expression이
	매개변수로 주어질 때,

	우승 시 받을 수 있는 가장 큰 상금 금액을 
	return 하는 solution 함수 구현

	expression은 3이상 100이하의 문자
	
	expression은 공백문자, 괄호문자 없이 오로지 숫자와 
	3가지 연산자(+, -, *)로만 이루어진 올바른 중위 표기법으로 표현된 연산식

	expression의 피연산자는 0이상 999 이하의 숫자

	expression은 적어도 1개 이상의 연산자를 포함

	연산자 우선순위를 어떠헥 적용하더라도,
	expression의 중간 계산값과 최종 결괏값은 절댓값이
	2^63 - 1이하가 되도록 입력이 주어진다

	같은 연산자끼리는 앞에 있는 것이 우선순위가 더 높다


	parameter
	"100-200*300-500+20"


	return
	60420


	sol
	* > + > -로 우선순위를 하는 경우
	100 - 200 * 300 - 500 + 20
	= 100 - 60000 - 500 + 20
	= 100 - 60000 - 520
	= -60420
	이고 60420이다

	+ > - > *로 우선순위를 하는 경우
	100 - 200 * 300 - 500 + 20
	= 100 - 200 * 300 - 520
	= -100 * -220
	= 22000
	이고 22000이다

	이렇게 다른 경우도 찾아보면 60420이 최대값임을 알 수 있다
*/

#include <string>
#include <vector>

#define ll long long
#define Abs(X)	(((X) < 0) ? -(X) : (X))

using namespace std;

inline void ReadString(string& _expression, vector<ll>& _nums, vector<ll>& _ops)
{

	/*
	
	숫자와 연산자를 구분
	*/

	int num = 0;
	for (const char c : _expression)
	{

		if (c == '*' || c == '+' || c == '-')
		{

			_nums.push_back(num);
			num = 0;
			_ops.push_back(c);
		}
		else num = num * 10 + c - '0';
	}

	_nums.push_back(num);
}

void Op(vector<ll>& _nums, vector<ll>& _ops,
	char _op, vector<ll>& _rnums, vector<ll>& _rops)
{

	/*
	
	해당 연산 진행
	남은 숫자는 rnums, 남은 연산은 rops로 간다
	*/

	_rnums.push_back(_nums[0]);
	for (int i = 0; i < _ops.size(); i++)
	{

		if (_ops[i] == _op)
		{

			// 실행해야 하는 연산만 실행한다
			int idx = _rnums.size() - 1;

			if (_op == '*') _rnums[idx] *= _nums[i + 1];
			else if (_op == '+') _rnums[idx] += _nums[i + 1];
			else _rnums[idx] -= _nums[i + 1];
		}
		else 
		{

			// 실행해야 할 연산이 아니므로 다음 연산 결과로만 넘긴다
			_rnums.push_back(_nums[i + 1]);
			_rops.push_back(_ops[i]);
		}
	}
}

ll DFS(vector<ll>& _nums, vector<ll>& _ops, int _state = 0b111)
{

	/*
	
	연산을 하나씩 진행하면서 최대값을 찾는다
	*/

	if (!_state) return _nums[0];

	ll ret = 0;

	// 다음 숫자와 연산자
	vector<ll> rnums, rops;

	if (_state & (1 << 0))
	{

		// 곱셈 연산 실행
		Op(_nums, _ops, '*', rnums, rops);
		ll chk = DFS(rnums, rops, _state ^ (1 << 0));
		chk = Abs(chk);
		ret = ret < chk ? chk : ret;
	}

	if (_state & (1 << 1))
	{

		// 덧셈 연산 실행
		rnums.clear();
		rops.clear();
		Op(_nums, _ops, '+', rnums, rops);
		ll chk = DFS(rnums, rops, _state ^ (1 << 1));
		chk = Abs(chk);
		ret = ret < chk ? chk : ret;
	}

	if (_state & (1 << 2))
	{

		// 빼기 연산 실행
		rnums.clear();
		rops.clear();

		Op(_nums, _ops, '-', rnums, rops);
		ll chk = DFS(rnums, rops, _state ^ (1 << 2));
		chk = Abs(chk);
		ret = ret < chk ? chk : ret;
	}

	return ret;
}

ll solution(string _expression)
{

	vector<ll> nums, ops;
	ReadString(_expression, nums, ops);
	ll answer = DFS(nums, ops);
	return answer;
}