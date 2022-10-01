// we want to have k elements 
// optimal to choose k numbers in sequence in sorted array so distance = max(k numbers)
// also optimal to take largest number in sequence which don't need us to come back 
// if we start from back (someone is going to have that elements and dist shurely = back)
// then we have to take all k-1 elements behind it so that those elements won't add distance to solution in any set
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
 

void solve(){
    int n; 
    cin>>n;
    int k; 
    cin>>k; 
    int val; 
    vi pos,neg; 
    // don't affect solution only added for simplicity
    pos.push_back(0); 
    neg.push_back(0); 
    for(int i=0;i<n;i++){
        cin>>val; 
        if(val >0){
            pos.push_back(val); 
        }
        else{
            neg.push_back(-val); 
        }
    }
    sort(all(pos)); 
    sort(all(neg)); 
    ll ans = 0; 
    for(int i=pos.size()-1;i>=0;i-=k){
        ans += 2*pos[i]; 
    }
    for(int i=neg.size()-1;i>=0;i-=k){
        ans += 2*neg[i]; 
    }
    // now remove one who is going to have single triversal 
    ans -= max(pos.back(),neg.back()); 
    cout<<ans<<endl; 
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