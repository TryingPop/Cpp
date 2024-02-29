#include <vector>

/*
날짜 : 2024. 2. 29
이름 : 배성훈
내용 : 날짜 비교하기
	정수 배열 date1, date2가 주어진다
	date는 { yyyy, mm, dd }로 이루어져 있다
	여기서 yyyy는 년도, mm은 월, dd는 일을 의미한다

	date1이 date2보다 앞서는 날짜라면 1을
	아니면 0을 return하는 solution 함수를 구현
*/

using namespace std;
int solution(vector<int> _date1, vector<int> _date2) 
{

	int answer = 0;

	for (int i = 0; i < 3; i++) 
	{

		if (_date1[i] != _date2[i])
		{

			answer = _date1[i] < _date2[i];
			break;
		}
	}

	return answer;
}