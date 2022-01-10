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
//  let's try to balance 1's usinb (((.....))) type formation 
// and balancing 0's using ()()()type formation 
// try to have bruteforce means both formation when we have odd number of 1's 
// then odd bracket in taken in both direction and formation which gives both brackets as balanced in the correct one 
void solve(){
    int n; 
    cin>>n; 
    string s; 
    cin>>s; 
    int zeros = 0; 
    int ones = 0;
    vector<char> a(n),b(n);  
    for(auto &i: s){
        if(i == '1') ones++; 
        else zeros++; 
    }
    ones/=2; 
    if(s[0] == '0' or s[n-1] == '0' or (zeros&1)){
        cout<<"NO"<<endl; 
        return;
    }
    else{
        int c=0; 
        for(int i=0;i<n;i++){
            if(s[i] == '1'){
                if(c < ones){
                    a[i] = b[i] = '('; 
                }
                else{
                    a[i] = b[i] = ')'; 
                }
                c++; 
            } 
        }
        int br = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '0'){
                if(br == 0){
                    a[i] = ')'; 
                    b[i] = '('; 
                }
                else{
                    a[i] = '('; 
                    b[i] = ')'; 
                }
                br = 1-br;
            } 
        }
    }
    cout<<"YES"<<endl; 
    for(auto &i: b) cout<<i; 
    cout<<endl; 
    for(auto &i: a) cout<<i;
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