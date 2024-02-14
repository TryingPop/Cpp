#include <vector>
#include <string>

/*
날짜 : 2024. 2. 14
이름 : 배성훈
내용 : 글자 이어 붙여 문자열 만들기
	문자열 my_string과 정수 배열 index_list가 주어진다
	my_string의 index_list의 원소들에 해당하는 인덱스의 글자들을 
	순서대로 이어 붙인 문자열을 return 하는 solution 함수 작성하기
*/

using namespace std;

string soluion(string _my_string, vector<int> _index_list)
{

	string answer;

	answer.reserve(_index_list.size());

	for (const int idx : _index_list)
	{

		answer.push_back(_my_string[idx]);
	}

	return answer;
}