/*
날짜 : 2024. 8. 11
이름 : 배성훈
내용 : 숫자 카드 나누기
	철수와 영희는 선생님으로부터 숫자가 하나씩 적힌
	카드들을 절반씩 나눠서 가진 후,
	다음 두 조건 중 하나를 만족하는 
	가장 큰 양의 정수 a의 값을 구하려고 한다

	1. 철수가 가진 카드들에 적힌 모든 숫자를 나눌 수 있고
	영희가 가진 카드들에 적힌 모든 숫자들 중 하나도 나눌 수 없는 양의 정수 a

	2. 영희가 가진 카드들에 적힌 모든 숫자를 나눌 수 있고,
	철수가 가진 카드들에 적힌 모든 숫자들 중 하나도 나눌 수 없는 양의 정수 a

	철수가 가진 카드에 적힌 숫자들을 나타내는 정수 배열 arrayA,
	영희가 가진 카드에 적힌 숫자들을 나타내는 정수 배열 arrayB가
	주어질 때,

	주어진 조건을 만족하는 가장 큰 양의 정수 a를 
	return 하는 solution 함수를 구현
	만약 조건을 만족하는 a가 없다면 0을 return

	arrayA의 길이와 arrayB의 길이는 같으며 50만 이하의 자연수이다
	arrayA, arrayB의 원소는 1억 이하의 자연수이고 중복된 원소가 있을 수 있다

	parameter
	{ 10, 20 }, { 5, 17 }


	return
	10

	
	sol
	10은 철수 카드의 10, 20을 모두 나누는 가장 큰 수다
	반면 5, 17을 나누지 못한다

	5, 17을 나누는 수는 1밖에 없고
	10, 20은 1에 나눠 떨어지므로
	영희카드를 모두 나누며 철수카드를 나누지 않는 수는 없다
*/

#include <vector>
#include <cmath>

using namespace std;

inline int EuclidGCD(int _a, int _b)
{

	/*
	
	GCD
	*/

	while (_b)
	{

		int temp = _a % _b;
		_a = _b;
		_b = temp;
	}

	return _a;
}

inline int GetArrGCD(vector<int>& _arr)
{

	/*
	
	arr전체의 GCD
	*/

	int gcd = _arr[0];
	for (int i = 1; i < _arr.size(); i++)
	{

		gcd = EuclidGCD(gcd, _arr[i]);
		if (gcd == 1) return 1;
	}

	return gcd;
}

inline bool NotDivArr(vector<int>& _arr, int _div)
{

	/*
	
	div가 arr의 원소를 적어도 하나 나누는지 확인
	*/

	for (int num : _arr)
	{

		if (num % _div) continue;
		return false;
	}

	return true;
}

int solution(vector<int> _arrayA, vector<int> _arrayB)
{

	/*
	
	수학
	전체의 array?의 gcd는
	array?의 모든 숫자를 나눌 수 있는 가장 큰 수다

	그리고, arrayA의 gcd인 gcdA가
	arrayB의 적어도 하나의 원소를 나눈다면
	gcdA의 모든 약수들은 그 원소를 나눈다

	그래서 gcdA로 arrayB를 나누는지 확인하면 된다
	적어도 하나를 나누는 경우 a가 존재하지 않는다
	반면 모두 나누지 않으면 gcdA는 a의 후보가 된다
	arrayB도 똑같이 확인한다
	
	a의 후보가 존재하지 않는 경우 정답은 없다
	a의 후보가 존재하는 경우 가장 큰 값이 a가 된다
	*/

	int answer;

	int gcdA = GetArrGCD(_arrayA);
	int gcdB = GetArrGCD(_arrayB);

	bool chk1 = NotDivArr(_arrayB, gcdA);
	bool chk2 = NotDivArr(_arrayA, gcdB);

	if (chk1 && chk2) answer = max(gcdA, gcdB);
	else if (chk1) answer = gcdA;
	else if (chk2) answer = gcdB;
	else answer = 0;

	return answer;
}