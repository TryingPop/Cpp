#include <iostream>
using namespace std; // std 이름 공간의 메소드를 간단하게 불러오기 위해 선언

/*
날짜 : 2023. 1. 22
이름 : 배성훈
내용 : 이름공간
	함수의 이름이 같아서 생기는 문제를 해결하기 위해 나온 문법(?)
	::을 통해 네임스페이스안의 함수를 읽어온다
*/

namespace BestComImpl {

	void SimpleFunc(void) {

		cout << "BestComp이 정의한 함수" << endl;
	}
}

namespace ProgComImpl {

	void SimpleFunc(void) {

		cout << "ProgCom이 정의한 함수" << endl;
	}
}



int main()
{

	BestComImpl::SimpleFunc();
	ProgComImpl::SimpleFunc();

	return 0;
}