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
class DSU
{
    vector<int> parent;

public:
    DSU() : parent(26, -1) {}
    int find(int x)
    {
        if (parent[x] == -1)
            return x;
        return parent[x] = find(parent[x]);
    }
    bool join(int x, int y)
    {
        int px = find(x);
        int py = find(y);
        if (px == py)
        {
            return false;
        }
        parent[x] = y; // make them connected
        return true;
    }
};
void solve()
{
    int n;
    cin >> n;
    string s, res;
    cin >> s;
    DSU dsu;
    // for each element we can give other pair to connect if it has no connected edge of that kind
    // let adding i,j they shound't be already connected
    // i,i are considered connected
    map<char, char> mp;
    vi visited(26, false);
    for (auto &ch : s)
    {
        if (mp.find(ch) == mp.end())
        {
            int toJoin = -1;
            int other = ch - 'a';
            for (int i = 0; i < 26; i += 1)
            {
                if (not visited[i] and dsu.join(i, other))
                {
                    visited[i] = true;
                    toJoin = i;
                    break;
                }
            }
            if (toJoin == -1) // last cycle is valid cycle since all characters has been considered
            {
                for (int i = 0; i < 26; i += 1)
                {
                    if (not visited[i])
                    {
                        toJoin = i;
                        break;
                    }
                }
            }
            mp[ch] = char(toJoin + 'a');
        }
        res += mp[ch];
    }
    cout << res << endl;
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
