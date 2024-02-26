#include <vector>
#include <cmath>

/*
날짜 : 2024. 2. 26
이름 : 배성훈
내용 : 배열의 길이를 2의 거듭제곱으로 만들기
	정수 배열 arr이 매개변수로 주어진다
	arr의 길이가 2의 정수 거듭제곱이 되도록
	arr 뒤에 정수 0을 추가
	arr에 최소한의 개수로 0을 추가한 배열을 
	return하는 solution 함수 구현
*/

using namespace std;

vector<int> solution(vector<int> _arr)
{

	vector<int> answer;

	int log = (int)ceil(log2(_arr.size()));
	int size = pow(2, log);

	answer.reserve(size);

	for (int i = 0; i < _arr.size(); i++)
	{

		answer.push_back(_arr[i]);
	}

	// 남은 부분 0으로 채운다
	answer.resize(size, 0);

	return answer;
}