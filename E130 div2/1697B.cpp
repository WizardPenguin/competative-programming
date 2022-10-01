//           <|---- Written By Shreyash Verma a.k.a Drizzer on x/y/2022 ----|>

/*------------------------------------<AARAMBH>----------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

//________________________________| Abbreviations |___________________________________||

#define ld long double
#define int long long
#define mp make_pair
#define pb push_back
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define PQ(type) priority_queue<type>
/*
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
*/
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef set<int> si;
typedef vector<pair<int,int>> vii;
typedef map<int,int> mii;
typedef map<char,int> mci;

//___________________________________| Numbers |______________________________________||

#define pi 3.141592653589793238
const int N = 1e5+10;
const int N2 = 1e7+10;
const int mod = 1e9+7;
//__________________________________| Debugging |_____________________________________||
/*
template<typename T, typename V>
    void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
    template<typename T>
    void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
    void _print() {cerr << "]\n";}
    template <typename T, typename... V>
    void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
*/
//__________________________________| Functions |_____________________________________||

/*void BinaryForm(int n){
    for(int i=10;i>=0;--i){
        cout<<((n>>i) & 1);
    }
    cout<<"\n";
}*/

/*int binary_expo(int a, int b,int m){
    int result = 1;
    while(b){
        if(b&1){
            result = (result * 1LL * a) % m;
        }
        a = (a * 1LL * a)%m;
        b >>= 1;
    }
    return result;
}*/

/*int binary_search(int arr[],int n,int x){
    int r = n-1,l = 0;
    while(r>=l){
        int m = (l+r)/2;
        if(arr[m]==x)
            return m;
        else if(arr[m]<x)
            l = m+1;
        else
            r = m-1;
    }
    return 0;
}*/

/*void funcsolv(){
    
}*/

/*void dynamic_programming(){
    
}*/

//_______________________________| Normal Changes |___________________________________||

void uttar();

signed main()
//int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        uttar();
    }
    return 0;
}

//_______________________________| Prashn ka Uttar |__________________________________||

void uttar()
{
    int sum = 0;
    int n,m;
    cin>>n>>m;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum += arr[i];
    }
    if(sum>m){
        cout<<sum-m<<"\n";
    }
    else{
        cout<<0<<"\n";
    }
}

/*--------------------------------------<ANNT>----------------------------------------------*/
