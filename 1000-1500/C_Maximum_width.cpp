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
        int n,m;
        cin>>n>>m;
        string a,b; 
        cin>>a>>b;
        vector<vector<int> > v(26);
        for(int i=0;i<n;i++){
            v[a[i]-'a'].push_back(i);
        }
        // little precomputation for making serach for character easy 
        // we have to decide index between which this maxLen 
        // for i max len is between ith char and i+1th character 
        int start = -1;
        vector<int> pre(m,0);
        pre[m-1] = v[b[m-1]-'a'].back();
        // other character in previous direction should be clogest before it 
        // i.e lower_bound(this in prev character) - 1 th index 
        bool found = true; 
        for(int i=m-2;i>0;i--){
            auto &tp = v[b[i] - 'a'];
            // using upper bound could give same index to repreated chaaracters
            auto it = lower_bound(all(tp),pre[i+1]) - tp.begin();
            pre[i] = tp[it-1];
        } 
        int ans = INT_MIN;
        for(int i=0;i<m-1;i++){
            auto &tp = v[b[i] - 'a']; 
            // find index // lower bound could give same number again for repeated character
            start = upper_bound(all(tp),start) - tp.begin(); 
            // find value at index 
            start = tp[start]; 
            int end = pre[i+1]; 
            ans = max(ans,end - start);
        }
        cout<<ans<<endl; 
    }
    return 0;
}