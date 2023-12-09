/*
��¥ : 2023. 12. 09
�̸� : �輺��
���� : ���������
	���� 45 ~ 46p
*/

class Widget {

public:

	Widget();								// �⺻ ������
	Widget(const Widget& rhs);				// ���� ������
											// rhs�� ���빰�� �ٲ��� �ʰڴٰ� ��������� const ����

	Widget& operator=(const Widget& rhs);	// ���� ���� ������
};

Widget w1;									// �⺻ ������ ȣ��
Widget w2(w1);								// ���� ������ ȣ��

bool hasAcceptableQuality(Widget w);

void main() {

	w1 = w2;								// ���� ���� ������ ȣ��
	Widget w3 = w1;							// ���� ������ ȣ��

	Widget aWidget;

	// aWidget�� w�� ����ȴ� 
	// �� �� ����Ǵ� ���翡 Widget�� ���� �����ڰ� ���δ�
	// ����� ���� Ÿ���� ������ �ѱ�� �߻��� �Ϲ������� ���� �ʴ� �׺��ٴ� ��� ��ü�� ���� ������ �ѱ�Ⱑ �� ����
	if (hasAcceptableQuality(aWidget)) {	// ���� ������ ȣ��

		// ...
	}
}