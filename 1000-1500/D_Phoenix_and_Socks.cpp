// if we have a pair of same color in left or stock then change them to type stock till left != right
// change colors of remaining elements to make them in pairs of same color 
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
        int n,l,r; 
        cin>>n>>l>>r; 
        vector<int> v(n); 
        for(int i=0;i<n;i++){
            cin>>v[i]; 
        }
        map<int,int> mp; 
        int ans =0; 
        if(l == (n/2)){
            // only need to change color
            for(int i=0;i<n/2;i++){
                mp[v[i]]++;
            }
            for(int i=n/2;i<n;i++){
                if(mp.find(v[i]) != mp.end() and mp[v[i]]){
                    mp[v[i]]--; 
                }
            }
            for(auto i: mp){
                ans += i.second;
            }
        }
        else if(l < n/2){
            for(int i=l;i<n;i++){
                mp[v[i]]++; 
            }
            for(int i=0;i<l;i++){
                if(mp.find(v[i])!= mp.end() and mp[v[i]]){
                    mp[v[i]]--; 
                }
            }
            int required = r - n/2; 
            for(auto &i: mp){
                if(required and i.second > 1){
                    int canRemove = i.second/2; 
                    if(canRemove <= required){
                        i.second -= 2*canRemove;
                        required -= canRemove; 
                        ans += canRemove; 
                    }
                    else{
                        ans += required; 
                        i.second -= 2*required; 
                        required = 0; 
                    }
                }
            } 
            // we need to change direction and change color of some nodes 
            // dbg(ans); 
            for(auto i: mp){
                ans += i.second; 
            }
            // dbg(ans);
        }
        else{
            // change l to r then change color when required 
            for(int i=0;i<l;i++){
                mp[v[i]]++; 
            }
            for(int i=l;i<n;i++){
                if(mp.find(v[i])!= mp.end() and mp[v[i]]){
                    mp[v[i]]--; 
                }
            }
            int required = l - n/2; 
            for(auto &i: mp){
                if(required and i.second > 1){
                    int canRemove = i.second/2; 
                    if(canRemove <= required){
                        i.second -= canRemove;
                        required -= canRemove;  
                    }
                    else{
                        i.second -= required; 
                        required = 0; 
                    }
                }
            }
            for(auto i: mp){
                ans += i.second; 
            }
        }
        cout<<ans<<endl; 
    }
    return 0;
}