#include <string>
#include <vector>

/*
날짜 : 2024. 2. 9
이름 : 배성훈
내용 : 더 크게 합치기
	새로운 연산 +를 정의

	12 + 3 = 123
	3 + 12 = 312

	a, b를 넣었을 때,
	a + b나 b + a 중 큰 것을 출력하게 하는 solution 함수 만들기
	a, b는 1만 이하의 자연수

	input
	3 12

	answer
	312

	그냥 +연산과 max 함수를 이용하는게 좋아보인다
*/

using namespace std;

int solution(int _a, int _b)
{

	int answer = 0;

	string strA = to_string(_a);
	string strB = to_string(_b);

	
	string calc = "";
	calc.reserve(strA.size() + strB.size());

	calc.append(strA).append(strB);
	int front = stoi(calc);
	calc.clear();
	calc.append(strB).append(strA);
	int back = stoi(calc);

	answer = ((front < back) ? back : front);
	return answer;
}