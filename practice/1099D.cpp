// for each element = -1
// it's all childs should have same value
// if that values == -1 then they don't contribute to sum
// otherwise we can decide value for root of subtree in a deterministic way
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
vvi tree;
vi weights;
bool found = true;
int recursive1(int node, int parentSum, int prefixSum = 0)
{
    if (parentSum == -1)
    {
        // means we already have value for this node which is prefix sum pass it to child
        for (auto &child : tree[node])
        {
            recursive1(child, 0, weights[node]);
        }
    }
    else
    {
        // we need to compute prefix sum for this node, for that first find child's prefix sum
        if (tree[node].size() == 0)
        {
            // means no child so prefix sum = same as parent's prefix sum
            return weights[node] = prefixSum;
        }
        weights[node] = weights[tree[node].back()];
        for (auto &child : tree[node])
        {
            if (weights[child] != weights[node])
                found = false;
        }
        weights[node] = prefixSum + weights[node] - prefixSum;
        for (auto &child : tree[node])
        {
            recursive1(child, -1, weights[node]);
        }
    }
    return weights[node];
}
vi newWeights;
void recursive2(int node, int parentSum)
{
    newWeights[node] = weights[node] - parentSum;
    if (newWeights[node] < 0)
        found = false;
    for (auto &child : tree[node])
    {
        recursive2(child, weights[node]);
    }
}
void solve()
{
    int n;
    cin >> n;
    int par;
    tree = vvi(n);
    weights = vi(n);
    newWeights = vi(n);
    for (int i = 1; i < n; i += 1)
    {
        cin >> par;
        tree[par - 1].push_back(i);
    }

    for (int i = 0; i < n; i += 1)
        cin >> weights[i];
    recursive1(0, -1);
    recursive2(0, 0);
    if (not found)
    {
        cout << -1 << endl;
        return;
    }
    cout << accumulate(all(newWeights), 0) << endl;
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