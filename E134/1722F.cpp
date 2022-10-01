#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<vector<ll> > vvll;
typedef vector<vector<pll> > vvpll;
typedef vector<pll> vpll;
typedef vector<pii> vpii;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<vector<bool> > vvb;
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
// there should be no diagonal connection 
// there should be no component size != 3
// there should not be any straight line of size = 3
int n,m;
vpii moves = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}}; 
int dfs(vs &v,int x,int y){
    if(x < 0 or y < 0 or x >= n or y >= m or v[x][y] == '.') return 0; 
    v[x][y] = '.';
    int count = 1 ; 
    for(auto &[dx,dy]: moves){
        count += dfs(v,x+dx,y+dy); 
    }
    return count; 
}
bool checkConnectedComponents(vs v){
    for(int i=0;i<n;i+=1){
        for(int j=0;j<m;j+=1){
            int sz = dfs(v,i,j); 
            if(sz and sz != 3){
                return false; 
            }
        }
    }
    return true; 
}
bool checkL(vs &v){
    int count = 0; 
    for(int i=0;i<n;i+=1){
        for(int j=0;j<m;j+=1){
            if(v[i][j] == '*'){
                count += 1; 
                vpii mv = {{-1,0},{0,1},{1,0},{0,-1}};
                string s; 
                for(auto &[dx,dy] : mv){
                    int x = i + dx; 
                    int y = j + dy; 
                    if(x < 0 or y < 0 or x >= n or y >= m or v[x][y] == '.'){
                        s += '0'; 
                    }
                    else{
                        s += '1'; 
                    }
                }
                s += *s.begin(); 
                if(s.find("11") != string::npos){
                    count-=3; 
                }
            }
        }
    }
    // cout<<count<<endl; 
    return count == 0; 
}
void solve(){
    cin>>n>>m; 
    vs v(n); 
    for(auto &s: v) cin>>s; 
    if(checkConnectedComponents(v) and checkL(v)){
        cout<<"YES"<<endl; 
    }
    else{
        cout<<"NO"<<endl; 
    }
}
int main(){
    fast_cin();
    ll test;
    cin >> test;
    while(test--){
        solve();
    }
    return 0;
}