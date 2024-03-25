#include <string>
#include <vector>

/*
날짜 : 2024. 3. 26
이름 : 배성훈
내용 : 로그인 성공?
	아이디와 패스워드가 담긴 배열 id_pw와
	회원들의 정보가 담긴 2차원 배열 db가 주어질 때,

	아이디와 비밀번호 모두 일치하는 회원 정보가 있을 때
	login을 return

	로그인이 실패 했을 때 아이디가 일치하는 회원이 없다면
	fail, 아이디는 일치하지만 비밀번호가 일치하는 회원이 없다면
	wrong pw를 return 하는 solution 함수 구현

	db에서 id는 중복되지 않는다
*/

using namespace std;

int comp(string& _str1, string& _str2)
{

	if (_str1.length() != _str2.length()) return 0;
	
	for (int i = 0; i < _str1.length(); i++)
	{

		if (_str1[i] != _str2[i]) return 0;
	}

	return 1;
}

string solution(vector<string> _id_pw, vector<vector<string>> _db)
{

	string answer;

	int id = 0;
	int pw = 0;

	for (vector<string> user : _db)
	{

		if (!comp(user[0], _id_pw[0])) continue;
		id = 1;
		if (comp(user[1], _id_pw[1])) pw = 1;
		break;
	}

	if (id & pw) answer = "login";
	else if (id) answer = "wrong pw";
	else answer = "fail";

	return answer;
}