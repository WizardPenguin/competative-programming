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
void solve()
{
    int n;
    cin >> n;
    vs v(n);
    for (auto &elm : v)
        cin >> elm;
    // now we want to find min operation for each strip in row and column extracted from outside
    // first strip of length n on all 4 sides, 2nd of length n-2 .... needs to be made equal so direction don't matter
    int steps = 0;
    int lr, rr, lc, rc;
    lr = lc = 0;
    rr = rc = n - 1;
    while (rc > lc and rr > lr)
    {
        vector<int> count(n, 0);
        for (int i = lc + 1; i < rc; i += 1)
        {
            count[i] += (v[lr][i] == '1');
        }
        for (int i = lr + 1; i < rr; i += 1)
        {
            count[i] += (v[i][rc] == '1');
        }
        for (int i = rc - 1; i > lc; i -= 1)
        {
            count[n - 1 - i] += (v[rr][i] == '1');
        }
        for (int i = rr - 1; i > lr; i -= 1)
        {
            count[n - 1 - i] += (v[i][lc] == '1');
        }
        int diagCount = (v[lr][lc] == '1') + (v[rr][lc] == '1') + (v[lr][rc] == '1') + (v[rr][rc] == '1');
        for (auto &elm : count)
        {
            steps += min(elm, 4 - elm);
        }
        steps += min(diagCount, 4 - diagCount);
        // debug(rc, lc, rr, lr, steps);
        rc--, lc++;
        rr--, lr++;
    }
    cout << steps << endl;
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