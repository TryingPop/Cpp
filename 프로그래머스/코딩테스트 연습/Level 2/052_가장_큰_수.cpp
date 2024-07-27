/*
날짜 : 2024. 7. 27
이름 : 배성훈
내용 : 가장 큰 수
	0 또는 양의 정수가 주어졌을 때,
	정수를 이어붙여 만들 수 잇는 가장 큰 수를 알아내 주세요

	예를들어 주어진 정수가 { 6, 10, 2 }라면
	{ 6102, 6210, 1062, 1026, 2610, 2106 }을 만들 수 있고,
	이중에 가장 큰 수는 6210이다

	0 또는 양의 정수가 담긴 배열 numbers가 매개변수로 주어졌을 때,
	순서를 재배치하여 만들 수 있는 가장 큰 수를 문자열로 바꾸어 
	return 하도록 solution 함수 구현

	numbers의 길이는 1 이상 10만 이하
	numbers의 원소는 1'000 이하의 음이 아닌 정수
	정답은 문자열로 바꾸어 return

	parameter
	{ 6, 10, 2 }


	return
	"6210"


	sol
	문제 설명에 있다
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

inline bool MyComp(int _f, int _b)
{

	/*

	숫자 비교 함수
	f에 b를 이어붙였을 때 숫자를 n1,
	b에 f를 이어붙였을 때 숫자를 n2라하면
	n1 > n2이면 f를 앞에 오게한다

	string의 비교 연산은 사전식 연산이고,
	길이가 같은 경우 문자에 한해서는 숫자 크기 연산과 사전식 연산은 같다

	그리고 만약 숫자가 같다면 더 큰 수를 앞에 오게한다
	*/

	string f = to_string(_f);
	string b = to_string(_b);

	string chk1 = f + b;
	string chk2 = b + f;

	if (chk1 != chk2) return chk1 > chk2;
	return _b < _f;
}

string solution(vector<int> _numbers)
{

	string answer = "";

	/*
	
	Greedy
	*/

	sort(_numbers.begin(), _numbers.end(), MyComp);

	// MyComp 정렬 방법에 의해 앞에 있는 원소가 왼쪽에 있을 경우 더 큰 수가 된다
	// 이렇게 최대가 되게 계속해서 이어붙여나가면 모든 경우에서 최대가 보장된다
	if (_numbers[0])
	{

		for (int num : _numbers)
		{

			answer.append(to_string(num));
		}
	}
	// 만약 앞이 0이면 00000으로 이어붙이기에 반례처리
	// 케이스 중에 해당 부분 검증하는 문제 있다
	else answer = "0";

	return answer;
}