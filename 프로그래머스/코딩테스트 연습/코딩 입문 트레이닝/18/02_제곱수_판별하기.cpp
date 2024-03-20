/*
날짜 : 2024. 3. 20
이름 : 배성훈
내용 : 제곱수 판별하기
	어떤 자연수를 제곱했을 때,
	나오는 정수를 제곱수라고 한다
	n이 매개변수로 주어질 때,
	n이 제곱수라면 1을 아니면 2로
	return 하는 solution 함수를 구현
*/

int solution(int _n)
{

	int answer = 2;

	for (int i = 1; i <= _n; i++)
	{

		if (i * i > _n) break;
		if (i * i < _n) continue;

		answer = 1;
		break;
	}

	return answer;
}