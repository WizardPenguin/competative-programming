// bruteforce solution is 
// for index i find all OR that are possible using elements with id >= i
// then for i-1th value find all OR possible using this value with all possible values of bi
// then OR all these values with all possible OR at index i to find all possible OR at index i +1
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
    int n,m; 
    cin>>n>>m; 
    vi a(n); 
    for(int i=0;i<n;i++) cin>>a[i]; 
    vi b(m); 
    for(int i=0;i<m;i++) cin>>b[i]; 
    set<int> possible; 
    possible.insert(0); 
    // we are never going to have possible OR > 1000 due to problem constraints
    // also we are going to have O(N*2) inner loop that makes complexity inside constraints
    for(int i=n-1;i>=0;i--){
        // find all possible at this index 
        set<int> current; 
        for(int j=0;j<m;j++){
            current.insert(a[i]&b[j]); 
        }
        set<int> tp; 
        for(auto &val: possible){
            for(auto &cur: current){
                tp.insert(val|cur); 
            }
        }
        swap(tp,possible); 
    }
    cout<<(*possible.begin())<<endl; 
}
int main(){
    fast_cin();
    solve(); 
    return 0;
}