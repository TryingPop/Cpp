#include <vector>

/*
날짜 : 2024. 3. 7
이름 : 배성훈
내용 : 분수의 덧셈
	첫 번째 분수의 분자와 분모를 뜻하는 numer1, denom1
	두 번째 분수의 분자와 분모를 뜻하는 numer2, denom2
	가 정수 형태의 매개변수로 주어진다

	두 분수를 더한 값을 기약 분수로 나타냈을 때
	분자와 분모를 순서대로 담은 배열을
	return하는 solution 함수 구현
*/

using namespace std;

int getgcd(int _a, int _b)
{

	// Euclid division algorithm으로 gcd를 찾는다
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

vector<int> solution(int _numer1, int _denom1, int _numer2, int _denom2)
{

	vector<int> answer;
	answer.reserve(2);

	// a / b + c / d = ad / bd + cb / bd
	int numer = _denom2 * _numer1 + _denom1 * _numer2;
	int denom = _denom1 * _denom2;

	// 합의 결과가 기약분수가 아닐 수도 있다
	// 1 / 6 + 1 / 6 = 2 / 6
	// 그래서 최대 공약수를 찾아 나눈다
	int gcd = getgcd(numer, denom);

	// 최대공약수로 나누면 기약분수
	numer /= gcd;
	denom /= gcd;

	answer.push_back(numer);
	answer.push_back(denom);

	return answer;
}