
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
        int n; cin>>n; 
        vector<int> v(n); 
        for(int i=0;i<n;i++) cin>>v[i]; 
        string s; 
        cin>>s; 
        // separate increasing and decreasing elements 
        vector<int> inc,dec; 
        for(int i=0;i<n;i++){
            if(s[i] == 'R'){
                inc.push_back(v[i]); 
            }
            else{
                dec.push_back(v[i]); 
            }
        }
        vector<bool> done(n+1,false);
        sort(all(inc)); 
        sort(all(dec)); 
        int start = 1; 
        bool found = true; 
        for(int i=0;i<dec.size();i++){
            if(start <= dec[i]){
                // means we can decrease this number till this one 
                start++; 
            }
            else{
                found = false; 
                break;
            }
        }
        if(!found){
            cout<<"NO"<<endl; 
        }
        else{
            int end = n; 
            for(int i=inc.size()-1;i>=0;i--){
                if(end >= inc[i]){
                    end--; 
                }
                else{
                    found = false; 
                    break; 
                }
            }
            if(!found){
                cout<<"NO"<<endl; 
            }
            else{
                cout<<"YES"<<endl; 
            }
        }
    }
    return 0;
}