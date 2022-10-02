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
    int n, k;
    cin >> n >> k;
    vvi v(n, vi(k));
    map<vi, int> mp;
    for (int i = 0; i < n; i += 1)
    {
        for (int j = 0; j < k; j += 1)
            cin >> v[i][j];
        mp[v[i]] = i;
    }
    vector<int> count(n, 0);
    for (int i = 0; i < n; i += 1)
    {
        for (int j = i + 1; j < n; j += 1)
        {
            vi tp(k);
            for (int t = 0; t < k; t += 1)
            {
                if (v[i][t] == v[j][t])
                    tp[t] = v[i][t];
                else
                    tp[t] = 3 - v[i][t] - v[j][t];
            }
            // now we have pairing elements for elements i,j
            if (mp.find(tp) != mp.end())
            {
                count[i] += 1;
                count[j] += 1;
                count[mp[tp]] += 1;
                // cout << i << " " << j << " " << mp[tp] << endl;
            }
        }
    }
    long long ans = 0;
    for (auto &elm : count)
    {
        long long cnt = elm / 3;
        ans += cnt * (cnt - 1) / 2;
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