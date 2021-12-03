// let's consider inserting from ending 
// for last element 2 options
// if startiing chosen than it forms inversions with element < it 
// if ending chosen then forms inversions with element > it 
// order of inner element will never affect inversions with last elements so we can do int from here
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
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
vector<int> tree; 
void makeTree(vector<int> &a,int start,int end ,int index =1){
    if(start == end){
        tree[index] = a[start]; 
        return; 
    }
    int mid = (start + end)/2; 
    makeTree(a,start,mid,2*index); 
    makeTree(a,mid+1,end,2*index + 1); 
    tree[index] = tree[2*index] + tree[2*index + 1]; 
    return; 
}
int query(int ss,int se,int qs,int qe,int index =1){
    // ss se needs to be completly inside query points then return value 
    // for ss to be insider it must be >= qs ///******
    if(ss >= qs and se <= qe){
        return tree[index]; 
    }
    if(qs > se or ss > qe) return 0; 
    int mid = (ss + se)/2; 
    // cout<<mid<<" ";
    return query(ss,mid,qs,qe,2*index) + query(mid + 1,se,qs,qe,2*index + 1); 
}
// change in point change so no need to update on fly just change it in full tree at once 
void change(int ss,int se,int id,int index =1){
    if(!(id >= ss and id <= se)){
        return; 
    }
    if(ss == se and ss == id){
        tree[index]--; // we know always update is going to be remove 1 element
        return; 
    }
    int mid = (ss + se)/2; 
    if(id <= mid) change(ss,mid,id,2*index); 
    else change(mid+1,se,id,2*index + 1); 
    tree[index] = tree[2*index] + tree[2*index+1]; 
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
        map<int,int> mp; 
        for(int i=0;i<n;i++){
            cin>>v[i];
            if(mp[v[i]]){
                mp[v[i]]++; 
            } 
            else{
                mp[v[i]]= 1; 
            }
        }
        vector<int> tp,val; 
        for(auto i: mp){
            tp.push_back(i.first);
            val.push_back(i.second); 
        }
        int sz = val.size() - 1; 
        tree = vector<int>((sz + 1)*4 + 4,0); 
        makeTree(val,0,sz); 
        ll ans = 0; 
        for(int i=n-1;i>=0;i--){
            auto ele = v[i]; 
            int id = lower_bound(all(tp),ele) - tp.begin(); 
            int q = query(0,sz,0,id); 
            // this finds number of elements present from 0 to id 
            // remove elements at id 
            int left = q - val[id]; 
            int right = n - q; 
            // cout<<"val"<<ele<<" "<<val[id]<<" "<<left<<" "<<right<<endl; 
            // remove element from datastructure
            ans += min(left,right); 
            val[id]--; 
            change(0,sz,id); 
            n--;
        }
        cout<<ans<<endl; 
    }
    return 0;
}