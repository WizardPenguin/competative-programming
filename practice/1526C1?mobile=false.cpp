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
bool checkAndMake(vll &v, int i, vi &elms)
{
    for (int x = i; x < elms.size(); x += 1)
    {
        ll prevSum = v[x + 1] + elms[i];
        if (prevSum < 0)
            return false;
    }
    // it's good to take this number so better take it
    for (int x = i; x < elms.size(); x += 1)
    {
        v[x + 1] += elms[i];
    }
    return true;
}
void solve()
{
    int n;
    cin >> n;
    vi v(n);
    for (auto &elm : v)
        cin >> elm;
    vll pref(n + 1, 0);
    map<int, vector<int>> negatives;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int take = 0;
        if (v[i] >= 0)
        {
            take = v[i];
            ans += 1;
        }
        else
        {
            negatives[v[i]].push_back(i);
        }
        pref[i + 1] += (pref[i] + take);
    }
    // we have -ve numbers sorted by their values, smaller on first
    // it's optimal to take that smallest -ve number first irrespective of it's position
    // it will be taken only if its passes till last +ve number otherwise it'll decrease solution, better try other ones
    for (auto it = negatives.rbegin(); it != negatives.rend(); it++)
    {
        auto &ids = it->second;
        for (auto &id : ids)
        {
            ans += checkAndMake(pref, id, v);
        }
    }
    cout << ans << endl;
}
int main()
{
    fast_cin();
    ll test = 1;
    while (test--)
    {
        solve();
    }
    return 0;
}