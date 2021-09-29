// array is increasing can't have solution 
// array having <= 2 elements ha many solutions 
// x -> y be decreasing elements in array then m = y - x-c
// let x->y be increasing part of array then c = y - x
// m should be > 0 during this calculation and it should satisfy all the element of array 
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
        // it doesn't cover when all are equal 
        bool equal = true; 
        for(int i=1;i<n;i++){
            if(v[i] != v[i-1]){
                equal = false; 
                break; 
            }
        }
        if(equal){
            cout<<0<<endl; 
            continue; 
        }
        bool increasing = true; 
        bool decreasing = true; 
        for(int i=0;i<n-1;i++){
            if(v[i] < v[i+1]){
                // if it's less it can't be decreasing array 
                decreasing = false; 
            }
        }
        for(int i=0;i<n-1;i++){
            if(v[i] > v[i+1]){
                increasing = false; 
            }
        }
        if(increasing or decreasing){
            // we need to check they are in AP
            bool ap = true; 
            int d= v[1] - v[0]; 
            for(int i=1;i<n;i++){
                int expected = v[i-1] + d; 
                if(expected != v[i]){
                    ap = false; 
                    break; 
                }
            }
            if(ap){
                cout<<0<<endl; 
            }
            else{
                cout<<-1<<endl; 
            }
            continue; 
        }
        // check for strictly increasing or decreasing array 
        ll c,m;
        c = m = -1; 
        // since this is not strictly increasing neither decreasing 
        for(int i=0;i<n-1;i++){
            if(v[i] < v[i+1]){
                c = v[i+1] - v[i]; 
                break; 
            }
        }
        for(int i=0;i<n-1;i++){
            if(v[i] > v[i+1]){
                m = v[i] + c - v[i+1]; 
                break; 
            }
        }
        // m also needs to be largest out of all numbers out here 
        int maxi = *max_element(all(v)); 
        if(m <= 0 or m <= maxi){
            // cout<<"m couldn't be found"<<endl; 
            cout<<-1<<endl; // no solution 
            continue; 
        }
        bool found = true; 
        // now check weather this m and c are consistent 
        for(int i=1;i<n;i++){
            int pred =(v[i-1] + c)%m;
            if(pred != v[i]){
                found = false; 
            }
        }
        if(found){
            cout<<m<<" "<<c<<endl; 
        }
        else{
            cout<<-1<<endl; 
        }
    }
    return 0;
}