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
    int x,y; 
    cin>>x>>y; 
    if(x > y or y%x){
        cout<<0<<" "<<0<<endl;
    }
    else{
        int rem = y/x; 
        if(rem == 1){
            cout<<"1 1"<<endl; 
        }
        else{
            for(int i=2;i<=100;i+=1){
                int num = i; 
                int a = 1; 
                while(num < rem){
                    num *= i;  // taking some power of it 
                    a += 1; 
                }
                if(num == i){
                    cout<<a<<" "<<i<<endl; 
                    return; 
                }
            }
            cout<<"0 0"<<endl; 
        }
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