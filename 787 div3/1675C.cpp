#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
	string s;
	cin >> s;

	int first_zero = -1, last_one = -1;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '1') last_one = i;
		if (s[i] == '0' && first_zero == -1) {
			first_zero = i;
		}
	}

	if (last_one == -1 && first_zero == -1) {
		cout << s.size() << "\n";
		return;
	}
	if (last_one != -1 && first_zero != -1 && first_zero > last_one) {
		cout << first_zero - last_one + 1 << "\n";
		return;
	}
	if (last_one != -1 && first_zero != -1 && first_zero < last_one) {
		cout << 1 << "\n";
		return;
	}
	if (last_one != -1) {
		cout << s.size() - last_one << "\n";
		return;
	}
	if (first_zero != -1) {
		cout << first_zero + 1 << "\n";
	}
}

int32_t main()
{
	int t = 1;
	cin >> t;

	while (t--)
	{
		solve();
	}
	return 0;
}