// final s added is going to be containing only single character 
// in final string final character should be such that it divides whole string's count of this char evenly 
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
string check(string &s,int x){
    // previous s characters are in s
    set<char> st; 
    int n = s.length(); 
    st.insert(s[n-1]); 
    int i=n-x-1;
    vector<int> temp(200,0); 
    temp[s[n-1]] = x; 
    string res; 
    res += s[n-1]; 
    // we are taking prevous x characters of previous char
    while(i >=0){
        vector<int> v(26,0);
        while(i>=0 and st.find(s[i]) != st.end()){
            v[s[i]] ++; 
            i--; 
        } 
        char &ch = s[i];
        cout<<ch<<" "<<i<<endl;
        res += ch;  
        st.insert(s[i]); 
        while(i >=0 and st.find(s[i]) != st.end()){
            v[s[i]] ++; 
            i--; 
        }
        temp[ch] = v[ch];
        for(int j=0;j<200;j++){
            if(temp[j] != v[j]) return ""; 
        }
    }
    return res; 
}
int main()
{
    fast_cin();
    ll test;
    cin >> test;
    while(test--){
        string s; 
        cin>>s; 
        int n = s.length(); 
        auto ch = s[n-1]; 
        int count = 0; 
        for(auto &i: s){
            if(i == ch) count++; 
        }
        double preCount = 1; 
        int i=0;
        for(i=n-2;i>0 and s[i] == s[i-1];i++){
            preCount++; 
        }
        if(i == 0){
            cout<<s<<endl; 
            continue; 
        }
        cout<<count<<" "<<preCount<<endl; 
        // O(n*root(n))
        bool found = false; 
        for(int i=1;i<=min(preCount,sqrt(count));i++){
            if((count%i) == 0){
                cout<<"check "<<endl; 
                string res = check(s,i); 
                if(res.size() != 0){
                    found = true; 
                    cout<<res<<endl; 
                    break; 
                } 
            }
        }
        if(found == false){
            cout<<-1<<endl; 
        }
    }
    return 0;
}