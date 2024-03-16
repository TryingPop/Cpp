#include <string>

/*
날짜 : 2024. 3. 16
이름 : 배성훈
내용 : 369게임
	1부터 숫자를 하나씩 대며
	숫자에 3, 6, 9가 들어가는 숫자의 경우
	3, 6, 9의 개수만큼 박수를 치는 게임

	숫자 order가 매개변수로 주어질 때,
	쳐야할 박수의 횟수를 return하는 solution 함수 구현
*/

using namespace std;

int solution(int _order)
{

	int answer = 0;

	string strOrder = to_string(_order);
	for (const char c : strOrder)
	{

		if (c == '3' || c == '6' || c == '9') answer++;
	}

	return answer;
}