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
pair<long long, long long> check(int a, int b)
{
    if (a < b)
        swap(a, b); // a be sum (x + y)
    int sum = a + b;
    int x = sum / 2;
    int y = a - x;
    swap(x, y);
    return {x, y};
}
bool checkSquare(long long a)
{
    long long s = sqrtl(a);
    return (s * s) == a;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &elm : v)
        cin >> elm;
    int ans = 1;
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i += 1)
    {
        for (int j = i + 1; j < n; j += 1)
        {
            int diff = v[j] - v[i];
            // find all factors and then check weather it's in form a-b, a+b , if yes
            for (int x = 1; x * x <= diff; x += 1)
            {
                if (diff % x == 0)
                {
                    auto ret = check(x, diff / x);
                    int count = 0;
                    if (ret.first * ret.first >= v[i])
                    {
                        long long x = ret.first * ret.first - v[i];
                        for (auto &elm : v)
                        {
                            count += checkSquare(elm + x);
                        }
                    }
                    ans = max(ans, count);
                }
            }
        }
    }
    cout << ans << endl;
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