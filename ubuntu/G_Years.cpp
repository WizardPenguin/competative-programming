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
struct compare{
    // return true when b needs to be one top 
    // b is on top if it's 2nd value is smaller
    bool operator()(const pii &a,const pii &b){
        return b.second < a.second; 
    }
};
void solve(){
    int n; 
    cin>>n; 
    vpii v; 
    int x,y; 
    for(int i=0;i<n;i++){
        cin>>x>>y; 
        v.push_back({x,y}); 
    }
    sort(all(v)); // sorting according to arrival time 
    priority_queue<pii,vpii,compare> pq;
    int elem = 0; 
    int miny = 0; 
    for(int i=0;i<n;i++){
        // we are inserting element at year y 
        // remove elements which have been matured till this year 
        // and find elements left on this particular year 
        y = v[i].first; 
        // cout<<y<<endl; 
        pq.push(v[i]); 
        while(true and pq.size()){
            auto tp = pq.top(); 
            // cout<<tp.first<<" "<<tp.second<<endl;  
            if(tp.second <= y){
                pq.pop(); 
            }
            else{
                break; 
            }
        }
        if(pq.size() > elem){
            elem = pq.size(); 
            miny = y; 
        }
    }
    cout<<miny<<" "<<elem<<ln; 
}
int main(){
    fast_cin();
    solve(); 
    return 0;
}