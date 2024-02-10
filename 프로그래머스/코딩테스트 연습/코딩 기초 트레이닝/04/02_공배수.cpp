/*
날짜 : 2024. 2. 10
이름 : 배성훈
내용 : 공배수
	정수 number, n, m이 주어질 때,
	number가 n의 배수이면서 동시에 m의 배수이면 1, 이외는 0을 반화하는 함수 만들기
*/

int solution(int _number, int _n, int _m)
{

	int answer = 0;

	answer = (_number % _n == 0) && (_number % _m == 0);
	return 0;
}