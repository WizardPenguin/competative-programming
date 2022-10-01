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
#define MOD 998244353
ll power(ll x, ll y, ll M)
{
    if (y == 0)
        return 1;

    ll p = power(x, y / 2, M) % M;
    p = (p * p) % M;

    return (y % 2 == 0) ? p : (x * p) % M;
}
ll modInverse(ll A, ll M)
{
    return power(A, M - 2, M);
}
vector<ll> factorials;
vector<ll> inverse;
void solve()
{
    int n;
    cin >> n;
    int req = n / 2;
    if (req == 1)
    {
        cout << "1 0 1" << endl;
    }
    else
    {
        debug(n);
        ll total = ((factorials[n] * inverse[req]) % MOD) * inverse[req] % MOD;
        debug(total);
        ll toRemove = 0;
        if (req > 1)
        {
            toRemove += (factorials[n - 1] * inverse[req - 1]) % MOD * inverse[n - req] % MOD;
        }
        if (req > 3)
        {
            toRemove += (factorials[n - 4] * inverse[req - 3]) % MOD * inverse[n - req - 1] % MOD;
            toRemove += (factorials[n - 4] * inverse[req - 3]) % MOD * inverse[n - req - 1] % MOD;
            toRemove -= 1;
            toRemove += MOD;
            toRemove %= MOD;
        }
        else if (req == 3)
        {
            toRemove += 2;
        }
        cout << toRemove << " " << (total - toRemove - 1 + MOD) % MOD << " " << 1 << endl;
    }
}
int main()
{
    fast_cin();
    ll test;
    cin >> test;
    ll prev = 1;
    factorials.push_back(1); // 0! = 1
    for (ll i = 1; i <= 60; i += 1)
    {
        prev = prev * i;
        prev %= MOD;
        factorials.push_back(prev);
    }
    // debug(factorials);
    inverse.push_back(1);
    for (int i = 1; i <= 60; i += 1)
    {
        inverse.push_back(modInverse(factorials[i], MOD));
    }
    while (test--)
    {
        solve();
    }
    return 0;
}