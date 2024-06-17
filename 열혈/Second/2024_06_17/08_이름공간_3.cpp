/*
날짜 : 2024. 6. 17
이름 : 배성훈
내용 : 이름공간 기반의 함수 선언과 정의 구분
	교재 p41 ~ 44

	동일한 이름공간에 있는 함수는 직접호출이 가능하다
	그리고 이름공간은 다른 이름공간 안에 삽입될 수 있다
	namespace ONE
	{

		namespace TWO { }
		namespace THREE { }
	}

	접근 방법 역시 ONE::TWO::... 형식으로 접근이 가능하다

	std::cout, std::cin, std::endl등도
	std 이름공간에 선언된 것들이다
	이름충돌을 막기위해 C++ 표준에서 제공하는 다양한 요소들은
	이름공간 std안에 선언되어 있다
*/

#include <iostream>

namespace BestComImpl
{

	void SimpleFunc(void);
}

namespace BestComImpl
{

	void PrettyFunc(void);
}

namespace ProgComImpl 
{

	void SimpleFunc(void);
}

int main(void)
{

	BestComImpl::SimpleFunc();

	return 0;
}

void BestComImpl::SimpleFunc(void)
{

	std::cout << "BestCom이 정의한 함수" << std::endl;
	PrettyFunc();				// 동일 이름공간
	ProgComImpl::SimpleFunc();	// 다른 이름공간
}

void BestComImpl::PrettyFunc(void)
{

	std::cout << "So Pretty!!" << std::endl;
}

void ProgComImpl::SimpleFunc(void)
{

	std::cout << "ProgCom이 정의한 함수" << std::endl;
}