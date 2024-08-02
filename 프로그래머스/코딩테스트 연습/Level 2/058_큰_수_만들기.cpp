/*
날짜 : 2024. 8. 2
이름 : 배성훈
내용 : 큰 수 만들기
	어떤 숫자에서 k개의 수를 제거했을 때
	얻을 수 있는 가장 큰 숫자를 구하려고 한다

	문자열 형식으로 숫자 number와 제거할 수의 개수 k가
	solution 함수의 매개변수로 주어질 때,

	number에서 k개의 수를 제거했을 때 만들 수 있는
	수 중 가장 큰 숫자를 문자열 형태로 return 하도록
	solution 함수를 구현

	number은 2자리 이상 100만 자리 이하의 숫자이고,
	k는 1이상 number의 자릿수 미만인 자연수이다

	parameter
	"1231234", 3


	return
	"3234"


	sol
	12, 1을 제외하면된다
*/

#include <string>

using namespace std;

string solution(string _number, int _k)
{

	/*
	
	스택, Greedy

	*/
	string answer = "";
	answer.reserve(_number.size() - _k + 1);

	// 앞에서부터 남은 제거횟수거리 안에 
	// 자기보다 뒤에 큰 수가 있으면 제거한다
	// 아니면 해당 수를 살린다
	int top = -1;
	for (const char c : _number)
	{

		while (_k > 0 && top >= 0 && _number[top] < c)
		{

			top--;
			_k--;
		}

		_number[++top] = c;
	}

	// 아직 k개 제거 안되면 뒤에서부터 제거한다
	if (_k) top -= _k;

	// 정답 이어붙이기
	answer.insert(answer.begin(), _number.begin(), _number.begin() + top + 1);

	return answer;
}