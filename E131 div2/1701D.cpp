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
#define va vector<array<int,3> >

void solve(){
    int n; 
    cin>>n; 
    vi v(n); 
    for(int i=0;i<n;i+=1) cin>>v[i]; 
    // now we want something else find ranges for each index 
    va data(n); 
    set<int> st; 
    for(int i=0;i<n;i+=1){
        st.insert(i+1); 
        auto &d = data[i]; 
        d[2] = i; 
        if(v[i] == 0){
            d[0] = min(i+2,n); 
            d[1] = n; 
        }
        else{
            d[1] = (i+1)/v[i]; 
            d[0] = min(d[1],(i+1)/(v[i]+1)+1);
        }
    }
    sort(all(data),[](auto &a,auto &b){
        return a[1] < b[1]; 
    }); 
    vi res(n); 
    int val = 1; 
    for(auto &i: data){
        auto lb = *st.lower_bound(i[0]); 
        res[i[2]] = lb; 
        st.erase(lb); 
    }
    for(auto &i: res) cout<<i<<" "; 
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