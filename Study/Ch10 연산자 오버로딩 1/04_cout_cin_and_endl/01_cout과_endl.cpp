/*
��¥ : 2023. 2. 14
�̸� : �輺��
���� : cout�� endl
	c++ �ܼ� ����¿� ���Ǵ� cout�� enl�� ���ظ� ���� ���� ����
*/

#include<iostream>
namespace mystd {

	using namespace std;

	class ostream {

	public:
		void operator<< (const char* str) {

			printf("%s", str);
		}

		void operator<< (char str) {

			printf("%c", str);
		}

		void operator<< (int num) {

			printf("%d", num);
		}

		void operator<< (double e) {

			printf("%g", e);
		}

		// �Լ� ������ fp
		// ��ȯ�� *������ (����)
		// �׷��� ostream�� �ּҸ� ��ȯ
		// ������ �������� fp
		// �Լ��� ���� ���� ���´� pstream�� �ּ�
		void operator<< (ostream& (*fp)(ostream& ostm)) {

			fp(*this);
		}
	};

	ostream& endl(ostream& ostm) {

		ostm << '\n';
		fflush(stdout);
		return ostm;
	}

	ostream cout;
}

int main(void) {

	using mystd::cout;
	using mystd::endl;

	cout << "Simple String";
	cout << endl;
	cout << 3.14;
	cout << endl;
	cout << 123;
	endl(cout);
}