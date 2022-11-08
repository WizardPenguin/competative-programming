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
vector<pair<int, int>> steps;
void find(string &a, string &b)
{ // we have all opposite parities
    // now find remaining steps;
    int n = a.length();
    if (a[0] == '1')
    {
        // find components of 0's and convert them to 1's
        int i = 0;
        while (i < n)
        {
            while (i < n and a[i] == '1')
                i += 1;
            // now it's component of 0's
            if (i == n)
            {
                steps.push_back({1, 1});
                steps.push_back({2, n});
                return;
            }
            auto id = i;
            while (i < n and a[i] == '0')
                i += 1;
            steps.push_back({id + 1, i + 1}); // invert over all 0's
        }
        steps.push_back({1, 1});
        steps.push_back({2, n});
    }
    else
    {
        int i = 0;
        int count = 0;
        while (i < n)
        {
            while (i < n and a[i] == '0')
                i += 1;
            // now it's component of 0's
            if (i == n)
            {
                if (not(count & 1))
                {
                    steps.push_back({1, 1});
                    steps.push_back({2, 2});
                    steps.push_back({1, 2});
                }
                return;
            }
            auto id = i;
            while (i < n and a[i] == '1')
                i += 1;
            steps.push_back({id + 1, i}); // invert over all 0's
            count += 1;
        }
        if (not(count & 1))
        {
            steps.push_back({1, 1});
            steps.push_back({2, 2});
            steps.push_back({1, 2});
        }
    }
    return;
}
void solve()
{
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    steps.clear();
    int count = 0;
    int count1 = 0;
    for (int i = 0; i < n; i += 1)
    {
        count += (a[i] == b[i]);
        count1 += (a[i] == '1' and (a[i] == b[i]));
    }
    if (count1 == n)
    {
    }
    else if (count1 == 0)
    {
    }
    else if (count == n)
    {
        if (a[0] == '1')
        {
            a[0] = '0';
            b[0] = '1'; // since these are all same
            for (int i = 1; i < n; i += 1)
            {
                b[i] = '0';
            }
        }
        else if (a[0] == '0')
        {
            a[0] = '1';
            b[0] = '0'; // since these are all same
            for (int i = 1; i < n; i += 1)
            {
                b[i] = '1';
            }
        }
        steps.push_back({1, 1});
        find(a, b);
    }
    else if (count == 0) // no one is same
    {
        find(a, b);
    }
    else
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    cout << steps.size() << endl;
    for (auto &[x, y] : steps)
    {
        cout << x << " " << y << endl;
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