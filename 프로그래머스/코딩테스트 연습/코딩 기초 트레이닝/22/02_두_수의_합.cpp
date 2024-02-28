#include <string>
#include <vector>

/*
날짜 : 2024. 2. 28
이름 : 배성훈
내용 : 두 수의 합
	0 이상의 두 정수가 문자열 a, b로 주어질 때,
	a + b의 값을 문자열로 
	return하는 solution 함수를 구현

	a, b의 길이는 10만까지 될 수 있다
	a, b는 숫자로만 이루어져 있고
	앞에 0으로 시작하는 경우는 0뿐이다
*/

using namespace std;

string solution(string _a, string _b)
{

	string answer;

	string min = _a.length() < _b.length() ? _a : _b;
	string max = _a.length() < _b.length() ? _b : _a;

	int lenMin = min.length();
	int lenMax = max.length();

	answer.reserve(lenMax + 1);

	int lenR = lenMax - lenMin;

	for (int i = 0; i < lenR; i++)
	{

		// 앞부분 그냥 채운다
		answer.push_back(max[i]);
	}

	for (int i = 0; i < lenMin; i++)
	{

		// 뒷자리 더하기 연산
		int calc = min[i] + max[i + lenR] - '0';
		answer.push_back(calc);
	}

	for (int i = lenMax - 1; i > 0; i--)
	{

		// 해당 위치의 값이 10 이상인거 변형
		if (answer[i] > '9') 
		{ 

			answer[i] -= 10; 
			answer[i - 1] += 1;
		}
	}

	// 맨 앞자리 자리수 늘려야 하는지 확인
	if (answer[0] > '9')
	{

		answer[0] -= 10;
		answer.insert(answer.begin(), '1');
	}

	return answer;
}