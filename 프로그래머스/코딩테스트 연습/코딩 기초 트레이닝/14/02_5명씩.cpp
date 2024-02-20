#include <vector>
#include <string>
#define GROUP 5

/*
날짜 : 2024. 2. 20
이름 : 배성훈
내용 : 5명씩
	최대 5명씩 탑승 가능한 놀이기구를 타기 위해 줄을 서있는 
	사람들의 이름이 담긴 문자열 리스트 names가 주어질 때,
	앞에서부터 5명씩 묶은 그룹의 가장 앞에 서있는 사람들의 이름을 담은 리스트를
	return 하는 solution 함수 구현
	마지막 그룹이 5명이 되지 않더라도 가장 앞에 있는 사람의 이름을 포함
*/
using namespace std;

vector<string> solution(vector<string> _names)
{

	vector<string> answer;

	for (int i = 0; i < _names.size(); i += GROUP)
	{

		answer.push_back(_names[i]);
	}
	return answer;
}