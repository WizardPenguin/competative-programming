// store left and right segment which needs to be baught so that all in middle can be baught in free
// now any of left or right is superset of other then we need to toke one with min cost out of them 
// left shoudl start with min number till now and right should end at max number till now 
// we have to take left and right with min cost 
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
struct tripli{
    int l = INT_MAX; 
    int r = 0; 
    int c = INT_MAX; 
}; 
void solve(){
    int n; 
    cin>>n; 
    int l,r,c; 
    // we need to store interval of left and right with thier cost 
    // there is case of complete interval 
    // we are storing it separately so that left and right could do their work properly 
    tripli left,right,tp,complete; 
    left = right =  {INT_MAX,0,INT_MAX};
    for(int i=0;i<n;i++){
        cin>>tp.l>>tp.r>>tp.c; 
        if(left.l > tp.l){
            // hard change 
            left = tp; 
        }
        else if(left.l == tp.l){
            if(left.c > tp.c){
                left = tp; 
            }
        }
        if(right.r < tp.r ){
            // hard change 
            right = tp; 
        }
        else if(right.r == tp.r){
            if(right.c > tp.c){
                right = tp; 
            }
        }
        if(tp.l == left.l and tp.r == right.r ){
            if(complete.l == tp.l and complete.r == tp.r){ // already such found 
                complete.c = min(complete.c,tp.c);
            }
            else{
                complete = tp; 
            }
        }
        else if(complete.l != left.l or complete.r != right.r){ // we don't have complete set 
            complete.c = INT_MAX; 
        }
        cout<<min(complete.c, left.c + right.c)<<ln; 
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