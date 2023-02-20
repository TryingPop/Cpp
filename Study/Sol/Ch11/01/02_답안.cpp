/*
날짜: 2023. 2. 21
이름 : 배성훈
내용 : 교재 453p 문제2
	Chapter 07의 문제 07 - 2의 두 번째 문제에서는 다음의 두 클래스 정의를 요구하였다.
	class Book {
	private:
		char* title;	// 책의 제목
		char* isbn;		// 국제표준도서번호
		int price;		// 책의 정가
		....
	};

	class EBook : public Book {
	private:
		char* DRMKey;	// 보안관련 키
		....
	};
	이 때 정의한 두 클래스를 대상으로 Book 클래스도, EBook 클래스도 깊은 복사가 진행이 되도록 복사 생성자와 대입 연산자를 정의하고,
	이의 확인을 위한 main 함수도 적절히 정의해보자.
	참고로 이 문제의 해결을 위해서는 여러분이 생각해봐야 할 요소들이 몇 가지 존재한다.
	특히 앞서 말한 다음 사실을 완전히 이해한 다음 이 문제를 해결하기 바란다.
	- C++에서, AAA형 참조자는 AAA 객체 또는 AAA를 직접 혹은 간접적으로 상속하는 모든 객체를 참조할 수 있다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

class Book {

private:
	char* title;
	char* isbn;
	int price;

public:
	Book(const char* title, const char* isbn, int value) 
		: price(value) {

		this->title = new char[strlen(title) + 1];
		this->isbn = new char[strlen(isbn) + 1];

		strcpy(this->title, title);
		strcpy(this->isbn, isbn);
	}

	Book(const Book& ref) 
		: price(ref.price) {

		title = new char[strlen(ref.title) + 1];
		isbn = new char[strlen(ref.isbn) + 1];

		strcpy(title, ref.title);
		strcpy(isbn, ref.isbn);
	}

	Book& operator=(const Book& ref) {

		delete[] title;
		delete[] isbn;

		title = new char[strlen(ref.title) + 1];
		isbn = new char[strlen(ref.isbn) + 1];

		strcpy(title, ref.title);
		strcpy(isbn, ref.isbn);

		price = ref.price;
		return *this;
	}

	void ShowBookInfo() {

		cout << "제목: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "가격: " << price << endl;
	}

	~Book() {

		delete[] title;
		delete[] isbn;
	}
};

class EBook : public Book {

private:
	char* DRMKey;

public:
	EBook(const char* title, const char* isbn, int value, const char* key)
		: Book(title, isbn, value) {

		DRMKey = new char[strlen(key) + 1];
		strcpy(DRMKey, key);
	}

	EBook(const EBook& ref)
		: Book(ref) {

		DRMKey = new char[strlen(ref.DRMKey) + 1];
		strcpy(DRMKey, ref.DRMKey);
	}

	EBook& operator=(const EBook& ref) {

		Book::operator=(ref);

		delete[] DRMKey;
		DRMKey = new char[strlen(ref.DRMKey) + 1];
		strcpy(DRMKey, ref.DRMKey);
		return *this;
	}

	void ShowEBookInfo() {

		ShowBookInfo();
		cout << "인증키: " << DRMKey << endl;
	}

	~EBook() {

		delete[] DRMKey;
	}
};

int main(void)
{

	EBook ebook1("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	EBook ebook2 = ebook1;	// 복사 생성자의 호출
	ebook2.ShowEBookInfo();
	cout << endl;
	EBook ebook3("dummy", "dummy", 0, "dummy");
	ebook3 = ebook2;		// 대입 연산자의 호출
	ebook3.ShowEBookInfo();
	return 0;
}