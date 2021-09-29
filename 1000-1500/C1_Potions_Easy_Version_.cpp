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
    ll test = 1;
    while(test--){
        int n; cin>>n;
        // cout<<n<<endl;  
        vector<int> v(n); 
        for(int i=0;i<n;i++){
            cin>>v[i]; 
        }
        // move and take each element so -ve not formed in between make min heap to -ve values taken 
        // when power becomes -ve then remove the largst -ve from previous path and try using that 
        priority_queue<int,vector<int>,greater<int> > pq; 
        long long power = 0; 
        int ans = 0;
        int taken =0;
        for(int i=0;i<n;i++){
            // cout<<power<<endl; 
            if(v[i] >= 0){
                power += v[i];
                taken++;  
            }
            else{
                if((power + v[i]) < 0){
                    if(pq.empty()) continue; 
                    auto tp = pq.top();
                    // dbg(tp);
                    if(tp < v[i]){
                        pq.pop(); 
                        power += v[i]; 
                        pq.push(v[i]);
                        power -= tp; 
                    }
                }
                else{
                    power += v[i]; 
                    pq.push(v[i]);
                    taken++;
                }
            }
            ans = max(ans,taken);
        } 
        cout<<ans<<endl; 
    }
    return 0;
}