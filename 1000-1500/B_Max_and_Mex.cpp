// if mex > max then inf elem generated
// else one new element generated add it to set and find number of uniq elements there 
// careful about base cases if k == 0 
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
        int n,k;
        cin>>n>>k; 
        set<int> s; 
        int val; 
        for(int i=0;i<n;i++) cin>>val,s.insert(val); 
        int prev = *s.begin(); 
        auto it = s.begin(); 
        it++;
        bool found; 
        if(prev == 0) found = true; 
        else found = false,prev = 0; 
        for(;it != s.end() and found;it++){
            if(prev == (*it) - 1){
                prev = *it; 
            }
            else{
                prev++;
                found = false; 
            }
        }
        if(found){
            cout<<s.size() + k<<endl; 
        }
        else{
            if( k == 0) cout<<s.size()<<endl; 
            else{
                int newElm = ceil((prev + *s.rbegin())/2.0); 
                s.insert(newElm);
                cout<<s.size()<<endl;
            } 
        }
    }
    return 0;
}