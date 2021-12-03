// bruteforce code with starting point as 0
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
void print(){
    int n=10; 
    for(int k=0;k<=3;k++){
        int x = k; 
        for(int i=1;i<=n;i++){
            if((x%2) == 0){
                x -=i; 
            }
            else{
                x+=i; 
            }
            cout<<(x-k)<<" "; 
        }
        cout<<endl; 
    }
    cout<<endl; 
}
int main()
{
    fast_cin();
    ll test;
    cin >> test;
    while(test--){
        ll x,n; 
        cin>>x>>n; 
        // print(); 
        ll rem = n%4; 
        ll xrem = abs(x)%4; 
        // dbg(xrem); 
        if(xrem == 1){
            if(rem == 0){
            cout<<x <<endl; 
            }
            else if(rem == 1){
                cout<<(x + n )<<endl; 
            }
            else if(rem == 2){
                cout<<x-1<<endl; 
            }
            else{
                cout<<(x-(n + 1))<<endl; 
            }
        }
        else if(xrem == 0){
            if(rem == 0){
            cout<<x<<endl; 
            }
            else if(rem == 1){
                cout<<(x - n)<<endl; 
            }
            else if(rem == 2){
                cout<<x+1<<endl; 
            }
            else{
                cout<<(x + n + 1)<<endl; 
            }
        }
        else if(xrem == 2){
            if(rem == 0){
            cout<<x <<endl; 
            }
            else if(rem == 1){
                cout<<(x - n )<<endl; 
            }
            else if(rem == 2){
                cout<<x + 1 <<endl; 
            }
            else{
                cout<<(x + n + 1)<<endl; 
            }
        }
        else{
            if(rem == 0){
            cout<<x <<endl; 
            }
            else if(rem == 1){
                cout<<(x + n)<<endl; 
            }
            else if(rem == 2){
                cout<<x -1<<endl; 
            }
            else{
                cout<<(x - (n + 1))<<endl; 
            }
        }
    }
    return 0;
}