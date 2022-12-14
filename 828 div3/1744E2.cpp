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
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    vll fa, fb;
    for (ll i = 1; i * i <= a; i += 1)
    {
        if (a % i == 0)
        {
            fa.push_back(i);
            fa.push_back(a / i);
        }
    }
    for (ll i = 1; i * i <= b; i += 1)
    {
        if (b % i == 0)
        {
            fb.push_back(i);
            fb.push_back(b / i);
        }
    }
    // debug(fa);
    // debug(fb);
    for (auto &elm : fa)
    {
        for (auto &elm2 : fb)
        {
            // find nearest factor of fa or fb in rang a-c or b-d
            // also their consecutive pair should have it's factor in range b-d
            ll fn = elm2 * elm;
            ll sn = (a * b) / fn;
            ll afn = (a / fn + 1) * fn;
            ll asn = (a / sn + 1) * sn;
            ll bfn = (b / fn + 1) * fn;
            ll bsn = (b / sn + 1) * sn;
            if (afn <= c and bsn <= d)
            {
                cout << afn << " " << bsn << endl;
                return;
            }
            else if (asn <= c and bfn <= d)
            {
                cout << asn << " " << bfn << endl;
                return;
            }
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