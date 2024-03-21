#include <string>
#include <vector>

/*
날짜 : 2024. 3. 21
이름 : 배성훈
내용 : 잘라서 배열로 저장하기
	문자열 my_str과 n이 매개변수로 주어질 때,
	my_str을 길이 n씩 잘라서 저장한 배열을
	return 하도록 solution 함수를 구현
*/

using namespace std;

vector<string> solution(string _my_str, int _n)
{

	vector<string> answer;

	int len = _my_str.length() / _n;
	if (_my_str.length() % _n) len++;
	answer.reserve(len);

	string temp;
	temp.reserve(_n);

	for (const char c : _my_str) 
	{

		temp.push_back(c);
		if (temp.length() != _n) continue;

		answer.push_back(temp);
		temp.clear();
	}

	if (!temp.empty()) answer.push_back(temp);
	return answer;
}