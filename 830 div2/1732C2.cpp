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
    // try first 30 and last 30 indices removal from full array and return result
    // we can reduce size of our subarray only if xor += val, sum += val by same amount when it's taken
    // 0 can be removed with any frequency, but we have constraint on non-zero numbers
    // xor,sum has same effect only when all bits of number are added first time
    // we can try for all 30 possibilities on left and right side , (also their combination)
    // and work on them
    int n, q;
    cin >> n >> q;
    vi v(n);
    for (int i = 0; i < n; i += 1)
    {
        cin >> v[i];
    }
    vll sum(n, 0);
    vi zor(n, 0);
    sum[0] = zor[0] = v[0];
    for (int i = 1; i < n; i += 1)
    {
        sum[i] = (v[i] + sum[i - 1]);
        zor[i] = (zor[i - 1] ^ v[i]);
    }
    vi nonZeros;
    for (int i = 0; i < n; i += 1)
    {
        if (v[i])
            nonZeros.push_back(i);
    }
    while (q--)
    {
        int x, y, sid, eid, st, et;
        cin >> x >> y; // this is range where we need to work on
        sid = lower_bound(all(nonZeros), x - 1) - nonZeros.begin();
        n = upper_bound(all(nonZeros), y - 1) - nonZeros.begin();
        if (sid >= n)
        {
            cout << x << " " << x << ln;
            continue;
        }
        pii res = {0, 0};
        ll maxi = 0;
        for (sid, st = 0; sid < n and st < 31; sid += 1, st += 1)
        {
            int start = nonZeros[sid];
            ll toRemove = ((start) ? sum[start - 1] : 0);
            ll toRemovez = ((start) ? zor[start - 1] : 0);
            for (eid = n - 1, et = 0; eid >= sid and et < 32; eid -= 1, et += 1)
            {
                int end = nonZeros[eid];
                ll currents = sum[end] - toRemove;
                ll currentz = zor[end] ^ toRemovez;
                // debug(currents, currentz);
                if (maxi < currents - currentz)
                {
                    maxi = currents - currentz;
                    res = {start + 1, end + 1};
                }
                else if (maxi == currents - currentz)
                {
                    // if this is of smaller size then take it
                    int curSize = end - start + 1;
                    int prevSize = res.second - res.first + 1;
                    if (curSize <= prevSize)
                    {
                        res = {start + 1, end + 1};
                    }
                }
            }
        }
        cout << res.first << " " << res.second << ln;
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