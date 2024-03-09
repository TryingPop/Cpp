#define PRICE_1 100'000
#define PRICE_2 300'000
#define PRICE_3 500'000

#define SALE_1 95 / 100
#define SALE_2 9 / 10
#define SALE_3 4 / 5

/*
날짜 : 2024. 3. 9
이름 : 배성훈
내용 : 옷가게 할인 받기
	10만원 이상 사면 5%,
	30만원 이상 사면 10%,
	50만원 이상 사면 20%를 할인

	구매한 옷의 가격 price가 정수로 주어질 때,
	지불해야할 금액을 return하는 solution 함수 구현
*/

int solution(int _price)
{

	int answer;

	// 세일 적용 가능한지 확인하고 세일가 적용 시킨다
	if (_price < PRICE_1) answer = _price;
	else if (_price < PRICE_2) answer = _price * SALE_1;
	else if (_price < PRICE_3) answer = _price * SALE_2;
	else answer = _price * SALE_3;

	return answer;
}