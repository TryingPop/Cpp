/*
��¥ : 2023. 1. 27
�̸� : �輺��
���� : const �Լ��� const ������
	const �Լ�
		�� �Լ� �������� ��������� ����� ���� �������� �ʰڴ�
		��������� ���� ��ȯ ��Ű�� ������ ������ �߻�
		���� const �Լ� �������� const�� �ƴ� �Լ��� ȣ���� ���ѵȴ�

	const ������
		�Ű������� const�� ���� ������
		C++������ const �����ڸ� ������� ���� ���� �ɷ��� ���� �Լ��� ȣ���� ������� �ʴ´�
*/
#include <iostream>
using namespace std;

class SimpleClass {

private:
	int num;

public:
	void InitNum(int n) {

		num = n;
	}

	int GetNum() {

		return num;
	}

	void ShowNum() const {

		// cout << GetNum() << end; // ������ ���� �߻�
									// GetNum �� const �Լ��� �ƴϴ�
	}
};

class OtherClass {

private:
	int num;

public:
	// const ������
	void InitNum(const SimpleClass& simple) {

		// num = simple.GetNum();	// ������ ���� �߻�
									// simple.GetNum �Լ��� const �Լ��� �ƴϴ�
	}
};