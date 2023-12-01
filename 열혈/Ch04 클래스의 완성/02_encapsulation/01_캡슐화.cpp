/*
��¥ : 2023. 1. 27
�̸� : �輺��
���� : ĸ��ȭ�� �ʿ伺
	ĸ��ȭ�� �������� Ŭ���� ��ȣ���谡 ����������
	�׷��� ���α׷� ��ü�� ���⵵�� ���̴� ����� �̾�����
*/
#include <iostream>
using namespace std;

class SinivelCap {	// �๰ óġ�� ĸ��

public:
	void Take() const { cout << "�๰�� ��~ ���ϴ�." << endl; }
};

class SneezeCap {	// ��ä�� óġ�� ĸ��

public:
	void Take() const { cout << "��ä�Ⱑ �½��ϴ�." << endl; }
};

class SnuffleCap {	// �ڸ��� óġ�� ĸ��

public:
	void Take() const { cout << "�ڰ� �� �ո��ϴ�." << endl; }
};

class ColdPatient {

public:
	void TakeSinivelCap(const SinivelCap& cap) const { cap.Take(); }
	void TakeSneezeCap(const SneezeCap& cap) const { cap.Take(); }
	void TakeSnuffleCap(const SnuffleCap& cap) const { cap.Take(); }
};

int main(void) 
{

	SinivelCap scap;
	SneezeCap zcap;
	SnuffleCap ncap;

	ColdPatient sufferer;
	sufferer.TakeSinivelCap(scap);
	sufferer.TakeSneezeCap(zcap);
	sufferer.TakeSnuffleCap(ncap);
	return 0;
}