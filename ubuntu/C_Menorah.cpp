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
    string a,b; 
    cin>>a>>b; 
    int m=0,nm=0; 
    int m1 = 0,nm1=0; 
    int m0 = 0,nm0 = 0; 
    if(a == b){
        cout<<0<<endl; 
        return; 
    } 
    for(int i=0;i<n;i++){
        if(a[i] == b[i]){
            m++; 
            if(a[i] == '1'){
                m1++; 
            }
            else{
                m0++; 
            }
        }
        else{
            nm++; 
            if(a[i] == '1'){
                nm1++; 
            }
            else{
                nm0++; 
            }
        }
    }
    // we are required to have atlest 1 ON bit in nm or m part 
    // cout<<m<<" "<<m1<<endl; 
    // cout<<nm<<" "<<nm1<<endl; 
    int ans = INT_MAX; 
    if((m0 == m1 - 1) and m&1){ // we need m to be odd 
        ans = min(ans,m); 
    }
    if(nm1 == nm0 and nm%2 == 0){ // we need nm to be even so we can make it same as b 
        ans = min(ans,nm); 
    }
    if(ans == INT_MAX){
        cout<<-1<<endl;
    }
    else{
        cout<<ans<<endl; 
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