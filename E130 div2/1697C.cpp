// try having 2 pointer kind of solution
// two string a,b
// first string has character 'a' and asks 'b' in second, mark next += 1, retreive later, or check in storage
// first string has character 'b' and asks for 'a', fauty
// when we have character 'c' asks for b , check for storate only 
// after then storate should have extra b's not need should be remaining when moving forward 
// when 'b' and 'c' found, 
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
    string a,b; 
    cin>>a>>b; 
    int countb = 0; 
    for(auto &i: a) countb += (i == 'b'); 
    for(auto &i: b) countb -= (i == 'b'); 
    if(countb){
        cout<<"NO"<<endl; 
        return; 
    }
    int i=0,j=0; 
    int container = 0; 
    bool found = true; 
    while(i<n and j<n){
        // cout<<i<<" "<<j<<" "<<container<<endl;
        if(b[j] == 'b'){
            // resolve using container 
            container-=1;
            j+=1; 
            continue; 
        }
        if(a[i] == 'b'){
            container += 1; 
            i+=1;
            continue;  
        }
        // also we need to consider container with proper condition 
        if(a[i] == 'a'){
            if(container > 0){
                found = false; 
                break; 
            }
        }
        else if(a[i] == 'c'){
            if(container < 0){
                found = false; 
                break; 
            }
        }
        // now remaining cases to be fulfilled 
        if(a[i] != b[j]){
            found = false; 
            break;  
        }
        else{
            i+=1; 
            j+=1; 
        }
    }
    if(found){
        cout<<"YES"<<endl; 
    }
    else{
        cout<<"NO"<<endl; 
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