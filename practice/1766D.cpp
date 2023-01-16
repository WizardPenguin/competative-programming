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
#define N 10000007
void solve()
{
    // find after how many steps first/smaller number is multiple of difference
    // loop works in NlogN time
    // about 1e8 or 2s at max
    // for every number 1e6 we are dealing with all it's prime factors about power(n,2/3) seem in complexity
    int n;
    cin >> n;
    vector<int> data(n);
    vector<list<int>> ids(N);
    for (int i = 0; i < n; i += 1)
    {
        int x, y;
        cin >> x >> y;
        data[i] = y;
        ids[y - x].push_back(i);
    }
    vector<int> solution(n, INT_MAX);
    bitset<N> b(0);
    for (int i = 2; i < N; i += 1)
    {
        if (b[i] == 0)
        {
            for (int j = i; j < N; j += i)
            {
                for (auto &id : ids[j])
                {
                    solution[id] = min(solution[id], ((data[id] + i - 1) / i) * i);
                }
                b[j] = 1;
            }
        }
    }
    for (int i = 0; i < n; i += 1)
    {
        if (solution[i] == INT_MAX)
            cout << -1 << '\n';
        else
            cout << solution[i] - data[i] << '\n';
    }
}
int main()
{
    fast_cin();
    solve();
    return 0;
}