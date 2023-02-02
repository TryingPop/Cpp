/*
날짜 : 2023. 2. 2
이름 : 배성훈
내용 : C에서 static 키워드
	전역변수에 선언된 static : 선언된 파일 내에서만 참조를 허용
	함수 내에 선언된 static : 하넌만 초기화되고, 지역변수와 달리 함수를 빠져나가도 소멸되지 않는다
*/

#include <iostream>
using namespace std;

void Counter() {

	static int cnt;
	cnt++;
	cout << "Current cnd: " << cnt << endl;
}

int main(void) 
{

	for (int i = 0; i < 10; i++) {

		Counter();
	}
	
	return 0;
}