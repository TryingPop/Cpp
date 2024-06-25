/*
��¥ : 2024. 6. 25
�̸� : �輺��
���� : ĸ��ȭ�� ��Ȯ�� ����
	���� p163 ~ 166

	���� ������ ĸ��ȭ�� �����̴�
	����� ���� ������ �����ϴ�

	ĸ��ȭ�� �� �� �ϳ��� Ŭ�����θ� ��� ���� �����ؾ� �ϴ� ���� �ƴϴ�
	�ٸ� Ŭ������ Ȱ���ص� �ȴ�
	������ ��� ������ �ϴ��İ� �ƴϰ�,
	��� �������� �����ϴ°��̴�

	�����ִ� ������ �Լ��� �ϳ��� Ŭ���� �ȿ� ���� ���� ĸ��ȭ�̴�
	ĸ��ȭ�� ����� �����̴� ĸ��ȭ�� ������ �����ϴ� ���� ���� �ʱ� �����̴�

	ĸ��ȭ�� ���δ� �����̴�
	�׷��� ���η��� �����ϰ� ���ξ��Ѵ�
	��������� ������ �ʰ� ������ �����ؼ� ���θ� ����
	ĸ��ȭ�� �⺻������ ���������� �����ϴ� �����̴�

	���踹�� ��ü���� ���α׷��Ӹ� �����ϴµ� ù ��° ������ ĸ��ȭ�̴�
	ĸ��ȭ�� �ϰ��ǰ� ������ �� �ִ� �ܼ��� ������ �ƴϰ�,
	�����ϴ� ���α׷��� ���ݰ� Ư���� ����
	�����ϴ� ������ �޶����Ƿ� ������ ���� �����̱� �����̴�
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

class CONTAC600
{

private:
	SinivelCap sin;
	SneezeCap sne;
	SnuffleCap snu;

public:
	void Take() const
	{

		sin.Take();
		sne.Take();
		snu.Take();
	}
};

class ColdPatient
{

public:
	void TakeCONTAC600(const CONTAC600& cap) const
	{

		cap.Take();
	}
};

int main(void)
{

	CONTAC600 cap;
	ColdPatient sufferer;
	sufferer.TakeCONTAC600(cap);
	return 0;
}