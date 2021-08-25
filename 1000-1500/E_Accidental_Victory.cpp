// find the lowerst player who can win the game 
// for that we need a check which will work on O(n)
// and binary search make whole complexity nlog(n)
// if someone can win game then all player > him can shurely win game 
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
vector<long long> v,sum; 
bool check(int i){ 
    int n = v.size(); 
    while(i < n){
        long long prev = sum[i]; 
        auto lb = upper_bound(all(v),prev) - v.begin(); 
        if(lb == n) return true; 
        lb--; // last value it can win 
        if(i == lb) return false;
        i = lb;  
    }
    return false; 
}
int main()
{
    fast_cin();
    ll test;
    cin >> test;
    while(test--){
        int n; 
        cin>>n;
        v = vector<long long>(n); 
        for(int i=0;i<n;i++) cin>>v[i]; 
        vector<int> indices(n); 
        iota(all(indices),0); 
        sort(all(indices),[&](int &a,int &b){return v[a] < v[b];}); 
        sort(all(v)); 
        // for(auto i: v) cout<<i<<" "; 
        // cout<<endl; 
        sum = vector<long long>(n); 
        sum[0] = v[0]; 
        for(int i=1;i<n;i++){
            sum[i] += sum[i-1] + v[i]; 
        }
        // for(auto i: sum) cout<<i<<" ";
        // cout<<endl; 
        int l = 0; 
        int r = n-1; 
        int ans = -1;
        while(l <= r){
            int mid = (l + r)/2; 
            if(check(mid)){
                // if mid satisfies condition we need to find more lower one
                ans = mid; 
                r = mid-1; 
            }
            else{
                l = mid+1; 
            }
        }
        // dbg(ans); 
        vector<int> res; 
        for(int i=ans;i<n;i++) res.push_back(indices[i] + 1); 
        sort(all(res)); 
        cout<<res.size()<<endl; 
        for(auto i: res) cout<<i<<" "; 
        cout<<endl; 
    }
    return 0;
}