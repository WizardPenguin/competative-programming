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
class segmentTree
{
    vi t;
    int n;
    void build(vi &a, int v, int tl, int tr)
    {
        // debug(v, tl, tr);
        if (tl == tr)
        {
            t[v] = a[tl];
            return;
        }
        int tm = (tl + tr) / 2;
        build(a, 2 * v, tl, tm);
        build(a, 2 * v + 1, tm + 1, tr);
        t[v] = (t[2 * v] + t[2 * v + 1]);
    }
    int query(int v, int tl, int tr, int l, int r)
    {
        // debug(tl, tr, l, r);
        if (l > r)
            return 0;
        if (tl == l and tr == r)
        {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        // min max are only applied on breaking point of range i.e. tm
        return query(2 * v, tl, tm, l, min(tm, r)) + query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
    }
    void update(int v, int tl, int tr, int pos, int new_val)
    {
        // debug(tl, tr, 0, pos, new_val);
        if (tl == tr)
        {
            t[v] = new_val;
        }
        else
        {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(2 * v, tl, tm, pos, new_val);
            else
                update(2 * v + 1, tm + 1, tr, pos, new_val);
            t[v] = (t[2 * v] + t[2 * v + 1]);
        }
    }

public:
    segmentTree(vector<int> &a, int n) : n(n), t(4 * n + 1, 0)
    {
        build(a, 1, 0, n - 1);
    }
    void change(int id, int new_val)
    {
        update(1, 0, n - 1, id, new_val);
    }
    int find(int l, int r)
    {
        return query(1, 0, n - 1, l, r);
    }
};
void solve()
{
    // just check which side it's less costlier it can't reduce cost more than that
    set<int> st;
    int n;
    cin >> n;
    vi v(n);
    for (int i = 0; i < n; i += 1)
        cin >> v[i], st.insert(v[i]);
    vi data;
    for (auto &elm : st)
    {
        data.push_back(elm);
    }
    vi count(data.size(), 0);
    segmentTree tree(count, data.size());
    // debug(data);
    long long inversions = 0;
    for (int i = 0; i < n; i += 1)
    {
        int id = lower_bound(all(data), v[i]) - data.begin();
        int countLeft = tree.find(0, id - 1);
        int countRight = tree.find(id + 1, data.size() - 1);
        // debug(id, countLeft, countRight);
        inversions += min(countLeft, countRight);
        count[id]++;
        tree.change(id, count[id]);
        // debug(count);
    }
    cout << inversions << endl;
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