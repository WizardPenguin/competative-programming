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
    int k; 
    cin>>n; 
    cin>>k; 
    string s; 
    cin>>s; 
    // cout<<s<<endl; 
    vi v(26,0); 
    for(auto &ch: s){
        v[ch-'a']++; 
    }
    // now find how many are odd 
    int odd = 0; 
    // we can take atmost k odd to make k odd pallindromes 
    int even = 0; 
    for(int i=0;i<26;i++){
        if(v[i]&1){
            odd++; 
        }
        even += (v[i]/2); 
    }
    // now distribute all even into k numbers a much as possible 
    // dbg(even); 
    // dbg(odd); 
    int evenDist = even/k; 
    evenDist*=2; 
    int nonDist = even%k; 
    odd += nonDist*2; 
    if(odd >= k){
        // cout<<s<<endl; 
        cout<<evenDist + 1<<endl; 
    }
    else{
        // cout<<"1 "<<s<<endl; 
        cout<<evenDist<<endl; 
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