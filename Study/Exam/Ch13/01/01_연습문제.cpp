/*
날짜 : 2023. 2. 22
이름 : 배성훈
내용 : 교재 535p 문제1
	인자로 전달되는 두 변수에 저장된 값을 서로 교환하는 SwapData라는 이름의 함수를 템플릿으로 정의해보자.
	그리고 다음 Point 클래스를 대상으로 값의 교환이 이뤄짐을 확인할 수 있도록 main 함수를 구성해보자.

	class Point {

	private:
		int xpos, ypos;

	public:
		Point(int x = 0, int y = 0) 
			: xpos(x), ypos(y) { }

		void ShowPosition() const {
			
			cout << '[' << xpos << ", " << ypos << ']' << endl;
		}
	};
*/

#include <iostream>

using namespace std;

class Point {

private:
	int xpos, ypos;

public:
	Point(int x = 0, int y = 0)
		: xpos(x), ypos(y) { }

	void ShowPosition() const {

		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
};

template <typename T>
void SwapData(T& a, T& b) {

	T temp = a;
	a = b;
	b = temp;
}

int main(void)
{

	Point pos1(3, 4);
	Point pos2(5, 6);

	SwapData(pos1, pos2);

	pos1.ShowPosition();	// [5, 6]
	pos2.ShowPosition();	// [3, 4]
	return 0;
}