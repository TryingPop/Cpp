#include<string>
#include<vector>
#include<algorithm>

/*
날짜 : 2024. 2. 22
이름 : 배성훈
내용 : 배열에서 문자열 대소문자 변환하기
	문자열 배열 strArr이 주어진다
	모든 원소가 알파벳으로만 이루어져 있을 때,
	배열에서 홀수번째 인덱스의 문자열은 모든 문자를 대문자로,
	짝수번째 인덱스의 문자열은 모든 문자를 소문자로 바꿔서 변환하는
	solution 함수를 완성
*/

using namespace std;

vector<string> solution(vector<string> _strArr)
{

	vector<string> answer;

	for (int i = 0; i < _strArr.size(); i++) 
	{

		string temp = _strArr[i];

		if (i & 1) transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
		else transform(temp.begin(), temp.end(), temp.begin(), ::tolower);

		answer.push_back(temp);
	}
	return answer;
}