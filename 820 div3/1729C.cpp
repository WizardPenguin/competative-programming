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
    string s;
    cin >> s;
    int n = s.length();
    vector<int> visited(26, false);
    for (auto &ch : s)
    {
        visited[ch - 'a'] = true;
    }
    int start = s[0] - 'a';
    int end = s.back() - 'a';
    vector<vector<int>> graph(26);
    for (int i = 0; i < 26; i += 1)
    {
        if (not visited[i])
            continue;
        for (int j = 0; j < 26; j += 1)
        {
            if (visited[j])
            {
                graph[i].push_back(j);
            }
        }
    }
    int factor;
    if (start < end)
    {
        factor = -1;
    }
    else
    {
        factor = 1;
    }
    // debug(start, end);
    vector<int> parent(26, -1);
    vector<int> distance(26, INT_MAX);
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
    pq.push({0, start, factor * start});
    while (not pq.empty())
    {
        auto [dist, node, p] = pq.top();
        p = abs(p);
        pq.pop();
        if (parent[node] != -1)
            continue;
        parent[node] = p;
        distance[node] = dist;
        for (auto &nbr : graph[node])
        {
            if (parent[nbr] == -1) // not already visited
            {
                pq.push({dist + abs(node - nbr), nbr, factor * node});
            }
        }
    }
    vector<vector<int>> indices(26);
    for (int i = 0; i < n; i += 1)
    {
        indices[s[i] - 'a'].push_back(i);
    }
    for (auto &elm : indices)
        reverse(all(elm));
    vector<int> path;
    // debug(parent);
    while (parent[end] != end)
    {
        for (auto &ind : indices[end])
        {
            path.push_back(ind);
        }
        end = parent[end];
    }
    for (auto &ind : indices[start])
        path.push_back(ind);
    reverse(all(path));
    cout << distance[s.back() - 'a'] << " " << path.size() << endl;
    for (auto &nbr : path)
        cout << nbr + 1 << " ";
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