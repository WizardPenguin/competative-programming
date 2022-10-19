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
    vector<array<int, 3>> tuples(n);
    for (auto &i : tuples)
    {
        for (auto &j : i)
            cin >> j;
    }
    int cost = tuples[0][2];
    int minCost = cost;
    vector<array<int, 3>> lr = {tuples[0]};
    auto [tl, tr, tc] = tuples[0];
    cout << minCost << endl;
    for (int i = 1; i < n; i += 1)
    {
        auto &[l, r, cost] = tuples[i];
        if (l > tl and r < tr)
        {
            continue;
        }
        else if (l < tl or r > tr)
        {
            // it's outside check which side it's outside
            if (l < tl and r > tr)
            {
                lr = {tuples[i]};
                auto [tl, tr, tc] = lr.front();
            }
            else if (l < tl and r <= r)
            {
                tc -= lr.front()[2];
                lr.front() = tuples[i];
                tc += lr[0][2];
                tl = l;
            }
            else if (r > tr and l <= tr)
            {
                tc -= lr.back()[2];
                lr.back() = tuples[i];
                tc += lr.back()[2];
                tr = r;
            }
            else
            {
                // it's new interval to be added
                if (l < tr)
                {
                    lr.insert(lr.begin(), tuples[i]);
                    cost += lr.front()[2];
                    tl = l;
                }
                else
                {
                    lr.push_back(tuples[i]);
                    cost += lr.back()[2];
                    tr = r;
                }
            }
        }
        else
        {
            // there is concergence at edges which are only taken if they gives better cost
            if (tl == l and tr == r)
            {
                if (cost < tc)
                {
                    lr = {tuples[i]};
                    auto [tl, tr, tc] = lr.front();
                }
            }
            else if (tl == l)
            {
                if (cost < lr.front()[2])
                {
                    tc -= lr.back()[2];
                    lr.back() = tuples[i];
                    tc += lr.back()[2];
                }
            }
            else if (tr == r)
            {
                if (cost < lr.back()[2])
                {
                    tc -= lr.front()[2];
                    lr.front() = tuples[i];
                    tc += lr[0][2];
                }
            }
        }
        debug(lr);
        cout << tc << endl;
    }
    cout << endl;
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