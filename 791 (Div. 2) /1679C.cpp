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
#define N 1000005
class segmentTree{
    public: 
    vector<int> t; 
    int n; 
    segmentTree(int n){
        this->n = n; 
        t = vector<int>(4*n + 12,0); 
    }
    void build(int a[], int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            t[v] = t[v*2] + t[v*2+1];
        }
    }
    int sum(int v, int tl, int tr, int l, int r) {
        if (l > r) 
            return 0;
        if (l == tl && r == tr) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return sum(v*2, tl, tm, l, min(r, tm))
            + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
    }
    void update(int v, int tl, int tr, int pos, int new_val) { // point update 
        if (tl == tr) {
            t[v] = new_val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v*2, tl, tm, pos, new_val);
            else
                update(v*2+1, tm+1, tr, pos, new_val);
            t[v] = t[v*2] + t[v*2+1];
        }
    }
};
map<int,int> rc,cc; 
void update(segmentTree &tree,int x){ // add 1 to count 
    tree.update(1,0,tree.n,x,1); 
}
void reduce(segmentTree &tree,int x){ // remove 1 from count
    tree.update(1,0,tree.n,x,0); 
}
int sum(segmentTree &tree,int x,int y){
    return tree.sum(1,0,tree.n,x,y); 
}
void solve(){
    int n,q; 
    cin>>n>>q;
    segmentTree row(n + 3),col(n + 3); 
    int type,x,y,x1,y1;  
    while(q--){
        cin>>type>>x>>y; 
        if(type == 1){
            // inserting // adding to count of row and column; 
            if(not rc[x]) update(row,x); 
            if(not cc[y]) update(col,y); 
            rc[x] += 1; 
            cc[y] += 1; 
        }
        else if(type == 2){
            rc[x] -= 1; 
            cc[y] -= 1;
            if(not rc[x]) reduce(row,x);
            if(not cc[y]) reduce(col,y); 
        }
        else if(type == 3){
            cin>>x1>>y1; 
            int s1 = sum(row,x,x1); 
            int s2 = sum(col,y,y1); 
            if(s1 == (x1 - x + 1) or s2 == (y1 - y + 1)){
                cout<<"Yes"<<ln; 
            }
            else{
                cout<<"No"<<ln; 
            }
        }
    }
}
int main(){
    fast_cin();
    solve(); 
    return 0;
}