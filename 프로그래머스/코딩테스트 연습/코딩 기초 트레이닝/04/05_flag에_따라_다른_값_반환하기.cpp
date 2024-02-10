/*
날짜 : 2024. 2. 10
이름 : 배성훈
내용 : flag에 따라 다른 값 반환하기
	두 정수 a, b와 bool 변수 flag가 매개변수로 주어질 때,
	flag가 true면 a + b를, false면 a - b를 반환하는 함수 만들기
*/

int solution(int _a, int _b, bool _flag)
{

	int answer = 0;

	answer = _flag ? _a + _b : _a - _b;
	return answer;
}