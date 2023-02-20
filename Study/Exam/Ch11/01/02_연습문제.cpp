/*
��¥ : 2023. 2. 20
�̸� : �輺��
���� : ���� 453p ����2
	Chapter 07�� ���� 07-2�� �� ��° ���������� ������ �� Ŭ���� ���Ǹ� �䱸�Ͽ���.

	class Book {

	private:
		char* title;	// å�� ����
		char* isbn;		// ����ǥ�ص�����ȣ
		int price;		// å�� ����
		....
	};
	
	class EBook : public Book {

	private:
		char* DRMKey;	// ���Ȱ��� Ű
		....
	};

	�� �� ������ �� Ŭ������ ������� Book Ŭ������, EBook Ŭ������ ���� ���簡 ������ �ǵ��� ���� �����ڿ� ���� �����ڸ� �����ϰ�,
	���� Ȯ���� ���� main �Լ��� ������ �����غ���.
	����� �� ������ �ذ��� ���ؼ��� �������� �����غ��� �� ��ҵ��� �� ���� �����Ѵ�.
	Ư�� �ռ� ���� ���� ����� ������ ������ ���� �� ������ �ذ��ϱ� �ٶ���.
		- C++����, AAA�� �����ڴ� AAA ��ü �Ǵ� AAA�� ���� Ȥ�� ���������� ����ϴ� ��� ��ü�� ������ �� �ִ�.
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

		cout << "����: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "����: " << price << endl;
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

	// �����ڷ� ���ڸ� �����Ա⿡ �̴ϼȶ������� ������ ���� ����
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
		cout << "����Ű: " << DBMKey << endl;
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