/*
날짜 : 2024. 8. 27
이름 : 배성훈
내용 : 우박수열 정적분
	콜라츠 추측은 로타르 콜라츠(Lothar Collatz)가 1937년에
	추측으로 모든 자연수 k에 대해 대해 다음 작업을 반복하면
	항상 1로 만들 수 있다는 추측이다

	1 - 1. 입력된 수가 짝수라면 2로 나눈다
	1 - 2. 입력된 수가 홀수라면 3을 곱하고 1을 더한다
	2. 결과로 나온 수가 1보다 크다면 1번 작업을 반복한다

	수가 커졌다 작아지기를 반복하는 모습이 비구름에서
	빗방울이 오르락 내리락 하며 우박이 되는 모습과 비슷하다고 하여
	우박수 또는 우박수열로 불리기도 한다

	현재 약 1해까지의 수에서 반례가 없음이 밝혀졌다

	우박수열을 좌표 평면 위에 꺾은선 그래프로 나타내보려고 한다
	초항이 k인 경우 우박수열이 있다면 x = 0일 때 y = k이고
	다음 우박수는 x = 1에 표시한다
	이런 식으로 우박수가 1이 될 때까지 점들을 찍고 
	인접한 점들끼리 직선으로 연결하면 꺾은선 그래프를 만들 수 있다

	이렇게 만든 꺾은선 그래프를 정적분한다
	x에 대한 어떤 범위 a, b가 주어진다면
	이 범위에 대한 정적분 결과는 꺾은선 그래프와
	x = a, x = b, y = 0으로 둘러싸인 공간의 면적가ㅗ 같다

	이것을 우박수열 정적분이라 정의하였고
	다양한 구간에 대해서 우박수열 정적분을 하려고 한다

	0이상의 수 b에대해 { a, -b }에 대한 정적분 결과는
	x = a, x = n - b, y = 0으로 둘러쌓인 공간의 면적으로 정의하며
	여기서 n은 k가 초항인 우박수열이 1이 될때 까지의 횟수를 의미한다

	우박수의 초항 k와, 정적분을 구하느느 구간들의 목록 ranges가 주어질 때,
	정적분의 결과 목록을 return 하는 solution 함수의 구현

	단 주어진 구간의 시작점이 끝점보다 커서 
	유효하지 않은 구간이 주어질 수 있으며 이때의 정적분 결과는 -1로 정의한다

	k는 2이상 1만 이하의 자연수

	ranges의 길이는 1이상 1만 이하의 자연수

	ranges의 원소는 { a, b }형태이며
	a는 200이하의 음이아닌 정수, b는 -200보다 크거나 같은 양이 아닌 정수

	주어진 모든 입력에 대해 정적분 결과는 2^27을 넘지 않는다


	parameter
	5, { { 0, 0 }, { 0, -1 }, { 2, -3 }, { 3, -3 } }


	return
	{ 33, 31.5, 0, -1 }


	sol
	5의 우박수열은 5, 16, 8, 4, 2, 1
	
	그래프에서 꺾이는 지점을 경계로 5개의 구역의 넓이를 구하면 각각
	10.5, 12, 6, 3, 1.5이다

	그리고 ranges의 각 x의 구간은
	[0, 5], [0, 4], [2, 2], [3, 2]이고 각각 누적합으로 구하면 된다
	여기서 [3, 2]는 유효하지 않은 구간이므로 -1이다
*/

#include <vector>

using namespace std;

inline int Collatz(int _num)
{

	/*
	
	다음 콜라츠 수
	*/
	return (_num & 1) ? (_num * 3 + 1) : (_num >> 1);
}

inline void SetArea(int _k, vector<double>& _area)
{

	/*
	
	면적을 누적합으로 구해준다
	*/

	// 먼저 우박수열 찾는다
	vector<int> y;
	y.push_back(_k);
	while (_k != 1)
	{

		_k = Collatz(_k);
		y.push_back(_k);
	}

	// 각 구간의 면적을 찾는다
	_area.reserve(y.size());
	_area.push_back(0.0);

	for (int i = 1; i < y.size(); i++)
	{

		int m = y[i] + y[i - 1];
		_area.push_back(m / 2.0);
	}

	// 연속된 구간의 면적이므로
	// 매번 구간의 범위를 더해주지 않기위해
	// 연속된 구간의 누적합을 구한다
	for (int i = 1; i < _area.size(); i++)
	{

		_area[i] += _area[i - 1];
	}
}

vector<double> solution(int _k, vector<vector<int>> _ranges)
{

	/*
	
	수학, 누적합
	*/
	vector<double> answer;
	vector<double> area;

	SetArea(_k, area);

	int end = area.size() - 1;
	for (vector<int>& range : _ranges)
	{

		int f = range[0];
		int b = end + range[1];

		double ret = f <= b ? area[b] - area[f]: -1.0;

		answer.push_back(ret);
	}

	return answer;
}