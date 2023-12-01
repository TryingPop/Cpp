/*
날짜 : 2023. 2. 3
이름 : 배성훈
내용 : const static 멤버
	const 멤버변수는 이니셜라이저를 통해 초기화 가능
	const static 멤버변수는 선언과 동시에 초기화 가능
*/

#include <iostream>
using namespace std;

class CountryArea {

public:
	const static int RUSSIA = 1707540;
	const static int CANADA = 998467;
	const static int CHINA = 957290;
	const static int SOUTH_KOREA = 9922
};

int main(void)
{

	cout << "러시아 면적: " << CountryArea::RUSSIA << "km" << endl;
	cout << "캐나다 면적: " << CountryArea::CANADA << "km" << endl;
	cout << "중국 면적: " << CountryArea::CHINA << "km" << endl;
	cout << "한국 면적: " << CountryArea::SOUTH_KOREA << "km" << endl;
	return 0;
}