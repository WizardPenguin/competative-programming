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
// move smallest number 
void solve(){
    int n; 
    cin>>n; 
    vb taken(n+1,false); 
    vi nt; 
    int val; 
    for(int i=1;i<=n;i++){
        cin>>val; 
        if(val <=n and !taken[val]) taken[val] = true; 
        else nt.push_back(val); 
    }
    sort(all(nt)); 
    int t=0; 
    bool found = true; 
    for(int i=1;i<=n;i++){
        if(!taken[i]){
            int need = 2*i + 1; 
            if(nt[t] >= need){
                t++; 
            }
            else{
                found = false; 
                break; 
            }
        }
    }
    if(found){
        cout<<nt.size()<<endl; 
    }
    else{
        cout<<-1<<endl; 
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