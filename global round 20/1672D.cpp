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
    vi a(n),b(n); 
    for(int i=0;i<n;i+=1) cin>>a[i]; 
    for(int i=0;i<n;i+=1) cin>>b[i]; 
    int i=n-1; 
    int j=n-1; 
    stack<int> stk; 
    while(i>=0 or j>=0){
        // cerr<<i<<" "<<j<<endl; 
        if(j < 0 or a[i] != b[j]){ 
            if(j == n-1){
                cout<<"NO"<<endl; 
                return; 
            }
            else if(b[j] == b[j+1]){
                // means we can have rotation 
                stk.push(b[j]); 
                j-=1; 
            }
            else if(not stk.empty() and stk.top() == a[i]){
                stk.pop(); 
                i-=1; 
            }
            else if(j<0){
                cout<<"NO"<<endl; 
                return; 
            }
            else{
                cout<<"NO"<<endl; 
                return; 
            }
        }
        else{
            i-=1; 
            j-=1; 
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