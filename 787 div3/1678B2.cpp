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
    // we are going to have count 
    int ans = 0; 
    vi tp; 
    for(int i=0;i<n;i+=2){
        string sub = s.substr(i,2); 
        if(sub == "01" or sub == "10"){
            // tp.push_back(3); 
            ans += 1; 
        }
        else if(sub == "11"){
            tp.push_back(1); 
        }
        else if(sub == "00"){
            tp.push_back(0); 
        }
    }
    // now count frequency of same kind 
    int i=0; 
    int count = 0; 
    while(i<tp.size()){
        int prev = tp[i]; 
        while(i<tp.size() and tp[i] == prev){
            i+=1; 
        }
        if(prev == 1 or prev == 0){
            count += 1;  
        }
    }
    cout<<(ans)<<" "<<max(1,count)<<endl; 
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