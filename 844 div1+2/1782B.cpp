#include <bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        int elm;
        map<int, int> mp;
        for (int i = 0; i < n; i += 1)
            cin >> elm, mp[elm] += 1;
        int prev = 0;
        int ans = (mp[0] == 0);
        for (auto &[elm, count] : mp)
        {
            prev += count;
            if (prev > elm)
            {
                if (mp.upper_bound(elm) != mp.end())
                {
                    ans += (mp.upper_bound(elm)->first > prev);
                }
                else
                {
                    ans += 1; // we don't have next element but this is still good
                }
            }
        }
        cout << ans << endl;
    }
}