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
// select 2 cards and try guessing 3rd card if their card is given then take it otherwise check other possibility 
// if feature in 2 cards is same then new one should have same 
// otherwise new one whould have different from both 
// if we found a,b and such c that satisfy condition then ans ++
// also other 2 can also pair to form remaining 2 means 3 possible same triplets so ans/3
void solve(){
    int n,k; 
    cin>>n>>k; 
    vs v(n); 
    unordered_set<string> s; 
    for(int i=0;i<n;i++) cin>>v[i],s.insert(v[i]); 
    int ans = 0; 
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            string formed;
            auto &a = v[i]; 
            auto &b = v[j]; 
            for(int f=0;f<k;f++){
                if(a[f] == b[f]){
                    formed += a[f]; 
                }
                else{
                    if(a[f] != 'S' and b[f] != 'S'){
                        formed += 'S'; 
                    }
                    else if(a[f] != 'E' and b[f] != 'E'){
                        formed += 'E'; 
                    }
                    else{
                        formed += 'T'; 
                    }
                }
            }
            if(s.find(formed) != s.end()){
                ans++;
                // cout<<formed<<endl;  
            }
        }
    }
    cout<<ans/3<<endl; 
}
int main(){
    fast_cin();
    solve(); 
    return 0;
}