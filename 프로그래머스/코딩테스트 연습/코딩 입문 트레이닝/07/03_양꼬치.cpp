#include <algorithm>
#define 양꼬치 12'000
#define 음료 2'000

/*
날짜 : 2024. 3. 10
이름 : 배성훈
내용 : 양꼬치
	양꼬치 1인분에 12,000원,
	음료는 1개에 2,000원

	양꼬치 10인분에 음료 1개 공짜

	정수 n과 k가 매개변수로 주어질 때,
	n은 양꼬치, k는 음료를 먹었다는 의미이다
	이때 지불해야하는 총 금액을 return 하는 solution 함수 구현
*/

using namespace std;

int solution(int _n, int _k)
{

	int answer;

	answer = 양꼬치 * _n;
	// 음료 할인은 음이 아닐 때까지만 하는게 일반적이지 않나 싶다?
	// 다만 여기서는 max 없어도 이상없다
	answer += 음료 * max((_k - (_n / 10)), 0);

	return answer;
}