#include <vector>

/*
��¥ : 2024. 2. 13
�̸� : �輺��
���� : �迭 ����� 4
	���� �迭 arr�� �־�����
	arr�� �̿��� ���ο� �迭 stk�� �����

	���� i�� ����� �ʱⰪ�� 0���� ������ �� i�� arr�� ���̺��� ������ ���� �۾��� �ݺ�
	���� stk�� �� �迭�̶�� arr[i]�� stk�� �߰��ϰ� i�� 1�� ���Ѵ�
	stk�� ���Ұ� �ְ�, stk�� ������ ���Ұ� arr[i]���� ������ arr[i]�� stk�� �ڿ� �߰��ϰ� i�� 1�� ���Ѵ�
	stk�� ���Ұ� �ִµ� stk�� ������ ���Ұ� arr[i]���� ũ�ų� ������ stk�� ������ ���Ҹ� stk���� �����Ѵ�

	�� �۾��� ��ġ�� ��������� stk�� return�ϴ� solution �Լ� �����
*/

using namespace std;

vector<int> solution(vector<int> _arr)
{

	vector<int> stk;

	for (int i = 0; i < _arr.size(); i++) 
	{

		if (stk.empty()) stk.push_back(_arr[i]);
		else if (stk.back() < _arr[i]) stk.push_back(_arr[i]);
		else 
		{

			stk.pop_back();
			i--;
		}
	}
	return stk;
}