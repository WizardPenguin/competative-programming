// we can either remove 1 edge or 2 edges such that all components have same xor 
// if more that that removal gives same xor then they can be merged into 2 or 3 components
// when only 1 edge removed then both components will have same xor then whole data xor must be 0
// when 2 edges removed 
// for a given node u xor of it's subtree = x = total tree node since 3 compoent have same xor with x^x^x = total subtree xor 
// now remove edge from some other part than it's subtree 
// if we remove from other disjoint part then other part should have xor = x auto their part xor = x
// if we remove some ancestor edge then it's xor has effect of given node's xor u since it's removed
// for that we got mathematical condition xor(ancestor) = 0 
#include <bits/stdc++.h> 
#include <complex>
#include <cmath>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
int wholeXor = 0; 
vector<int> v,subtree; 
vector<vector<int> > graph;    
int dfsXor(int par,int cur){
    int s = 0;
    for(auto &nbr: graph[cur]){
        if(nbr != par){
            s ^= dfsXor(cur,nbr); 
        }
    }
    return subtree[cur] = s^v[cur]; 
}
bool disjoinSubtree = false; 
bool dfs(int par = -1,int cur = 1,bool ancestor = false){
    if(subtree[cur] == 0){
        ancestor = true; 
    }
    else if(subtree[cur] == wholeXor){
        if(ancestor or disjoinSubtree){
            return true; 
        }
    }
    for(auto &nbr: graph[cur]){
        if(nbr != par){
            if(dfs(cur,nbr,ancestor)) return true; 
        }
    }
    if(subtree[cur] == wholeXor){
        disjoinSubtree = true; 
    }
    return false; 
}
int main()
{
    fast_cin();
    ll test;
    cin >> test;
    while(test--){
        disjoinSubtree = false; 
        wholeXor = 0; 
        int n,k; 
        cin>>n>>k; 
        v = vector<int>(n + 1); 
        for(int i=1;i<=n;i++){
            cin>>v[i];
            wholeXor ^= v[i];  
        }
        graph = vector<vector<int> >(n+1); 
        int t = n-1; 
        while(t--){
            int x,y; 
            cin>>x>>y; 
            graph[x].push_back(y); 
            graph[y].push_back(x); 
        }
        // cout<<"graph formed"<<endl; 
        // cout<<wholeXor<<endl; 
        if(wholeXor == 0){
            cout<<"YES"<<endl; 
        }
        else{
            if(k <= 2){ // we can take k-1 edges
                cout<<"NO"<<endl; 
            }
            else{
                subtree = vector<int>(n+1,0); 
                dfsXor(-1,1); 
                // cout<<"subtree formed"<<endl; 
                /// now we have computed xor of each subtree
                if(dfs()){
                    cout<<"YES"<<endl; 
                }
                else{
                    cout<<"NO"<<endl; 
                }
            }
        }
    }
    return 0;
}