#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef vector<vector<pll>> vvpll;
typedef vector<pll> vpll;
typedef vector<pii> vpii;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<vector<bool>> vvb;
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

void solve()
{
    int l, r;
    cin >> l >> r;
    vector<int> original(32, 0), newCount(32, 0);
    for (int i = l; i <= r; i += 1)
    {
        auto tp = i;
        int it = 0;
        while (tp)
        {
            if (tp & 1)
                original[it] += 1;
            tp >>= 1;
            it += 1;
        }
        cin >> tp;
        it = 0;
        while (tp)
        {
            if (tp & 1)
                newCount[it] += 1;
            tp >>= 1;
            it += 1;
        }
    }
    int res = 0;
    for (int i = 0; i < 32; i += 1)
    {
        if (original[i] != newCount[i])
        {
            res += (1 << i);
        }
    }
    cout << res << endl;
}
int main()
{
    fast_cin();
    ll test;
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}