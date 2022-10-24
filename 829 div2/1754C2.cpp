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
    vi v(n);
    int count = 0;
    for (int i = 0; i < n; i += 1)
        cin >> v[i];
    // just count number of zeros in between
    int i = 0;
    vpii res;
    while (i < n)
    {
        int val = v[i];
        int startId = i + 1;
        if (val == 0)
        {
            while (i < n and v[i] == val)
                i += 1;
            res.push_back({startId, i});
        }
        else
        {
            i += 1;
            if (i == n) // there is not next element
            {
                cout << -1 << endl;
                return;
            }
            int count = 0;
            while (i < n and v[i] == 0) // finding first non-zero number
                i += 1, count += 1;
            if (i == n)
            {
                cout << -1 << endl;
                return;
            }
            if (count % 2 == 0)
            {
                // odd means next number has changed it's parity
                if (val == v[i])
                {
                    res.push_back({startId, i + 1});
                }
                else
                {
                    res.push_back({startId, startId});
                    res.push_back({startId + 1, i + 1});
                }
            }
            else
            {
                if (val == v[i])
                {
                    res.push_back({startId, startId});
                    res.push_back({startId + 1, i + 1});
                }
                else
                {
                    res.push_back({startId, i + 1});
                }
            }
            i += 1;
        }
    }
    cout << res.size() << endl;
    for (auto &[x, y] : res)
    {
        cout << x << " " << y << ln;
    }
    // cout << endl;
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