/*
날짜 : 2023. 2. 24
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

template<typename T>
T SumArray(T arr[], int len) {

	T sum = (T)0;	// T 타입으로 캐스팅(사실상 형식적)
	for (int i = 0; i < len; i++) {

		sum += arr[i];
	}

	return sum;
}

int main(void)
{

	int arr1[] = { 10, 20, 30 };
	cout << SumArray(arr1, sizeof(arr1) / sizeof(int)) << endl;
	double arr2[] = { 10.3, 20.4, 30.5 };
	cout << SumArray(arr2, sizeof(arr2) / sizeof(double)) << endl;
	return 0;
}