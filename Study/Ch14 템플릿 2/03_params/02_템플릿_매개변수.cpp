/*
날짜 : 2023. 2. 24
이름 : 배성훈
내용 : 템플릿 매개변수
	템플릿 매개변수에도 초기 값(디폴트 값) 지정 가능
*/

#include<iostream>
using namespace std;

template<typename T = int, int len = 7>
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

		return *this
	}
};

int main(void)
{

	SimpleArray<> arr;	// 디폴트 값으로 템플릿 클래스의 객체 생성
						// <> 기호는 반드시 넣어야한다!
	for (int i = 0; i < 7; i++) {

		arr[i] = i + 7;
	}

	for (int i = 0; i < 7; i++) {

		cout << arr[i] << ", ";
	}
	cout << endl;
	
	return 0;
}