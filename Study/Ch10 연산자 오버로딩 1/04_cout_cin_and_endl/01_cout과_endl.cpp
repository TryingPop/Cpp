/*
날짜 : 2023. 2. 14
이름 : 배성훈
내용 : cout과 endl
	c++ 콘솔 입출력에 사용되는 cout과 enl의 이해를 돕기 위한 예제
*/

#include<iostream>
namespace mystd {

	using namespace std;

	class ostream {

	public:
		void operator<< (const char* str) {

			printf("%s", str);
		}

		void operator<< (char str) {

			printf("%c", str);
		}

		void operator<< (int num) {

			printf("%d", num);
		}

		void operator<< (double e) {

			printf("%g", e);
		}

		// 함수 포인터 fp
		// 반환형 *변수명 (인자)
		// 그래서 ostream의 주소를 반환
		// 포인터 변수명은 fp
		// 함수에 들어가는 인자 형태는 pstream의 주소
		void operator<< (ostream& (*fp)(ostream& ostm)) {

			fp(*this);
		}
	};

	ostream& endl(ostream& ostm) {

		ostm << '\n';
		fflush(stdout);
		return ostm;
	}

	ostream cout;
}

int main(void) {

	using mystd::cout;
	using mystd::endl;

	cout << "Simple String";
	cout << endl;
	cout << 3.14;
	cout << endl;
	cout << 123;
	endl(cout);
}