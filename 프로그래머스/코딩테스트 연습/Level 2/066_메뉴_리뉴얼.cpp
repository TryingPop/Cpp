/*
날짜 : 2024. 8. 10
이름 : 배성훈
내용 : 메뉴 리뉴얼
	레스토랑을 운영하던 스카피는 코로나19로 인한
	불경기를 극복하고자 메뉴를 새로 구성하려고 고민하고 있다

	기존에는 단품으로만 제공하던 메뉴를 조합해서
	코스요리 형태로 재구성해서 새로운 메뉴를 제공하기로 결정했다

	어떤 단품메뉴들을 조합해서 코스요리 메뉴로 구성하면 좋을지
	고민하던 스카피는 이전에 각 손님들이 주문할 때 가장 많이 함께 주문한
	단품메뉴들을 코스요리 메뉴로 구성하기로 했다

	단 코스요리 메뉴는 최소 2가지 이상의 단품메뉴로 구성하려고 한다
	또한 최소 2명 이상의 손님으로부터 주문된 단품메뉴 조합에 대해서만
	코스요리 메뉴 후보에 포함하기로 했다

	각 손님들이 주문한 단품메뉴들이 문자열 형식으로 담긴 배열 orders,
	스카피가 추가하고 싶어하는 코스요리를 구성하는 단품메뉴들의 갯수가 담긴
	배열 course가 매개변수로 주어질 때,

	스카피가 새로 추가하게 될 코스요리의 메뉴 구성을 문자열 형태로 배열에 담아
	return 하는 solution 함수 구현

	orders 배열의 크기는 2이상 20이하

	orders 배열의 각 원소는 크기가 2 이상 10 이하인 문자열
	각 문자열은 알파벳 대문자로만 이루어져 있다
	각 문자열에는 같은 문자열이 중복해서 들어가 있지 않다

	정답은 각 코스요리 메뉴의 구성을 문자열 형식으로 배열에 담아 사전 순으로
	오름차순 정렬해서 return 해주세요
	배열의 각 원소에 저장된 문자열 또한 알파벳 오름차순으로 정렬되어야 한다
	만약 가장 많이 함께 주문된 메뉴 구성이 여러 개라면, 모두 배열에 담아 return
	orders와 course 매개변수는 return 하는 배열의 길이가 1 이상이 되도록 주어진다

	(단품 메뉴 개수별로 최대 갯수에 해당하는 코스요리만 배열에 담아야 한다)

	parameter
	{ "ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD" }, { 2, 3, 5 }


	return
	{ "ACD", "AD", "ADE", "CD", "XYZ" }


	sol
	2개, 3개, 5개로 구성된 코스요리들을 찾아야한다
	여기서 최소 2명 이상이 먹은 2개짜리 코스요리들을 보면
	"AB", "CD", "AC", "AD", "XY", "YZ", "XZ", "DE", "AE"가 존재하는데
	여기서 "AD", "CD"만 3번이고 나머지는 2번만 먹어 후보에서 탈락된다

	3개짜리 요리도 찾아보면
	"ACD", "ADE", "XYZ"가 있고
	이들 모두 2개이므로 코스요리 후보가 된다

	5개짜리는 "ABCDE"만 유일하고 1명만 먹었으므로 추가하지 않는다

	그래서 결과적으로
	"AD", "CD", "ACD", "ADE", "XYZ"인데 이들을 정렬하면

	"ACD", "AD", "ADE", "CD", "XYZ"
	가 된다
*/

#include <vector>
#include <algorithm>
#include <string>

#if !first
#include <unordered_map>
#endif
using namespace std;

#if first

// 비트마스킹, 백트래킹
vector<int> cnt;				// 비트마스킹해서 사람마다 주문한 요리를 저장
vector<int> chkDepth;			// course 벡터를 idx - val를 val - idx관계로 바꾼 배열
vector<vector<int>> temp;		// idx가지 사용한 코스 요리를 idx에 숫자로 보관하는 임시 배열
vector<int> maxLen;				// course별 최대 사용 횟수

inline void FillCnt(const vector<string>& _orders)
{

	/*
	
	주문한 요리를 비트마스킹해서 숫자로 변환하고
	cnt 배열에 저장
	*/
	for (const string& order : _orders)
	{

		int add = 0;
		for (const char c : order)
		{

			add |= 1 << (c - 'A');
		}

		cnt.push_back(add);
	}
}

inline void ChkDepth(vector<int>& _course)
{

	/*
	
	조합할 단품메뉴 개수를 확인하는 chkDepth배열 채우기
	_couse[idx] = val 관계를
	chkDepth[val] = idx로 바꾼다
	*/
	chkDepth.resize(11, -1);

	for (int i = 0; i < _course.size(); i++)
	{

		chkDepth[_course[i]] = i;
	}
}

inline void DFS(int _depth, int _cur, int _prev, int _escape)
{

	/*
	
	백트래킹으로 
	정답이 되는 코스요리 찾기
	*/

	// 더 이상 탐사할 필요 없다
	if (_depth == _escape) return;

	// 재료 개수
	int match = 0;

	// 메뉴가 적어도 1개 포함되었을 때부터 센다
	if (_depth)
	{

		for (int n : cnt)
		{

			if ((n & _cur) == _cur) match++;
		}

		// 해당 메뉴에서 매칭되는게 2개 이하면 더 탐색할 필요 없다
		// 재료를 늘려봤자 현재 개수를 넘지 못하기 때문이다
		if (match < 2) return;
	}

	// 코스요리에 들어가는 단품메뉴 개수가 
	// 조건에 부합하는 횟수인지 확인
	int idx = chkDepth[_depth];
	if (idx != -1)
	{

		// 부합하는 최대 사람이 갱신되는 경우
		if (maxLen[idx] < match)
		{

			// 이전 음식은 필요없기에 버린다
			temp[idx].clear();
			temp[idx].push_back(_cur);
			maxLen[idx] = match;
		}
		// 같은 경우면 현재 요리만 추가
		else if (maxLen[idx] == match) temp[idx].push_back(_cur);
	}

	// 다음 코스 요리 확인
	for (int i = _prev; i < 26; i++)
	{

		DFS(_depth + 1, _cur | (1 << i), i + 1, _escape);
	}
}

inline void IntToStr(int _num, string& _str)
{

	/*
	
	숫자를 문자열로
	숫자로 저장했기에 문자열로 바꿔줘야 한다
	*/
	_str.clear();

	for (int i = 0; i < 26; i++)
	{

		if (_num & (1 << i)) _str.push_back((char)(i + 'A'));
	}
}
#else

unordered_map<string, int> combi;		// 코스요리, 만족하는 사람 수

inline void DFS(string& _order, int _len, string _temp, int _prev)
{

	/*
	
	주문한 사람에 대해 len개 조합 찾기
	*/
	if (_temp.length() == _len)
	{

		combi[_temp]++;
		return;
	}

	for (int i = _prev; i < _order.length(); i++)
	{

		DFS(_order, _len, _temp + _order[i], i + 1);
	}
}
#endif

vector<string> solution(vector<string> _orders, vector<int> _course)
{

	vector<string> answer;

#if first

	FillCnt(_orders);
	ChkDepth(_course);

	temp.resize(_course.size(), vector<int>());
	maxLen.resize(_course.back(), 0);

	DFS(0, 0, 0, _course.back() + 1);

	string str;
	for (vector<int>& arr : temp)
	{

		for (int num : arr)
		{

			IntToStr(num, str);
			answer.push_back(str);
		}
	}
#else

	for (string& order : _orders)
	{

		// 메뉴 알파벳 순으로 정렬
		sort(order.begin(), order.end());
	}

	for (int len : _course)
	{

		// 이전 길이의 메뉴 제거
		combi.clear();

		for (string& order : _orders)
		{

			// order에서 길이 len인 코스 요리 찾는다
			// 요리에 대해 만족하는 사람 최소 1명은 보장
			DFS(order, len, "", 0);
		}

		// 만족하는 사람의 최대 수
		int maxCnt = 0;
		for (pair<string, int> ele : combi)
		{

			maxCnt = max(maxCnt, ele.second);
		}

		// 2명 이상이 필수이므로 2명 미만이면 넘긴다
		if (maxCnt < 2) continue;

		for (pair<string, int> ele: combi)
		{

			// 해당 메뉴의 최대값 메뉴 answer에 저장
			if (combi[ele.first] == maxCnt) answer.push_back(ele.first);
		}
	}
#endif

	// 반환 조건 맞추기
	sort(answer.begin(), answer.end());

	return answer;
}