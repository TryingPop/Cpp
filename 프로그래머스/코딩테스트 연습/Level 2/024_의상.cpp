/*
날짜 : 2024. 7. 2
이름 : 배성훈
내용 : 의상
	의상들이 담긴 2차원 배열 clothes가 매개변수로 주어진다
	clothes는 의상의 이름, 의상의 종류로 이뤄져 있고
	의상의 종류는 최대 1가지 의상만 착용할 수 있다

	착용한 의사의 일부가 겹치더라도 다른 의상이 겹치지 않거나,
	혹은 의상을 추가로 더 착용한 경우에는 서로 다른 방법으로 옷을 착용한 것으로 본다

	그리고 최소 1개의 의상을 입어야 한다
	서로 다른 옷의 조합의 수를 return 하는 solution 함수 구현

	같은 이름의 가진 의상은 존재하지 않는다
	모든 문자열은 알파벳 소문자 또는 언더 바(_)로만 이뤄져 있다


	parameter
	{ { "yellow_hat", "headgear" }, 
	  { "blue_sunglasses", "eyewear" }, 
	  { "green_turban", "headgear" } }


	return
	5


	sol
	yellow_hat
	blue_sunglasses
	green_turban
	yellow_hat + blue_sunglasses
	green_turban + blue_sunglasses

	총 5가지가 존재한다
*/

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> _clothes)
{

	int answer = 0;

	unordered_map<string, int> cnt;
	for (vector<string>& vec : _clothes)
	{

		if (cnt.count(vec[1])) cnt[vec[1]]++;
		else cnt[vec[1]] = 2;
	}

	answer = 1;
	for (pair<string, int> element : cnt)
	{

		answer *= element.second;
	}

	answer--;

	return answer;
}