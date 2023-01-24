/*
날짜 : 2023. 1. 25
이름 : 배성훈
내용 : 교재 99p 문제2
	다음 세 함수를 이용해서 0이상 100미만의 난수를 총 5개 생성하는 예제를 만들되,
	C++ 의 헤더를 선언해서 작성해보자.
	참고로 C언어의 경우 time 함수는 <time.h>에 선언되어 있고, 
	rand 함수와 srand 함수는 <stdlib.h>에 선언되어 있다.
		rand, srand, time
*/

#include <ctime>	// time
#include <cstdlib>	// srand, rand
#include <iostream>	// cout, endl

using namespace std;

int main(void)
{

	srand((unsigned int)time(NULL));	// 현재 시간을 기준으로 seed값 설정
	
	int nums[5];
	
	for (int i = 0; i < 5; i++) {
		
		bool chk = true;

		while (chk) {
			chk = false;
			int rd = rand() % 100; // 0 ~ 100 사이의 자연수인 난수 생성 
			nums[i] = rd;

			// 중복 체크
			for (int j = 0; j < i; j++) {

				if (nums[j] == rd) {

					chk = true;
					break;
				}
			}
		}
	}

	cout << nums[0] << endl;
	cout << nums[1] << endl;
	cout << nums[2] << endl;
	cout << nums[3] << endl;
	cout << nums[4] << endl;
}