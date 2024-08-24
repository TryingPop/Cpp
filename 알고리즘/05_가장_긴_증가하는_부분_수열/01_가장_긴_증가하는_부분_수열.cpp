#include <vector>

using namespace std;

inline int BinarySearch(vector<int>& _arr, vector<int>& _lis, int _chk)
{

    /*
    
    이분 탐색으로
    chk보다 작은 수가 lis에 몇개있는지 반환한다
    */
    int l = 0;
    int r = _lis.size() - 1;

    while (l <= r)
    {

        int mid = (l + r) >> 1;

        if (_arr[_lis[mid]] < _chk) l = mid + 1;
        else r = mid - 1;
    }

    return l;
}

inline void LIS(vector<int>& _arr, vector<int>& _prev, vector<int>& _lis)
{

    /*
    
    해당 지점을 끝점으로 하는 가장 긴 증가하는 부분수열을 찾아가면서
    전체 LIS의 길이를 찾는다

    그리고 LIS 를 하나 찾기 위해 이전값도 함께 저장한다
    lis에는 arr의 idx를 저장한다
    */
    _lis.clear();
    _lis.push_back(0);

    _prev[0] = -1;
    for (int i = 1; i < _arr.size(); i++)
    {

        int idx = BinarySearch(_arr, _lis, _arr[i]);
        if (idx == _lis.size()) _lis.push_back(i);
        else _lis[idx] = i;

        if (idx == 0) _prev[i] = -1;
        else _prev[i] = _lis[idx - 1];
    }
}

inline void GetLIS(vector<int>& _arr, vector<int>& _prev, vector<int>& _lis)
{

    /*
    
    이전값을 이용해 LIS 하나를 찾는다
    */

    // 최장 길이일 때의 수열의 idx를 찾는다
    for (int i = _lis.size() - 1; i > 0; i--)
    {

        _lis[i - 1] = _prev[_lis[i]];
    }

    // arr의 값으로 바꾼다
    for (int i = 0; i < _lis.size(); i++)
    {

        _lis[i] = _arr[_lis[i]];
    }
}