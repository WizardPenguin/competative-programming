// take largest count of number we can have with given cost 
// after then try to increase those numbers as largest as possible with that cost 
// if someone gets largest and still some cost remaining then we can repeat this step
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
    int budget; 
    cin>>budget;
    // store largest number we can get with given cost 
    map<int,int> cost; 
    int val; 
    for(int i=0;i<9;i+=1){
        cin>>val; 
        cost[val] = i+1; 
    }
    // now take smallest cost first 
    auto pr = *cost.begin(); 
    int count = budget/pr.first; // this is largest count we can have now try replacing it with largest ones 
    if(count == 0){ // we can't have anything 
        cout<<-1<<endl; 
        return; 
    }
    int rem = budget%pr.first; 
    while(count){
        count -=1; 
        rem += pr.first; 
        int maxi = 0; 
        int maxCost = 0; 
        for(auto it = cost.begin();it != cost.end() and it->first <= rem; it++){
            if(it->second > maxi){
                maxi = it->second; 
                maxCost = it->first; 
            }
        }
        cout<<maxi;
        rem -= maxCost; 
    }
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