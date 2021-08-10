// try to move all around middle sheep 
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
        int n; 
        cin>>n; 
        string s; cin>>s; 
        int sum = 0; 
        int count = 0; 
        for(auto i: s) count += (i == '*');
        if(count == 0 or count == 1){
            cout<<0<<endl; 
            continue; 
        } 
        int mid = (count + 1)/2;
        int pos;  
        for(int i=0;i<n;i++){
            if(mid == 1) pos = i; 
            if(s[i] == '*') mid--; 
        }
        // dbg(pos); 
        long long ans = 0; 
        for(int i=0;i<n;i++){
            if(s[i] == '*' and i!=pos){
                ans += abs(i - pos); 
            }
        }
        long long left = count - (count+1)/2; 
        long long right = count - left-1; 
        ans -= ((left)*(left+1))/2 + ((right)*(right+1))/2; 
        cout<<ans<<endl; 
    }
    return 0;
}