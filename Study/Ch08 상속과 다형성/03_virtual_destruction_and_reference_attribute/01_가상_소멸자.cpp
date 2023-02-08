/*
��¥ : 2023. 2. 8
�̸� : �輺��
���� : ���� �Ҹ���
	Virtual Destructor
		�Ҹ��� �տ� virtual�� ������ �ȴ�
		virtual ~Ŭ������() { �����ڵ� }

*/

#include <iostream>
using namespace std;

class First {

private:
	char* strOne;

public:
	First(const char* str) {

		strOne = new char[strlen(str) + 1];
	}

	~First() {

		cout << "~First()" << endl;
		delete[] strOne;
	}
};

class Second : public First {

private:
	char* strTwo;

public:
	Second(const char* str1, const char* str2)
		: First(str1) {

		strTwo = new char[strlen(str2) + 1];
	}

	// ���� �Ҹ��� ����
	virtual ~Second() {

		cout << "~Second()" << endl;
		delete[] strTwo;
	}
};

class Third :public Second {

private:
	char* strThird;

public:
	Third(const char* str1, const char* str2, const char* str3)
		: Second(str1, str2) {

		strThird = new char[strlen(str3) + 1];
	}

	~Third() {

		cout << "~Third()" << endl;
		delete[] strThird;
	}
};

int main(void) 
{

	Second* ptr1 = new Third("1", "2", "3");
	delete ptr1;	// Third, Second, First ������ ȣ��

	First* ptr2 = new Third("First", "Second", "Third");
	delete ptr2;	// First�� ȣ�� �ȴ� �޸� ���� �߻�
					// vs������ �� ������ ������ �� ���� �޸� �ִٰ� ������ ������ �ҷ�����Ų��
	return 0;
}