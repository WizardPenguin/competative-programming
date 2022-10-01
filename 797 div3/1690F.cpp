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
    string s; 
    cin>>s; 
    vi v(n+1); 
    for(int i=1;i<=n;i+=1){
        cin>>v[i]; 
    }
    vb visited(n+1,false); 
    vector<ll> l; 
    l.push_back(1); 
    for(int i=1;i<=n;i+=1){
        if(visited[i]) continue; 
        string formed; 
        int id = i; 
        do{
            id = v[id];
            visited[id] = true;
            formed += s[id-1]; 
        }while(id != i);
        // cerr<<formed<<endl; 
        int sz = formed.size(); 
        int length = 1; 
        for(int i=1;i<=sz;i+=1){
            string checking = formed.substr(0,i); 
            bool found = true; 
            for(int j=0;j<sz;j+=i){
                if(checking != formed.substr(j,i)){
                    found = false; 
                    break; 
                }
            }
            if(found){
                length = i; 
                break; 
            }
        }
        l.push_back(length); 
    }
    // cerr<<" working "<<endl; 
    // for(auto &i: l) cerr<<i<<" "; cerr<<endl; 
    ll lcm = 1; 
    for(auto &i: l){
        lcm = (lcm*i)/gcd(lcm,i);
    }  
    cout<<lcm<<endl; 
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