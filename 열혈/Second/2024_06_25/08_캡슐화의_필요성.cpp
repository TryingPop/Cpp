/*
��¥ : 2024. 6. 25
�̸� : �輺��
���� : ĸ��ȭ
	���� p161 ~ 163

	ĸ��ȭ�� ���������� ���̸� �ƴ� ���� �߿��ϴ�
	���� ĸ��ȭ�� �������� ���� ������ ����

	�ϳ��� �����Ͽ� �� �̻��� ����� �𿩼� �ϳ��� ������ �޼��ϰ� �ִ�
	���⼭ ����� ������ ����� �� �ְ� ���� ���ΰ� �߿��� ��,
	�Ʒ� ������ �ſ� ������ ������ �� �� �ۿ� ����

	ĸ��ȭ�� �������� ��ü�� Ȱ���� �ſ� ���������
	�Ӹ� �ƴ϶� ĸ��ȭ�� �������� Ŭ���� ��ȣ���谡 ���������� ������ �̴� ���α׷� ��ü�� ���⵵�� ���̴� ����� �̾�����
*/

#include <iostream>

using namespace std;

class SinivelCap
{

public:
	void Take() const
	{

		cout << "�๰�� ��~ ���ϴ�." << endl;
	}
};

class SneezeCap
{

public:
	void Take() const
	{

		cout << "��ä�Ⱑ �ܽ��ϴ�." << endl;
	}
};

class SnuffleCap
{

public:
	void Take() const
	{

		cout << "�ڰ� �� �ո��ϴ�." << endl;
	}
};

class ColdPatient
{

public:
	void TakeSinivelCap(const SinivelCap& cap) const
	{

		cap.Take();
	}

	void TakeSneezeCap(const SneezeCap& cap) const
	{

		cap.Take();
	}

	void TakeSnuffleCap(const SnuffleCap& cap) const
	{

		cap.Take();
	}
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