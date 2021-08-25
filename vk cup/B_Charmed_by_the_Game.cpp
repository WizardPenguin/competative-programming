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
        set<int> res; 
        int totalGame = a+b; 
        if(totalGame&1){
            int g = totalGame/2; 
            if(g >=a)
            for(int i=g-a,j=0;i<=g;i++,j++){
                if(j > g+1) break;
                res.insert(i + j); 
            }
            if(g >=b)
            for(int i=g-b,j=0;i<=g;i++,j++){
                if(j > g+1) break; 
                res.insert(i + j); 
            }
            g++; 
            if(g >=a)
            for(int i=g-a,j=0;i<=g;i++,j++){
                if(j > g-1) break; 
                res.insert(i + j); 
            }
            if(g >=b)
            for(int i=g-b,j=0;i<=g;i++,j++){
                if(j > g-1) break; 
                res.insert(i + j); 
            }
        }
        else{
            int g = totalGame/2; 
            if(g >= a)
            for(int i=g-a,j=0;i<=g;i++,j++){
                if(j > g) break; 
                res.insert(i + j); 
            }
            if(g >= b)
            for(int i=g-b,j=0;i<=g;i++,j++){
                if(j > g) break; 
                res.insert(i + j); 
            }
        }
        cout<<res.size()<<endl; 
        for(auto i: res) cout<<i<<" "; 
        cout<<endl; 
    }
    return 0;
}