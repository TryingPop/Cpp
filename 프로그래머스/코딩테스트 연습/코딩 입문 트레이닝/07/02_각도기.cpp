/*
날짜 : 2024. 3. 10
이름 : 배성훈
내용 : 각도기
	각에서 0 초과 90 미만은 예각
	90도는 직각
	90 초과 180 미만은 둔각
	180도는 평각

	각 0 초과 180이하인 정수 angle이 매개변수로 주어질 때
	예각 1, 직각 2, 둔각 3, 평각 4를
	return 하는 solution 함수 구현
*/

int solution(int _angle)
{

	int answer;

	if (_angle < 90) answer = 1;
	else if (_angle == 90) answer = 2;
	else if (_angle < 180) answer = 3;
	else answer = 4;

	return answer;
}