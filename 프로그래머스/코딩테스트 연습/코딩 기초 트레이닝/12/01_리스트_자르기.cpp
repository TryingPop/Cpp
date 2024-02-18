#include <vector>

/*
��¥ : 2024. 2. 18
�̸� : �輺��
���� : ����Ʈ �ڸ���
	���� n�� ���� 3���� ��� ����Ʈ slicer �׸��� ���� ���� ���� ��� ����Ʈ num_list�� �־�����
	slicer�� ��� ������ ���ʴ�� a, b, c��� �� ��, n�� ���� ������ ���� num_list�� �����̽��Ѵ�

	n = 1, num_list�� 0�� �ε������� b�� �ε��� ����
	n = 2, num_list�� a�� �ε������� ������ �ε�������
	n = 3, num_list�� a�� �ε������� b�� �ε�������
	n = 4, num_list�� a�� �ε������� b�� �ε������� c ��������

	�ùٸ��� �����̽��� ����Ʈ�� return�ϵ��� solution �Լ��� �ϼ�
*/

using namespace std;

vector<int> solution(int _n, vector<int> _slicer, vector<int> _num_list)
{

	vector<int> answer;

	int s = 0, e = _num_list.size() - 1, i = 1;
	switch (_n)
	{

		case 1:
			e = _slicer[1];
			break;

		case 2:
			s = _slicer[0];
			break;

		case 3:
			s = _slicer[0];
			e = _slicer[1];
			break;

		default:
			s = _slicer[0];
			e = _slicer[1];
			i = _slicer[2];
			break;
	}

	for (int idx = s; idx <= e; idx += i) 
	{

		answer.push_back(_num_list[i]);
	}
	return answer;
}