#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
#include <cmath>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
int main()
{
    fast_cin();
    int n,m; 
    cin>>n>>m; 
    string res[] = {
        {"###"},{"#.#"},{"###"}
    };
    vector<string> q(n); 
    for(int i=0;i<n;i++) cin>>q[i];
    vector<vector<bool> > vis(n,vector<bool>(m,false)); 
    for(int i=0;i<n-2;i++){
        for(int j=0;j<m-2;j++){
            if(q[i][j] == '#'){
                // check stamp shouldn't mark . as #
                bool found = true; 
                for(int k=0;k<3;k++){
                    for(int l=0;l<3;l++){
                        if(q[i + k][j + l] != res[k][l] and q[i+k][j+l] == '.'){ // dot being stamped
                            found = false; 
                            goto end; 
                        }
                    }
                }
                // make changes
                end:;
                if(found){
                    for(int k=0;k<3;k++){
                        for(int l=0;l<3;l++){
                            if(res[k][l] == '#') // mark ones which are stamped with #
                            vis[i+k][j+l] = true; 
                        }
                    }
                }
            }
        }
    }
    bool found = true; 
    // final check for solution 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            // cout<<vis[i][j]<<" "; 
            if(q[i][j] == '#' and !vis[i][j]){
                found = false; 
                goto END; 
            }
        }
        cout<<endl; 
    }
    END:;
    if(found){
        cout<<"YES"<<endl; 
    }
    else{
        cout<<"NO"<<endl; 
    }
}