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
int search(ll size,ll sum,int cost){
    // we need number of days required 
    ll left = 0; 
    ll right = 1e9; 
    while(left < right){
        ll mid = (left + right)/2; 
        ll curSum = sum + mid*(size); 
        if(curSum > cost){
            right = mid; 
        }
        else{
            left = mid+1; 
        }
    }
    // we found day on which curCost > our money,
    return right; 
}

void solve(){
    int n,cost; 
    cin>>n>>cost; vll v(n); 
    for(int i=0;i<n;i+=1) cin>>v[i]; 
    sort(all(v)); 
    for(int i=1;i<n;i+=1){
        v[i] += v[i-1]; 
    }
    ll days = 0; 
    ll prevDays = 0; 
    for(int i=n-1;i>=0;i-=1){
        ll d = search(i+1,v[i],cost); 
        // cerr<<"d   "<<d<<endl; 
        days += (i+1)*(d-prevDays);
        prevDays = d;  
    }
    cout<<days<<endl; 
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