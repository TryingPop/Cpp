#include <iostream>
using namespace std; // std 이름 공간의 메소드를 간단하게 불러오기 위해 선언

/*
날짜 : 2023. 1. 22
이름 : 배성훈
내용 : 이름공간
	이름공간 함수를 먼저 선언하고 이후에 정의하는 방법
*/

namespace BestComImpl {

	void SimpleFunc(void);
}

namespace ProgComImpl {

	void SimpleFunc(void);
}

int main()
{

	BestComImpl::SimpleFunc();
	ProgComImpl::SimpleFunc();

	return 0;
}

void BestComImpl::SimpleFunc(void) {

	cout << "BestCom이 정의한 함수" << endl;
}

void ProgComImpl::SimpleFunc(void) {

	cout << "ProgCom이 정의한 함수" << endl;
}