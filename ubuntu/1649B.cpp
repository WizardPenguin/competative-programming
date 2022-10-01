// one persone having maximum can pass balls through him at max other times + 1
// if he has more passes than that then he needs new balls
// if maxima is in range we can always complete passing in single ball by going round and round till someone has pass
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
    vi v(n);
    ll sum = 0; 
    int maxi =  0;  
    for(int i=0;i<n;i+=1){
        cin>>v[i];
        sum += v[i];
        maxi  = max(maxi,v[i]);
    }
    if(sum ==0){
        cout<<0<<endl;
        return;
    }
    sum -= maxi; 
    if(sum >= maxi){
        cout<<1<<endl;
    }
    else{
        cout<<maxi - sum<<endl; 
    }
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