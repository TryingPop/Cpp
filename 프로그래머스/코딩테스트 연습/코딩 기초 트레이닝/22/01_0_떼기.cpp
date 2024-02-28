#include <string>

/*
날짜 : 2024. 2. 28
이름 : 배성훈
내용 : 0 떼기
	정수로 이루어진 문자열 n_str이 주어진다
	n_str의 가장 왼쪽에 처음으로 등장하는 0들을 뗀
	문자열을 return하도록 solution 함수를 구현

	n_str의 길이는 10자리 이하이다
*/

using namespace std;

string solution(string _n_str)
{

	string answer = to_string(stol(_n_str));
	return answer;
}