#include <vector>

/*
날짜 : 2024. 3. 10
이름 : 배성훈
내용 : 배열 자르기
	정수 배열 numbers와 정수 num1, num2가 
	매개변수로 주어질 때,
	numbers의 num1번째 인덱스부터 
	num2번째 인덱스까지 자른 정수 배열을
	return 하는 solution 함수 구현
*/

using namespace std;

vector<int> solution(vector<int> _numbers, int _num1, int _num2)
{

	vector<int> answer;
	answer.assign(_numbers.begin() + _num1, _numbers.begin() + _num2 + 1);
	return answer;
}