/*
��¥ : 2023. 1. 24
�̸� : �輺��
���� : ���� 80p ����2
	�ռ� �Ұ��� ���� RefSwap.cpp�� SwapByRef2 �Լ���
	������ ���·� ȣ���ϸ� ������ ������ �߻��Ѵ�.

	SwapByRef2(23, 45);

	������ ������ �߻��ϴ� ������ �������� �����غ���

	SwapByRef2�Լ��� ����
	void SwapByRef2(int& ref1, int &ref2){

		int temp = ref1;
		ref1 = ref2;
		ref2 = temp;
	}
*/

// ������ �ߴ� ������ �����ڰ� ����� ������ �� ���� �����̴�
void SwapByRef2(int& ref1, int& ref2) {

	int temp = ref1;
	ref1 = ref2;
	ref2 = temp;
}


int main(void)
{

	// SwapByRef2(23, 45); //���� : ��const ������ ���� �ʱ� ���� lvalue���� �Ѵ�.
}