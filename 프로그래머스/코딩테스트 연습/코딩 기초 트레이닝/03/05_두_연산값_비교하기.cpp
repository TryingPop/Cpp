// #include <iostream>
#include <string>
#include <vector>

/*
��¥ : 2024. 2. 9
�̸� : �輺��
���� : �� ���� ���갪 ���ϱ�
	���ο� + ���� ����
	12 + 3 = 123
	3 + 12 = 312

	a, b�� 1�� ������ �ڿ���
	a, b�� �־����� ��, a + b�� 2 * a * b�� ū ���� return�ϴ� solution �Լ� �ϼ��ϱ�


*/

using namespace std;

int solution(int _a, int _b)
{

	int answer = 0;

	string A = to_string(_a);
	string B = to_string(_b);

	string calc;
	calc.reserve(A.size() + B.size());
	calc.append(A).append(B);

	answer = max(stoi(calc), 2 * _a * _b);

	// ���� ��������� ������ �ǹ��� ���´�
	// �׷��� ���� ���α׷��ӽ������� Ʋ����, ���⼭�� ���� ���
	// https://stackoverflow.com/questions/3130490/deleting-string-object-in-c
	// 
	// ���� �����÷ο쿡�� �亯�� ����
	// ���ڿ��� ����� �ش� �Ҹ��ڰ� �ڵ����� ȣ��ǰ� �޸𸮰� �����ȴٰ� �Ѵ�
	// �Լ����� ��ȯ�� ��, string Ŭ������ �Ҹ��ڰ� �۵��ϴ°� ����
	// delete &A, &B, &calc;
	return answer;
}


/*
int main(void)
{

	int a, b;
	int result;

	cin >> a >> b;
	result = solution(a, b);
	cout << result;
}
*/