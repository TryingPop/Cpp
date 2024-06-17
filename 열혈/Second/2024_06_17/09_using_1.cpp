/*
날짜 : 2024. 6. 17
이름 : 배성훈
내용 : using을 이용한 이름공간의 명시
	교재 p44 ~ 45
	
	using 키워드를 이용하면이름공간 안에 선언된 함수를 
	범위지정 없이 그냥호출할 수 있다

	아래 예제를 보면, HybFunc를 이름곤간 Hybrid에서 찾으라는 일종의 선언이다
	여기서 HybFunc는 변수가 될 수도 있고 함수가 될 수 있다
	지역변수로 선언되었으므로 선언된 지역을 벗어나면 선언의 효력은 일ㅀ게 된다

	프로그램 전체 영역에 효력을 미치게 하려면
	전역변수와 마찬가지로 함수 밖에 선언을 해야 한다
*/

#include <iostream>

namespace Hybrid
{

	void HybFunc(void)
	{

		std::cout << "So simple function!" << std::endl;
		std::cout << "In namespace Hybrid" << std::endl;
	}
}

int main(void)
{

	using Hybrid::HybFunc;
	HybFunc();
	return 0;
}