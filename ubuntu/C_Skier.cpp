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
    string s; 
    cin>>s; 
    // we need to store weather segment has been previously visited 
    // for that we don't require to store larger segment rather we can just store a->b as segment move
    // then we can check weather this is similar move as previous segment and take time accordingly 
    int res = 0; 
    int n = s.length(); 
    set<array<int,4> > st; 
    pair<int,int> start = {0,0};
    for(int i=0;i<n;i++){
        auto prev = start; 
        switch(s[i]){
            case 'W': start.first++;  break; 
            case 'E': start.first--;  break; 
            case 'N': start.second++;  break; 
            case 'S': start.second--;  break; 
        }
        array<int,4> v= {prev.first,prev.second,start.first,start.second}; 
        if(st.find(v) != st.end()){
            res += 1; 
        }
        else{
            res += 5; 
            st.insert(v);
            st.insert({start.first,start.second,prev.first,prev.second}); 
        }
    }
    cout<<res<<endl; 
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