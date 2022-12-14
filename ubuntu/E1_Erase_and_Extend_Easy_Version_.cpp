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
typedef vector<vector<bool> > vvb;
typedef vector<string> vs;
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
    string smaller;
    int lens = 1; 
    for(int i=1;i<n;i++){
        int len = i+1; 
        for(int j=0;j<k;j++){
            int id1 = j%len; 
            int id2 = j%lens;
            if(s[id1] < s[id2]){
                lens = len;  
                break; 
            }
            else if(s[id1] > s[id2]){
                lens = lens; 
                break; 
            }
        }
    }
    for(int i=0;i<k;i++){
        cout<<s[i%lens]; 
    }
    cout<<endl;
}
int main(){
    fast_cin();
    solve();
    return 0;
}