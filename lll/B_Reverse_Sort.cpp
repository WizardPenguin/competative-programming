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
        string s; 
        cin>>s; 
        int ones  = 0,zeros = 0; 
        for(auto &i: s){
            if(i == '0') zeros++; 
            else ones++;
        }
        vector<int> id; 
        for(int i=0;i<zeros;i++){
            if(s[i] == '1'){
                id.push_back(i); 
            }
        }
        for(int i=zeros;i<n;i++){
            if(s[i] == '0'){
                id.push_back(i); 
            }
        }
        if(id.size() == 0){
            cout<<0<<endl; 
        }
        else{
            cout<<1<<endl; 
            cout<<id.size()<<" "; 
            for(int i=0;i<id.size();i++) cout<<id[i] + 1<<" "; 
        }
    }
    return 0;
}