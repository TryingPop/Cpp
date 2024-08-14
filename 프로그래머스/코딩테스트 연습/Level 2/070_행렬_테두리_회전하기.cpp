/*
날짜 : 2024. 8. 14
이름 : 배성훈
내용 : 행렬 테두리 회전하기
	rows x columns 크기인 행렬이 있습니다.
	행렬에는 1부터 rows x columns까지의 숫자가 
	한 줄씩 순서대로 적혀있다

	이 행렬에서 직사각형 모양의 범위를 여러 번 선택해,
	테두리 부분에 있는 숫자들을 시계방향으로 회전시키려 한다

	각 회전은 (x1, y1, x2, y2)인 정수 4개로 표현하며,
	그 의미는 다음과 같다

	x1행 y1열부터 x2행 y2열까지의 영역에 해당하는
	직사각형에서 테두리에 있는 숫자들을 한 칸씩 시계방향으로 회전한다

	행렬의 세로 길이(행 개수) rows, 가로 길이(열 개수) columns,
	그리고 회전들의 목록 queries가 주어질 때,
	각 회전들을 배열에 적용한 뒤,
	그 회전에 의해 위치가 바뀐 숫자들 중 
	가장 작은 숫자들을 순서대로 배열에 담아 
	return 하는 solution 함수 구현

	rows는 2 이상 100 이하인 자연수
	columns는 2 이상 100 이하인 자연수

	가로 방향으로 숫자가 1부터 하나씩 증가하면서 적힌다

	queries의 행의 개수(회전의 개수)는 1이상 1만 이하

	queries의 각 행은 4개의 정수 { x1, y1, x2, y2 }
	x1행 y1열 부터 x2 y2 열까지 영역의 테두리를 시계방향으로 회전한다는 뜻이다
	열과 행은 1 <= x1 < x2 <= rows, 1 <= y1 < y2 <= columns이다

	모든 회전은 순서대로 이뤄진다

	parameter 
	6, 6, { { 2, 2, 5, 4 },{ 3, 3, 6, 6 },{ 5, 1, 6, 3 } }


	return
	{ 8, 10, 25 }


	sol
	처음 회전은 2행 2열부터 5행 4열에 해당하는 테두리이다

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

	8, 9, 10, 16, 22, 28, 27, 26, 20, 14 가 해당된다
	이들을 시계방향으로 회전하면

		1		2		3		4		5		6
		7	   14		8	    9 	   11	   12
	   13	   20	   15  	   10 	   17	   18
	   19	   26	   21  	   16 	   23	   24
	   25	   27	   28	   22      29	   30
	   31	   32	   33	   34	   35	   36

	이되고 회전한 수 중에 가장 작은 값은 8이다

	3행 3열에서 6행 6열까지 회전시키면 다음과 같다

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

	이 중에서 가장 작은 수는 10이다

	그리고 5행 1열에서 6행 3열까지 구간을 회전시키면 다음과 같다

		1		2		3		4		5		6
		7	   14		8	    9 	   11	   12
	   13	   20	   21  	   15 	   10	   17
	   19	   26	   28  	   16 	   23	   18
	   ------------------
	  |31	   25	   27|	   22      29	   24
	  |32	   34	   33|	   35	   36	   30
	   ------------------

	이 중에 가장 작은 수는 25이다

	그래서 { 8, 10, 25 }
*/


#include <vector>

#define adjust(x) ((x) - 1)
using namespace std;

inline void GetMap(vector<vector<int>>& _map, const int _row, const int _col)
{

	/*
	
	맵 초기 세팅
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
	
	회전하고 이동한 노드 중 가장 작은 값을 반환
	*/
	int temp = _map[adjust(_pos[0])][adjust(_pos[1])];
	int ret = temp;

	// 좌
	int j = adjust(_pos[1]);
	for (int r = adjust(_pos[0]); r < adjust(_pos[2]); r++)
	{

		_map[r][j] = _map[r + 1][j];
		if (_map[r][j] < ret) ret = _map[r][j];
	}

	// 하
	int i = adjust(_pos[2]);
	for (int c = adjust(_pos[1]); c < adjust(_pos[3]); c++)
	{

		_map[i][c] = _map[i][c + 1];
		if (_map[i][c] < ret) ret = _map[i][c];
	}

	// 우
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
	
	구현, 시뮬레이션
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