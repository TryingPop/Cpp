/*
��¥ : 2023. 1. 28
�̸� : �輺��
���� : ����Ʈ ������
	�޸� �Ҵ� ���Ŀ� �������� ȣ����� �Ϸ�Ǿ�� ��ü
	��, ��ü�� �Ǳ� ���ؼ��� �ݵ�� �ϳ��� �����ڰ� ȣ��Ǿ�� �Ѵ�

	new �����ڷ� ȣ���ϸ� �����ڰ� ȣ��ȴ�
	�ݸ� malloc���� ȣ���ϸ� ������ ȣ���� �ȵȴ�
*/

#include<cstdlib>
using namespace std;

class AAA {

private:
	int num;

public:
	int GetNum() { return num; }
	// AAA() { } // ����Ʈ �����ڰ� ����
};

int main(void) 
{

	AAA* nptr = new AAA();
	AAA* mptr = (AAA*)malloc(sizeof(AAA));
}