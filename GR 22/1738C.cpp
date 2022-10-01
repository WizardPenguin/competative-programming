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
#define val dp[odd][even][previous][turn]
int dp[102][102][2][2];
bool recursive(int odd, int even, int previous, int turn = 1)
{ // previuos shows parity of sum at alice till now
    if (not odd and not even)
        return (previous == 0);
    if (val != -1)
        return val;
    if (turn)
    {
        int count = 0;
        if (odd)
        {
            int ret = recursive(odd - 1, even, 1 - previous, 1 - turn);
            count += ret;
        }
        if (even)
        {
            int ret = recursive(odd, even - 1, previous, 1 - turn);
            count += ret;
        }
        return val = count;
    }
    else
    {
        int count = 0;
        if (odd)
        {
            int ret = recursive(odd - 1, even, previous, 1 - turn);
            count += 1 - ret;
        }
        if (even)
        {
            int ret = recursive(odd, even - 1, previous, 1 - turn);
            count += 1 - ret;
        }
        return val = (not count);
    }
}
void solve()
{
    int n;
    cin >> n;
    vi v(n);
    for (int i = 0; i < n; i += 1)
        cin >> v[i];
    int countO = 0;
    for (int i = 0; i < n; i += 1)
    {
        countO += (v[i] & 1);
    }
    // we have odd elements to work with
    for (int i = 0; i < 102; i += 1)
    {
        for (int j = 0; j < 102; j += 1)
        {
            for (int k = 0; k < 2; k += 1)
            {
                for (int l = 0; l < 2; l += 1)
                {
                    dp[i][j][k][l] = -1;
                }
            }
        }
    }
    if (recursive(countO, n - countO, 0))
    {
        cout << "Alice" << endl;
    }
    else
    {
        cout << "Bob" << endl;
    }
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