/*
날짜 : 2024. 6. 8
이름 : 배성훈
내용 : 최댓값과 최솟값
	문자열 s에는 공백으로 구분된 숫자들이 저장되어 있다
	str에 나타나는 숫자 중 최솟값과 최댓값을 찾아
	이를 "(최솟값) (최댓값)" 형태의 문자열을 반환하는 함수,
	solution 함수를 구현

	예를들어 s가 "1 2 3 4"라면 "1 4"를 리턴하고,
	"-1 -2 -3 -4"라면 "-4 -1"을 return하면 된다

	s에는 둘 이상의 정수가 공백으로 구분되어 있다
*/

#include <string>		// 문자열 입력
#include <sstream>		// split

using namespace std;

string solution(string _s)
{

	string answer;

	stringstream ss(_s);
	int n;

	int ret1 = 1e9;			// min
	int ret2 = -1e9;		// max

	// 공백을 띄어서 읽는다
	while (ss >> n)
	{

		// 최댓값 최솟값 찾기
		ret1 = n < ret1 ? n : ret1;
		ret2 = ret2 < n ? n : ret2;
	}

	// 출력 형태에 맞춰 출력
	answer = to_string(ret1) + " " + to_string(ret2);
	return answer;
}