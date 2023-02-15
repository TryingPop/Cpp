/*
날짜 : 2023. 2. 15
이름 : 배성훈
내용 : 배열 클래스
	const 함수를 이용한 오버로딩
*/

#include <iostream>
#include <cstdlib>
using namespace std;

class BoundCheckIntArray {

private:
	int* arr;
	int arrlen;
	BoundCheckIntArray(const BoundCheckIntArray& arr) { }
	BoundCheckIntArray& operator=(const BoundCheckIntArray& arr) { }

public:
	BoundCheckIntArray(int len)
		: arrlen(len) {

		arr = new int[len];
	}

	int& operator[](int idx) {

		if (idx < 0 || idx >= arrlen) {

			cout << "Array index out of bound exception" << endl;
			exit(1);
		}

		return arr[idx];
	}


	// const 선언도 오버로딩을 정의하지 않으면 
	// ShowAllData에서 에러뜬다
	int& operator[](int idx) const {

		if (idx < 0 || idx >= arrlen) {

			cout << "Array index out of bound exception" << endl;
			exit(1);
		}

		return arr[idx];
	}

	int GetArrLen() const {

		return arrlen;
	}

	~BoundCheckIntArray() {
		delete[] arr;
	}
};

void ShowAllData(const BoundCheckIntArray& ref) {

	int len = ref.GetArrLen();
	for (int idx = 0; idx < len; idx++) {

		cout << ref[idx] << endl;	// operator[]가 const 선언되어야 불러올 수 있다
	}
}

int main(void)
{

	BoundCheckIntArray arr(5);
	for (int i = 0; i < 5; i++) {

		arr[i] = (i + 1) * 11;
	}

	ShowAllData(arr);
	return 0;
}