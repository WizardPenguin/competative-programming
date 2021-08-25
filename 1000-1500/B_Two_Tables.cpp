// we have position of first table and dimention of second table 
// assuming new table's dim are < room 
// from placing table we need atlest x,y distance it it's position 
// for that either move both dim on old table or move one since other can adjust itself auto
// so it's optimal to make 1 directional move at a time 
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
#define dist sqrt(d1*d1 + d2*d2) 
int main()
{
    fast_cin();
    ll test;
    cin >> test;
    while(test--){
        int W,H; 
        cin>>W>>H; 
        int x1,y1,x2,y2; 
        cin>>x1>>y1>>x2>>y2; 
        int x,y; 
        cin>>x>>y; 
        int ans = INT_MAX; 
        if( x <= (W - abs(x2 - x1))){
            // we can move towards x and y will adjust itself 
            // if x1 >= x then dist is -ve hence takes 0 as movement which is min movenent 
            int dist1 = max(0,x - x1); // is x1 is already that distance apart then no need to move
            int dist2 = max(0,x2 - (W - x));
            ans = min(dist1,dist2); 
        }
        if( y <= (H - abs(y2 - y1))){
            int dist1 = max(0,y - y1); 
            int dist2 = max(0,y2 - (H - y));
            ans = min(ans,min(dist1,dist2)); 
        }
        if(ans != INT_MAX){
            cout<<(ans)<<endl; 
        }
        else{
            cout<<-1<<endl; 
        }
    }
    return 0;
}