/*
��¥ : 2023. 1. 28
�̸� : �輺��
���� : ������ ����ġ
	�Ű������� void������ ����Ǵ� ����Ʈ �����ڴ�,
	�����ڰ� �ϳ��� ���ǵǾ� ���� ���� ������ ���Եȴ�
*/

class SoSimple {

private:
	int num;

public:
	SoSimple(int n) :num(n){ }
	// SoSimple(int n = 0) : num(n){ }
};

int main(void) 
{

	SoSimple simObj1(10);
	SoSimple* simPtr1 = new SoSimple(2);

	// �����ڰ� �����Ƿ� �Ʒ� ������� ���� �Ұ�
	// �ٸ� �ʱⰪ �������ָ� ��� ����
	// SoSimple simObj2;
	// SoSimple* simPtr2 = new SoSimple;


}