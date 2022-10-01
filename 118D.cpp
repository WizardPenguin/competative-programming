// exhaust all maximas with other 2 numbers using their occurences bounded by k1 and k2 
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
#define M 100000000
map<array<int,4>,int> dp; 
int n1,n2; 
int k1,k2;
// index is not state variable since it can be calculated with given values of n1 and n2 
// choice makes different state for solution 
int recursive(int n1,int n2,bool choice){
    // till particular index using given n1 and n2 cound find way's to get good permutation 
    if(n1 == 0 and n2 == 0){
        return 1; 
    }
    else if(n1 < 0 or n2 < 0 ) return 0; 
    if(dp.find({n1,n2,choice}) != dp.end()){
        return dp[{n1,n2,choice}]; 
    }
    int ans =0 ; 
    if(choice){
        for(int i=1;i<=k1;i+=1){
            ans += recursive(n1 - i,n2,not choice); 
        }
    }
    else{
        for(int i=1;i<=k2;i+=1){
            ans += recursive(n1,n2-i,not choice); 
        }
    }
    return dp[{n1,n2,choice}] = ans%M; 
}
void solve(){
    cin>>n1>>n2>>k1>>k2; 
    cout<<(recursive(n1,n2,1) + recursive(n1,n2,0))%M<<endl; 
}
int main(){
    fast_cin();
    ll test;
    test = 1; 
    while(test--){
        solve();
    }
    return 0;
}