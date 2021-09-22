// sorting even and odd elements 
// for each we have 2 option either choose our element or choose other's element 
// take the one which is going to give smallest loss
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
        int n; cin>>n; 
        vector<int> odd,even; 
        int num; 
        for(int i=0;i<n;i++){
            cin>>num; 
            if(num&1){
                odd.push_back(num);
            }
            else{
                even.push_back(num); 
            }
        }
        sort(all(odd),greater<int>()); 
        sort(all(even),greater<int>()); 
        int i,j; 
        i = j = 0;  
        int x = odd.size(); 
        int y = even.size(); 
        int move = 1; 
        long long s1,s2; 
        s1 = s2  =0; 
        while(i<x and j<y){
            // now check which is going to give largest profit 
            // better think only about current move we don't know what will be next move by other player
            if(move){
                if(even[j] > odd[i]){
                    s1 += even[j]; 
                    j++; 
                }
                else{
                    i++; 
                }
            }
            else{
                if(odd[i] > even[j]){
                    // taking own number is more profitable 
                    s2 += odd[i]; 
                    i++; 
                }
                else{
                    j++; 
                }
            }
            move = 1 - move; 
        }
        // cout<<s1<<" "<<s2<<endl; 
        while(i < x){
            // odd elements
            if(!move){
                s2 += odd[i]; 
            }
            i++; 
            move = 1 - move; 
        }
        while(j < y){
            if(move){
                s1 += even[j]; 
            }
            j++; 
            move = 1- move; 
        }
        // cout<<s1<<" "<<s2<<endl;
        if(s1 == s2){
            cout<<"Tie"<<endl; 
        } 
        else if(s1 > s2){
            cout<<"Alice"<<endl; 
        }
        else{
            cout<<"Bob"<<endl; 
        }
    }
    return 0;
}