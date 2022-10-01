#include<bits/stdc++.h>
using namespace std; 
#define ll long long 
#define vvi vector<vector<int> >
ll dp[1003][102]; 
int n,p;
ll findValue(ll start,ll end,ll reach,ll prevValue){
    // we have some previous value 
    // and i is final to reach 
    return min(abs(start - prevValue) + abs(end - start) + abs(end-reach), 
    abs(end - prevValue) + abs(start - end) + abs(start - reach)); 
}
ll recursive(vvi &v,int i,int j,int prevValue){
    // selecting jth of previous on and now we are on ith row 
    if(i == n){
        return 0; // no more cost applied 
    }
    if(dp[i][j] != -1) return dp[i][j]; 
    auto &arr = v[i]; 
    ll ans = LLONG_MAX; 
    int start,end,reach; 
    for(int id=0;id<p;id+=1){
        // take any of them
        reach = arr[id];  
        if(id == 0){
            start = arr[1]; 
        }
        else{
            start = arr[0];  
        }
        if(id == (p-1)){
            end = arr[p-2]; 
        }
        else{
            end = arr.back();  
        }
        ans = min(ans, findValue(start,end,reach,prevValue) + recursive(v,i+1,id,reach)); 
    }
    return dp[i][j] = ans; 
}
/// ########## handle case when n == 1
int main(){
    int test; 
    cin>>test; 
    for(int i=1;i<=test;i+=1){
        cout<<"Case #"<<i<<": ";  
        cin>>n>>p; 
        vvi v(n,vector<int>(p)); 
        for(int i=0;i<n;i+=1){
            for(int j=0;j<p;j+=1){
                cin>>v[i][j]; 
                dp[i][j] = -1; 
            }
            sort(v[i].begin(),v[i].end()); 
        }
        ll ans = 0; 
        int prevValue = 0; 
        if(p == 1){
            for(int i=0;i<n;i+=1){
                ans += abs(prevValue - v[i][0]); 
                prevValue = v[i][0]; 
            }
            cout<<ans<<endl; 
            return 0; 
        }
        // handle case when 
        // now we have found solution 
        cout<<recursive(v,0,0,0)<<endl; 
    }
    return 0; 
}