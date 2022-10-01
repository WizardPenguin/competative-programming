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
    int n,k; 
    cin>>n>>k; 
    string s; 
    cin>>s; 
    bool allzero = true; 
    for(int i=0;i<n;i+=1){
        if(s[i] != '0') allzero = false; 
    }
    if(n == 1){
        cout<<s<<endl; 
        cout<<k<<endl; 
        return; 
    }
    vector<int> flips(n,0); 
    if(allzero){
        if(n&1){
            flips.back() = k; 
            for(int i=0;i<n-1;i++){
                cout<<1; 
            }
            cout<<0<<endl; 
        }
        else{
            // flip end then flip remaining at starting 
            flips.back() = 0; 
            flips[0] = k-1; 
            cout<<1; 
            for(int i=1;i<n;i+=1) cout<<0; 
            cout<<endl; 
        }
    }
    if(n&1){
        if(s[0] == '0'){
            // means we can make them 1 with 1 moves and work with even moves thereafter 
            int found1 = -1; 
            for(int i=0;i<n;i+=1){
                if(s[i] == '1'){
                    found1 = i; 
                    break; 
                }
            }
            flips[found1] = 1; 
            k-=1; 
            // now all reamining are zero 
            for(int i=found1+1;i<n;i+=1){
                if(s[i] == '1'){
                    s[i] = '0'; 
                }
                else{
                    s[i] = '1'; 
                }
            }
            for(int i=found1+1;i<n and k;i+=1){
                if(s[i] == '0'){
                    if(i+1 < n){
                        flips[i] = 1; 
                        flips[i+1] = 1; 
                        s[i] = '1'; 
                        if(s[i+1] == '0') i+=1,s[i] = '1'; 
                        k-=2; 
                    }
                    else{
                        // we have even flips apply on last node and it remains as it is 
                        flips.back() = k; 
                        k=0; 
                    }
                }
            }
            if(k){
                flips.back() = k; 
            }
            for(int i=0;i<=found1;i+=1) cout<<1; 
            for(int i=found1+1;i<n;i+=1){
                cout<<s[i]; 
            }
            cout<<endl; 
        }
        else{
            for(int i=0;i<n and k;i+=1){
                if(s[i] == '0'){
                    if(i+1 < n){
                        flips[i] = 1; 
                        flips[i+1] = 1; 
                        s[i] = '1'; 
                        if(s[i+1] == '0') i+=1,s[i] = '1'; 
                        k-=2; 
                    }
                    else{
                        flips.back() = k; 
                        k=0;  
                    }
                }
            }
            if(k){
                flips.back() = k; 
            }
            cout<<s<<endl; 
        }
    }
    else{

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