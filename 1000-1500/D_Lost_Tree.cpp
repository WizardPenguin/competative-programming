// we are desired to reduce number of calls
// in reach call we can exactly find neighbouring edges 
// so using 1 call we decide level of tree using given distance
// then out of given 3 we can use only middle level or outer 2 levels for less call 
// so at starting we decide either odd or even levels we are going to ask for and hence find solution
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
    int n; 
    cin>>n; 
    // nodes are 1 indexed; 
    // ask first question for getting how many nodes are at which level 
    cout<<"? 1"<<endl; 
    cout<<endl; 
    // 1 node already considered at even level so if odd level is selected mark 1 turn already waisted  
    int ec = 0,oc = 1; 
    vector<int> v(n+1); 
    for(int i=1;i<=n;i++){
        cin>>v[i]; 
        if(v[i] &1){
            oc++; 
        }
        else{
            ec ++; 
        }
    }
    vector<pair<int,int> > edges; 
    // first level already found 
    int x; 
    if(oc > ec){
        // if even count is less 
        for(int i=1;i<=n;i++){
            if(v[i] == 1){
                edges.push_back({1,i}); 
            }
        } 
        for(int i=2;i<=n;i++){ // node 1 has already been considered at leve = 0
            if(v[i]&1) continue; 
            else{
                cout<<"? "<<i<<endl; 
                cout<<endl; 
                for(int j=1;j<=n;j++){
                    cin>>x; 
                    if(x == 1){
                        edges.push_back({i,j}); 
                    }
                }
            }
        }
    }
    else{
        for(int i=2;i<=n;i++){
            if(v[i]&1){
                // then do the work; 
                cout<<"? "<<i<<endl; 
                cout<<endl; 
                for(int j=1;j<=n;j++){
                    cin>>x; 
                    if(x == 1){
                        edges.push_back({i,j}); 
                    }
                }
            }
        }
    }
    cout<<"!"<<endl; 
    for(auto &i: edges){
        cout<<i.first<<" "<<i.second<<endl; 
    }
    cout<<endl; 
    return 0;
}