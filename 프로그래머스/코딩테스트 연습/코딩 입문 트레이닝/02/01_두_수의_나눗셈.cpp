/*
날짜 : 2024. 3. 7
이름 : 배성훈
내용 : 두 수의 나눗셈
	정수 num1, num2가 주어질 때,
	num1을 num2로 나누는 값에 1'000을 곱한 후
	정수 부분을 return 하도록 solution 함수 구현
*/

int solution(int _num1, int _num2)
{

	int answer = (_num1 * 1000 / _num2);
	return answer;
}