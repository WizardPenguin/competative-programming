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
    int prev = 0;  // specifies element to be inserted 
    // means till now elements < prev has already been inserted means max = prev 
    vi res(n); 
    stack<int> stk; 
    int val;
    for(int i=0;i<n;i++){
        cin>>val; 
        stk.push(i);
        while(prev < val){
            res[stk.top()] = prev;stk.pop(); 
            prev++; 
        }
    }
    int maxi = 1e6; 
    while(!stk.empty()){
        res[stk.top()] = maxi; 
        stk.pop(); 
    }
    for(auto &i: res) cout<<i<<" ";
}
int main(){
    fast_cin();
    solve(); 
    return 0;
}