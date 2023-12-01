#include <iostream>
using namespace std; // std 이름 공간의 메소드를 간단하게 불러오기 위해 선언

/*
날짜 : 2023. 1. 22
이름 : 배성훈
내용 : usingDcl
	네임스페이스 공간의 함수를 간단하게 명명
*/

namespace Hybrid {

	void HybFunc(void) {

		cout << "So simple function!" << endl;
		cout << "In namespace Hybrid" << endl;
	}
}

void HybFunc(void) {

	cout << "no namespace Hybrid" << endl;
}


int main()
{

	HybFunc();				// no namespace Hybrid 출력
	using Hybrid::HybFunc;	// Hybrid namespace의 HybFunc를 HybFunc로 호출하기 위해 선언
	HybFunc();				// In namespace Hybrid 출력
	return 0;
}

