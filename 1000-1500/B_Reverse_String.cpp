/// ************** we can only move right and then left once 
// these moves in any direction can either be 0
// so we only need to check for each starting position and fix some number of right moves
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
        string s; 
        cin>>s; 
        string res; 
        cin>>res; 
        int n = s.size();
        int m = res.size();  
        bool found = false; 
        // go from l to r the some reverse step 
        for(int l = 0; l < n;l++){
            // speicfying forward length 
            for(int len = 1; len <= m; len++){
                int rem = m - len; 
                int forwardPointer = l + len -1; 
                int backwardPointer =  forwardPointer - rem; 
                if((backwardPointer) >=0 and (forwardPointer) <n ){
                    // if both pointers are in bound 
                    string s1 = s.substr(backwardPointer,rem);
                    reverse(all(s1));
                    string s2 = s.substr(l,len); 
                    // cout<<s1<<" "<<s2<<endl; 
                    // cout<<s2 + s1<<endl;
                    if(res == (s2 + s1)){
                        found = true; 
                        break; 
                    } 
                }
            }
            if(found) break; 
        }
        if(found){
            cout<<"YES"<<endl; 
        }
        else{
            cout<<"NO"<<endl; 
        }
        
    }
    return 0;
}