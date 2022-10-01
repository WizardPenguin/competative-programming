// this that is to be considered is that moving exam to end also results as a good option since that doesn't divide days
// otherwise place picked exam in between of largest break dividing it into smaller parts 
// we need to consider moving both ends of min break exam 
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
int n,d; 
int score(vector<int> &v,int toRemove){
    int prev = 0; 
    // find largest partition without considerint min element 
    // also find smallest element removing this element
    int maxi = 0; int mini = d;  
    for(int i=1;i<=n;i+=1){
        if(i == toRemove) continue; 
        int part = v[i] - prev - 1; 
        maxi = max(maxi,part); 
        mini = min(mini,part);
        prev = v[i]; 
    }
    // cout<<mini<<" "<<d - prev - 2 <<(maxi - 1)/2<<endl; 
    return min({mini,max(d - prev - 1,(maxi-1)/2)});
}
void solve(){
    cin>>n>>d; 
    vector<int> v(n+1,0);
    int minPartition = d;
    int index = -1;  
    for(int i=1;i<=n;i+=1){
        cin>>v[i]; 
        int partition = v[i] - v[i-1] - 1; 
        if(partition < minPartition){
            minPartition = partition; 
            index = i; 
        }
    }
    // cout<<index<<endl; 
    // try removing both ends of minima, and find what is largest we can get 
    // either insert it in middle of largest one or insert it at end 
    cout<<max({score(v,index-1),score(v,index)})<<endl; 
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