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
 // if x is factor or n then taking it in product will leave us with some multiple of x which is not 1
 // so we are going to take numbers which are coprime with n 
 // after then multiplying them might not give modulo n , then number given by taking modulo is definately going to be some factor of coprime
 // since < n it's going to be someone from numbers we multiplied 
 // so we are going to remove this number that makes modulo 1 
void solve(){
    int n; 
    cin>>n; 
    ll prod = 1; 
    vi ele; 
    for(int i=1;i<n;i++){
        if(__gcd(i,n) == 1){
            prod *= i; 
            ele.push_back(i); 
            prod %= n; 
        }
    }
    if(prod%n == 1){
        cout<<ele.size()<<endl; 
        for(auto &i: ele) cout<<i<<" "; 
    }
    else{
        cout<<ele.size()-1<<endl; 
        int x = prod%n; 
        for(auto &i: ele){
            if(i == x) continue; 
            cout<<i<<" "; 
        }
    }
    cout<<endl; 
}
int main(){
    fast_cin();
    solve(); 
    return 0;
}