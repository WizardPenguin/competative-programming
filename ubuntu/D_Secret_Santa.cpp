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
    vi v(n+1); 
    for(int i=1;i<=n;i++) cin>>v[i]; 
    vb taken(n+1,false),given(n+1,false);
    int count = 0; 
    for(int i=1;i<=n;i++){
        if(!taken[v[i]]){
            taken[v[i]] = true; 
            given[i] = true; 
        }
        else{
            v[i] = -v[i]; // not known whom he's going to give gift
            count++; 
        }
    }
    // problem when only 1 element left for giving and taking gift then we need to replace it by someone else
    vi common; 
    vi canTake; 
    for(int i=1;i<=n;i++){
        if(!taken[i] and !given[i]){
            common.push_back(i); 
            canTake.push_back(i); 
        }
    }
    if(common.size() == 1 and count == 1){
        auto problem = common[0]; 
        given[problem] = true; 
        auto give = -v[problem]; 
        for(int i=1;i<=n;i++){
            if(v[i] == give){
                v[i] = -v[i]; 
                given[i] = false; 
            }
        }
        v[problem] = -v[problem]; // make it +ve sice it's begin getting considered again 
        // make these array's again 
        common.clear(); 
        canTake.clear(); 
        for(int i=1;i<=n;i++){
            if(!taken[i] and !given[i]){
                common.push_back(i); 
                canTake.push_back(i); 
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(!taken[i] and given[i]){
            canTake.push_back(i); 
        }
    }
    int md = canTake.size();
    for(int i=0;i<sz(common);i++){
        v[common[i]] = canTake[(i+1)%md]; 
        given[common[i]] = true; 
    } 
    int id = sz(common); 
    for(int i=1;i<=n;i++){
        if(!given[i]){
            v[i] = canTake[(id+1)%md]; 
            id++; 
        }
    }
    cout<<(n - md)<<endl; 
    for(int i=1;i<=n;i++) cout<<v[i]<<" "; 
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