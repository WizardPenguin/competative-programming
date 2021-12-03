// bruteforce will give n^3/2 which is will satisfy conditions
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
// global variables causes many issues remeber to reinitialize it after every test case
vector<vector<int> > transformation; 
map<int,int> formed; 
int n; 
void makeTranformation(){
    // we need to make those tranformations
    auto &prev = transformation.back(); 
    vector<int> newv(prev.size(),0); 
    map<int,int> newm; 
    for(int i=0;i<n;i++){
        newv[i] = formed[prev[i]]; 
        if(newm[newv[i]]){
            newm[newv[i]]++; 
        }
        else{
            newm[newv[i]] = 1;
        }
    }
    if(newv != prev){
        formed = newm; 
        transformation.push_back(newv); 
        makeTranformation(); 
    }
}
int main()
{
    fast_cin();
    ll test;
    cin >> test;
    while(test--){
        transformation = {}; 
        formed = {}; 
        cin>>n; 
        vector<int> nums; 
        int num; 
        for(int i=0;i<n;i++){
            cin>>num; 
            nums.push_back(num);
            if(formed[num]){
                formed[num]++;
            }
            else{
                formed[num] = 1; 
            }
        }
        transformation.push_back(nums);
        makeTranformation(); 
        // for(auto &i: transformation){
        //     for(auto j: i) cout<<j<<" "; 
        //     cout<<endl; 
        // }
        int q; 
        cin>>q; 
        int x,y; 
        int lastId = transformation.size()-1; 
        while(q--){
            cin>>x>>y; 
            int id = min(y,lastId); 
            cout<<transformation[id][x-1]<<endl; 
        }
    }
    return 0;
}