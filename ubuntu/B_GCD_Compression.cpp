#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
// try for gcd being 2...2000 and check weather we can achieve it 
/// for that we can add number n%i with (n- n%i) only 
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
    vi v(2*n);
    for(int i=0;i<2*n;i++){
        cin>>v[i]; 
    }
    // while applying bruteforce it is found that if we want gcd = 2
    // then rem = 0 has x numbers and remaining are at rem = 1
    // rem = 1 can be combined(added) with each other to give number divisible by 2
    // same for rem = 1 , both can atmost give 1 spare element so solution always exist 
    vvi id(2); 
    for(int i=0;i<2*n;i++){
        id[v[i]&1].push_back(i); 
    }
    vpii p; 
    for(int i=0;i<2;i++){
        int j=0; 
        int k = id[i].size()-1; 
        while(j < k){
            p.push_back({id[i][j],id[i][k]}); 
            j++,k--; 
        }
    }
    for(int i=0;i<n-1;i++){
        cout<<p[i].first + 1<<" "<<p[i].second + 1<<endl; 
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