#include <iostream>
using namespace std; // std 이름 공간의 메소드를 간단하게 불러오기 위해 선언

/*
날짜 : 2023. 1. 22
이름 : 배성훈
내용 : 이름공간
	동일한 이름 공간에서는 이름공간 명시가 필요없다
	그리고 이름 공간 안에 이름 공간을 정의할 수 있다
*/

namespace BestComImpl {

	void SimpleFunc(void);
	void PrettyFunc(void);
}

namespace ProgComImpl {

	void SimpleFunc(void);
}

// 이름공간안에 이름공간을 선언
namespace Parent {

	int num = 0;

	namespace Child {

		int num = 1;
	}
}

int main()
{

	BestComImpl::SimpleFunc();
	cout << "Parent num : " << Parent::num << endl;
	cout << "Child num : " << Parent::Child::num << endl;

	return 0;
}


void BestComImpl::SimpleFunc(void) {

	cout << "BestCom이 정의한 함수" << endl;
	// BestComImpl::PrettyFunc()라 명시할 필요가 없다
	PrettyFunc();
	ProgComImpl::SimpleFunc();
}

void BestComImpl::PrettyFunc(void) {

	cout << "So Pretty!!" << endl;
}

void ProgComImpl::SimpleFunc(void) {

	cout << "ProgCom이 정의한 함수" << endl;
}
