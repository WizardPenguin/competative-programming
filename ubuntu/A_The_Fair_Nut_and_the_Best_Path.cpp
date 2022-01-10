// for every node either max is from node -> some node on left side
// or from node -> some node on right side
// or from some node on left side to some node for right side
// remember to use greater<ll> to sort vector of ll since it doesn't show any kind of error
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
typedef vector<vector<bool>> vvb;
typedef vector<string> vs;
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
vvpll graph;
vll petrol;
ll ret = 0;
// dfs returns max we can get from path ending at node from some subtree leaf
ll dfs(int node, int par)
{
    if (graph[node].size() == 1 and par != -1)
    { // return petrol at leaf node
        ret = max(ret,petrol[node]); 
        return petrol[node];
    }
    vll v;
    for (auto &nbr : graph[node])
    {
        auto &nd = nbr.first;
        auto &wt = nbr.second;
        if (nd == par)
            continue;
        v.push_back(dfs(nd, node) - wt);
    }
    sort(all(v), greater<ll>());
    if (v.size() > 1)
    {
        ret = max(ret, max(petrol[node] , v[0] + v[1] + petrol[node])); // combining 2 sides taking this node as bridge node
    }
    auto val = max(petrol[node], v[0] + petrol[node]);
    ret = max(ret, val);
    return val; // largest subtree petrol to any child below it
}
void solve()
{
    int n;
    cin >> n;
    graph = vvpll(n + 1);
    petrol = vll(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> petrol[i];
    for (int i = 1; i < n; i++)
    {
        ll x, y, w;
        cin >> x >> y >> w;
        graph[x].push_back({y, w});
        graph[y].push_back({x, w});
    }
    if (n == 1)
    {
        cout << petrol[1] << endl;
        return;
    }
    cout << max(dfs(1, -1), ret) << endl;
}
int main()
{
    fast_cin();
    solve();
    return 0;
}