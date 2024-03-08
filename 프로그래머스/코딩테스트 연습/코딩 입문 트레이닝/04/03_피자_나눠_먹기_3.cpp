/*
날짜 : 2024. 3. 8
이름 : 배성훈
내용 : 피자 나눠 먹기 3
	피자를 2 조각에서 10조각까지 원하는 조각 수로 자른다
	피자 조각 수 slice와 먹는 사람의 수 n이 
	매개변수로 주어질 때,
	n명의 사람이 최소 1 조각 이상의 피자를 먹으려면
	최소 몇 판을 주문해야하는지를 return하는 solution 함수 구현
*/

int solution(int _slice, int _n)
{

	int answer = 1 + (_n - 1) / _slice;
	return answer;
}