// create two map and store how many have repeating frequencies
// at each step if we found both parts having no repeats and their size == largest element inside it then partition
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
    for(int i=0;i<n;i++) cin>>v[i]; 
    map<int,int> a,b; 
    int left =0,right = 0; // specify number of duplicating characters 
    for(auto &i: v){
        a[i] = a[i] + 1; 
        if(a[i] == 2){
            // when it increased it's freqnency for first time 
            right++; 
        } 
    }
    b[v[0]] = 1;  // b is map for left side
    vpii res; 
    for(int i=0;i<n-1;i++){
        // remove current element 
        a[v[i]] --; 
        if(a[v[i]] == 1){
            right--;
        }
        else if(a[v[i]] == 0){
            a.erase(v[i]); 
        }
        // check condition 
        if(a.rbegin()->first == a.size() and b.rbegin()->first == b.size() and left == 0 and right == 0){
            // cout<<a.size()<<" "<<b.size()<<endl; 
            res.push_back({b.size(),a.size()});
        }
        // add next element 
        b[v[i+1]] = b[v[i+1]] + 1; 
        if(b[v[i+1]] == 2){
            left++;  
        }
    }
    cout<<res.size()<<endl; 
    for(auto &pr: res){
        cout<<pr.first<<" "<<pr.second<<endl; 
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