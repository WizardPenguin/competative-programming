// at the end if solution exist we are remaining with x element which are same 
// if x is odd then we can shurely reduce it to 3 partitions of same size value
// if x is even then we can shurely reduce it to 2 partitions of same value using xor
// so we are left with problem to find such partitions 
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
    fast_cin();
    ll test;
    cin >> test;
    while(test--){
        int n; 
        cin>>n; 
        vector<int> v(n); 
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        // let's try using 2 partition i.e 1 number is dividing it to 2 parts
        int xorLeft = v[0];
        int xorRight = 0; 
        for(int i=1;i<n;i++){
            xorRight ^= v[i];           
        } 
        int tp = xorRight; 
        bool found = false;
        if(xorLeft == xorRight) found = true;  
        for(int i=1;i<n-1;i++){
            xorLeft ^= v[i]; 
            xorRight ^= v[i];
            if(xorLeft == xorRight){
                found = true; 
                break; 
            } 
        }
        // input will necessarily have atlest 2 elements
        xorLeft = v[0]; 
        xorRight = tp^v[1]; 
        tp = xorRight; 
        if(found){
            cout<<"YES"<<endl; 
            continue; 
        }
        // let i denotes left part ending exclusive 
        // and j denotes ending of 2nd/mid part of array 
        // remaining part is the right part 
        for(int i=1;i<n-1;i++){
            // from i index middle part starts
            int xorMid = v[i];
            if(xorMid == xorLeft and xorLeft == xorRight){
                found = true; break; 
            } 
            for(int j=i+1;j<n-1;j++){
                xorMid ^= v[j]; 
                xorRight ^= v[j]; 
                if(xorMid == xorLeft and xorLeft == xorRight){
                    found = true; break; 
                } 
            }
            if(found){
                break;
            }
            // remove current element from right side 
            xorRight = tp ^ v[i+1]; 
            xorLeft ^= v[i];
            tp = xorRight;  
        }
        if(found){
            cout<<"YES"<<endl; 
        }
        else{
            cout<<"NO"<<endl; 
        }
    }
    return 0;
}