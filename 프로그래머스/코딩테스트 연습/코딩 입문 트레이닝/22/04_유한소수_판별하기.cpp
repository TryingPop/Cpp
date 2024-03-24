/*
날짜 : 2024. 3. 24
이름 : 배성훈
내용 : 유한소수 판별하기
	두 정수 a와 b가 매개변수로 주어질 때,
	a / b가 유한 소수이면 1을 무한 소수라면 2를
	return 하는 solution함수를 구현
*/

int getgcd(int _a, int _b)
{

	if (_a < _b)
	{

		int temp = _a;
		_a = _b;
		_b = temp;
	}

	while (_b)
	{

		int temp = _a % _b;
		_a = _b;
		_b = temp;
	}

	return _a;
}

int mydiv(int _a, int _q)
{

	// 해당 소수로 안나눠 떨어질 때까지 나눈다
	while (!(_a % _q)) 
	{

		_a /= _q;
	}

	return _a;
}

int solution(int _a, int _b)
{

	int answer;

	int gcd = getgcd(_a, _b);
	_b /= gcd;

	_b = mydiv(_b, 2);
	_b = mydiv(_b, 5);

	// 2, 5 이외의 약수가 존재
	answer == _b == 1 ? 1 : 2;
	return answer;
}