// we have only option to choose indices in increasing order and make rotation on prefix of size z 
// so we can just reverse operation to get last element at it's position 
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
    vi v(n); 
    for(int i=0;i<n;i+=1){
        cin>>v[i]; 
    }
    vector<int> res; 
    for(int i=n-1;n;i-=1){
        int j=0; 
        for(j=0;j<n;j+=1){
            if(v[j] == i+1) break; 
        }
        int rotation = j+1;
        if(rotation == n) rotation = 0; // it doesn't really matter 
        res.push_back(rotation);  
        // we have found where our element is now just make reverse rotation 
        // i.e. index j has our last element 
        // j+1,...n and i.....j-1 are elements of our remaining array 
        vector<int> tp; 
        for(int k=j+1;k<n;k+=1){
            tp.push_back(v[k]); 
        }
        for(int k=0;k<j;k+=1){
            tp.push_back(v[k]); 
        }
        // for(auto &i: tp) cout<<i<<" "; cout<<endl; 
        swap(tp,v); 
        n-=1; // we have found position of 1 arary element 
    }
    reverse(all(res)); 
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