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
#define N 9
void solve()
{
    string s;
    cin >> s;
    int w, q;
    cin >> w >> q;
    vector<int> prefixValues = {0};
    vpii values(N, {-1, -1});
    for (int i = 0; i < s.length(); i += 1)
    {
        prefixValues.push_back((s[i] - '0' + prefixValues.back()) % N);
    }
    // debug(prefixValues);
    for (int i = 1; i + w - 1 < prefixValues.size(); i += 1)
    {
        int currentSum = ((prefixValues[i + w - 1] - prefixValues[i - 1] + N) % N);
        if (values[currentSum].first == -1)
        {
            values[currentSum].first = i;
        }
        else if (values[currentSum].second == -1)
        {
            values[currentSum].second = i;
        }
    }
    // debug(values);
    while (q--)
    {
        int l, r, rem;
        cin >> l >> r >> rem;
        int currentSum = (prefixValues[r] - prefixValues[l - 1] + N) % N; // no inverse needed since it's always 1
        // debug(l, r, currentSum);
        vpii possibleValues;
        for (int i = 0; i < N; i += 1)
        {
            for (int j = 0; j < N; j += 1)
            {
                if ((i * currentSum + j) % N == rem)
                {
                    auto &x = values[i];
                    auto &y = values[j];
                    if (i == j)
                    {
                        if (x.first != -1 and x.second != -1)
                        {
                            possibleValues.push_back(x);
                        }
                    }
                    else
                    {
                        if (x.first != -1 and y.first != -1)
                        {
                            possibleValues.push_back({x.first, y.first});
                        }
                    }
                }
            }
        }
        if (possibleValues.size())
        {
            sort(all(possibleValues));
            cout << possibleValues.front().first << " " << possibleValues.front().second << endl;
        }
        else
            cout << -1 << " " << -1 << ln;
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