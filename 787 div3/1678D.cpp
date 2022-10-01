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
    vector<int> v((n+1)*m,0), row((n+1)*m,0); 
    string s; 
    cin>>s; 
    reverse(all(s)); 
    for(int i=0;i<m;i+=1){
        s += "0"; 
    }
    reverse(all(s)); 
    int it = m;
    int lastOne = 0; 
    for(int i=0;i<n;i+=1){
        for(int offset=0;offset<m;offset+=1,it+=1){
            v[it] += v[it-1]; 
            if(s[it] == '1' or s[it - m] == '1'){
                // means this is ON bit 
                v[it] += 1; 
                if(s[it] == '1') lastOne = it; 
                s[it] = '1'; 
            }
            int cumSum = v[it] - v[it-m]; 
            // finding row value for this 
            row[it] = row[it-m]; 
            if(lastOne > it-m){
                row[it] += 1; 
            }
            // cerr<<lastOne<<" "; 
            cout<<cumSum + row[it]<<" ";
        }
    } 
    // cerr<<endl; 
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