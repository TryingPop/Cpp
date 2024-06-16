/*
날짜 : 2023. 2. 24
이름 : 배성훈
내용 : 템플릿 인자
	template<typename T1, typename T2> 에서
	T1, T2 를 템플릿 매개변수라 한다.
	그리고 매개변수에 전달되는 자료형 정보를 가리켜 템플릿 인자라 한다

	템플릿 매개변수에는 변수의 선언이 올 수 있다
*/

#include<iostream>
using namespace std;

// 배열의 길이를 템플릿 매개변수로 전달한다
template<typename T, int len>
class SimpleArray {

private:
	T arr[len];

public:
	T& operator[] (int idx) {

		return arr[idx];
	}

	SimpleArray<T, len>& operator=(const SimpleArray<T, len>& ref) {

		for (int i = 0; i < len; i++) {
			
			arr[i] = ref.arr[i];
		}
		return *this;
	}
};

int main(void) 
{

	SimpleArray<int, 5> i5arr1;
	for (int i = 0; i < 5; i++) {

		i5arr1[i] = i * 10;
	}

	SimpleArray<int, 5> i5arr2;
	// 배열의 길이가 같아서 위의 정의된 대입연산자 이용 가능
	i5arr2 = i5arr1;
	for (int i = 0; i < 5; i++) {

		cout << i5arr2[i] << ", ";
	}
	cout << endl;

	SimpleArray<int, 7> i7arr1;
	for (int i = 0; i < 7; i++) {

		i7arr1[i] = i * 10;
	}

	SimpleArray<int, 7> i7arr2;
	i7arr2 = i7arr1;
	for (int i = 0; i < 7; i++) {

		cout << i7arr2[i] << ", ";
	}
	cout << endl;
	return 0;
}