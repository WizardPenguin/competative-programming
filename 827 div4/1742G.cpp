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
// we just need prefix OR to be lexiographically largest
// simply means we need largest set bit giving element on front
// if we have many such numbers then compare on 2nd largest bit till we have single number
// place it
// then again do for other non visited bits
// steps goes at most 32 times over all array of size N , means under time limit
int ans = -1;
void solve()
{
    int n;
    cin >> n;
    vi v(n);
    for (int i = 0; i < n; i += 1)
    {
        cin >> v[i];
    }
    vector<int> res;
    vector<int> visited(n, false);
    vector<int> bits(32, false);
    while (true)
    {
        // first iteration is to get largest ON bit
        vector<int> toWork;
        int i = 0;
        for (i = 32 - 1; i >= 0; i -= 1)
        {
            vector<int> formed;
            if (bits[i])
                continue;
            for (int elm = 0; elm < n; elm += 1)
            {
                if (v[elm] & (1 << i))
                {
                    formed.push_back(elm);
                }
            }
            bits[i] = true;
            if (formed.size())
            {
                swap(formed, toWork);
                break;
            }
        }
        while (i >= 0)
        {
            if (bits[i])
            {
                i--;
                continue;
            }
            vector<int> newFormed;
            for (auto &id : toWork)
            {
                if (v[id] & (1 << i))
                {
                    bits[i] = true; // we don't need this bit again sinc OR doesn't makes difference
                    newFormed.push_back(id);
                }
            }
            if (newFormed.size())
                swap(newFormed, toWork);
            i--;
        }
        // now take 1 element from remaining work
        if (not toWork.size())
            break;
        visited[toWork[0]] = true;
        res.push_back(v[toWork[0]]);
    }
    for (auto &elm : res)
    {
        cout << elm << " ";
    }
    for (int i = 0; i < n; i += 1)
    {
        if (not visited[i])
            cout << v[i] << " ";
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