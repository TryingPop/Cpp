#include <iostream>
using namespace std; // std 이름 공간의 메소드를 간단하게 불러오기 위해 선언

/*
날짜 : 2023. 1. 22
이름 : 배성훈
내용 : usingDcl
	네임스페이스안의 모든 함수와 변수를 간단하게 명명
*/

namespace Hybrid {

	void HybFunc(void) {

		cout << "So simple function!" << endl;
		cout << "In namespace Hybrid" << endl;
	}
}
/*
void HybFunc(void) {

	cout << "no namespace Hybrid" << endl;
}
*/

int main()
{

	using namespace Hybrid;	// Hybrid namespace의 함수들을 Hybrid::함수명(변수명) 이 아닌 함수명(변수명)으로 함수호출 가능하게 해준다 
							// no namespace Hybrid 주석이 없는 경우 모호하다는 에러가 뜬다

	HybFunc();				// In namespace Hybrid 출력
	return 0;
}
