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
    string s; cin>>s; 
    set<char> st; 
    int k; char ch; 
    cin>>k; 
    while(k--) cin>>ch, st.insert(ch); 
    int i=0; 
    int ans = -1; 
    int current = 0; 
    for(i=0;i<n;i+=1){
        if(st.find(s[i]) != st.end()){
            // this is special character 
            if(ans == -1){
                ans = current; 
            }
            else if(current >= ans){
                ans = current + 1; 
            }
            // otherwise answer doesn't change
            current = 0; 
        }
        else{
            current += 1; 
        }
    }
    cout<<max(ans,0)<<endl; 
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