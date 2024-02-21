#include <vector>

/*
날짜 : 2024. 2. 21
이름 : 배성훈
내용 : 조건에 맞게 수열 변화하기 2
	정수 배열 arr이 주어진다
	arr의 각 원소의 값이 50보다 크거나 같은 짝수라면 2로 나누고,
	50보다 작은 홀수라면 2를 곱하고 1을 더한다

	이러한 작업을 x번 반복한 결과인 배열을 arr(x)라고 표현했을 때,
	arr(x) = arr(x + 1)인 x가 항상 존재한다
	(여기서 =은 컴퓨터에서 쓰는 대입연산자가아니라 같음을 의미하는 기호로 썼다!)
	이러한 x중 가장 작은 값을 return하는 solution 함수 구현
	
*/

using namespace std;

int solution(vector<int> _arr)
{

	int answer = 0;

	vector<int> temp;
	temp.reserve(100);

	for (int i = 1; i <= 100; i++)
	{

		int repeatNum = 0;
		int calc = i;

		while (true)
		{

			if ((calc & 1) && calc < 50)
			{

				calc *= 2;
				calc++;
				repeatNum++;
			}
			else if (!(calc & 1) && calc >= 50)
			{

				calc /= 2;
				repeatNum++;
			}
			else break;
		}
		
		temp.push_back(repeatNum);
	}

	for (const int i : _arr) 
	{

		int chk = temp[i - 1];
		if (chk > answer) answer = chk;
	}

	return answer;
}