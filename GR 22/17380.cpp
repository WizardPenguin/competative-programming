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
    vll type(n), value(n);
    ll sum = 0;
    for (auto &elm : type)
    {
        cin >> elm;
    }
    for (auto &elm : value)
        cin >> elm;
    vvll pairs(2);
    for (int i = 0; i < n; i += 1)
    {
        pairs[type[i]].push_back(value[i]);
        sum += value[i];
    }
    sort(all(pairs[0]), greater<int>());
    sort(all(pairs[1]), greater<int>());
    debug(pairs);
    int x = pairs[0].size();
    int y = pairs[1].size();
    if (not x or not y)
    {
        cout << sum << endl;
        return;
    }
    int i = 0, j = 0;
    ll ans1 = 0, ans2 = 0;
    do
    {
        if (j < y)
            ans1 += pairs[1][j];
        if (i < x - 1)
        {
            ans1 += pairs[0][i];
        }
        i++, j++;
    } while (j < y and i < x);
    i = 0, j = 0;
    do
    {
        if (i < x)
            ans2 += pairs[0][i];
        if (j < y - 1)
        {
            ans2 += pairs[1][j];
        }
        i++, j++;
    } while (j < y and i < x);
    debug(ans1, ans2);
    cout << sum + max(ans1, ans2) << endl;
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