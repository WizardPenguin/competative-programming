// first hits and the second one hits
// we have to avoid 2nd one from last hit as much as possible 
// make (first + second ) moves till they are valid 
// after then find number of skips required to make first one to end the remaining game 
// then take peoples who are taking min steps for this increasingly 
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
    double a,b; 
    int n,k; 
    cin>>n>>a>>b>>k; 
    vi v(n); 
    for(int i=0;i<n;i++) cin>>v[i]; 
    vector<int> need; 
    int sum = a+b; 
    int ans =0; 
    for(int i=0;i<n;i++){
        if(v[i]%sum == 0){
            v[i] = b; 
            // find ways to reach here by skipping 
            need.push_back(ceil(v[i]/(a*1.0))); 
            // cout<<i<<" "<<need.back()<<endl; 
        }
        else{
            v[i]%= sum; 
            if(v[i] > a){
                // then I need to skip 
                v[i] -= a; 
                need.push_back(ceil(v[i]/(a*1.0))); 
                // cout<<i<<" "<<need.back()<<endl; 
            } 
            else{
                ans++; 
            }
        }
    }
    sort(all(need)); 
    // for(auto &i: need) cout<<i<<" "; cout<<endl; 
    int i=0; 
    while(i<need.size() and need[i] <= k){
        k-= need[i]; 
        ans++; 
        i++;
    }
    cout<<ans<<endl; 
}
int main(){
    fast_cin();
    solve(); 
    return 0;
}