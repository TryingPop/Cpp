/*
날짜 : 2024. 3. 10
이름 : 배성훈
내용 : 짝수의 합
	정수 n이 주어질 때,
	n이하의 짝수를 모두 더한 값을
	return 하는 solution 함수 구현
*/

int solution(int _n)
{

	// 합의 공식?을 썼다
	int answer = (_n / 2) * (_n / 2 + 1);
	return answer;
}