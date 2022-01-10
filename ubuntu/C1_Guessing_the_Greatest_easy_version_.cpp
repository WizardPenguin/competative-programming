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
typedef vector<vector<bool> > vvb;
typedef vector<string> vs;
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
int global; 
int mid,v2,v1,chk; 
int recursive(int l,int r){
    if(l == r-1){
        // only 2 elements left 
        if(l == global) return r; 
        else return l; 
    }
    else if(l == r-2){
        // means 3 elements are there 
        cout<<"? "<<l<<" "<<l+1<<endl; 
        fflush(stdout); 
        cin>>v1; 
        if(v1 == global){
            // means l and l+1 are having maxima and 2nd maxima or size == 2
            if(global == l+1) return l;
            else return l+1; 
        }
        else{
            // means global and v1 are excluded and remaining index is result
            set<int> st = {l,l+1,r}; 
            st.erase(v1); 
            st.erase(global); 
            return *st.begin(); 
        }
    }
    mid = l + (r - l)/2; 
    if(global <= mid){
        // means we can search in this range 
        cout<<"? "<<l<<" "<<mid<<endl;
        fflush(stdout);  
        cin>>v1; 
        if(v1 == global){
            // means both are in same part 
        }
        else{
            // global is maxima of this part so we need to go to next part 
            // but before going we need to find global for that part 
            cout<<"? "<<mid+1<<" "<<r<<endl; 
            fflush(stdout); 
            cin>>global; 
            return recursive(mid+1,r); 
        }
    }
    else{
        cout<<"? "<<mid + 1<<" "<<r<<endl; 
        fflush(stdout);
        cin>>v1; 
        if(v1 == global){// both in same part
            return recursive(mid+1,r); 
        }
        else{
            // ned to go other way 
            cout<<"? "<<l<<" "<<mid<<endl; 
            fflush(stdout); 
            cin>>global; 
            return recursive(l,mid);
        }
    }
}
int main(){
    fast_cin();
    int n; 
    cin>>n; 
    cout<<"? 1 "<<n<<endl; 
    fflush(stdout); 
    cin>>global; 
    // each recursive call assumes that their global has already been calculated
    int res = recursive(1,n); 
    cout<<"! "<<res<<endl; 
    // cout<<res<<endl; 
    return 0;
}