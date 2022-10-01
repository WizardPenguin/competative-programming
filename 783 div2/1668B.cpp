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
    int n,m; 
    cin>>n>>m; 
    vi v(n); for(int i=0;i<n;i+=1) cin>>v[i]; 
    if(n == 1){
        if(m >= v[0] + 1){
            cout<<"YES"<<endl; 
        }
        else{
            cout<<"NO"<<endl;
        }
        return; 
    }
    sort(v.begin(),v.end(),greater<int>()); 
    int start = 1; 
    int end = m - v[0] ; 
    int i=0; 
    int j=1; 
    auto check = [&](){
        int distance = end - start-1; 
        if(start > end or distance < max(v[(i >= n)? i-2: i],v[(j>=n)? j-2: j])) return true; 
        return false; 
    }; 
    // cerr<<start<<" begin "<<end<<endl; 
    while(i<n or j<n){
        // means we have atlest 1 valid value to insert 
        if(check()){
            cout<<"NO"<<endl; 
            return; 
        }
        i += 2; 
        if(i < n){
            start += v[i-2] + 1; 
            if(check()){
                cout<<"NO"<<endl; 
                return; 
            }
        }
        // cerr<<start<<" "<<end<<endl; 
        if(j<n)
        j += 2; 
        if(j < n){
            end -= (v[j-2] + 1); 
        }
        // cerr<<start<<" "<<end<<endl; 
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