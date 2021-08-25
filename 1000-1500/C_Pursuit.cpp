// bruteforce is O(n)
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
        vector<vector<int> > v(2,vector<int>(n));
        int myScore = 0 ;
        int Escore = 0; 
        for(int i=0;i<n;i++) cin>>v[0][i]; 
        for(int i=0;i<n;i++) cin>>v[1][i]; 
        sort(all(v[1]),greater<int>());
        sort(all(v[0]),greater<int>()); 
        int sz = n-n/4; 
        for(int i=0;i<sz;i++){
            myScore += v[0][i]; 
            Escore += v[1][i]; 
        }
        int rounds = 0; 
        int ptr1 = sz; 
        int ptr2 = sz; 
        while(myScore < Escore){
            n++;
            rounds++; 
            if((n%4 == 0) and ptr1){
                // then size remains constant i.e. 100 replaces previous minima
                if(ptr1){
                    myScore += (100 - v[0][ptr1-1]);
                    ptr1--;
                }
                else myScore += 100; 
            }
            else{
                myScore += 100; 
                if(ptr2 < v[1].size()){
                    Escore += v[1][ptr2]; 
                    ptr2++;
                }
            }
        }
        cout<<rounds<<endl; 
    }
    return 0;
}