#include <vector>
#define AMERICANO 5'500

/*
날짜 : 2024. 3. 9
이름 : 배성훈
내용 : 아이스 아메리카노
	아이스 아메리카노는 한 잔에 5,500원

	머쓱이가 가지고 있는 돈 money가 정수로 주어질 때,
	머쓱이가 최대로 마실 수 잇는 아메리카노의 잔 수와
	남은 돈을 순서대로 담은 배열을
	return 하는 solution 함수 구현
*/

using namespace std;

vector<int> solution(int _money)
{

	vector<int> answer;
	answer.reserve(2);

	// 아메리카노 수, 남은 돈
	answer.push_back(_money / AMERICANO);
	answer.push_back(_money % AMERICANO);

	return answer;
}