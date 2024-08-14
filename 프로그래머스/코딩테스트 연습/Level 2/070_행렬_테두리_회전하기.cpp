/*
��¥ : 2024. 8. 14
�̸� : �輺��
���� : ��� �׵θ� ȸ���ϱ�
	rows x columns ũ���� ����� �ֽ��ϴ�.
	��Ŀ��� 1���� rows x columns������ ���ڰ� 
	�� �پ� ������� �����ִ�

	�� ��Ŀ��� ���簢�� ����� ������ ���� �� ������,
	�׵θ� �κп� �ִ� ���ڵ��� �ð�������� ȸ����Ű�� �Ѵ�

	�� ȸ���� (x1, y1, x2, y2)�� ���� 4���� ǥ���ϸ�,
	�� �ǹ̴� ������ ����

	x1�� y1������ x2�� y2�������� ������ �ش��ϴ�
	���簢������ �׵θ��� �ִ� ���ڵ��� �� ĭ�� �ð�������� ȸ���Ѵ�

	����� ���� ����(�� ����) rows, ���� ����(�� ����) columns,
	�׸��� ȸ������ ��� queries�� �־��� ��,
	�� ȸ������ �迭�� ������ ��,
	�� ȸ���� ���� ��ġ�� �ٲ� ���ڵ� �� 
	���� ���� ���ڵ��� ������� �迭�� ��� 
	return �ϴ� solution �Լ� ����

	rows�� 2 �̻� 100 ������ �ڿ���
	columns�� 2 �̻� 100 ������ �ڿ���

	���� �������� ���ڰ� 1���� �ϳ��� �����ϸ鼭 ������

	queries�� ���� ����(ȸ���� ����)�� 1�̻� 1�� ����

	queries�� �� ���� 4���� ���� { x1, y1, x2, y2 }
	x1�� y1�� ���� x2 y2 ������ ������ �׵θ��� �ð�������� ȸ���Ѵٴ� ���̴�
	���� ���� 1 <= x1 < x2 <= rows, 1 <= y1 < y2 <= columns�̴�

	��� ȸ���� ������� �̷�����

	parameter 
	6, 6, { { 2, 2, 5, 4 },{ 3, 3, 6, 6 },{ 5, 1, 6, 3 } }


	return
	{ 8, 10, 25 }


	sol
	ó�� ȸ���� 2�� 2������ 5�� 4���� �ش��ϴ� �׵θ��̴�

		1		2		3		4		5		6
		      --------------------
		7	  | 8		9	   10|	   11	   12
		      |        --		 |
	   13	  |14	  |15| 	   16|	   17	   18
	   19	  |20	  |21| 	   22|	   23	   24
			  |		   --		 |
	   25	  |26	   27	   28|     29	   30
	          --------------------
	   31	   32	   33	   34	   35	   36

	8, 9, 10, 16, 22, 28, 27, 26, 20, 14 �� �ش�ȴ�
	�̵��� �ð�������� ȸ���ϸ�

		1		2		3		4		5		6
		7	   14		8	    9 	   11	   12
	   13	   20	   15  	   10 	   17	   18
	   19	   26	   21  	   16 	   23	   24
	   25	   27	   28	   22      29	   30
	   31	   32	   33	   34	   35	   36

	�̵ǰ� ȸ���� �� �߿� ���� ���� ���� 8�̴�

	3�� 3������ 6�� 6������ ȸ����Ű�� ������ ����

		1		2		3		4		5		6
		7	   14		8	    9 	   11	   12
					   --------------------------
	   13	   20	  |21  	   15 	   10	   17|
					  |		   ----------		 |
	   19	   26	  |28  	  |16 	   23|	   18|
	   25	   27	  |33	  |22      29|	   24|
					  |		   ----------		 |
	   31	   32	  |34	   35	   36	   30|
	                   --------------------------

	�� �߿��� ���� ���� ���� 10�̴�

	�׸��� 5�� 1������ 6�� 3������ ������ ȸ����Ű�� ������ ����

		1		2		3		4		5		6
		7	   14		8	    9 	   11	   12
	   13	   20	   21  	   15 	   10	   17
	   19	   26	   28  	   16 	   23	   18
	   ------------------
	  |31	   25	   27|	   22      29	   24
	  |32	   34	   33|	   35	   36	   30
	   ------------------

	�� �߿� ���� ���� ���� 25�̴�

	�׷��� { 8, 10, 25 }
*/


#include <vector>

#define adjust(x) ((x) - 1)
using namespace std;

inline void GetMap(vector<vector<int>>& _map, const int _row, const int _col)
{

	/*
	
	�� �ʱ� ����
	*/
	_map.resize(_row, vector<int>(_col));

	int n = 1;

	for (int r = 0; r < _row; r++)
	{

		for (int c = 0; c < _col; c++)
		{

			_map[r][c] = n++;
		}
	}
}

inline int Rotate(vector<vector<int>>& _map, const vector<int>& _pos)
{

	/*
	
	ȸ���ϰ� �̵��� ��� �� ���� ���� ���� ��ȯ
	*/
	int temp = _map[adjust(_pos[0])][adjust(_pos[1])];
	int ret = temp;

	// ��
	int j = adjust(_pos[1]);
	for (int r = adjust(_pos[0]); r < adjust(_pos[2]); r++)
	{

		_map[r][j] = _map[r + 1][j];
		if (_map[r][j] < ret) ret = _map[r][j];
	}

	// ��
	int i = adjust(_pos[2]);
	for (int c = adjust(_pos[1]); c < adjust(_pos[3]); c++)
	{

		_map[i][c] = _map[i][c + 1];
		if (_map[i][c] < ret) ret = _map[i][c];
	}

	// ��
	j = adjust(_pos[3]);
	for (int r = adjust(_pos[2]); r > adjust(_pos[0]); r--)
	{

		_map[r][j] = _map[r - 1][j];
		if (_map[r][j] < ret) ret = _map[r][j];
	}

	i = adjust(_pos[0]);
	for (int c = adjust(_pos[3]); c > adjust(_pos[1]); c--)
	{

		_map[i][c] = _map[i][c - 1];
		if (_map[i][c] < ret) ret = _map[i][c];
	}

	_map[adjust(_pos[0])][_pos[1]] = temp;

	return ret;
}

vector<int> solution(int _rows, int _columns, vector<vector<int>> _queries)
{

	/*
	
	����, �ùķ��̼�
	*/

	vector<int> answer;
	answer.reserve(_queries.size());

	vector<vector<int>> map;
	GetMap(map, _rows, _columns);

	for (vector<int>& query : _queries)
	{

		int m = Rotate(map, query);
		answer.push_back(m);
	}

	return answer;
}