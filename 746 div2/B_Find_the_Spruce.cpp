// try to check for spouces of each length 
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
        // we need to find spuces of each length if length i's spuce are not there then none of > i are there 
        // 1≤i≤k all cells with the row number x+i−1 and columns in range [y−i+1,y+i−1]
        int n,m; 
        cin>>n>>m; 
        vector<vector<int> > mat(n,vector<int>(m)); 
        char val; 
        int count =1; 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>val; 
                if(val == '*'){
                    mat[i][j] = count++; 
                }
                else{
                    mat[i][j] = -1; 
                } 
            }
        }
        int ans = 0;  
        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                // ** we don't need to interate again and again for each length 
                // just check for current length since we only reached here because previous length are valid 
                for(int len= 1; row +len <= n and col + len <= m and col - len + 1 >= 0; len++){
                    bool found = true; 
                    int x = row + len -1; 
                    int y1 = col - len + 1; 
                    int y2 = col + len - 1; 
                    if(mat[x][y1] != -1 and mat[x][y2] != -1){
                        int dist = mat[x][y2] - mat[x][y1] + 1 ; 
                        int d = y2 - y1 + 1; 
                        if(d != dist) break; 
                        else ans++; 
                    }
                    else break; 
                }
            }
        } 
        cout<<ans<<endl; 
    }
    return 0; 
}