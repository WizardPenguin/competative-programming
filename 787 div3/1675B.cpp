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
    int val; 
    vector<ll> v(n); 
    for(int i=0;i<n;i+=1) cin>>v[i]; 
    if(n == 1){
        cout<<0<<endl; 
        return; 
    }
    val = v.back(); 
    for(int s = 0; val; s += 1){
        ll prev = val; 
        ll steps = s; 
        bool found = true; 
        for(int i=n-2;i>=0;i-=1){
            ll tp = v[i]; 
            while(tp and tp >= prev){
                tp /= 2; 
                steps += 1; 
            }
            if(tp >= prev){   
                found = false; 
                break;
            }
            prev = tp; 
        }
        val /= 2; 
        if(found){
            cout<<steps<<endl; 
            return; 
        }
    }
    cout<<-1<<endl; 
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