/*
날짜 : 2023. 12. 09
이름 : 배성훈
내용 : 복사생성자
	교재 45 ~ 46p
*/

class Widget {

public:

	Widget();								// 기본 생성자
	Widget(const Widget& rhs);				// 복사 생성자
											// rhs의 내용물을 바꾸지 않겠다고 명시적으로 const 선언

	Widget& operator=(const Widget& rhs);	// 복사 대입 연산자
};

Widget w1;									// 기본 생성자 호출
Widget w2(w1);								// 복사 생성자 호출

bool hasAcceptableQuality(Widget w);

void main() {

	w1 = w2;								// 복사 대입 연산자 호출
	Widget w3 = w1;							// 복사 생성자 호출

	Widget aWidget;

	// aWidget은 w로 복사된다 
	// 이 때 수행되는 복사에 Widget의 복사 생성자가 쓰인다
	// 사용자 정의 타입을 값으로 넘기는 발상은 일반적으로 좋지 않다 그보다는 상수 객체에 대한 참조로 넘기기가 더 좋다
	if (hasAcceptableQuality(aWidget)) {	// 복사 생성자 호출

		// ...
	}
}