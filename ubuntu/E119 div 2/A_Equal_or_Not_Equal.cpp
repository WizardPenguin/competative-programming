#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
// we need to check last relation by adding n-1 relations to graph 
// if last relation says they are equal then either 0 or > 1 N should be there 
// if relation says they are not equal then all shouldn't be connected with equal 
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
    string s; 
    cin>>s; 
    int e=0,n=0; 
    for(int i=0;i<s.length()-1;i++){
        if(s[i] == 'E') e++; 
        else n++; 
    }
    if(s.back() == 'E'){
        if(n != 1){
            cout<<"YES"<<endl; 
        }
        else{
            cout<<"NO"<<endl; 
        }
    }
    else{
        if(n > 0){
            cout<<"YES"<<endl; 
        }
        else{
            cout<<"NO"<<endl; 
        }
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