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
int count(vector<int> &v,int start){
    // unbalanced odd and even respectively 
    stack<int> uo; 
    stack<int> ue; 
    for(int i=0;i<v.size();i++){
        if(v[i] != start){
            if(v[i]) uo.push(i); 
            else ue.push(i); 
        }
        start ^= 1; 
    }
    int ans = 0; 
    while(!uo.empty()){
        ans += abs(uo.top() - ue.top()); 
        uo.pop();
        ue.pop(); 
    }
    return ans; 
}
int main()
{
    fast_cin();
    ll test;
    cin >> test;
    while(test--){
        int n;
        cin>>n; 
        vector<int> v(n); 
        for(int i=0;i<n;i++){
            cin>>v[i]; 
            v[i] = v[i]&1; 
        }
        // let resulting sequence starts with even or odd then consecutive odd even 
        // if given sequence has no maching character then replace it with nearest other invlaid required character
        // this replacement will cost abs(i-j) where i,j are id of numbers which needs to be swaped 
        // for given unbalanced id i,j that need to be swapped all elements in middle are going to be correct
        // now if we manually use adjacent swaps to eventually swap those values we'll get abs(i-j) steps 
        int even = 0; 
        int odd = 0; 
        for(int i=0;i<n;i++){
            if(v[i]){
                odd++; 
            }
            else even++; 
        }
        if(abs(even - odd) > 1){
            cout<<-1<<endl;  
        }
        else{
            if(odd == even){
                cout<<min(count(v,0),count(v,1))<<endl; 
            }
            else if(odd > even){
                cout<<count(v,1)<<endl; 
            }
            else{
                cout<<count(v,0)<<endl; 
            }
        }
    }
    return 0;
}