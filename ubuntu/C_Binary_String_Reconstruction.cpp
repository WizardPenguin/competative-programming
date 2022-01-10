// if current character is zero then make it's left and right nbr as 0
// then check remaining string satisfies all constraints
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
    string s; 
    cin>>s; 
    int x; 
    cin>>x; 
    string res; 
    int n = s.length(); 
    for(int i=0;i<n;i++) res += "1";
    for(int i=0;i<n;i++){
        if(s[i] == '0'){
            if(i + x < n){
                res[i + x] = '0'; 
            }
            if(i-x >=0){
                res[i - x] = '0'; 
            }
        }
    }
    bool found = true; 
    for(int i=0;i<n;i++){
        if(s[i] == '1'){
            if(i + x < n and res[i + x] == '1') continue; 
            else if(i - x >=0 and res[i - x] == '1') continue; 
            else{
                found = false; 
                break;
            }
        }
    }
    // dbg(res); 
    if(found){
        cout<<res<<endl; 
    }
    else{
        cout<<-1<<endl; 
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