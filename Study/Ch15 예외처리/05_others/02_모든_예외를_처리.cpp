/*
��¥ : 2023. 2. 25
�̸� : �輺��
���� : ��� ���ܸ� ó��
	��� ���ܰ� �ڷ����� ������� �ɷ���� ���� 

	�ٸ� ���ܿ� ���� ��� ������ ���� �� ����
	���޵� ������ ������ ������ �Ұ����ϴ�
*/

#include<iostream>
using namespace std;

void ExceptionGenerator(int num) throw(int, char, float){

	if (num == 1) {

		int ex = 0;
		cout << "int" << endl;
		throw ex;
	}
	else if (num == 2) {

		char ex = 'A';
		cout << "char" << endl;
		throw ex;
	}
	else if (num == 3) {

		float ex = 1.1f;
		cout << "float" << endl;
		throw ex;
	}
}


int main(void)
{
	int sel;

	while (1) {

		try {

			cout << "���� ����(1: int,  2: char, 3: float, 4: ����): ";
			cin >> sel;

			ExceptionGenerator(sel);
			if (sel == 4) {

				break;
			}
			else {

				cout << "�߸��� �Է��� �Ͽ����ϴ�." << endl;
				cout << "���Է��� �����մϴ�." << endl << endl;
			}
		}
		catch (...) {

			cout << "���ܰ� �߻�" << endl << endl;
		}
	}

}