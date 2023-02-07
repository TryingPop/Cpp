/*
날짜 : 2023. 2. 7
이름 : 배성훈
내용 : 교재 312p 문제2
	'책'을 의미하는 Book 클래스와 '전자 책'을 의미하는 Ebook 클래스를 정의하고자 한다.
	그런데 '전자 책'도 '책'의 일종이므로,
	다음의 형태로 클래스의 상속관계를 구성하고자 한다(클래스에 선언 되어야 할 멤버변수만 제시하였다).
	class Book {
	private:
		char* title;	// 책의 제목
		char* isbn;		// 국제표준도서번호
		int price;		// 책의 정가
		...
	};
	class EBook : public Book {
	private:
		char* DRMKey;	// 보안관련 키
		...
	};
	위의 EBook 클래스에 선언된 멤버 DRMKey는 전자 책에 삽입이 되는 보안관련 키(Key)의 정보를 의미한다.
	그럼 다음 main 함수와 함께 실행이 가능하도록 위의 클래스를 완성해보자.
	[main 함수]
	int main(void)
	{
		Book book("좋은 C++", "555-12345-890-0", 20000);
		book.ShowBookInfo();
		cout << endl;
		EBook ebook("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
		ebbok.ShowEBookInfo();
		return 0;
	};
	[실행의 예]
	제목: 좋은 C++
	ISBN: 555-12345-890-0
	가격: 20000
	제목: 좋은 C++ ebook
	ISBN: 555-12345-890-1
	가격: 10000
	인증키: fdx9w0i8kiw
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
	EBook(const char* title, const char* isbn, int value, const char* key) 
		: Book(title, isbn, value) {

		DBMKey = new char[strlen(key) + 1];
		strcpy(DBMKey, key);
	}

	void ShowEBookInfo() {

		ShowBookInfo();
		cout << "인증키: " << DBMKey << endl;
	}

	~EBook() {

		delete[] DBMKey;
	}
};

int main(void)
{

	Book book("좋은 C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout << endl;
	EBook ebook("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook.ShowEBookInfo();
	return 0;
}