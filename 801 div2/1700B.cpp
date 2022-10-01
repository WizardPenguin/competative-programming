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
    int len; 
    cin>>len; 
    string s; 
    cin>>s; 
    reverse(all(s)); 
    vi res; 
    int carry = 0; 
    if(s.back() == '9'){
        for(int i=0;i<len;i+=1){
            if(s[i] == '0'){
                if(carry){
                    res.push_back(0); 
                }
                else{
                    res.push_back(1); 
                }
                carry = 0; 
            }
            else{
                // find consecutive element 
                int elm =11 -  (s[i] - '0') - carry; 
                if(elm >= 10){
                    // means s[i] == '1; and we have no previous carry so to converge this 
                    res.push_back(0);
                    carry = 0;
                }
                else{
                    res.push_back(elm); 
                    carry = 1;
                } 
            }
        } 
    }
    else{
        // we can make 999999 everywhere since first digit would required valid number 
        for(int i=0;i<len;i+=1){
            int elm = 9 - (s[i] - '0'); 
            res.push_back(elm); 
        }
    }
    reverse(all(res)); 
    for(auto &i: res) cout<<i; 
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