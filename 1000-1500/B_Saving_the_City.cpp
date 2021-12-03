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
        int a,b; 
        cin>>a>>b; 
        string s; 
        cin>>s; 
        int i=0; 
        ll ans = 0;
        int n = s.length();  
        while(i<n and s[i] == '0')i++; 
        int prevCount = 0; 
        priority_queue<int,vector<int>,greater<int> > q; 
        while(i<n){
            while(i<n and s[i] == '1') i++; 
            ans += a; 
            q.push(prevCount);
            prevCount = 0; 
            while(i<n and s[i] == '0') i++,prevCount++; 
        }
        // while(!q.empty()){
        //     cout<<q.top()<<endl; 
        //     q.pop(); 
        // }
        if(!q.empty())
        q.pop(); // remove 0 inserted in queue
        while(!q.empty()){
            ll tp = q.top(); 
            q.pop(); 
            ll cost= tp*b + a; 
            ll prevCost = 2*a; 
            // cout<<prevCost<<" "<<cost<<endl; 
            if(prevCost > cost){
                ans -= prevCost; 
                ans += cost; 
            }
            else{
                break; 
            }
        }
        cout<<ans<<endl; 
    }
    return 0;
}