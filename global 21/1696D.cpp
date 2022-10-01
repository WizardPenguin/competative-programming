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
#define MAXN 25005
class minTree{
    public: 
    vector<int> t; 
    minTree(int n){
        t = vector<int>(4*n+1); 
    }
    void build(vector<int> &a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            t[v] = min(t[v*2] ,t[v*2+1]); /// er esny minims in tsnhr 
        }
    }
    int mini(int v, int tl, int tr, int l, int r) {
        if (l > r) 
            return INT_MAX;
        if (l == tl && r == tr) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return min(mini(v*2, tl, tm, l, min(r, tm)) ,mini(v*2+1, tm+1, tr, max(l, tm+1), r));
    }
}; 
class maxTree{
    public: 
    vector<int> t; 
    maxTree(int n){
        t = vector<int>(4*n+1); 
    }
    void build(vector<int> &a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            t[v] = max(t[v*2] ,t[v*2+1]); /// er esny minims in tsnhr 
        }
    }
    int maxi(int v, int tl, int tr, int l, int r) {
        if (l > r) 
            return INT_MIN;
        if (l == tl && r == tr) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return max(maxi(v*2, tl, tm, l, min(r, tm)) ,maxi(v*2+1, tm+1, tr, max(l, tm+1), r));
    }
};
void solve(){
    int n; 
    cin>>n; 
    vi v(n); 
    for(int i=0;i<n;i+=1) cin>>v[i];
    if(n == 1){
        cout<<0<<endl; 
        return; 
    }
    minTree sm(n);
    maxTree lr(n); 
    sm.build(v,1,0,n-1); 
    lr.build(v,1,0,n-1);
    vector<int> mapping(n+1); 
    for(int i=0;i<n;i+=1){
        mapping[v[i]] = i; // acts as upper bound for search 
    }
    vector<int> larger(n,n),smaller(n,n); 
    stack<int> stk; 
    for(int i=n-1;i>=0;i-=1){
        // finding first element smaller than current 
        while(not stk.empty() and v[stk.top()] > v[i]) stk.pop(); 
        if(not stk.empty()) smaller[i] = stk.top(); 
        stk.push(i); 
    }
    while(not stk.empty()) stk.pop(); 
    for(int i=n-1;i>=0;i-=1){
        while(not stk.empty() and v[stk.top()] < v[i]) stk.pop();
        if(not stk.empty()) larger[i] = stk.top(); 
        stk.push(i); 
    }
    // for(auto &i: smaller) cerr<<i<<" "; cerr<<endl;
    // for(auto &i: larger) cerr<<i<<" "; cerr<<endl; 
    int i=0; 
    int steps = 0; 
    while(i<n-1){
        if(v[i] < v[i+1]){
            // find first element < this in next area which acts as upper bound
            // then find smaller element in range
            int upper = smaller[i]; 
            int maxElm = lr.maxi(1,0,n-1,i,upper-1); 
            i = mapping[maxElm];
        }
        else{
            // find first element > this element 
            int upper = larger[i];  
            int minElm = sm.mini(1,0,n-1,i,upper-1); 
            i = mapping[minElm];
        }
        steps+=1; 
        // cerr<<i<<endl; 
    }
    cout<<steps<<endl; 
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