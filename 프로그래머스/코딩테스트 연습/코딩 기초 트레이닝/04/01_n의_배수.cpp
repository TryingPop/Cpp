/*
날짜 : 2024. 2. 10
이름 : 배성훈
내용 : n의 배수
	정수 num과 n이 매개변수로 주어질 때,
	num이 n의 배수이면 1, 아니면 0을 출력하는 함수 만들기
*/

int solution(int _num, int _n) 
{

	int answer = 0;

	answer = _num % _n == 0;
	return answer;
}