// all time is divided into segments due to exams 
// pick both ends 1 by 1 of smallest segment and try to increase it's size to largest 
// when picking done new segment for size left + right formed and previous segments break;s 
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
#define s(x) segments[(x)]

void solve(){
    int n,d; 
    cin>>n>>d; 
    // find index of minimum and maximum segments starting points
    int start = 0; 
    vector<ll> segments;
    ll val; 
    for(int i=0;i<n;i+=1){
        cin>>val; 
        if(val - start - 1)
        segments.push_back(val - start - 1); 
        start = val; 
    }
    cerr<<segments.size()<<"size"<<endl; 
    n = segments.size();
    segments.push_back(d - start);
    for(auto &i: segments) cout<<i<<" "; cout<<endl; 
    // index of minimum and maximum segment 
    ll mini = min_element(all(segments)) - segments.begin();
    ll ans = segments[mini]; 
    cerr<<mini<<" "<<ans<<endl; 
    // we are going to remove 2 nbrs of our minima and insert a joined number 
    // after then find maxima out of them and break it using removed exam 
    // insert smaller part and find final minima for our operations
    if(mini > 0){
        // means we can remove mini and mini-1 th element 
        auto tp = segments; 
        ll sum = segments[mini] + segments[mini-1];
        tp.erase(tp.begin()  + mini);
        tp.erase(tp.begin() + mini-1);
        cerr<<"removed successfully on top "<<sum<<endl ;
        tp.push_back(sum);
        int maxi = max_element(all(tp)) - tp.begin();
        auto maxVal = tp[maxi]; 
        tp.erase(tp.begin() + maxi);
        tp.push_back((maxVal-1)/2);
        ans = max(ans,*min_element(all(tp)));
    }
    if(mini < n-1){
        auto tp = segments; 
        ll sum = segments[mini]+ segments[mini+1];
        tp.erase(tp.begin()+mini + 1);
        tp.erase(tp.begin() + mini);
        cerr<<"removed successfully "<<sum<<endl; 
        tp.push_back(sum);
        int maxi = max_element(all(tp)) - tp.begin();
        auto maxVal = tp[maxi]; 
        tp.erase(tp.begin() + maxi);
        tp.push_back((maxVal-1)/2);
        ans = max(ans,*min_element(all(tp)));
    }
    cout<<ans<<endl; 
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