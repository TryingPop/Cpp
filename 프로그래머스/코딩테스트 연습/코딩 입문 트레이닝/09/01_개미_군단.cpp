/*
날짜 : 2024. 3. 11
이름 : 배성훈
내용 : 개미 군단
	장군 개미는 5의 공격력을,
	병정 개미는 3의 공격력을,
	일 개미는 1의 공격력을 갖는다

	사냥감의 체력 hp가 매개변수로 주어질 때,
	사냥감의 체력에 딱 맞게 최소한의 병력을 구성하려면
	몇 마리의 개미가 필요한지 return 하는 solution 함수 구현
*/

int solution(int _hp)
{

	int answer;

	// 그리디 알고리즘 적용
	answer = _hp / 5;
	_hp %= 5;
	answer += _hp / 3;
	_hp %= 3;
	answer += _hp;

	return answer;
}