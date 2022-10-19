// each operation is causing changes in only 1 part if we form segment tree 
// NlogN complexity of simulation tree of operations
// with dp storing result of each operation 
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
vector<int> mp;  
vector<int> a;
int create(int left,int right,int index){
    // we might need to return which operation is going to be performed on root 
    if(left+1 == right){
        mp[index] = a[left] | a[right];
        return 1; 
        // 1 means we need xor operation
    }
    int mid = (left + right)>>1;
    // cerr<<"mid "<<mid<<endl;    
    auto found = create(left,mid,2*index + 1); 
    create(mid+1,right, 2*index + 2);
    auto &l = mp[2*index + 1]; 
    auto &r = mp[2*index + 2];
    if(found){
        mp[index] = l ^ r; 
        return 0; 
    }
    mp[index] = l | r; 
    return 1;  
}
int update(int left,int right,int index,int id){
    if(left + 1 == right){
        mp[index] = a[left] | a[right]; 
        return 1;
    }
    // now we want to check which side element is present
    int mid = (left + right)/2; 
    int ret; 
    if(id <= mid){
        ret = update(left,mid,2*index+1,id);
    } 
    else{
        ret = update(mid+1,right,2*index + 2,id); 
    }
    auto &l = mp[2*index+1]; 
    auto &r = mp[2*index + 2];
    if(ret){
        mp[index] = l ^ r; 
        return 0; 
    }
    mp[index] = l | r;
    return 1; 
}
void solve(){
    int n,operations; 
    cin>>n>>operations;  
    a = vector<int>(1<<n,0); 
    mp = vector<int>((1<<n)*4 + 1,0);
    for(int i=0;i<(1<<n);i+=1){
        cin>>a[i]; 
    }
    create(0,(1<<n) - 1,0); 
    // now we want to make dfs tree with optimisation by storing result of states 
    // states are formed by left and right bound of array formed during operations
    for(int i=0;i<operations;i+=1){
        int index,val; 
        cin>>index>>val;
        index -= 1; 
        a[index] = val; 
        update(0,(1<<n)-1,0,index);
        cout<<mp[0]<<endl; 
    }
}
int main(){
    fast_cin();
    ll test = 1; 
    while(test--){
        solve();
    }
    return 0;
}