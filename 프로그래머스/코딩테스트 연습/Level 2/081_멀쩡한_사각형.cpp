/*
날짜 : 2024. 8. 25
이름 : 배성훈
내용 : 멀쩡한 사각형
	가로 길이 w, 세로 길이 h인 직사각형 종이가 있다
	종이에는 가로, 세로 방향과 평행하게 격자 형태로 선이 그어져 있다
	모든 격자칸 크기는 1 x 1 크기이다

	이 종이를 격자 선을 따라 1 x 1 의 정사각형으로 잘라	사용할 예정이었는데, 
	누군가가 이 종이를 대각선 꼭지점 2개를 잇는 방향으로 잘랐다

	현재 직사각형 종이는 크기가 같은 직각 삼각형 2개로 나누어진 상태다
	새로운 종이를 구할 수 없기에
	이 종이에서 원래 종이의 가로, 세로 방향과 평행하게 
	1 x 1로 잘라 사용할 수 있는 만큼만 사용하기로 했다

	가로의 길이 w, 세로의 길이 h가 주어질 때,
	사용할 수 잇는 정사각형의 개수를 구하는
	solution 함수 구현

	w, h 는 1억 이하의 자연수


	parameter
	2, 3


	return
	2


	sol
	종이를 보면
		1	1
		1	1
		1	1

	이고 잘린 부분을 0으로 표현하면 다음과 같다
		0	1
		0	0
		1	0
	그래서 정답은 2이다
*/

#define ll long long

using namespace std;

inline int GetGCD(int _a, int _b)
{

	/*
	
	유클리드 호제법으로 gcd를 찾는다
	*/
	while (_b)
	{

		int temp = _a % _b;
		_a = _b;
		_b = temp;
	}

	return _a;
}

inline int Sub(int _a, int _b)
{

	/*
	
	사용 못하는 부분을 찾는다
	w, h의 gcd 만큼 모양이 반복해서 나타난다
	
	나눠진 구간에 한해 y가 증가하는 구간을 기준으로 보면
	증가하는 x 값이 정수이면 1칸 쓰고,
	아니면 2칸을 쓴다
	이는 y의 증가 개수만큼 칸을 쓴다

	그래서 못쓰는 구간은 나눠진 구간의 w를 x, h를 y라 하면
	x + y - 1개이다
	*/
	if (_a < _b)
	{

		int temp = _a;
		_a = _b;
		_b = temp;
	}

	int gcd = GetGCD(_a, _b);
	_a /= gcd;
	_b /= gcd;

	int ret = _a + _b - 1;
	return ret * gcd;
}

ll solution(int _w, int _h)
{

	/*
	
	수학 문제
	*/
	ll answer = 1LL * _w * _h;
	answer -= Sub(_w, _h);
	return answer;
}