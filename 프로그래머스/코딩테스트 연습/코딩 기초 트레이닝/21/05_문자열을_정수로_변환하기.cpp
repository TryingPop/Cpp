#include <string>

/*
날짜 : 2024. 2. 27
이름 : 배성훈
내용 : 문자열을 정수로 변환하기
	숫자로만 이루어진 문자열
	n_str이 주어질 때,

	n_str을 정수로 변환하여 return하는 solution 함수 구현
*/

using namespace std;

int solution(string _n_str)
{

	int answer = stoi(_n_str);
	return answer;
}