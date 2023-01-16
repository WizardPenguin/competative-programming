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
// C++ program to find prime factorization of a
// number n in O(Log n) time with precomputation
// allowed.
#include "bits/stdc++.h"
using namespace std;

const int MAXN = 5e5 + 5;
int spf[MAXN];
void sieve()
{
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++)
        spf[i] = i;

    for (int i = 4; i < MAXN; i += 2)
        spf[i] = 2;

    for (long long i = 3; i * i < MAXN; i++)
    {
        if (spf[i] == i)
        {
            for (long long j = i * i; j < MAXN; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}
vector<int> getFactorization(int x)
{
    vector<int> ret;
    while (x != 1)
    {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> visited(n, false);
    vector<int> parent(n, -1);
    vector<set<int>> pm(MAXN);
    vector<vector<int>> f(MAXN);
    sieve();
    for (int i = 0; i < v.size(); i += 1)
    {
        cin >> v[i];
        vector<int> factors;
        if (f[v[i]].size())
            factors = f[v[i]];
        else
            factors = f[v[i]] = getFactorization(v[i]);
        for (auto &elm : factors)
        {
            pm[elm].insert(i);
        }
    }
    int a, b;
    cin >> a >> b;
    a--, b--;
    visited[a] = true;
    vector<int> q = {a};
    auto remove = [&](int node)
    {
        auto &factors = f[v[node]];
        for (auto &fact : factors)
        {
            pm[fact].erase(node);
        }
    };
    remove(a);
    while (not q.empty())
    {
        vector<int> tq;
        for (auto &id : q)
        {
            auto &factors = f[v[id]];
            for (auto &elm : factors)
            {
                for (auto &other : pm[elm])
                {
                    tq.push_back(other);
                    parent[other] = id;
                    visited[other] = true;
                }
                set<int> tp = pm[elm]; // each element is called atmost once
                for (auto &node : tp)  // this removes existance of this element in O(60) at max
                    remove(node);
            }
        }
        swap(q, tq);
    }
    if (not visited[b])
    {
        cout << -1 << endl;
        return;
    }
    vector<int> res = {b};
    while (parent[res.back()] >= 0)
    {
        res.push_back(parent[res.back()]);
    }
    cout << res.size() << endl;
    reverse(res.begin(), res.end());
    for (auto &elm : res)
        cout << elm + 1 << " ";
    cout << endl;
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