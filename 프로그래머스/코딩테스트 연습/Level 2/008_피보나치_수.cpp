/*
날짜 : 2024. 6. 15
이름 : 배성훈
내용 : 피보나치 수
	피보나치 수는 F(0) = 0, F(1) = 1이고
	2이상의 n에 대하여 F(n) = F(n - 1) + F(n - 2)가
	적용되는 수이다

	2 이상의 n이 입력되었을 때, n번째 피보나치 수를
	1234567으로 나눈 나머지를 return 하는 solution 함수 구현

	n은 2 이상 100'000 이하인 자연수

	parameter 
	5


	return 
	5
*/

int solution(int _n)
{

	int answer = 0;
	int calc = 1;

	for (int i = 1; i <= _n; i++)
	{

		int temp = (calc + answer) % 1234567;
		answer = calc;
		calc = temp;
	}

	return answer;
}