#include <bits/stdc++.h>
using namespace std;
#define int long long

constexpr int N = 2e5 + 5;
constexpr int inf = 1e18;

void solve_case()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    vector<vector<int>> dp(n, vector<int>(2, 0));
    if (s[0] == '0')
    {
        dp[0][0] = 0;
    }
    else
    {
        dp[0][0] = a[0];
    }
    dp[0][1] = -inf;

    for (int i = 1; i < n; i++)
    {
        if (s[i] == '1')
        {
            if (s[i - 1] == '0')
            {
                dp[i][1] = max(dp[i][1], a[i - 1] + dp[i - 1][0]);
            }
            else
            {
                dp[i][1] = max(dp[i][1], a[i - 1] + dp[i - 1][1]);
            }
            dp[i][0] = a[i] + max(dp[i - 1][0], dp[i - 1][1]);
        }
        else
        {
            dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
        }
    }

    cout << max(dp[n - 1][0], dp[n - 1][1]) << '\n';
}

int32_t main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    cin >> T;
    while (T-- > 0)
        solve_case();
}