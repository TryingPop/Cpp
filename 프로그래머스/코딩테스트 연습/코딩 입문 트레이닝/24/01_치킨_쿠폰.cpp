/*
날짜 : 2024. 3. 28
이름 : 배성훈
내용 : 치킨 쿠폰
	치킨을 시켜먹으면 한 마리당 쿠폰 1개씩 준다
	쿠폰을 10장 모으면 치킨 1마리를 서비스로 받을 수 있고,
	서비스 치킨에도 쿠폰을 준다

	시켜먹은 치킨의 수 chicken이 매개변수로 주어질 때,
	받을 수 있는 최대 서비스 치킨의 수를
	return 하도록 solution 함수 구현
*/

int solution(int _chicken)
{

	int answer = 0;

	while (_chicken > 0)
	{

		int temp = _chicken / 10;
		answer += temp;
		_chicken = _chicken % 10 + temp;
	}

	return answer;
}