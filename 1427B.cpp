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
    priority_queue<int,vi,greater<int>> pq; 
    int start = 0,end = 0; 
    int i=0; 
    int j = n-1; 
    int cost = 0; 
    while(i<=j and s[i] == 'L') start += 1,i+=1; 
    while(i<=j and s[j] == 'L') end +=1,j-=1; 
    cerr<<i<<" start "<<j<<endl; 
    cerr<<start<<" se "<<end<<endl; 
    while(true){
        int component = 0; 
        int wins = 0; 
        while(i<=j and s[i] == 'W') i+=1,wins += 1; 
        while(i<=j and s[i] == 'L') component += 1, i+=1; 
        // cerr<<component<<" c "; 
        cost += 2*wins-1; 
        pq.push(component); 
        if(i>j) break; 
    } cerr<<endl; 
    while(not pq.empty() and pq.top() >= k){
        k-=pq.top(); 
        if(pq.top())
        cost += 2*pq.top()+1; 
        pq.pop();
    }
    if(pq.empty()){
        cost += 2*min(k,end);
        k-= min(k,end); 
        if(k > start){
            cost += 2*min(k,start);
        }
    }
    else{
        cost += 2*k-1; 
    }
    cout<<cost<<endl; 
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