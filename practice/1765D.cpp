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
// we need video viewing work to be done in paralel as much as possible
// for that start with largest number that has it's smaller pair to fit into same memory
// at max it can be n-1, and will definately depend on input
// take that largest, then it's pair(smallest), taking it always makes space for just smaller number than largest we had taken
// similarly we can make as much pairs as possible till everything from start to end is done
// total cost = (sum of those numbers) given that last video is still to be watched
// remaining cost = remainingCount + remaining(sum) + 1(last video)
void solve()
{
    int n, m;
    cin >> n >> m;
    long long sum = 0, starting = 0;
    vi v(n);
    for (auto &elm : v)
        cin >> elm, sum += elm;
    sort(all(v));
    int prev = 0;
    for (int i = n - 1; i > starting; i -= 1)
    {
        if (v[starting] + v[i] > m)
        {
            sum += 1;
        }
        else
        {
            starting += 1;
        }
    }
    cout << sum + 1 << endl;
}
//##### it is not necessary after we have 1 pair v[0] + v[i] <= m all inner will make such pairs
// for that we need to iterate from end and ones forming pairs are going to be removed just at that time
// something like 2 pointers
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