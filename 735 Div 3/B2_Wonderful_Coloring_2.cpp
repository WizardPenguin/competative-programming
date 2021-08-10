// if frequency > k then store them in other variable 
// remaining has to be distributed with different colors such that each have same count of elements 
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
        // store indices of elements in vector of map takes 2*n space 
        map<int,vector<int> > frequency; 
        int n,k; cin>>n>>k; 
        vector<int> v(n); 
        for(int i=0;i<n;i++) cin>>v[i]; 
        // 0 means no color assigned to them 
        for(int i=0;i<n;i++){
            frequency[v[i]].push_back(i);
        }
        vector<int> res(n,0); 
        if(k > n){
            for(auto i: res) cout<<i<<" "; 
            cout<<endl; 
            continue; 
        }
        // if frequency < k then store them in set and paint them at end 
        int color = 0; 
        // paint with color+1
        // take mod at each step 
        vector<int> remaining; 
        for(auto i: frequency){
            auto &temp = i.second; 
            if(temp.size() >= k){
                for(int i=1;i<=k;i++){
                    res[temp[i-1]] = i; 
                }
            }
            else{
                for(auto i: temp){
                    remaining.push_back(i);
                }
            }
        }
        // we have final color which needs to be triversed back to 0 if it's not already 
        for(int i=0;(i + k - 1) < remaining.size();i+=k){
            int color = 1; 
            for(int j=i;j < i + k; j++){
                res[remaining[j]] = color++; 
            }
        }
        for(auto i: res){
            cout<<i<<" "; 
        }
        cout<<endl; 
    }
    return 0;
}