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
bool check(vll &v,ll val){
    ll canTake = 0, toGive = 0; 
    for(int i=0;i<v.size();i+=1){
        if(v[i] > val){
            toGive += (v[i] - val); 
        }
        else{
            canTake += (val - v[i])/2; 
        }
    }
    if(canTake >= toGive) return true; 
    return false; 
}
int search(vll &v){
    int left = 1; 
    ll right = 1000000000000; 
    while(left < right){
        ll mid = (left + right)/2; 
        if(check(v,mid)){
            right = mid; 
        }
        else{
            left = mid+1; 
        }
    }
    return left; 
}
void solve(){
    int n,m; 
    cin>>n>>m; 
    vll v(n,0); int val; 
    for(int i=0;i<m;i+=1){
        cin>>val;
        v[val-1]+=1; 
    } 
    cout<<search(v)<<endl;  
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