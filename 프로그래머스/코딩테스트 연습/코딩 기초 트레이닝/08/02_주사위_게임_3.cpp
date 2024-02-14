/*
날짜 : 2024. 2. 14
이름 : 배성훈
내용 : 주사위 게임 3
	1 ~ 6까지 적힌 주사위 4개가 있다
	네 개의 주사위에서 나온 숫자가 모두 p로 같다면 1111 * p의 점
	세 주사위에서 나온 숫자가 p로 같고 나머지 다른 주사위에서 나온 숫자가 q(!= p)라면, (10 * p + q)^2점
	주사위가 두 개씩 같은 값이 나오고, 나온 숫자를 각각 p, q라고 한다면 (p + q) * |p - q| (|a|는 a의 절대값)점
	어느 두 주사위에서 나온 숫자가 p로 같고 나머지 두 주사위에서 나온 숫자가 각각 p와 다른 q, r(!= q) 이라면 q * r점
	네 주사위에서 적힌 숫자가 모두 다르다면 나온 숫자 중 가장 작은 숫자 만큼의 점수를 얻는다

	주사위 4개를 굴렸을 때, 위 규칙을 따르는 점수를 반환하는 함수 만들기
*/

int solution(int _a, int _b, int _c, int _d)
{

	int answer;
	int chk[7] = { 0, 0, 0, 0, 0, 0, 0 };		// C++11부터 지원
	
	chk[_a]++;
	chk[_b]++;
	chk[_c]++;
	chk[_d]++;

	if (chk[_a] == 4) answer *= _a * 1111;
	else if (chk[_a] == 3)
	{

		int q = chk[_a] == chk[_b] ?
			(chk[_a] == chk[_c] ? _d : _c) : _b;

		answer = (10 * _a + q);
		answer *= answer;
	}
	else if (chk[_a] == 1 && chk[_b] == 3)
	{

		answer = (10 * _b + _a);
		answer *= answer;
	}
	else if (chk[_a] == 2 && chk[_b] == 2 && chk[_c] == 2)
	{

		if (_a == _b)
		{

			answer = _a - _c;
			answer *= _a + _c;
		}
		else
		{

			answer = _a - _b;
			answer *= _a + _b;
		}

		answer = answer < 0 ? -answer : answer;
	}
	else if (chk[_a] == 2)
	{

		if (_a == _b) answer = _c * _d;
		else if (_a == _c) answer = _b * _d;
		else answer = _b * _c;
	}
	else if (chk[_b] == 2)
	{

		if (_b == _c) answer = _a * _d;
		else answer = _a * _c;
	}
	else if (chk[_c] == 2) answer = _a * _b;
	else 
	{

		int min = _a;
		min = _b < min ? _b : min;
		min = _c < min ? _c : min;
		min = _d < min ? _d : min;

		answer = min;
	}
	return answer;
}