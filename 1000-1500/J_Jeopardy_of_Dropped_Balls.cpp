// let's try bruteforce 
// with check if no right or left move encountered for any row then this column will not change it's solution 
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
int ans = 0; 
bool dfs(vector<vector<int> > &v,int i,int j){
    // decide which move to take 
    // cout<<i<<" "<<j<<endl; 
    if(i == v.size()){
        // ans is which column it has landed
        ans = j ; 
        return true; 
    }
    if(v[i][j] == 1){
        v[i][j] = 2;
        dfs(v,i,j+1);  
    }
    else if(v[i][j] == 2){
        if(dfs(v,i+1,j)){
            v[i][j] = ans + 4; 
            return true; 
        } 
    }
    else if(v[i][j] == 3){
        v[i][j] = 2;
        dfs(v,i,j-1);   
    }
    else{
        ans = v[i][j] - 4; 
        return true;
    }
    return false; 
}
int main()
{
    fast_cin();
    ll test;
    test = 1; 
    while(test--){
        int n,m,k; 
        cin>>n>>m>>k; 
        vector<vector<int> > v(n,vector<int>(m,0)); 
        // we are also including one more state ans + 4: which tells after this node path is clear so return 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>v[i][j]; 
            }
        }
        // for(auto i: v){
        //     for(auto j: i) cout<<j<<" "; 
        //     cout<<endl; 
        // }
        while(k--){
            int c; 
            cin>>c; 
            ans = -1; 
            // cout<<c-1<<endl; 
            dfs(v,0,c-1); 
            cout<<ans + 1<<" "; 
        }
    }
    return 0;
}