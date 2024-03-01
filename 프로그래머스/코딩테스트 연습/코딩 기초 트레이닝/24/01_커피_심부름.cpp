#include <string>
#include <vector>

/*
날짜 : 2024. 3. 1
이름 : 배성훈
내용 : 커피 심부름
	카페에서 커피를 뜨거운거 차가운거 상관없이
	라떼만 5000원, 이외는 모두 일괄적으로 4500원에 판다

	주문하는 메뉴가 string 리스트인 order로 주어졌을 때,
	결제하게 될 금액을 출력
*/

using namespace std;

int solution(vector<string> _order) 
{

	int answer = 0;

	for (const string str : _order)
	{

		if (str.find("caffelatte") != string::npos) answer += 5000;
		else answer += 4500;
	}

	return answer;
}