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
    int m, s;
    cin >> m >> s;
    // we need length m
    if (s == 0)
    {
        if (m == 1)
        {
            cout << "0 0" << endl;
        }
        else
        {
            cout << "-1 -1" << endl;
        }
    }
    else
    {
        int minLength = (s + 8) / 9;
        // debug(minLength);
        if (m < minLength)
        {
            cout << "-1 -1" << endl;
            return;
        }
        // try forming largest number
        vi largest, smallest;
        auto tp = s;
        while (s)
        {
            largest.push_back(min(s, 9));
            s -= min(s, 9);
        }
        while (largest.size() < m)
        {
            largest.push_back(0);
        }

        // try to form smallest number
        // add 1 till we have goodness w.r.t length
        s = tp;
        if (m == minLength)
        {
            smallest = largest;
            reverse(all(smallest));
        }
        else
        {
            smallest.push_back(1);
            s -= 1;
            while ((m - smallest.size()) > (s + 8) / 9) // required length should be > remaining
            {
                smallest.push_back(0);
            }
            if (s % 9)
                smallest.push_back(s % 9);
            while (s >= 9)
            {
                smallest.push_back(9);
                s -= 9;
            }
        }
        // now print both
        for (auto &ch : smallest)
            cout << ch;
        cout << " ";
        for (auto &ch : largest)
            cout << ch;
        cout << " ";
    }
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