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
#define MOD 1000000007
set<int> ls,rs; 
void bs(vector<int> &a,int x){
    int left = 1; 
    int right = a.size(); 
    // cout<<"calling"<<endl; 
    while(left < right){
        int mid = (left + right)/2; 
        // cout<<mid<<endl; 
        if(a[mid] <= x){
            left = mid+1;
            ls.insert(mid); 
        }
        else{
            right = mid; 
            rs.insert(mid); 
        }
    }
    // cout<<a[left -1]<<endl; 
}
ll fact(ll n){
    if(n <= 0){
        return 1; 
    }
    ll ans = 1; 
    while(n){
        ans *= n; 
        n--;
        ans %= MOD;  
    }
    return ans; 
}
int modInv(ll val,int mod){
    ll ans = 1; 
    while(mod){
        if(mod&1){
            ans *= val; 
            ans %= MOD; 
        }
        val *= val; 
        val %= MOD; 
        mod >>=1; 
    }
    return ans; 
}
int main()
{
    int n; 
    int x,pos; 
    cin>>n>>x>>pos; 
    vector<int> v; 
    v.push_back(0); 
    // we are going to have binary serach on position and find which path does it follows
    // then find combinations of 1..n numbers that must give same path so it converges at this position 
    // we are going to fix number x and position pos
    for(int i=0;i<n;i++){
        v.push_back(i); 
    }
    // cout<<"calling"<<endl; 
    bs(v,pos);
    int l = ls.size()-1; 
    int r = rs.size(); 
    // cout<<l<<" "<<r<<endl; 
    // cout<<l<<" "<<r<<endl;
    // cout<<"serach done"<<endl;  
    if(l > x-1 or r > n-x){
        cout<<0<<endl; 
        return 0; 
    }
    int f1 = fact(x -1); 
    int f2 = fact(n - x );
    int f3 = fact(n - l - r - 1); 
    int f4 = fact(x - 1 - l);
    int f5 = fact(n - x - r); 
    f4 = modInv(f4,MOD-2); 
    f5 = modInv(f5,MOD-2); 
    ll ans = 1; 
    for(auto &i: {f1,f2,f3,f4,f5}){
        ans *= i; 
        ans %= MOD; 
    }
    cout<<ans<<endl; 
    return 0;
}