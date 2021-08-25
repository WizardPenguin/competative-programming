// greedily take indices which are at odd distance from previous one for character required in t
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
        string s,t; 
        cin>>s>>t;
        int n = s.length();  
        // vector<array<vector<int>,2> > pre(26);
        // int n = s.length(); 
        // for(int i=0;i<n;i++){
        //     pre[s[i] - 'a'][i&1].push_back(i);
        // }
        // // find index of first character of t either take odd index or even index doesn't matter
        // int prev = pre[t[0] - 'a'][0][0];
        // for(int i=0;i<t.length();i++){
        //     // find index
        // }
        int m = t.length(); 
        int tid = 0; 
        int prev = 0; 
        for(int i=0;i<n and tid < m;i++){
            if(s[i] == t[tid]){
                int diff = i - prev; 
                if(diff == 0 or diff&1)
                tid++; 
            }
        }
        if(tid == m) cout<<"YES"<<endl; 
        else cout<<"NO"<<endl; 
    }
    return 0;
}