/*
��¥ : 2023. 2. 8
�̸� : �輺��
���� : ���� �����Լ��� �߻� Ŭ����
	Ŭ���� �߿��� ��ü������ �������� ���ǵ��� �ʴ� Ŭ������ �����Ѵ�

	pure virtual function
		�Լ��� ��ü�� ���ǵ��� �ʴ� �Լ�
		const�� const = 0 �� �����ν� �����Ϸ����� ��������� ��ü�� �������� �ʾҴٰ� �˷��ش�

	abstract Ŭ����
		�ϳ� �̻��� ����Լ��� ���� �����Լ��� ������ Ŭ����
*/

class AbsClass {

private:
	int num;

public:
	AbsClass() { }

	void Func1() { }
	virtual void Func2() const { }
	virtual void PureFunc() const = 0 { }	// �߻� Ŭ���� ����
};

int main(void)
{

	// �߻� Ŭ������ AbsClass�� ȣ���Ϸ� �߱⿡ ������ ������ ���
	// AbsClass abs1 = new AbsClass;
	// AbsClass abs2;
	return 0;
}