#include <vector>

/*
날짜 : 2024. 3. 14
이름 : 배성훈
내용 : 소인수분해
	자연수 n이 매개변수로 주어질 때,
	n의 소인수를 오름차순으로 담은 배열을
	return 하는 solution 함수를 구현

	다만 소인수를 중복해서 담지 않는다
	12의 경우 2 * 2 * 3이지만
	2, 3만 제출하면 된다
*/

using namespace std;

vector<int> solution(int _n)
{

	vector<int> answer;

	// 에라토스 테네스의 체 이론
	for (int i = 2; i <= _n; i++) 
	{

		// 여기서 에라토스 테네스의 체이론 이용
		if (i * i > _n) break;
		if (_n % i) continue;

		// 오름차순으로 찾고,
		// 소인수를 모두 제거하기에
		// 찾는 수는 소수가 보장된다
		answer.push_back(i);
		while (!(_n % i))
		{

			_n /= i;
		}
	}

	// 1이 아닌 경우 _n은 소수가 나오고
	// 해당 값을 넣어줘야한다
	if (_n != 1) answer.push_back(_n);
	return answer;
}