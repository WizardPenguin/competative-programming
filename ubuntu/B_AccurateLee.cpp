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
    int i=n-1; 
    stack<int> stk; 
    while(i>=0){
        if(s[i] == '1'){
            if(!stk.empty() and stk.top() == '0'){
                while(i>=0 and s[i] == '1') i--; 
                while(!stk.empty() and stk.top() == '0') stk.pop(); 
                stk.push('0'); 
            }
            else{
                stk.push('1'); 
                i--; 
            }
        }
        else{
            stk.push('0'); 
            i--; 
        }
    }
    string res; 
    while(!stk.empty()){
        res += stk.top(),stk.pop(); 
    }
    cout<<res<<endl; 
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