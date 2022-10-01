// infection can only spread from 1 child to other sibling child
// so we are required to find time by which infection may spread along all childs at each node 
// guess time using binary serach 
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<vector<ll> > vvll;
typedef vector<vector<pll> > vvpll;
typedef vector<pll> vpll;
typedef vector<pii> vpii;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<vector<bool> > vvb;
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
vvi graph; 
bool check(priority_queue<int> pq,int mid){
    while(not pq.empty() and mid){
        auto tp = pq.top(); pq.pop(); 
        tp -= mid; 
        if(tp > 0) pq.push(tp); 
        mid -= 1; 
    }
    return pq.empty(); 
}
void solve(){
    // initially we need atleast time = number of nodes who have atlest 1 child 
    int n; 
    cin>>n;
    // we only need count of child for each node, and 1 extra node as root who needs to be injected separately 
    vector<int> childs(n,0);
    int par;   
    for(int i=1;i<n;i+=1){
        cin>>par; 
        childs[par-1]+=1; 
    }
    priority_queue<int> pq; 
    for(int i=0;i<n;i+=1){
        if(childs[i]) pq.push(childs[i]); 
    }
    pq.push(1); // root
    int left = pq.size(); 
    int right = n; // every node is injected no infection spread is there 
    while(left < right){
        int mid = (left + right)/2; 
        if(check(pq,mid)){
            right = mid; 
        }
        else{
            left = mid+1; 
        }
    }
    cout<<left<<endl; 
}
int main(){
    fast_cin();
    ll test;
    cin >> test;
    while(test--){
        solve();
    }
    return 0;
}