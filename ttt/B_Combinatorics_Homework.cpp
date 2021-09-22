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
        vector<ll> v(3); 
        for(int i=0;i<3;i++) cin>>v[i];
        sort(all(v));  
        int m; 
        cin>>m;
        int prs = v[2] - 1 + v[1] - 1 + v[0] - 1;
        if(prs < m){
            cout<<"NO"<<endl; 
            continue; 
        }
        if((v[1] + v[0]) >= (v[2]-1)){
            // then try to make m pairs
            cout<<"YES"<<endl; 
        }
        else{
            int diff = (v[2] - 1 - (v[1] + v[0])); 
            // we need diff pairs in largest one only so it comes in inequality 
            // also these pairs mush be required 
            if((diff + 1) <= v[2] and diff <= m){
                cout<<"YES"<<endl; 
            }
            else{
                cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}