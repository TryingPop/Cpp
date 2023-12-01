/*
날짜 : 2023. 2. 26
이름 : 배성훈
내용 : reinterpret_cast
	상관없는 자료형으로의 변환

	reinterpret_cast 연산자의 형식
		reinterpret_cast<T>(expr)

		포인터를 대상으로 하는, 
		그리고 포인터와 관련이 있는 모든 유형의 형 변환을 허용한다
*/

#include<iostream>
using namespace std;

int main(void) 
{

	int num1 = 0x010203;		// 16진수로 값을 넣어라는 의미
								// 3 * (16)^0 + 0 * (16)^1 + 2 * (16)^2 + 0 * (16)^3 + 1 * (16)^4 + 0 * (16)*5
	
	// cout << num1 << endl;	// 66501

	char* ptr1 = reinterpret_cast<char*>(&num1); // num1의 값을 char로 읽는다
	
	// int num = 0x010000;
	// int num3 = 65536;

	// char* ptr3 = reinterpret_cast<char*>(&num3);
	// cout << static_cast<int>(*ptr3) << endl;	// 0

	// int num4 = 3;
	// char* ptr4 = reinterpret_cast<char*>(&num4);
	// cout << static_cast<int>(*ptr4) << endl;	// 3

	// 3, 2, 1, 0 출력
	for (int i = 0; i < sizeof(num1); i++) {

		// cout << *(ptr1 + i) << endl;				 	// , , ,  
														// 4번째는 공백이 출력
														// 각각 (char)3, (char)2, (char)1, (char)0의 값이다

		cout << static_cast<int>(*(ptr1 + i)) << endl;	// ptr이 char*형이므로 1바이트씩 읽는거 같다
														// 그래서 뒤에서부터 각각 03, 02, 01을 읽는다
														// 만약 num1 = 0x010248 이라 정의하면
														// 72(0x48), 2(0x02), 1(0x01), 0(0x00) 을 출력한다
	}
	
	int num2 = 72;							// 0x48 
	int* ptr2 = &num2;						// ptr2를 num2의 주소로 한다

	int adr = reinterpret_cast<int>(ptr2);	// 주소 값을 정수로 변환 
	cout << "Addr: " << adr << endl;		// 주소 값 출력
											// 쓰레기 값 나온다

	int* rptr = reinterpret_cast<int*>(adr);// 정수를 다시 주소 값으로 변환
	
	cout << "rptr: " << rptr << endl;		// rptr 출력하니 앞의 4바이트는 00000000 or FFFFFFFF 로 출력된다
											// rptr의 앞의 8자리(4바이트)가 00000000이면 adr은 양수, FFFFFFFF이면 adr은 음수

	cout << "value: " << *rptr << endl;		// 주소 값에 저장된 정수 출력
											// *rptr 읽는게 안되어 프로그램이 강제 종료된다

	return 0;
}