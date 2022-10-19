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
bool check(vector<int> &v,ll mid,ll maxi){
    ll ones = (mid+1)/2; 
    ll twos = mid - ones; 
    int n = v.size(); 
    if(maxi&1){
        ll need = 0; 
        for(int i=0;i<n;i+=1){
            if((v[i]&1) == 0) ones -= 1; 
            need += (maxi-v[i])/2;  
        }
        if(ones < 0) return false; 
        if(need > ones/2 + twos) return false; 
    }
    else{
        ll need = 0; 
        for(int i=0;i<n;i+=1){
            if((v[i]&1)) ones -= 1; 
            need += (maxi-v[i])/2;  
        }
        if(ones < 0) return false; 
        if(need > ones/2 + twos) return false; 
    }
    return true; 
}
ll find(vector<int> &v,int maxi){
    ll left = 0; 
    ll right = 1e16 + 1; 
    while(left < right){
        ll mid = (left + right)/2; 
        if(check(v,mid,maxi)){
            right = mid; 
        }
        else{
            left = mid+1; 
        }
    }
    return left; 
}
void solve(){
    int n; 
    cin>>n; 
    vector<int> v(n);
    for(int i=0;i<n;i+=1) cin>>v[i];  
    // let's binary serach for reaching number n 
    ll maxi = *max_element(all(v)); 
    cout<<min({find(v,maxi),find(v,maxi+1)})<<endl; 
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





// ll required(vector<int> &v,int maxi){
//     int n = v.size(); 
//     if(maxi&1){
//         ll requiredOnes = 0; 
//         ll requiredSum = 0; 
//         for(int i=0;i<n;i+=1){
//             if((v[i]&1) == 0){
//                 requiredOnes+=1; 
//             }
//             requiredSum += (maxi-v[i])/2; 
//         }
//         requiredSum = ceil(requiredSum/(3.0))*2; 
//         requiredOnes = (requiredOnes-1)*2 +1; 
//         cerr<<maxi<<"  odd   "<<endl; 
//         cerr<<requiredSum<<" "<<requiredOnes<<endl; 
//         return max(requiredSum,requiredOnes); 
//     }
//     else{
//         ll requiredOnes = 0; 
//         ll requiredSum = 0; 
//         for(int i=0;i<n;i+=1){
//             if((v[i]&1)) requiredOnes += 1; 
//             requiredSum += (maxi - v[i])/2; 
//         }
//         requiredSum = ceil(requiredSum/(3.0))*2; 
//         requiredOnes = (requiredOnes-1)*2 + 1; 
//         cerr<<maxi<<"  even   "<<endl; 
//         cerr<<requiredSum<<" "<<requiredOnes<<endl; 
//         return max(requiredOnes,requiredSum); 
//     }
// }