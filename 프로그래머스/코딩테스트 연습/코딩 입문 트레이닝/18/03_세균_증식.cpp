/*
날짜 : 2024. 3. 20
이름 : 배성훈
내용 : 세균 증식
	세균은 1 시간에 2 배만큼 증식한다
	처음 세균 마리 수 n과 경과한 시간 t가
	매개변수로 주어질 때,
	t 시간 후 세균의 수를 return 하는
	solution 함수 구현

	n은 10 이하의 자연수이고,
	t는 15 이하의 자연수 이다
*/

int solution(int _n, int _t)
{

	int answer = _n;
	for (int i = 0; i < _t; i++)
	{

		answer *= 2;
	}

	return answer;
}