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
    vi parent(n + 1);
    vvi graph(n + 1);
    for (int i = 2; i <= n; i += 1)
    {
        cin >> parent[i];
        graph[parent[i]].push_back(i); // directed edge
    }
    vi levelCount;
    vi q = {1};
    int level = 0;
    while (not q.empty())
    {
        levelCount.push_back(q.size());
        vi tp;
        level += 1;
        for (auto &node : q)
        {
            for (auto &nbr : graph[node])
            {
                tp.push_back(nbr);
            }
        }
        swap(q, tp);
    }
    // debug(levelCount);

    // now work by taking optimal breaking point at each step till k allows us to do that
    while (levelCount.size() > 2)
    {
        int sz = levelCount.size();
        // now we want' to have partioning that decreases height by most and giving least cost
        int l, r;
        if (levelCount.size() & 1)
        {
            l = r = (sz + 1) / 2;
        }
        else
        {
            l = sz / 2;
            r = l + 1;
        }
        bool found = false;
        while (r < sz)
        {
            int mini = min(levelCount[l], levelCount[r]);
            if (mini <= k)
            {
                k -= mini;
                found = true;
                break;
            }
            r += 1, l -= 1;
        }
        if (not found)
            break;
        int idc;
        if (levelCount[l] <= levelCount[r])
        {
            idc = l;
        }
        else
        {
            idc = r;
        }
        // debug(idc);
        vi newv;
        for (int i = 0; i < idc; i += 1)
        {
            newv.push_back(levelCount[i]);
        }
        // now add remaining in order from index 1
        int id = 1;
        for (int i = idc; i < sz; i += 1)
        {
            if (id >= newv.size())
            {
                newv.push_back(levelCount[i]);
            }
            else
            {
                newv[id] += levelCount[i];
            }
            id += 1;
        }
        swap(newv, levelCount);
    }
    // debug(levelCount);
    cout << levelCount.size() - 1 << endl;
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