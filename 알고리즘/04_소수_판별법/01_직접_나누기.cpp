#define ll long long

inline bool TrialDivision(ll _num)
{

	for (ll i = 2; i * i <= _num; i++)
	{

		if (_num % i) continue;
		return false;
	}

	return true;
}