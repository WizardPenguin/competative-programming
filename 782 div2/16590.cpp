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
    // since a > b always , then we have possibility to make all b's separate and a's between them 
    // we have n + 1 locations for a , divide them equally 
    // if we have something left then distribute reminders to others 
    int n,a,b; 
    cin>>n>>a>>b;
    int maxi = a/(b+1); 
    int rem = a%(b+1); 
    vector<int> str(b+1,maxi);  
    for(int i=0;i<rem;i+=1){
        str[i] += 1; 
    }
    for(int i=0;i<str[0]; i+=1) cout<<"R"; 
    for(int i=1;i<b+1;i+=1){
        cout<<'B'; 
        for(int j=0;j<str[i]; j+=1) cout<<"R";    
    }
    cout<<endl; 
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