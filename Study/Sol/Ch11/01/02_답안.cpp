/*
��¥: 2023. 2. 21
�̸� : �輺��
���� : ���� 453p ����2
	Chapter 07�� ���� 07 - 2�� �� ��° ���������� ������ �� Ŭ���� ���Ǹ� �䱸�Ͽ���.
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
		cout << "����Ű: " << DRMKey << endl;
	}

	~EBook() {

		delete[] DRMKey;
	}
};

int main(void)
{

	EBook ebook1("���� C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	EBook ebook2 = ebook1;	// ���� �������� ȣ��
	ebook2.ShowEBookInfo();
	cout << endl;
	EBook ebook3("dummy", "dummy", 0, "dummy");
	ebook3 = ebook2;		// ���� �������� ȣ��
	ebook3.ShowEBookInfo();
	return 0;
}