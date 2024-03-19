#include <string>

/*
날짜 : 2024. 3. 19
이름 : 배성훈
내용 : 숫자 찾기
	정수 num과 k가 매개변수로 주어질 때,
	num을 이루는 숫자 중에 k가 있으면,
	num의 그 숫자가 있는 자리수를
	return 하고 없으면 -1을 return 하는 solution 함수 구현
*/

using namespace std;

int solution(int _num, int _k) 
{

	int answer = -1;

	string numStr = to_string(_num);
	char find = _k + '0';

	for (int i = 0; i < numStr.length(); i++)
	{

		if (numStr[i] != find) continue;

		answer = i + 1;
		break;
	}

	return answer;
}