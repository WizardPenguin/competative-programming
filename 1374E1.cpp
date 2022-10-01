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
    int n,k; 
    cin>>n>>k;
    int a,b,c; 
    vector<int> both,alice,bob; 
    for(int i=0;i<n;i+=1){
        cin>>a>>b>>c; 
        if(b and c) both.push_back(a); 
        else if(b) bob.push_back(a); 
        else if(c) alice.push_back(a); 
    }
    sort(all(bob)); 
    sort(all(alice)); 
    for(int i=0;i<min(alice.size(),bob.size()); i+=1){
        both.push_back(alice[i] + bob[i]); 
    }
    if(both.size() < k){
        cout<<-1<<endl; 
    }
    else{
        sort(all(both));
        ll sum = 0; 
        for(int j=0;j<k;j+=1) sum += both[j]; 
        cout<<sum<<endl; 
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