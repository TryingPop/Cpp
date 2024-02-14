/*
날짜 : 2024. 2. 14
이름 : 배성훈
내용 : 간단한 논리 연산
	bool 변수 x1, x2, x3, x4가 매개변수로 주어질 때,
	(x1 or x2) and (x3 or x4)의 결과를 반환하는 함수를 구현
*/

bool solution(bool _x1, bool _x2, bool _x3, bool _x4)
{

	bool answer;
	answer = (_x1 || _x2) && (_x3 || _x4);
	return answer;
}