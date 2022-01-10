#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
// if all are divisible then never possible 
// if sum not divisible then whole array 
// otherwise try to remove first element from left or right that make sum not divislbe
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
    int n,x; 
    cin>>n>>x; 
    vi v(n); 
    int sum =0; 
    bool non = false; 
    for(int i=0;i<n;i++){
        cin>>v[i]; 
        if(v[i]%x !=0) non = true; 
        sum += v[i]; 
    }
    if(!non) cout<<-1<<ln; 
    else if(sum%x){
        cout<<n<<endl; 
    }
    else{
        int i=0; 
        while(i<n and v[i]%x == 0) i++; 
        int lenx = i+1; 
        i = n-1; 
        while(i<n and v[i]%x == 0) i--; 
        int leny = n-i; 
        cout<<n - min(lenx,leny)<<ln; 
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