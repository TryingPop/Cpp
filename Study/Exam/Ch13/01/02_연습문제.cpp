/*
날짜 : 2023. 2. 23
이름 : 배성훈
내용 : 교재 536p 문제2
	다음은 int형 배열에 저장된 값을 모두 더해서 그 결과를 반환하는 기능의 함수이다.
	int SumArray(int arr[], int len) {

		int sum = 0;
		for (int i = 0; i < len; i++) {
			
			sum += arr[i];
		}

		return sum;
	}

	이 함수를 템플릿으로 정의하여, 다양한 자료형의 배열을 대상으로 합을 계산하는 예제를 작성해보자
*/

#include <iostream>
using namespace std;

template <typename T>
T SumArray(T arr[], int len) {

	T sum = 0;
	for (int i = 0; i < len; i++) {

		sum += arr[i];
	}

	return sum;
}

int main(void)
{

	
	int iarr[3];
	for (int i = 0; i < 3; i++) {

		iarr[i] = (i + 1) * 7;
	}

	cout << SumArray<int>(iarr, 3) << endl;	// 42

	double darr[3];

	for (int i = 0; i < 3; i++) {

		darr[i] = (i + 1) * 0.3;
	}

	cout << SumArray(darr, 3) << endl;	// 1.8

	return 0;
}