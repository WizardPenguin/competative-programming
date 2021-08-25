// valid reflection are produced by 0,1,2,8
// find all possible combination of valid reflection in given range 
// then find nearest next reflection 
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
    vector<int> options = {0,1,2,5,8};
    map<int,int> reflections = {{0,0},{1,1},{2,5},{5,2},{8,8}};
    while(test--){
        // all possible combinations for the first part 
        // then all for second part 
        // then all for first -> second 
        int h,m;
        cin>>h>>m; 
        vector<pair<int,int> > v; 
        for(auto i: options){
            for(auto j: options){
                // check weather time is in range 
                v.push_back({i,j}); 
            }
        }
        vector<array<int,4> > times; 
        // we need to insert elements if their reflections are also valid
        for(auto &i: v){ // hour stemp
            int a = reflections[i.first]; 
            int b= reflections[i.second]; 
            if((i.first*10 + i.second) >= h) break; 
            for(auto &j: v){ // minute stamp
                int c = reflections[j.first]; 
                int d = reflections[j.second]; 
                if((j.first*10 + j.second) >= m) break; 
                if((d*10 + c) < h and (b*10 + a) < m)
                times.push_back({i.fi,i.se,j.fi,j.se});
            }
        }
        string t; 
        cin>>t; 
        array<int,4> time; 
        time[0] = t[0] - '0'; 
        time[1] = t[1] - '0'; 
        time[2] = t[3] - '0'; 
        time[3] = t[4] - '0'; 
        auto it = lower_bound(all(times),time); 
        if(it == times.end()){
            // cout<<"end"<<endl; 
            it = times.begin(); 
        }
        string res; 
        for(int i=0;i<4;i++){
            if(i == 2){
                res += ":";
            }
            res += to_string((*it)[i]); 
        }
        cout<<res<<endl; 
    }
    return 0;
}