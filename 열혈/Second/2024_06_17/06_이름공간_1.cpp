/*
날짜 : 2024. 6. 17
이름 : 배성훈
내용 : 이름공간
	교재 p36 ~ 39

	이름공간은 이름을 붙여놓은 공간을 의미한다
	특정 영역에 이름을 붙여주기 위한 문법적 요소이다

	프로그램이 대형화가되어 가면서 이름의 충돌문제가 등장했다
	프로젝트의 규모가 큰 경우 일을 구분하여 독립하여 진행했을 때,
	구현할 때 이름충돌이 날 수 있다

	함수 및 변수의 이름을 모두 정한 경우로 해결할 수 있다
	하지만 이는 한계가 있다

	이름공간(namespace)이라는 문법을 정의해서 
	이러한 문제에 대한 근본적인 해결책을 내놓고 있다

	연산자 ::을 가리켜 범위지정 연산자(scope resolution operator)라 한다
	이름공간을 지정할 때 사용하는 연산자이다
*/

#include <iostream>

namespace BestComImpl
{

	void SimpleFunc(void)
	{

		std::cout << "BestCom이 정의한 함수" << std::endl;
	}
}

namespace ProgComImpl
{

	void SimpleFunc(void)
	{

		std::cout << "ProgCom이 정의한 함수" << std::endl;
	}
}

int main(void)
{

	BestComImpl::SimpleFunc();
	ProgComImpl::SimpleFunc();

	return 0;
}