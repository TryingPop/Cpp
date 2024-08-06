/*
날짜 : 2024. 8. 7
이름 : 배성훈
내용 : 124 나라의 숫자
	124 나라에서는 10진법이 아닌 다음과 같은 규칙으로
	수를 표현한다

	124 나라에는 자연수만 존재한다
	124 나라에는 모든 수를 표현할 때 1, 2, 4만 사용한다

	자연수 n이 매개변수로 주어질 때, 
	n을 124 나라에서 사용하는 숫자로 바꾼 값을
	return 하는 solution 함수 구현

	n은 5천만 이하의 자연수

	parameter
	10


	return
	"41"


	sol
	
	숫자	124나라 숫자
	 1			 "1"
	 2			 "2"
	 3			 "4"
	 4			"11"
	 5			"12"
	 6			"14"
	 7			"21"
	 8			"22"
	 9			"24"
	10			"41"

	이므로 "41"이다
*/

#include <string>
#include <vector>

using namespace std;

string solution(int _n)
{

	/*
	
	Greedy
	*/
	string answer = "";

	vector<char> num = { '1', '2', '4' };
	vector<int> tPow;		// 자리값 별 나눌 수 (3의 제곱)
	_n--;					// 계산편의

	int add = 3;

	while (true) 
	{

		// 자리수 확인
		// 자리 초과하는 경우
		// 마지막 자리수는 못찾는다
		// 만약 시작과 동시에 3을 넣으면 찾을 수 있다
		if (_n - add < 0) break;
		_n -= add;
		tPow.push_back(add);
		add *= 3;
	}

	while (tPow.size())
	{

		// 가장 큰 수부터 찾아간다
		int div = tPow.back();
		tPow.pop_back();
		int idx = _n / div;
		_n %= div;
		answer.push_back(num[idx]);
	}

	// 마지막 자리수 따로 처리
	answer.push_back(num[_n]);
	return answer;
}