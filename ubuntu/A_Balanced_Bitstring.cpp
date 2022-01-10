// for it being k balanced substring of size k should repeat again and again 
// so we are going to check each piece of size = k in O(N)
// then merging them on top of each other 
// if it's ? then good 
// otherwise all should have same number 
// after then if we are able to get valid string then try making is k balanced by replacing ? left there accordingly 
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
    // now make mask of size = k and place others on it 
    string s; 
    cin>>s; 
    string sk = s.substr(0,k); 
    // cout<<sk<<endl;
    bool found = true; 
    for(int i=k;i<n;i++){
        if(sk[i%k] == '?'){
            // just replace it with new character whatever it is 
            sk[i%k] = s[i]; 
        }
        else if(s[i] != '?' and s[i] != sk[i%k]){
            found = false; 
            break; 
        }
    }
    if(found){
        // now check weather we can make sk as k-balanced 
        // cout<<sk<<endl; 
        int z=0,o = 0; 
        k/=2; 
        for(auto &i: sk){
            if(i == '1') o++; 
            else if(i == '0') z++; 
        }
        if(z <= k and o <= k){
            cout<<"YES"<<endl; 
            return; 
        }
        cout<<"NO"<<endl; 
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