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
ll start(ll prod, ll rt)
{
    // find value such that prod/val <= right
    ll left = 1, right = 1e9;
    while (left < right)
    {
        ll mid = (left + right) / 2;
        if (prod / mid <= rt)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    if (prod / right <= rt)
        return right;
    return 1000000007;
}
void solve()
{
    // we need factors of a*b such that both a <= 1e9 and b <= 1e9
    // so find first x such that a*b/x <= 1e9 , from there take all x
    // similarly try to fix y and find possible values of x iteratively
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll prod = a * b;
    ll st = start(prod, d + 1); // try guessing value of x
    for (ll i = max(st, a + 1); i <= c; i += 1)
    {
        if (prod / i < a)
            break;
        ll numberFormed = (a * b) / (__gcd(a * b, i));
        ll nearest = ((b + numberFormed) / numberFormed) * numberFormed;
        if (nearest <= d)
        {
            cout << i << " " << nearest << endl;
            return;
        }
    }
    st = start(prod, c + 1);
    for (ll i = max(st, b + 1); i <= d; i += 1)
    {
        if (prod / i < c)
            break;
        ll numberFormed = (a * b) / (__gcd(a * b, i));
        ll nearest = ((a + numberFormed) / numberFormed) * numberFormed;
        if (nearest <= c)
        {
            cout << i << " " << nearest << endl;
            return;
        }
    }
    cout << -1 << " " << -1 << endl;
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