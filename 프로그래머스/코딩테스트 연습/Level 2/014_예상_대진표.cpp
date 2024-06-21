/*
날짜 : 2024. 6. 21
이름 : 배성훈
내용 : 예상 대진표
	토너먼트 게임에 N명이 참가한다
	참가자는 1번부터 N번을 차례대로 배정을 받는다
	그리고 1 : 2, 3 : 4, 5 : 6 ,... , (N-1) : N
	순서로 대결을 한다

	그리고 이긴 사람은 다음 라운드에 진출을 하고
	참가자의 번호는 1 : 2에서 이긴사람은 1,
	3 : 4에서 이긴 사람은 2, .... (N-1) : N에서 이긴 사람은
	N / 2의 번호를 다시 배정받고 다음 라운드를 진행한다
	새로 부여받은 번호로 1 : 2, 3 : 4 ,.... 으로 다시 대전을 한다

	이 때 처음 라운드에서 A번을 가진 참가자는
	B번 참가자와 몇 번째 라운드에서 만나는지 찾아야한다
	
	전체 인원 n과 참가자 A의 번호 a와 참가자 B의 번호 b가
	매개변수로 주어질 때, 몇 라운드에서 A와 B가 만나는지
	반환하는 solution 함수를 구현
	
	A, B는 만나기 전까지 무조건 이긴다고 가정하고,
	n은 2의 지수 승으로 주어진다


	parameter
	8, 4, 7


	return
	3
*/

int solution(int _n, int _a, int _b)
{

	int answer = 0;

	_a--;
	_b--;

	while (_a != _b)
	{

		_a >>= 1;
		_b >>= 1;

		answer++;
	}

	return answer;
}