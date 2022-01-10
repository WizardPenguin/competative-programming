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
 // using k numbers from 1 .. n we can make min sum 1..k
 // and max sum n-k+1...n 
    // if given sum is in this range for k = len(sequence) we can form that sum 
// to form sum we are going to remove elements are take then if removing makes remaining sum in range 
// for better checking check removal from end because then max and min sum can be computed easily 
ll maxSum(int n,int k){
    ll ans = 0; 
    for(int i=n;i>n-k;i--){
        ans += i; 
    }
    return ans; 
}
// n must be >= k 
ll minSum(int n,int k){
    ll ans = 0; 
    for(int i=1;i<=k;i++){
        ans += i; 
    }
    return ans; 
}
void solve(){
    int n,l,r,s; 
    cin>>n>>l>>r>>s; 
    int k = r - l + 1; 
    vi v; 
    vb t(n+1,false);
    for(int i=n;i>0 and k;i--){
        // taking n in range 
        if(s < i) continue; 
        int ns = s-i; 
        int maxi = maxSum(i-1,k-1); 
        int mini = minSum(i-1,k-1); 
        if(ns >= mini and ns <= maxi){
            s = ns; 
            k -= 1; 
            v.push_back(i); 
            t[i] = true; 
        }
    }
    if(s == 0){
        sort(all(v));
        int x=1; 
        for(int i=1;i<l;i++){
            while(t[x]) x++; 
            cout<<x++<<" ";  
        }
        for(auto &i: v){
            cout<<i<<" "; 
        }
        for(int i=r+1;i<=n;i++){
            while(t[x]) x++; 
            cout<<x++<<" "; 
        }
        cout<<endl; 
    }
    else{
        cout<<-1<<endl; 
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