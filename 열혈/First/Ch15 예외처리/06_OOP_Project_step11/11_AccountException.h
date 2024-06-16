/*
��¥ : 2023. 2. 26
�̸� : �輺��
���� : ������� ���� ���α׷�
	���� 629p

	������� : MinusException Ŭ������ ����� ����, InsuffException Ŭ������ ����� ����
*/

#ifndef __ACCOUNT_EXCEPTION_H__
#define __ACCOUNT_EXCEPTION_H__

#include "10_BankingCommonDecl.h"

class MinusException {

private:
	int exval;	// ������ ������ �Ǵ� �ݾ�

public:
	MinusException(int val) 
		: exval(val) { }

	void ShowExceptionInfo(void) const {

		cout << "��(��)�ݾ�" << exval << "�� ��ȿ���� �ʽ��ϴ�!" << endl;
	}
};

class InsuffException {

private:
	int balance;	// ���� �ܾ�
	int reqval;		// ��� �䱸��

public:
	InsuffException(int val, int req)
		: balance(val), reqval(req) { }

	void ShowExceptionInfo(void) const {

		cout << "�ܾ׿��� " << reqval - balance << "�� �����մϴ�!" << endl;
	}
};

#endif
