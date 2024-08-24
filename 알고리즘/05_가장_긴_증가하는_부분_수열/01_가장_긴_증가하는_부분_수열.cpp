#include <vector>

using namespace std;

inline int BinarySearch(vector<int>& _arr, vector<int>& _lis, int _chk)
{

    /*
    
    �̺� Ž������
    chk���� ���� ���� lis�� ��ִ��� ��ȯ�Ѵ�
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
    
    �ش� ������ �������� �ϴ� ���� �� �����ϴ� �κм����� ã�ư��鼭
    ��ü LIS�� ���̸� ã�´�

    �׸��� LIS �� �ϳ� ã�� ���� �������� �Բ� �����Ѵ�
    lis���� arr�� idx�� �����Ѵ�
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
    
    �������� �̿��� LIS �ϳ��� ã�´�
    */

    // ���� ������ ���� ������ idx�� ã�´�
    for (int i = _lis.size() - 1; i > 0; i--)
    {

        _lis[i - 1] = _prev[_lis[i]];
    }

    // arr�� ������ �ٲ۴�
    for (int i = 0; i < _lis.size(); i++)
    {

        _lis[i] = _arr[_lis[i]];
    }
}