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
#define INF 1e18
// x and y are points on line each time ax , ax*ax ... multiplited with previous value 
// means at most logAX(val) points are formed 
// so we can choose 1 start , 1 end point using bruteforce and find if moves are in range or not
#define nx  (pointx.back())*ax + bx 
#define ny  (pointy.back())*ay + by
void solve(){
    ll x0,y0,ax,bx,ay,by; 
    ll sx,sy,t;  
    cin>>x0>>y0>>ax>>ay>>bx>>by; 
    cin>>sx>>sy>>t;

    vll pointx,pointy; 
    pointx.push_back(x0); 
    pointy.push_back(y0); 
    // abs(newx-sx) + abs(newy - sy) <= t this can't be termination condition because we don't know which side sx,sy is on first point of line 
    ll lim = LLONG_MAX/2;   // we are allowing addition atlest 2 times
    // we want ax + b <= lim (new point)
    // means x <= (lim -b)/a; 
    while( (lim -bx)/ax >= pointx.back() and (lim - by)/ay >=  pointy.back()){
        ll newx = nx;
        ll newy = ny;
        pointx.push_back(newx); 
        pointy.push_back(newy);
    }
    // cout<<pointx.size()<<endl;
    // we have found all points now take 2 pointer i,j and find weather we can take them or not
    int n = pointx.size(); 
    int ans = 0;
    ll dist;  
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            ax = pointx[i];
            ay = pointy[i]; 
            bx = pointx[j]; 
            by = pointy[j]; 
            // addition of distances might not be suitable 
            ll common = abs(ax - bx) + abs(ay - by); 
            ll left = abs(sx - ax) + abs(sy - ay); 
            ll right = abs(sx - bx) + abs(sy - by); 
            // dist = left + common or right + common , left + common <= t means t -common >= left 
            // dist = abs(sx - ax) + abs(sy - ay) + abs(ax - bx) + abs(ay - by); 
            ll rem = t - common; 
            if( rem >= left or rem >= right){
                ans = max(ans,j - i + 1); 
            }
        }
    }
    cout<<ans<<endl; 
}
int main(){
    fast_cin();
    solve(); 
    return 0;
}