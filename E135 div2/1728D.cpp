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
#define value(i, j) dp[(i)][(j)]
string s;
int dp[2003][2003];
int best(int l, int r)
{
    if (l == 1 or r == 1)
        return 1;
    else if (l == 0 or r == 0)
        return 0;
    return -1;
}
int worst(int l, int r)
{
    if (l == -1 or r == -1)
        return -1;
    else if (l == 0 or r == 0)
        return 0;
    return 1;
}
int check(int choice, int l, int r)
{
    if ((s[l] < s[choice] and value(l + 1, r) < 1) or (s[r] < s[choice] and value(l, r - 1) < 1))
    {
        return -1;
    }
    int ll = 1, rr = 1;
    if (s[l] == s[choice])
        ll = value(l + 1, r);
    else if (value(l + 1, r) == -1)
        ll = -1;
    if (s[r] == s[choice])
        rr = value(l, r - 1);
    else if (value(l, r - 1) == -1)
        ll = -1;
    return worst(ll, rr);
}
void solve()
{
    cin >> s;
    int n = s.length();
    // base case when length of string is 2 at end
    for (int i = 1; i < n; i += 1)
    {
        value(i - 1, i) = (s[i] != s[i - 1]);
    }
    for (int i = 4; i <= n; i += 2)
    {
        for (int j = 0; j + i - 1 < n; j += 1)
        {
            int l = j, r = j + i - 1;
            int res1 = check(l, l + 1, r);
            int res2 = check(r, l, r - 1);
            value(l, r) = best(res1, res2);
        }
    }
    auto res = value(0, n - 1);
    if (res == 1)
    {
        cout << "Alice" << endl;
    }
    else if (res == 0)
    {
        cout << "Draw" << endl;
    }
    else
    {
        cout << "Bob" << endl;
    }
}
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        solve();
    }
}
