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
        // if we consider strings from starting we have many options for starting point
        // after then we can have many optoins for middle elements too
        // this might take us to O(n^2) dp
        // if we consider string from ending 
        // if character matches the take it else skip 2 characters since we are pressing backspace
        // this makes our path deterministic so O(n) 
        string s,t; cin>>s>>t;
        if(t.length() > s.length()){
            cout<<"NO"<<endl; 
            continue;
        }
        reverse(all(s));
        reverse(all(t));
        int id = 0; 
        for(int i=0;i<s.length();i++){
            if(s[i] == t[id]){
                id++;
                if(id == t.length()){
                    break;  
                }
            }
            else{
                i++; 
            }
        }
        if(id == t.length()){
            cout<<"YES"<<endl; 
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}