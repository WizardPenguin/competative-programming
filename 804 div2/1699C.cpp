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
#define MOD 1000000007
vector<int> fact; 
void solve(){
    int n; 
    cin>>n; 
    vi v(n); 
    map<int,int> mp; 
    for(int i=0;i<n;i+=1) cin>>v[i],mp[v[i]] = i;
    int id = 1; 
    int left = mp[0]; 
    int right = mp[0]; 
    set<int> st; 
    int considered = 0;  // it's kind of space available 
    long long ans = 1; 
    while(id < n){
        // got next element 
        int next = mp[id];
        // st.insert(id); 
        if(left > next){
            for(int i=left-1;i>next;i-=1){
                st.insert(v[i]); 
                considered+=1; 
            }
            left = next; 
        }
        else{
            for(int i=right+1;i<next;i+=1){
                st.insert(v[i]); 
                considered+=1; 
            }
            right = next;
        }
        int count =0 ; 
        while(st.find(id+1) != st.end()) id+=1,count+=1; 
        id+=1;
        // we found inside elements
        // cerr<<count<<endl; 
        while(count--){
            ans *= considered--; 
            ans %= MOD;
        }
        // cerr<<id<<endl; 
        // cerr<<ans<<" "<<considered<<" "<<endl; 
    }  
    cout<<ans<<endl; 
}
int main(){
    fast_cin();
    ll test;
    cin >> test;
    fact.push_back(1); 
    for(ll i=1;i<100005;i+=1){
        fact.push_back((fact.back()*i)%MOD); 
    }
    while(test--){
        solve();
    }
    return 0;
}