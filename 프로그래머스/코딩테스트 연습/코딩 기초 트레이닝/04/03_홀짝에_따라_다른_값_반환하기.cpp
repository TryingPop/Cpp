/*
날짜 : 2024. 2. 10
이름 : 배성훈
내용 : 홀짝에 따라 다른 값 반환하기
	양의 정수 n이 주어지면, n이 홀수라면 n이하의 홀수인 모든 양의 정수의 합을 반환하고,
	n이 짝수라면 n이항의 짝수인 모든 양의 정수 제곱의 합을 반환하는 함수 만들기
*/

int solution(int _n) 
{

	int answer = 0;

	if (_n & 1 << 0) 
	{

		while (_n > 0)
		{

			answer += _n;
			_n -= 2;
		}
	}
	else 
	{

		while (_n > 0) 
		{

			answer += _n * _n;
			_n -= 2;
		}
	}

	return answer;
}