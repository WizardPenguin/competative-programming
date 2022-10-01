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
    int n,k; 
    cin>>n>>k; 
    string s; 
    cin>>s; 
    int steps = 0; 
    int notdone = 0; 
    for(int i=0;i<n;i+=1){
        int stp = s[i] - 'a'; 
        if(stp <= k){
            notdone = i+1; 
            steps = max(steps,stp); 
        }
        else{
            break; 
        }
    }
    // cerr<<steps<<endl; 
    // cerr<<notdone<<endl; 
    // cerr<<"next "<<endl; 
    if(notdone == n){
        for(int i=0;i<n;i+=1) cout<<'a'; 
        cout<<endl; 
        return; 
    }
    // now we have found steps 
    k -= steps; 
    if(not k){
        for(int i=0;i<n;i+=1){
            int stp = s[i] - 'a'; 
            if(stp <= steps){
                cout<<'a'; 
            }
            else{
                cout<<s[i]; 
            }
        }
        cout<<endl; 
        return; 
    }
    char ub = s[notdone]; 
    char lb = max('a',char(s[notdone] - k)); 
    // anyone needing <= steps are made = 'a' , and anyone in range char not done - remaining k's
    for(int i=0;i<n;i+=1){
        int st= s[i] - 'a'; 
        if(st <= steps ){
            cout<<'a'; 
        }
        else if(s[i] >= lb and s[i] <= ub){
            cout<<lb; 
        }
        else{
            cout<<s[i]; 
        }
    }
    cout<<endl; 
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