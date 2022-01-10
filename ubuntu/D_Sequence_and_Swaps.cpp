// for given number x find first number which is > x 
// also till then all numbers should be in sorted position because we can't change their position 
// then replace that number with this number and repeat step 
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
    int x; 
    cin>>x; 
    vi v(n+1); 
    v[0] = 0; 
    for(int i=1;i<=n;i++) cin>>v[i]; 
    // check weather we found some index where v[i] < v[i-1] 
    // means we are required to perform swap operation 
    // then find first index from where swapping has to start and perform swapping 
    // if after swapping we are able to resolve problem then good otherwise return -1
    int i=1; 
    bool found = true; 
    int steps = 0; 
    while(i<=n){
        int start = i; 
        while(i<=n and v[i] >= v[i-1]) i++; 
        if(i == n+1) break; // we are done 
        // means we have found some problem 
        // we need to start swapping from first element > x 
        for(int j = start;j <= i; j++){
            if(v[j] > x){
                swap(v[j],x); 
                steps++; 
            }
        }
        if(v[i] >= v[i-1]){ // check weather problem resolved or not 
            i++; 
        }
        else{
            found = false; 
            break; 
        }
    }
    if(found){
        cout<<steps<<endl; 
    }
    else{
        cout<<-1<<endl; 
    }
}

void solve(){

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