// always add new block to smallest stack will always give us a answer
#include <bits/stdc++.h> 
#include <complex>
#include <cmath>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())


int main()
{
    fast_cin();
    ll test;
    cin >> test;
    while(test--){
        int n,m,x; 
        cin>>n>>m>>x; 
        vector<int> v(n); 
        for(int i=0;i<n;i++) cin>>v[i]; 
        // they should be sorted according to height 
        priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > pq; 
        for(int i=0;i<m;i++) pq.push({0,i+1}); 
        for(int i=0;i<n;i++){
            auto pr = pq.top(); 
            pq.pop(); 
            pr.first += v[i]; 
            v[i] = pr.second; 
            pq.push(pr); 
        }
        cout<<"YES"<<endl; 
        for(auto i: v) cout<<i<<" "; 
        cout<<endl; 
    }
    return 0;
}