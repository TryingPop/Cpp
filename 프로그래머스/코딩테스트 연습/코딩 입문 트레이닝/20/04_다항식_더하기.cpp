#include <string>
#include <sstream>

/*
��¥ : 2024. 3. 22
�̸� : �輺��
���� : ���׽� ���ϱ�
	�� �� �̻��� ���� ������ �̷����
	���� ���׽��̶� �Ѵ�

	���׽��� ����� ���� �����׳���
	����Ͽ� �����Ѵ�

	�������� �̷���� ���׽� polynomial��
	�Ű������� �־��� ��,

	�����׳��� ���� �ᱣ���� return�ϴ�
	solution �Լ� ����

	���� ���̶�� ���� ª�� ������ return �ؾ��Ѵ�

	polynomial�� ���� 0 �ʰ� 100 �̸��̴�
	polynomial�� ���� �װ� ����θ� �̷���� �ִ�
	polynomial�� ���� ����, ����, x, +�� �̷���� �ִ�
	�װ� �����ȣ ���̿��� �׻� ������ ����
	������ ���ӵ��� �ʰ� ���� ó���� ������ ����
	������ ���� �տ� ���� ���� ����
	�߸��� �Է��� �־����� ���� ����
	0���� ���۵Ǵ� ��쵵 ����
	��� 1�� ���� �����ϴ�
*/

using namespace std;

string solution(string _polynomial)
{

	string answer = "";

	int a = 0;
	int b = 0;

	stringstream ss(_polynomial);

	string temp;
	temp.reserve(10);

	while (ss >> temp)
	{

		if (temp == "+") continue;
		else if (temp == "x") a++;
		else if (temp.back() == 'x')
		{

			temp.pop_back();
			a += stoi(temp);
		}
		else b += stoi(temp);
	}

	answer.reserve(20);

	if (a != 0) 
	{

		if (a != 1) answer.append(to_string(a));
		
		if (b != 0) answer.append("x + ");
		else answer.push_back('x');
	}

	if (b != 0) answer.append(to_string(b));

	if (answer.empty()) answer.push_back('0');
	return answer;
}