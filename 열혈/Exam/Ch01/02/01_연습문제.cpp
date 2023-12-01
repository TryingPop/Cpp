#include <iostream>
using namespace std;

/*

날짜 : 2023. 1. 22
이름 : 배성훈
내용 : 교재 26p 문제1
	다음 main 함수에서 필요로 하는 swap 함수를 오버로딩 해서 구현해보자.

	int main(void)
	{
		int num1 = 20, num2 = 30;
		swap(&num1, &num2);
		std::cout<<num1<<' '<<num2<<std::endl;

		char ch1='A', ch2='Z';
		swap(&ch1, &ch2);
		std::cout<<ch1<<' '<<ch2<<std::endl;

		double dbl1=1.111, dbl2=5.555;
		swap(&dbl1, &dbl2);
		std::cout<<dbl1<<' '<<dbl2<<std::endl;
		return 0;
	}
*/

// swap 오버로딩 함수들 정의
// 변수 앞의 * : 주소를 받아온다는 표시
// 주소의 swap이 아닌 값의 swap이다
void swap(int *num1, int *num2) {

	int temp;		// temp 생성
	temp = *num1;	// temp에 주소 *num1이 가리키는 값을 저장한다
	*num1 = *num2;	// 주소 num1에 주소 num2가 가리키는 값을 저장한다
	*num2 = temp;	// 주소 num2에 temp 값을 저장한다

	return;
}

void swap(char *ch1, char *ch2) {
	char temp;
	temp = *ch1;
	*ch1 = *ch2;
	*ch2 = temp;

	return;
}

void swap(double *dbl1, double *dbl2) {
	double temp;
	temp = *dbl1;
	*dbl1 = *dbl2;
	*dbl2 = temp;

	return;
}

int main(void)
{

	int num1 = 20, num2 = 30;
	swap(&num1, &num2);
	cout << num1 << ' ' << num2 << endl;

	char ch1 = 'A', ch2 = 'Z';
	swap(&ch1, &ch2);
	cout << ch1 << ' ' << ch2 << endl;

	double dbl1 = 1.111, dbl2 = 5.555;
	swap(&dbl1, &dbl2);
	cout << dbl1 << ' ' << dbl2 << endl;
	return 0;
}