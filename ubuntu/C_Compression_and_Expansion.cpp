// to make it memory optimized we can use stack 
// when 1 then push 1 to stack 
// otherwise pop till we found something < that value 
// this poping can be done since removed element can't be used again from other indentation since we are starting new one
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
    vector<int> stk; 
    int val; 
    for(int i=0;i<n;i++){
        cin>>val; 
        if(val == 1){
            stk.push_back(val); 
        }
        else{
            while(stk.back() != val-1) stk.pop_back(); 
            stk.pop_back(); 
            stk.push_back(val);
        }
        cout<<stk[0];  
        for(int i=1;i<stk.size();i++){
            cout<<"."<<stk[i]; 
        }
        cout<<endl; 
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