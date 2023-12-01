/*
날짜 : 2023. 2. 7
이름 : 배성훈
내용 : 교재 312p 문제1
	정사각형을 의미하는 Square 클래스와 직사각형을 의미하는 Rectangle 클래스를 정의하고자 한다
	class Rectangle {
		...
	};
	class Square : public Rectangle {
		...
	};
	이에 다음 main 함수와 함께 실행이 가능하도록 위의 클래스를 완성해보자.
	참고로 상속을 한다고해서 유도 클래스에 무엇인가를 많이 담아야 한다는 생각을 버리자!
	[main 함수]
	int main(void)
	{
		Rectangle rec(4, 3);
		rec.ShowAreaInfo();
		Square sqr(7);
		sqr.ShowAreaInfo();
		return 0;
	};
	[실행의 예]
	면적 : 12
	면적 : 49
*/

#include <iostream>
using namespace std;

class Rectangle {

private:
	int width;
	int height;

public:
	Rectangle(int wid, int hei)
		: width(wid), height(hei) { }

	void ShowAreaInfo() {

		cout << "면적: " << width * height << endl;
	}
};

class Square : public Rectangle {

public:
	Square(int side)
		: Rectangle(side, side) { }
};

int main(void)
{

	Rectangle rec(4, 3);
	rec.ShowAreaInfo();

	Square sqr(7);
	sqr.ShowAreaInfo();
	return 0;
}