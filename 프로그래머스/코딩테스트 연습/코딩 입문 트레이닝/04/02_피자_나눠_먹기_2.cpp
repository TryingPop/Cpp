/*
날짜 : 2024. 3. 8
이름 : 배성훈
내용 : 피자 나눠 먹기 2
	피자를 6조각으로 자른다
	피자를 나눠 먹을 사람의 수 n이 매개변수로 주어진다
	n명이 주문한 피자를 남기지 않고
	모두 같은 수의 피자 조각을 먹을 때,
	주문해야하는 최소 피자 판수를 return하는 solution 함수 구현
*/

int getgcd(int _a, int _b)
{

	if (_a < _b) 
	{

		int temp = _a;
		_a = _b;
		_b = temp;
	}

	while (_b > 0)
	{

		int temp = _a % _b;
		_a = _b;
		_b = temp;
	}

	return _a;
}

int solution(int _n)
{

	int answer;

	// 6과의 최대 공약수로 나누면 이상없다
	int gcd = getgcd(_n, 6);
	answer = _n / gcd;

	return answer;
}