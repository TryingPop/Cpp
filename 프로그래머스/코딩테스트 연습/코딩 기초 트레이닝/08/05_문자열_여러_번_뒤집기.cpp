#include <string>
#include <vector>
#include <algorithm>

/*
날짜 : 2024. 2. 14
이름 : 배성훈
내용 : 문자열 여러 번 뒤집기
	문자열 my_string과 이차원 정수 배열 queries가 매개변수로 주어진다
	queries의 원소는 { s, e }의 형태로,
	my_string의 인덱스 x부터 인덱스 e까지를 뒤집으라는 의미
	my_string에 queries의 명령을 순서대로 처리한 후의 문자열을 return 하는 solution 함수 구현
*/

using namespace std;

string solution(string _my_string, vector<vector<int>> _queries)
{

	string answer = _my_string;

	for (const vector<int> query : _queries)
	{

		// reverse함수
		// answer의 시작 지점 + query[0]에서
		// answer의 query[1] + 1의 바로 앞까지 바꾼다
		reverse(answer.begin() + query[0], answer.begin() + query[1] + 1);
		/*
		int mid = (query[0] + query[1]) / 2;
		for (int i = query[0]; i <= mid; i++) 
		{

			swap(answer[i], answer[query[0] + query[1] - i]);
		}
		*/
	}

	return answer;
}