/*
날짜 : 2023. 2. 14
이름 : 배성훈
내용 : cout과 endl
	앞에서는 
		cout << 1 << 'a' << endl;
	같은 문장은 사용 불가능했다 이를 사용 가능하게 보완
*/

#include <iostream>

namespace mystd {

	using namespace std;

	class ostream {

	public:
		ostream& operator<<(char* str) {

			printf("%s", str);
			return *this;
		}

		ostream& operator<<(char str) {

			printf("%c", str);
			return *this;
		}

		ostream& operator<<(int num) {

			printf("%d", num);
			return *this;
		}

		ostream& operator<<(double e) {

			printf("%g", e);
			return *this;
		}

		ostream& operator<< (ostream& (*fp)(ostream& ostm)) {

			return fp(*this);
		}
	};

	ostream& endl(ostream& ostm) {

		ostm << '\n';
		fflush(stdout);
		return ostm;
	}

	ostream cout;
}

int main(void)
{

	using mystd::cout;
	using mystd::endl;
	cout << 3.14 << endl << 123 << endl;
	return 0;
}