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
    string s;
    cin >> s;
    int id = -1;
    for (int i = 0; i < n; i += 1)
    {
        if (s[i] == '1')
        {
            id = i;
            break;
        }
    }
    if (id == -1)
    {
        cout << 0 << endl;
        return;
    }
    string tp = s.substr(id);
    // from this index I can take anything now first first 0 after that
    int zero = -1;
    for (int i = 0; i < n; i += 1)
    {
        if (tp[i] == '0')
        {
            zero = i;
            break;
        }
    }
    if (zero == -1)
    {
        cout << tp << endl;
        return;
    }
    // otherwise first largest xor we can get
    int length = tp.size() - zero;
    string ret = tp;
    for (int i = 0; i < zero; i += 1)
    {
        // take string of size
        string res = tp.substr(0, zero);
        for (int offset = 0; offset < length; offset += 1)
        {
            if (tp[zero + offset] == '1')
            {
                res += '1';
            }
            else if (tp[i + offset] == '1')
            {
                res += '1';
            }
            else
            {
                res += '0';
            }
        }
        ret = max(ret, res);
    }
    cout << ret << endl;
}
int main()
{
    fast_cin();
    solve();
    return 0;
}