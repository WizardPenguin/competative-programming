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
// this can be taken down to most frequent prefix sum in this range as solution
int maxZeros(vector<int> &v, int zeroId, int endingId)
{
    map<long long, int> mp;
    vector<long long> prefsum(endingId - zeroId + 1, 0);
    prefsum[0] = 0;
    mp[0] += 1;
    for (int i = zeroId + 1, id = 1; i <= endingId; i += 1, id += 1)
    {
        prefsum[id] += v[i] + prefsum[id - 1];
        mp[prefsum[id]] += 1;
    }
    int ans = mp[0];
    for (int i = 1; i < prefsum.size(); i += 1)
    {
        // making this index 0 by placing such number at zeroId
        // then count is count of remainig zeros
        long long prev = 0;
        prev = prefsum[i];
        ans = max(ans, mp[prev]);
        mp[prefsum[i]]--; // remove this since not going to be considered in future
    }
    debug(ans, zeroId, endingId);
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &elm : v)
        cin >> elm;
    // let's start from end
    // for each 0 I can use it to make subarray = 0 toll any index after this
    // last zero can make subarray zero after any index following it
    // try making all possible states after that and find largest 0's it can forming doing so
    // do this for all zeros seems resonably good
    // they makes non intersecting queries
    // since if previous zero has something remaining after it makes subarray sum = 0
    // then next zero can use it to make 0 after some time, but this can be considered same case as next zero made it here
    // so previous sum doesn't affect our current 0 in any way
    vector<int> zeroId;
    for (int i = 0; i < v.size(); i += 1)
    {
        if (v[i] == 0)
        {
            zeroId.push_back(i);
        }
    }
    zeroId.push_back(n);
    // taking some starting zero which are out of our control
    int ans = 0;
    long long prev = 0;
    for (int i = 0; i < zeroId.front(); i += 1)
    {
        prev += v[i];
        ans += (prev == 0);
    }
    debug(ans);
    // taking optimal solution of subarray starting with zero
    for (int i = 0; i < zeroId.size() - 1; i += 1)
    {
        ans += maxZeros(v, zeroId[i], zeroId[i + 1] - 1);
    }
    cout << ans << endl;
}
int main()
{
    fast_cin();
    int test;
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}