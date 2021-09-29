// let set order then using value given 
// when 2nd person remove element from top we'll mark it removed 
// so when first person try to remove it it'll come to know that he's already served 
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
    set<pair<int,int> > st; 
    // i need largest value on top and smallest id on top 
    // so we'll insert value,-id in set
    vector<bool> v(500005,false);
    int ptr1 = 0; 
    int ptrinsert = 0; 
    int x; 
    int y; 
    while(test--){
        cin>>x; 
        if(x == 1){
            cin>>y; 
            st.insert({y,-ptrinsert});
            ptrinsert++; 
        }
        // maximum element of set can be found at st.rbegin()
        else if(x == 3){
            auto tp = *st.rbegin(); 
            // cout<<tp.first<<endl; 
            while(v[-tp.second] == true){
                st.erase(tp); 
                tp = *st.rbegin(); 
            }
            st.erase(tp);
            cout<<-tp.second + 1<<" "; 
            v[-tp.second] = true;
        }
        else{
            while(v[ptr1]) ptr1++; 
            cout<<(ptr1 + 1)<<" "; 
            v[ptr1] = true; 
            ptr1++; 
        }
    }
    cout<<endl; 
    return 0;
}