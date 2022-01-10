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
    string a,b; 
    cin>>a>>b; 
    // z is initially empty and we want to make it equal to b by appending some elements from a     
    vvi v(27); 
    for(int i=0;i<a.length(); i++){
        v[a[i] - 'a'].push_back(i); 
    }
    int i=0; 
    int ans =0 ; 
    while(i<b.length()){
        int id = -1; 
        int index = b[i] - 'a'; 
        int fnd = upper_bound(all(v[index]),id) - v[index].begin(); 
        while(fnd != v[index].size()){ // making up largest subsequence for this step 
            id = v[index][fnd]; // update index 
            i++; // search for next character from now onwards
            if(i == b.length()) break; 
            index = b[i] - 'a';
            fnd = upper_bound(all(v[index]),id) - v[index].begin(); 
        }
        if(id != -1){
            ans++; 
        }
        else{
            cout<<-1<<ln; 
            return; 
        }
    }
    cout<<ans<<ln; 
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