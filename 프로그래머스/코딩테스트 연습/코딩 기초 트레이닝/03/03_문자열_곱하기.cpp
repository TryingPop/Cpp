#include <string>
#include <vector>

/*
날짜 : 2024. 2. 9
이름 : 배성훈
내용 : 문자열 곱하기
	문자열 my_string과 정수 k가 주어질 때,
	my_string을 k번 반복하는 문자열을 return하게 하는 solution 함수 작성

	my_string의 길이는 100이하고, 알파벳 소문자로 이루어진 문자열
	k는 100이하의 자연수

	input
	aaa 5

	answer
	aaaaaaaaaaaaaaa
*/

using namespace std;

string solution(string my_string, int k)
{

	string answer = "";
	//	int size = my_string.size() * k;
	//	answer.reserve(size);
	answer.reserve(my_string.size() * k);

	for (int i = 0; i < k; i++)
	{

		answer.append(my_string);
	}

	return answer;
}