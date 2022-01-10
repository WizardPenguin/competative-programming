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
// ai < ai+1 then removal is possible 
// if a[i] > first element we can store it for later since first element shurely removes it 
// smaller element can't be removed, so we need to find larger element for it 
void solve(){
    int n; 
    cin>>n; 
    vi v(n); 
    for(int i=0;i<n;i++) cin>>v[i];
    int first = v[0];
    int maxi = first; 
    int lmaxi = 0; 
    for(int i=0;i<n;i++){
        if(v[i] > first){
            maxi = max(v[i],maxi); 
        }
        else{
            lmaxi = max(lmaxi,v[i]);
            maxi = 0; // maxi till now are not considered find new maxi 
        }
        if(maxi > lmaxi){
            lmaxi = 0;  // mini got resoved by some new maxi then all greater than this and less then first auto resolved
        }
    } 
    // all lower elements should be resolved so at end only first element is left 
    if(lmaxi == 0){
        cout<<"YES"<<endl; 
    }
    else{
        cout<<"NO"<<endl; 
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