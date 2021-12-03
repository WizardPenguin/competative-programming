// we'll check largest reactangle and try reducing it's 1 side or 2 or 3 or all 4 
// then one given minimum is going to be our next target and reduce it 
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
int findCst(vector<vector<char> > mat,int sx,int sy,int ex,int ey){
    int cost = 0; 
    for(int i=sx + 1;i<ex;i++){
        cost += (mat[i][sy] != '1'); 
        cost += (mat[i][ey] != '1'); 
    }
    for(int j=sy +1; j<ey;j++){
        cost += (mat[sx][j] != '1');
        cost += (mat[ex][j] != '1');
    }
    for(int i=sx + 1; i<ex;i++){
        for(int j=sy+1;j < ey;j++){
            cost += (mat[i][j] == '1'); 
        }
    }
    return cost; 
}
int main()
{
    fast_cin();
    ll test;
    cin >> test;
    int moves[4][2] = {0,0,0,-1,-1,0,-1,-1};
    while(test--){
        int n,m; 
        cin>>n>>m; 
        vector<vector<char> > v(n,vector<char>(m)); 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>v[i][j]; 
            }
        }
        int minCost =0 ; 
        pair<int,int> start = {0,0}; 
        pair<int,int> end = {n-1,m-1}; 
        array<int,4> ar; 
        int mini = INT_MAX; 
        minCost = findCst(v,start.first,start.second,end.first,end.second); 
        int cost = INT_MAX; 
        while(true){
            int temp = minCost; 
            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    int x1 = start.first - moves[i][0]; 
                    int y1 = start.second - moves[i][1]; 
                    int x2 = end.first + moves[j][0]; 
                    int y2 = end.second + moves[j][1];
                    if(abs(x2 - x1) >= 5 and abs(y2-y1) >= 4 and x1 >=0 and x2 >=0 and y1 >=0 and y2 >=0 ){
                        cost = findCst(v,x1,y1,x2,y2); 
                        if(cost < minCost){
                            cout<<cost<<endl; 
                            minCost = cost ; 
                            ar = {x1,y1,x2,y2}; 
                        }
                    }
                }
            }
            // if cost has changed then we need to move to that matrix 
            // otherwise this is our solution 
            if(minCost < temp){
                cout<<cost<<endl; 
                start.first = ar[0]; 
                start.second = ar[1]; 
                end.first = ar[2];  
                end.second = ar[3]; 
            }
            else{
                break; 
            }
        }
        cout<<minCost<<endl; 
    }
    return 0;
}