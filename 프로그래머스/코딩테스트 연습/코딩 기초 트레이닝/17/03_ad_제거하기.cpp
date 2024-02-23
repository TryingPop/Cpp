#include <vector>
#include <string>

/*
날짜 : 2024. 2. 23
이름 : 배성훈
내용 : ad 제거하기
	문자열 배열 strArr이 주어진다
	배열 내의 문자열 중 ad라는 부분 문자열을 포함하고 있는
	모든 문자열을 제거하고 남은 문자열을 순서대로 유지하여
	배열로 return하는 solution 함수를 구현
*/

using namespace std;

vector<string> solution(vector<string> _strArr)
{

	vector<string> answer;

	for (const string s : _strArr)
	{

		int chk = s.find("ad");
		if (chk == string::npos) answer.push_back(s);
	}

	return answer;
}