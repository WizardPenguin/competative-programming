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
vvi pascalsTriangle;
#define MOD 1000000007
void solve()
{
    int n, m;
    cin >> n >> m;
    vi v(n);
    for (auto &elm : v)
        cin >> elm;
    sort(all(v), greater<int>());
    // debug(v);
    int occurence = 0, required = 0;
    for (int i = 0; i < n; i += 1)
    {
        if (v[i] == v[m - 1])
            occurence += 1, required += (i < m);
    }
    // debug(occurence, required);
    cout << pascalsTriangle[occurence][required] << endl;
}
int main()
{
    fast_cin();
    ll test;
    cin >> test;
    pascalsTriangle.push_back({1});
    for (int n = 1; n <= 1000; n += 1)
    {
        vector<int> newT = {1};
        auto &back = pascalsTriangle.back();
        for (int i = 0; i < back.size() - 1; i += 1)
        {
            newT.push_back((back[i] + back[i + 1]) % MOD);
        }
        newT.push_back(1);
        pascalsTriangle.push_back(newT);
    }
    // debug(pascalsTriangle);
    while (test--)
    {
        solve();
    }
    return 0;
}