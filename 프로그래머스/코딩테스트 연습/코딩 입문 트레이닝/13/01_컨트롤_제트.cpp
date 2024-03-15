#include <string>

/*
날짜 : 2024. 3. 15
이름 : 배성훈
내용 : 컨트롤 제트
	숫자와 "Z"가 공백으로 구분되어 담긴 문자열이 주어질 때,
	문자열에 있는 숫자를 차례대로 더하려고 한다

	이 때 "Z"가 나오면 바로 전에 더했던 숫자를 뺀다는 뜻
	숫자와 "Z"로 이루어진 문자열 s가 주어질 때,

	해당 규칙을 진행한 값을 return 하는 solution 함수 구현

	"Z"와 숫자는 공백으로 구분되어져 있다
	"Z"로 시작하지 않고 연속해서 "Z"가 나오지 않는다
	또한 0을 제외하고는 0으로 시작하는 숫자는 없다
	공백으로 시작하거나 공백으로 끝나지 않으며 연속해서
	공백이 나오지 않는다
*/

using namespace std;

int solution(string _s)
{

	int answer = 0;

	int before = 0;
	int calc;
	bool plus = true;

	for (const char c : _s) 
	{

		if (c == ' ')
		{

			// 공백 발견 시 숫자 넣기
			calc = plus ? calc : -calc;
			answer += calc;
			before = calc;
			calc = 0;
			plus = true;
		}
		else if (c == '-') plus = false;
		else if (c == 'Z') answer -= before;
		else calc = calc * 10 + c - '0';
	}

	if (calc != 0)
	{

		calc = plus ? calc : -calc;
		answer += calc;
	}

	return answer;
}