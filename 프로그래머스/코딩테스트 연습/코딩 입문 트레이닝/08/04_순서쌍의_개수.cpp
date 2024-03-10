/*
날짜 : 2024. 3. 10
이름 : 배성훈
내용 : 순서쌍의 개수
	순서쌍이란 두 개의 숫자를 순서를 정하여
	짝지어 나타낸 쌍

	자연수 n이 매개변수로 주어질 때,
	두 숫자의 곱이 n인 자연수
	순서쌍의 개수를 return하도록 solution 함수 구현
*/

int solution(int _n)
{

	int answer = 0;

	for (int i = 1; i <= _n; i++)
	{

		// 에라토스테네스의 체 이론
		if (i * i > _n) break;

		// 나눠떨어지지 않는 경우 다음 숫자로
		if (_n % i) continue;

		// 나눠떨어지는데 제곱수면 1개만 센다
		if (_n == i * i) answer++;
		else answer += 2;
	}

	return answer;
}