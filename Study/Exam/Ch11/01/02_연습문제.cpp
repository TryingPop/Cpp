/*
날짜 : 2023. 2. 20
이름 : 배성훈
내용 : 교재 453p 문제2
	Chapter 07의 문제 07-2의 두 번째 문제에서는 다음의 두 클래스 정의를 요구하였다.

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
	Book(const char* title, const char* isbn, int price)
		: price(price) {

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

		delete title;
		delete isbn;

		price = ref.price;
		title = new char[strlen(ref.title) + 1];
		isbn = new char[strlen(ref.isbn) + 1];

		strcpy(title, ref.title);
		strcpy(isbn, ref.isbn);

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
	char* DBMKey;

public:
	EBook(const char* title, const char* isbn, int price, const char* DBMKey)
		: Book(title, isbn, price) {

		this->DBMKey = new char[strlen(DBMKey) + 1];
		strcpy(this->DBMKey, DBMKey);
	}

	// 참조자로 인자를 가져왔기에 이니셜라이저에 다음과 같이 가능
	EBook(const EBook& ref) 
		: Book(ref) {

		DBMKey = new char[strlen(ref.DBMKey) + 1];
		strcpy(DBMKey, ref.DBMKey);
	}

	EBook& operator=(const EBook& ref) {

		Book::operator=(ref);
		delete DBMKey;

		DBMKey = new char[strlen(ref.DBMKey) + 1];
		strcpy(DBMKey, ref.DBMKey);

		return *this;
	}
	
	void ShowEBookInfo() {

		Book::ShowBookInfo();
		cout << "인증키: " << DBMKey << endl;
	}

	~EBook() {

		delete[] DBMKey;
	}
};


int main(void)
{

	EBook e1("A", "123", 10000, "12345ABC");
	EBook e2("B", "124", 12000, "12346ABD");

	EBook e3 = e1;
	
	e3.ShowEBookInfo();

	e3 = e2;
	e3.ShowEBookInfo();

	return 0;
}