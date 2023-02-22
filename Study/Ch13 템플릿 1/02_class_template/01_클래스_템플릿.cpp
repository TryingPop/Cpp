/*
날짜 : 2023. 2. 22
이름 : 배성훈
내용 : 클래스 템플릿
	템플릿을 기반으로 객체 생성
	
	함수 템플릿과 달리 변수 선언할 때 클래스명<자료형> 변수명
	부분에서 <자료형> 생략이 불가능하다
*/

#include <iostream>
using namespace std;

template <typename T>
class Point {

private:
	T xpos, ypos;

public:
	Point(T x = 0, T y = 0)
		: xpos(x), ypos(y) { }

	void ShowPosition() const {

		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
};

int main(void)
{

	Point<int> pos1(3, 4);			
	pos1.ShowPosition();			// [3, 4]

	Point<double> pos2(2.4, 3.6);
	pos2.ShowPosition();			// [2.4, 3.6]

	Point<char> pos3('P', 'F');		// 좌표정보를 문자로 표시하는 상황의 표현
	pos3.ShowPosition();			// [P, F]
	return 0;
}