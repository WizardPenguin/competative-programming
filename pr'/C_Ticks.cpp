// start from bottom and if point is painted then find largest size of tick from that point possible 
// if tick's all points are laredy considered then don't consider it as nwe tick
// else consider it and store it's height 
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
    // better mark nodes visited only when we have found that it's under our consideration 
    // if it's not then don't mark it and at then end check if all are visited once or not 
    fast_cin();
    ll test;
    cin >> test;
    while(test--){
        int n,m,k; 
        cin>>n>>m>>k; 
        vector<string> v(n); 
        for(int i=0;i<n;i++) cin>>v[i]; 
        vector<vector<bool> > already(n,vector<bool>(m,false)); 
        // count already of tick if == 2*n + 1 then don't consider it
        // if tick size < k then break 
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<m;j++){
                if(v[i][j] == '*'){
                    int h = 1;  
                    while(i-h >=0 and j-h >=0 and j+h <m and (v[i-h][j-h] == '*') and (v[i-h][j+h] == '*') ){  
                        h++;  
                    }
                    if(h > k){
                        for(int x=0;x<h;x++){
                            already[i-x][j+x] = already[i-x][j-x] = true; 
                        } 
                    }
                }
            }
        }
        bool found = true;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j] == '*' and !already[i][j]){
                    found = false; 
                    break; 
                }
            }
            if(!found) break; 
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
/* 
wrong apporach 
for(int j=0;j<m;j++){
    if(v[i][j] == '*'){
        int h = 1; 
        int sz = 0; 
        int count = already[i][j]; 
        already[i][j] = true; 
        while(i-h >=0 and j-h >=0 and j+h <m and (v[i-h][j-h] == '*') and (v[i-h][j+h] == '*') ){ 
            count += already[i-h][j-h]; 
            count += already[i-h][j+h]; 
            already[i-h][j+h] = already[i-h][j-h] = true;
            h++; 
            sz++; 
        }
        // cout<<i<<" "<<h<<" "<<count<<endl; 
        if(count == (2*sz + 1)){
            continue; // this has already been considered 
        }
        if(sz < k){
            found = false; 
            break; 
        }
    }
    if(!found) break; 
}
*/