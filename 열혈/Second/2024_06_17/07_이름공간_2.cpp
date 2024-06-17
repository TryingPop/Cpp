/*
날짜 : 2024. 6. 17
이름 : 배성훈
내용 : 이름공간 2
	교재p 40 ~ 41

	이름공간 기반에서 함수의 선언과 정의를 구분하는 방법이다
	함수의 선언에서 (반환형) (이름공간)::SimpleFunc(매개변수)로 선언하면 
	컴파일 에러 뜬다! 반면 정의 부분은 주석친 코드처럼 바꿔도 된다
*/

#include <iostream>

namespace BestComImpl 
{

	void SimpleFunc(void);
}

namespace ProgComImpl
{

	void SimpleFunc(void);
}

/*
// 컴파일 에러 발생
void ProgComImpl::SimpleFunc(void);
*/

int main(void)
{

	BestComImpl::SimpleFunc();
	ProgComImpl::SimpleFunc();

	return 0;
}

void BestComImpl::SimpleFunc(void)
{

	std::cout << "BestCom이 정의함 함수" << std::endl;
}

void ProgComImpl::SimpleFunc(void)
{

	std::cout << "ProgCom이 정의한 함수" << std::endl;
}


/*
namespace ProgComImpl
{

	void SimpleFunc(void)
	{

		std::cout << "ProgCom이 정의한 함수" << std::endl;
	}
}
*/