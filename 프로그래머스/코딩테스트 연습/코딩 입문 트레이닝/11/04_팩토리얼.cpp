/*
날짜 : 2024. 3. 12
이름 : 배성훈
내용 : 팩토리얼
	n 팩토리얼 n!은
	n! = 1 * 2 * 3 * ... * n
	다음결과값이다

	정수 n이 주어질 때, i! <= n인
	i의 최대값을 return 하는 solution 함수를 구현

	10! = 3'628'800이다
*/

int solution(int _n)
{

	int answer = 0;

	int fac = 1;
	for (int i = 1; i <= 10; i++)
	{

		fac *= i;
		// fac이 큰 경우 탈출
		if (_n < fac) break;
		// 작거나 같은 경우 i값 계승한다
		answer++;
	}

	return answer;
}