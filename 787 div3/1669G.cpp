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
    cin>>m>>n; 
    vs v(m); 
    for(int i=0;i<m;i+=1) cin>>v[i]; 
    int count = 0; 
    for(int j=0;j<n;j+=1){
        int count = 0;  
        for(int i=0;i<m;i+=1){
            if(v[i][j] == '*'){
                count += 1; 
                v[i][j] = '.'; 
            }
            else if(v[i][j] == 'o'){
                // adjust all * before it 
                while(count){
                    v[i-count][j] = '*'; 
                    count -= 1; 
                }
                // now count have became zero
            }  
        }
        while(count){
            v[m - count][j] = '*'; 
            count -= 1; 
        }
    }
    // cerr<<"done with preparatoins"<<endl;
    for(auto &i: v){
        cout<<i<<endl; 
    }
    cout<<endl ;
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