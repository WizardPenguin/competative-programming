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
// check for characters which are still not written on board
int findNearestUnknown(set<int> &st, int ending)
{
    while (st.find(ending) != st.end())
        ending -= 1;
    return ending; // finding largest unknown <= ending
}
void increase(set<int> &st, vector<int> &v, int mod)
{ // increase might cause changes recursively
    st.insert(0);
    int formed = 1;
    for (int i = v.size() - 2; i >= 0; i -= 1)
    {
        formed += v[i];
        if (formed >= mod)
        {
            formed = 1;
        }
        else
            break;
    }
    debug(formed);
    st.insert(formed);
}
void solve()
{
    int n, b;
    cin >> n >> b;
    debug(n, b);
    vector<int> v(n);
    set<int> st;
    for (auto &elm : v)
        cin >> elm, st.insert(elm);
    int unknown = findNearestUnknown(st, b - 1);
    if (unknown == -1)
    {
        cout << 0 << endl;
    }
    else if (unknown < v.back())
    {
        // we need complete iteration causes increase in previous number by 1
        debug("smaller");
        int steps = b - v.back();
        debug(steps);
        increase(st, v, b);
        unknown = findNearestUnknown(st, v.back());
        steps += max(0, unknown);
        debug(unknown);
        cout << steps << endl;
    }
    else
    {
        // TRY TO REACH LARGEST UNKNOWN
        debug("larger");
        int steps = unknown - v.back();
        unknown = findNearestUnknown(st, v.back()); // check weather we are done here
        if (unknown == -1)
        {
            cout << steps << endl;
            return;
        }
        steps = b - v.back();
        increase(st, v, b);
        unknown = findNearestUnknown(st, v.back());
        steps += max(0, unknown);
        cout << steps << endl;
    }
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