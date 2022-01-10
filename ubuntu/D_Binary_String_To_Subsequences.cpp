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
    string s; 
    cin>>s; 
    /// now form segments 
    vi res(n,0); 
    int part = 0; 
    int taken = 0; 
    // we can optimize it by storing starting point of each previous segment 
    // if next character is 1 then we should get previous one ending at 0 
    // otherwise previous string ending at 1
    // if there is none present then just create new one 
    vi e0; 
    vi e1; 
    int i=0; 
    for(int i=0;i<n;i++){
        if(s[i] == '1'){
            if(e0.size()){
                auto tp = e0.back(); 
                e0.pop_back();
                e1.push_back(tp); 
                res[i] = tp; 
            }
            else{
                part+=1; 
                e1.push_back(part); // creating new part 
                res[i] = part; 
            }
        }
        else{
            if(e1.size()){
                auto tp = e1.back(); 
                e1.pop_back(); 
                e0.push_back(tp); 
                res[i] = tp; 
            }
            else{
                part += 1; 
                e0.push_back(part); 
                res[i] = part; 
            }
        }
    } 
    cout<<part<<endl; 
    for(auto &i: res) cout<<i<<" "; 
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