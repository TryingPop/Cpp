/*
날짜 : 2024. 6. 18
이름 : 배성훈
내용 : 점프와 순간 이동
	한 번에 K 칸을 앞으로 점프하거나,
	(현재까지 온 거리) x 2에 해당하는 위치로 순간이동할 수 있다

	점프는 k칸 점프 시 k의 에너지를 소모한다
	순간이동은 0의 에너지를 소모한다

	0에서 n으로 이동한다
	매개변수 n이 주어질 때,

	점프나 순간이동으로 이동했을 때 
	소모하는 에너지의 최소값을 return 하는
	solution 함수 구현

	parameter 
	5


	return
	2
*/

int solution(int _n)
{

	int answer = 0;

	while (_n)
	{

		if (_n & 1) answer++;
		_n >>= 1;
	}

	return answer;
}