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
vpii moves = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
int bfs(vector<string> a)
{
    int n = a[0].length();
    int sx = -1, sy = -1;
    for (int i = 0; i < n; i += 1)
    {
        if (a[0][i] == 'B')
        {
            sx = 0, sy = i;
            break;
        }
        else if (a[1][i] == 'B')
        {
            sx = 1, sy = i;
            break;
        }
    }
    vpii q = {{sx, sy}};
    a[sx][sy] = 'W';
    int count = 1;
    while (not q.empty())
    {
        vpii tp;
        for (auto &[sx, sy] : q)
        {
            for (auto &[dx, dy] : moves)
            {
                auto x = sx + dx;
                auto y = sy + dy;
                if (x >= 0 and x <= 1 and y >= 0 and y < n and a[x][y] == 'B')
                {
                    a[x][y] = 'W';
                    count += 1;
                    tp.push_back({x, y});
                }
            }
        }
        swap(tp, q);
    }
    return count;
}
bool checkConnected(vector<string> &a)
{
    int countb = 0;
    for (auto &ch : a[0])
        countb += (ch == 'B');
    for (auto &ch : a[1])
        countb += (ch == 'B');
    return (bfs(a) == countb);
}
bool checker(vector<string> &a, int start, int end)
{
    return ((a[0][start] == a[0][end]) and (a[0][start] == 'B')) or ((a[1][start] == a[1][end]) and (a[1][start] == 'B'));
}
void solve()
{
    int n;
    cin >> n;
    vs a(2);
    cin >> a[0] >> a[1];
    int i = 0;
    int previous = -1; // just to store which was previous index where we found something
    if (not checkConnected(a))
    {
        cout << "NO" << endl;
        return;
    }
    int st = -1;
    int ed = -1;
    for (int i = 0; i < n; i += 1)
    {
        if (a[0][i] == 'B' or a[1][i] == 'B')
        {
            if (st == -1)
                st = i;
            ed = i + 1;
        }
    }
    while (i < n and (a[0][i] == 'W' and a[1][i] == 'W'))
        i += 1;
    while (i < n)
    {
        int count = 0;
        int start = i;
        while (a[0][i] == 'B' and a[1][i] == 'B')
        {
            i += 1, count += 1;
        }
        if (not count)
        {
            i++;
            continue;
        }
        if (start == st or i == ed)
        {
            continue;
        }
        // debug(start, i, checker(a, start - 1, i));
        if (not((count & 1) ^ checker(a, start - 1, i)))
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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