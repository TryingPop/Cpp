#include <vector>

/*
��¥ : 2024. 2. 25
�̸� : �輺��
���� : �迭 ����� 6
	0�� 1�θ� �̷���� ���� �迭 arr�� �־�����
	arr�� �̿��� ���ο� stk�迭�� �����

	i�� �ʱⰪ�� 0���� �ϰ�, i�� arr�� ���̺��� ������

	���� stk�� �� �迭�̸�, arr[i]�� stk�� �߰��ϰ� i+ 1,

	stk�� ���Ұ� �ְ� stk�� ������ ���Ұ� arr[i]�� ������
	stk�� ������ ���Ҹ� stk���� �����ϰ� i + 1,

	stk�� ���Ұ� �ִµ� stk�� ������ ���Ұ� arr[i]�� �ٸ���
	stk�� �� �������� arr[i]�� 1�� ���ϰ� i + 1

	�� �۾��� ��ģ �� ������� 
	stk�� return�ϴ� solution �Լ� ����

	���� �۾� �� stk�� �� �迭�̶�� { -1 }�� ��ȯ
*/

using namespace std;

vector<int> solution(vector<int> _arr)
{

	vector<int> stk;

	for (int i = 0; i < _arr.size(); i++)
	{

		if (stk.empty()) stk.push_back(_arr[i]);
		else if (stk.back() == _arr[i]) stk.pop_back();
		else stk.push_back(_arr[i]);
	}

	if (stk.empty()) stk.push_back(-1);

	return stk;
}