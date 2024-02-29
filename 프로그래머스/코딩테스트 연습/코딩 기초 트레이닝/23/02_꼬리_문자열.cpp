#include <string>
#include <vector>

/*
날짜 : 2024. 2. 29
이름 : 배성훈
내용 : 꼬리 문자열
	문자열 리스트 str_list와 
	제외하려는 문자열 ex가 주어진다
	
	str_list에서 ex를 포함한 문자열을 제외하고 
	만든 꼬리 문자열을 return하는 solution 함수를 구현

	여기서 말하는 list의 꼬리 문자열은
	list의 원소를 이어 붙인 문자열을 의미한다
	list = { str1, str2 }라면,
	꼬리문자열은 str1.append(str2) 한 것이다
*/

using namespace std;

string solution(vector<string> _str_list, string _ex)
{

	string answer = "";

	for (const string str : _str_list)
	{

		// ex를 포함하면 이어붙이지 않는다
		if (str.find(_ex) != string::npos) continue;

		answer.append(str);
	}

	return answer;
}