// seems like binary search over solution is better solution
// but how to check weather length l is valid solution or not
// for that we are going to take every number < l and mark then as unuseful
// after then using dp we are going to optimize searching of unuseful numbers in square area
// this takes O(n*m) time at max

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
void __print(int x)
{
    cerr << x;
}
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif
int n, m;
vector<vector<int>> v;
bool check(int l)
{
    auto dp = v;
    // debug(l);
    // finding good and bad elements
    for (auto &elm : dp)
    {
        for (auto &e : elm)
        {
            if (e >= l)
                e = 0;
            else
                e = 1;
        }
    }
    // debug(dp);
    // creating dp for them
    for (int i = 0; i < n; i += 1)
    {
        for (int j = 0; j < m; j += 1)
        {
            if (i)
            {
                dp[i][j] += dp[i - 1][j];
            }
            if (j)
            {
                dp[i][j] += dp[i][j - 1];
            }
            if (i and j)
            {
                dp[i][j] -= dp[i - 1][j - 1];
            }
        }
    }
    // check all possible squares of length l
    for (int i = 0; i + l - 1 < n; i += 1)
    {
        for (int j = 0; j + l - 1 < m; j += 1)
        {
            int ans = dp[i + l - 1][j + l - 1];
            if (i)
            {
                ans -= dp[i - 1][j + l - 1];
            }
            if (j)
            {
                ans -= dp[i + l - 1][j - 1];
            }
            if (i and j)
            {
                ans += dp[i - 1][j - 1];
            }
            if (not ans)
                return true;
        }
    }
    return false;
}
void solve()
{
    cin >> n >> m;
    // debug(n, m);
    v = vector<vector<int>>(n, vector<int>(m, 0));
    for (auto &elm : v)
    {
        for (auto &e : elm)
            cin >> e;
    }
    int l = 1, r = min(n, m);
    while (l < r)
    {
        int mid = (l + r + 1) / 2;
        if (check(mid))
        {
            // try to increase solution
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << r << endl;
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