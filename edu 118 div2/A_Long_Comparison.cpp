#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
#include <cmath>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
string make(int x){
    string res; 
    while(x){
        res += '0' + x%10; 
        x/=10; 
    }
    reverse(all(res)); 
    // while(p--) res += "0"; 
    return res; 
}
void solve(){
    int x,p1,p2; 
    cin>>x>>p1; 
    string s1 = make(x); 
    cin>>x>>p2; 
    string s2 = make(x); 
    // cout<<s1<<" "<<s2<<endl; 
    int len1 = s1.length() + p1; 
    int len2 = s2.length() + p2; 
    if(len1 > len2){
        cout<<">"<<endl; 
    }
    else if(len1 < len2){
        cout<<"<"<<endl; 
    }
    else{
        int mini = min(s1.length(),s2.length()); 
        bool found = false; 
        for(int i=0;i<mini;i++){
            if(s1[i] == s2[i]) continue; 
            else if(s1[i] > s2[i]){
                found = true; 
                cout<<">"<<endl; 
                return; 
            }
            else{
                found = true; 
                cout<<"<"<<endl; 
                return; 
            }
        }
        // if(found)
        if(s1.length() > mini){
            while(mini < s1.length() and s1[mini] == '0') mini++; 
            if(mini == s1.length()){
                cout<<"="<<endl; 
                return; 
            }
            cout<<">"<<endl; 
        }
        else if(s2.length() > mini){
            while(mini < s2.length() and s2[mini] == '0') mini++; 
            if(mini == s2.length()){
                cout<<"="<<endl; 
                return; 
            }
            cout<<"<"<<endl; 
        }
        else{ /// only zeros remaining to compare 
            cout<<"="<<endl; 
        }
    }

    return;
}
int main()
{
    fast_cin();
    ll test;
    cin >> test;
    while(test--){
        solve();
    }
    return 0;
}