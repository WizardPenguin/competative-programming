// for case x says y to be cruemate for imposter 
// if x -> y crewmate 
// then if x is c then y is also c and if x is i then y is also i i.e. same type
// if x -> y imposter
// then if x is i then y is c and if x is c then y is i 
// using this we can color edges with 2 colors that tells that both nodes should be same or different types
// after then we can verify using bfs that this coloring is valid or contradicting each other 
#include <bits/stdc++.h> 
#include <complex>
#include <cmath>
// every node has 2 states either imposter or crewmate
// we'll iterate for given node taking it as both imposter and crewmate and find all
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
// imposter 0, crewmate 1
int main()
{
    fast_cin();
    ll test;
    cin >> test;
    while(test--){
        int n,m; 
        cin>>n>>m; 
        vector<pair<int,int> > graph[n+1]; 
        int x,y; 
        string s; 
        // edge 0 -> crewmate causes both to have same type 
        // edge 1 -> imposter causing both to be of different type 
        while(m--){
            cin>>x>>y>>s; 
            if(s[0] == 'i'){
                graph[x].push_back({y,1}); 
                graph[y].push_back({x,1}); 
            }
            else{
                graph[x].push_back({y,0}); 
                graph[y].push_back({x,0}); 
            }
        }
        vector<int> col(n+1,-1); 
        // if node is not already colored then color it with color 1 starting bfs for a connected component 
        // other color will automatically satisfy their values 
        int ans =0; 
        bool found = false; 
        queue<int> q; 
        for(int i=1;i<=n;i++){
            // count color1 and color2 nodes and take imposters as max(col1,col2) colors can be swaped by changing root of bfs
            if(col[i] == -1){
                col[i] = 1; 
                q.push(i); 
                x = y = 0; 
                while(!q.empty()){
                    auto par = q.front();
                    q.pop();  
                    if(col[par]){
                        x++;
                    }
                    else{
                        y++; 
                    }
                    for(auto &e: graph[par]){
                        auto ch = e.first; 
                        auto tp = e.second; 
                        if(col[ch] != -1){
                            // i.e. it's already colored then it should satisfy other comments about it's color 
                            if(tp == 1 and col[ch] == col[par]){
                                // cout<<ch<<" "<<par<<endl; 
                                found = true; 
                                goto end; 
                            }
                            else if(tp == 0 and col[ch] != col[par]){
                                // cout<<ch<<" "<<par<<endl; 
                                found = true; 
                                goto end; 
                            }
                        }
                        else{
                            // color this node based on condition 
                            if(tp == 1){
                                col[ch] = 1 - col[par]; 
                            }
                            else{
                                col[ch] = col[par]; 
                            }
                            q.push(ch); 
                        }
                    }
                }
                ans += max(x,y); 
            }
        }
        end:;
        if(found){
            cout<<-1<<endl; 
        }
        else{
            cout<<ans<<endl; 
        }
    }
    return 0;
}