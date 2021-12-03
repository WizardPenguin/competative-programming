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
int answer(int x,int y,int diff){
    if(x > y){
        x -= diff; 
        y += 2*diff; 
        return abs(x - y); 
    }
    else{
        y -= 2*diff; 
        x += diff;
        return abs(x - y);  
    }
}
int main()
{
    fast_cin();
    ll test;
    cin >> test;
    while(test--){
        int a,b,c; 
        cin>>a>>b>>c; 
        int x = a + c; 
        int y = 2*b; 
        int diff =abs(x - y); 
        if(diff%3 == 0){
            cout<<0<<endl; 
        }
        else{
            int diff2 = ceil(diff/3.0); 
            diff = diff/3; 
            int ans1 = answer(x,y,diff); 
            int ans2 = answer(x,y,diff2); 
            // cout<<ans1<<" "<<ans2<<endl; 
            cout<<min(ans1,ans2)<<endl; 
        }
    }
    return 0;
}