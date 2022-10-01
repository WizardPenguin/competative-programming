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
// we need to given a multiple to each number so that in next operation we can make numbers = 0 by using len = that multiple 
// first step make a[0] as 0 using multiple of 1
// then take whole array and add -n*a[i] to each number which makes all = -(n-1)*a[i]
// after then we can select segment of length n-1 and add (n-1)*a[i] to each makes all remaining 0  

void solve(){
    int n; 
    cin>>n; 
    vll v(n); 
    for(int i=0;i<n;i++) cin>>v[i];
    if(n == 1){
        cout<<1<<" "<<1<<endl; 
        cout<<v[0]<<endl; 
        cout<<1<<" "<<1<<endl; 
        cout<<v[0]<<endl; 
        cout<<1<<" "<<1<<endl; 
        cout<<-3*v[0]<<endl; 
        return;
    } 
    cout<<1<<" "<<1<<endl; 
    cout<<-v[0]<<endl; 
    cout<<1<<" "<<n<<endl; 
    v[0] = 0; 
    for(int i=0;i<n;i++){
        cout<<-n*v[i]<<" "; 
    }
    cout<<endl; 
    cout<<2<<" "<<n<<endl; 
    for(int i=1;i<n;i++){
        cout<<(n-1)*v[i]<<" ";
    }
}
int main(){
    solve(); 
    return 0;
}