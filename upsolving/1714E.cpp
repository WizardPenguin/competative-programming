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
vector<int> offset = {
    0,
    1,
    0,
    9,
    18,
    0,
    6,
    25,
    14,
    23};
void solve()
{
    int n;
    cin >> n;
    vi v(n);
    bool found = false;
    for (int i = 0; i < n; i += 1)
    {
        cin >> v[i];
        if (v[i] % 5 == 0 or v[i] % 10 == 0)
            found = true;
    }
    if (found)
    {
        set<int> st;
        for (auto &elm : v)
        {
            if (elm % 10 == 0)
                st.insert(elm);
            else
                st.insert(elm + elm % 10);
        }
        if (st.size() == 1)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        return;
    }
    int maxi = *max_element(all(v));
    for (auto &elm : v)
    {
        if (elm + offset[elm % 10] <= maxi)
        {
            elm += offset[elm % 10];
            int remaining = maxi - elm;
            elm += (remaining / 20) * 20;
        }
    }
    // now check weather we can reach to consensus w.r.t each element
    vector<set<int>> data(n);
    for (int i = 0; i < v.size(); i += 1)
    {
        auto &elm = v[i];
        for (int j = 0; j < 8; j += 1)
        {
            data[i].insert(elm);
            elm += elm % 10;
        }
    }
    for (auto &elm : data[0])
    {
        bool found = true;
        for (int i = 1; i < n; i += 1)
        {
            if (not data[i].count(elm))
            {
                found = false;
                break;
            }
        }
        if (found)
        {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
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