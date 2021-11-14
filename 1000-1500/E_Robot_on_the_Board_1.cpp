// we are not required to triverse whole string at once 
// we need to find such coordinate that can triverse max length of string without going outside 
// we can have at max n-1 left and m-1 right moves 
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
        int n,m; 
        cin>>n>>m; 
        string s; 
        cin>>s; 
        int startx = 0; 
        int starty = 0; 
        int minx = 0; 
        int maxx = 0; 
        int miny  = 0; 
        int maxy = 0; 
        for(auto &i: s){
            if(i == 'R'){
                startx ++; 
                maxx = max(maxx,startx); 
            }
            else if(i == 'L'){
                startx--; 
                minx = min(minx,startx); 
            }
            else if(i == 'U'){
                starty++; 
                maxy = max(maxy,starty); 
            }
            else{
                starty--; 
                miny = min(miny,starty); 
            }
            if(maxx - minx >= m){
                // we need to reverse last move 
                if(minx == startx){ 
                    minx++; // reverse this move 
                }
                // other moves not affect solution
                break; 
            }
            if(maxy - miny >= n){
                if(maxy == starty){
                    maxy--; 
                }
                break; 
            }
            // cout<<i<<" "; 
        }
        // cout<<endl; 
        // cout<<"m "<<minx<<" "<<miny<<endl; 
        // now find max square needed for this particular square
        // there should be space for x backward in both axix 
        // find max backward moves required and give atlest that distance
        int right = 1-minx; 
        int down = 1+maxy;  
        cout<<down <<" "<<right<<endl; 
    }
    return 0;
}