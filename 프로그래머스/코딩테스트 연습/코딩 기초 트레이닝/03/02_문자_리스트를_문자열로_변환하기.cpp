#include <iostream>
#include <string>
#include <vector>

/*
날짜 : 2024. 2. 9
이름 : 배성훈
내용 : 문자 리스트를 문자열로 변환하기
	arr의 원소는 알파벳 소문자로이 이루어진 길이가 1인 문자열이다
	arr의 원소들을 순서대로 이어 붙인 문자열을 return하는 solution 함수제작하기

	input
	arr = { "a", "b", "c" };
	
	answer
	abc

	string에 push_back을 쓸 수 있는 매개변수는 char형이고,
	string을 넣으려면 append를 써야한다
*/

using namespace std;

string solution(vector<string> _arr)
{

	string answer = "";
	answer.reserve(_arr.size());

	for (string c : _arr) 
	{

		// answer.push_back(c[0]);
		answer.append(c);
	}

	return answer;
}