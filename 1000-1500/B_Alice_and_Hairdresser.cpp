/// when someone has increased it's length then we need to check it's both side weather it joins 2 segments 
// or creates new one accordingly we can find time taken those segments 
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
#include <cmath>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
//// we requires to mark nodes which are already in some component
// we need to check only if some node > l
// we need to compute continuouse segment where each node > l in initial stage
int main(){
    fast_cin();
    int n,m,l; 
    cin>>n>>m>>l; 
    v32 v(n); 
    int ans =0; 
    for(int i=0;i<n;i++){
        cin>>v[i];  
    }
    int id = 0; 
    while(id < n){ // need to count continuous segments of val > l 
        while(id < n and v[id] <= l) id++;
        if(id == n) continue; 
        while(id < n and v[id] > l){
            v[id] = -1; 
            id++; 
        } 
        ans++; 
    }
    int x,y,z; 
    while(m--){
        cin>>x; 
        if(x == 0){
            cout<<ans<<endl; 
        }
        else{
            cin>>y>>z; 
            y--; 
            if(v[y] == -1) continue;  // already in some component 
            v[y]+=z; 
            if(v[y] > l){ // if it's gone out of order then we are required to check all other things
                v[y] = -1; 
                if(y > 0 and v[y-1] == -1 and y < n-1 and v[y+1] == -1){
                    ans--; 
                }
                else if((y > 0 and v[y-1] == -1) or (y < n-1 and v[y+1]  == -1)){
                    // new segment added since it doesn't attaches to any previous and no merging of segments done
                    ans;
                }
                else ans++; 
            }  
        }
    }
    return 0;
}