#include <vector>

/*
날짜 : 2024. 2. 18
이름 : 배성훈
내용 : 리스트 자르기
	정수 n과 정수 3개가 담긴 리스트 slicer 그리고 정수 여러 개가 담긴 리스트 num_list가 주어진다
	slicer에 담긴 정수를 차례대로 a, b, c라고 할 때, n에 따라 다음과 같이 num_list를 슬라이싱한다

	n = 1, num_list의 0번 인덱스부터 b번 인덱스 까지
	n = 2, num_list의 a번 인덱스부터 마지막 인덱스까지
	n = 3, num_list의 a번 인덱스부터 b번 인덱스까지
	n = 4, num_list의 a번 인덱스부터 b번 인덱스까지 c 간격으로

	올바르게 슬라이싱한 리스트를 return하도록 solution 함수를 완성
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