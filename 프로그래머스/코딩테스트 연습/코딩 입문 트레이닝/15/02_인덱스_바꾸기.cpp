#include <string>
#include <vector>

/*
날짜 : 2024. 3. 17
이름 : 배성훈
내용 : 인덱스 바꾸기
	문자열 my_string과 정수 num1, num2이 매개변수로 주어질 때,
	my_string에서 인덱스 num1과 인덱스 num2에 해당하는 문자를 바꾼
	문자열을 return 하는 solution 함수 구현
*/

using namespace std;

string solution(string _my_string, int _num1, int _num2)
{

	string answer = _my_string;
	swap(answer[_num1], answer[_num2]);

	return answer;
}