// we are desired to make different sets of love and hate
// something sort of 2 coloring 
// for each edge both the nodes should be in opposit set they they hates else in same set 
// if they haven't been added to set till now then we can just add then as lovers of each other or haters
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
#define N 1e5 + 5
// WE NEED TO CREATE LOVERS AND HATERS SET W.R.T EACH NUMBER    
// since those sets migh connect with each other due to lover and hater relation we need to create them in same array 
v32 par(2*N,-1);
v32 rnk(2*N,1); // store number of element in lover / hater set 
int find(int x){
    // finding parent of their lovers set 
    if(par[x] == -1) return x; 
    return par[x] = find(par[x]); 
}
void join(int x,int y){
    int prx = find(x);
    int pry = find(y); 
    if(prx == pry){
        // cout<<"error"<<endl; // generated when pair's data has already considered in previously formed set
        return;
    }
    else{
        if(rnk[prx] > rnk[pry]){
            // add smaller one to larger one 
            par[pry] = prx; 
            rnk[prx] += rnk[pry]; 
        }
        else{
            par[prx] = pry; 
            rnk[pry] += rnk[prx]; 
        }
    }
    return; 
}
bool joinLovers(int x,int y){
    // if we need to join this edge then we need to make shure no one is hater of each other with any relation  
    // parent of hate set of x shouldn't have y as child 
    // parent of hate set of y shouldn't have x and child 
    int prhx = find(x+N); 
    int prhy = find(y+N); 
    int prlx = find(x); 
    int prly = find(y); 
    if(prhx == prly or prhy == prlx ){
        return false; 
    }
    // otherwise join them 
    // join their hate sets and lover sets togethers 
    join(prlx,prly); 
    join(prhx,prhy); 
    return true; 
}
bool joinHater(int x,int y){
    int prhx = find(x+N); 
    int prhy = find(y+N); 
    int prlx = find(x); 
    int prly = find(y);
    // x's lovers shoudn't love y's lovers 
    if(prlx == prly or prhx == prhy ){
        return false; 
    }
    join(prlx,prhy); 
    join(prly,prhx); 
    return true; 
}
int main()
{
    fast_cin();
    int n,m,q; 
    cin>>n>>m>>q;
    vector<string> v(n);  
    unordered_map<string,int> id; 
    for(int i=0;i<n;i++){
        cin>>v[i]; 
    }
    sort(all(v)); 
    for(int i=0;i<n;i++){
        id[v[i]] = i; 
    }
    // mapping string to integers 
    // now our next goal is to add edges 
    string x,y; 
    int t; 
    while(m--){
        cin>>t>>x>>y; 
        if(t == 1){
            if(joinLovers(id[x],id[y])) cout<<"YES"<<endl; 
            else cout<<"NO"<<endl;  
        }
        else{
            if(joinHater(id[x],id[y])) cout<<"YES"<<endl; 
            else cout<<"NO"<<endl; 
        }
    }
    while(q--){
        cin>>x>>y; 
        int idx = id[x]; 
        int idy = id[y]; 
        int prhx = find(idx+N); 
        int prhy = find(idy+N); 
        int prlx = find(idx); 
        int prly = find(idy); 
        if(prhx == prhy and prlx == prly){
            cout<<1<<endl; 
        }
        else if(prhx == prly and prlx == prhy){
            cout<<2<<endl; 
        }
        else cout<<3<<endl; 
    }
    // we have joined haters and lovers 
    return 0;
}