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
#define N 32
void solve(){
    int n; 
    cin>>n; 
    vi v(n); 
    for(int i=0;i<n;i++){
        cin>>v[i]; 
    }
    vb taken(n + 1,false);
    for(int val = n;val >= 1;val--){
        bool fnd = false; 
        for(int i=0;i<n;i++){
            if(taken[i]) continue; 
            auto tv = v[i]; 
            bool found = false; 
            if(tv >= val){ // possible one is >= required one 
                while(tv){
                    if(tv == val){
                        found = true; 
                        break; 
                    }
                    tv >>= 1; // divide operation 
                }
            }
            if(found){
                taken[i] = true;
                fnd = true; 
                break;  
            }
        }
        if(!fnd){
            cout<<"NO"<<endl; 
            return; 
        }
    }
    cout<<"YES"<<endl; 
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