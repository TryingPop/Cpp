/*
��¥ : 2023. 2. 7
�̸� : �輺��
���� : ���� 312p ����2
	'å'�� �ǹ��ϴ� Book Ŭ������ '���� å'�� �ǹ��ϴ� Ebook Ŭ������ �����ϰ��� �Ѵ�.
	�׷��� '���� å'�� 'å'�� �����̹Ƿ�,
	������ ���·� Ŭ������ ��Ӱ��踦 �����ϰ��� �Ѵ�(Ŭ������ ���� �Ǿ�� �� ��������� �����Ͽ���).
	class Book {
	private:
		char* title;	// å�� ����
		char* isbn;		// ����ǥ�ص�����ȣ
		int price;		// å�� ����
		...
	};
	class EBook : public Book {
	private:
		char* DRMKey;	// ���Ȱ��� Ű
		...
	};
	���� EBook Ŭ������ ����� ��� DRMKey�� ���� å�� ������ �Ǵ� ���Ȱ��� Ű(Key)�� ������ �ǹ��Ѵ�.
	�׷� ���� main �Լ��� �Բ� ������ �����ϵ��� ���� Ŭ������ �ϼ��غ���.
	[main �Լ�]
	int main(void)
	{
		Book book("���� C++", "555-12345-890-0", 20000);
		book.ShowBookInfo();
		cout << endl;
		EBook ebook("���� C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
		ebbok.ShowEBookInfo();
		return 0;
	};
	[������ ��]
	����: ���� C++
	ISBN: 555-12345-890-0
	����: 20000
	����: ���� C++ ebook
	ISBN: 555-12345-890-1
	����: 10000
	����Ű: fdx9w0i8kiw
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
	EBook(const char* title, const char* isbn, int value, const char* key) 
		: Book(title, isbn, value) {

		DBMKey = new char[strlen(key) + 1];
		strcpy(DBMKey, key);
	}

	void ShowEBookInfo() {

		ShowBookInfo();
		cout << "����Ű: " << DBMKey << endl;
	}

	~EBook() {

		delete[] DBMKey;
	}
};

int main(void)
{

	Book book("���� C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout << endl;
	EBook ebook("���� C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook.ShowEBookInfo();
	return 0;
}