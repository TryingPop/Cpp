/*
날짜 : 2024. 6. 28
이름 : 배성훈
내용 : n^2 배열 자르기
	정수 n, left, right가 주어진다
	다음 과정을 거쳐서 1차원 배열을 만든다
		1. n행 n열 크기의 비어있는 2차원 배열을 만든다
		2. i = 1, 2, 3, ..., n에 대해 다음 과정을 반복한다
			1행 1열부터 i행 i열까지의 영역내의 모든 빈 칸을 숫자 i로 채운다
		3. 1행, 2행, ..., n행을 잘라내어 모두 이어붙인 새로운 1차원 배열을 만든다
		4. 새로운 1차원 배열을 arr이라 할 때,
			arr[left], arr[left + 1], ... , arr[right]만 남기고 나머지를 지운다

	해당 과정을 거쳐 만들어진 1차원 배열을
	return 하는 solution 함수 구현

	n은 10^7 이하의 자연수
	left <= right이고, right는 n^2보다 작다
	right - left 는 10만 미만이다


	parameter
	3, 2, 5


	return
	{ 3, 2, 2, 3 }


	sol
	3크기의 2차원 배열을 만들면 다음과 같다
		1 2 3
		2 2 3
		3 3 3
	그리고 1차원 배열로 나열하면
		1 2 3 2 2 3 3 3 3
	여기서 2번부터 5번까지는
		3 2 2 3
*/

#include <string>
#include <vector>

using namespace std;

typedef long long ll;

vector<int> solution(int _n, ll left, ll right)
{

	vector<int> answer;
	int len = right - left + 1;
	answer.reserve(len);

	ll row, col;
	for (ll i = left; i <= right; i++) 
	{

		row = left / _n;
		col = right % _n;

		answer.push_back(max(row, col) + 1);
	}

	return answer;
}