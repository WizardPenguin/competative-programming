// we need to apply binary serach to find which message will do span 
#include<bits/stdc++.h>
using namespace std; 
#define ll long long
ll findCount(ll k,ll message){
    // cout<<message<<" "; 
    if(message > k){
        ll rem = message - k; 
        ll b = k - rem-1; 
        ll sub = (b*(b+1)/2 ) + k; 
        return(k*(k+1ll)) - sub; 
    }
    return message*(message+1)/2; 
}
ll bs(ll l,ll r,ll &x,ll &k){
    while(l < r){
        ll mid = (l + r)/2; 
        ll val = findCount(k,mid-1); 
        // cout<<val<<endl; 
        if(val < x){
            l = mid+1; 
        }
        else{
            r = mid-1; 
        }
    }
    return l; 
}
int main(){
    int test; 
    cin>>test; 
    while(test--){
        ll k,x; 
        cin>>k>>x; 
        ll messages = 2*k-1; 
        if(findCount(k,messages-1) < x){
            // cout<<"D"<<endl; 
            cout<<messages<<endl; 
        }
        else{
            ll ans = bs(1,messages,x,k); 
            if(findCount(k,ans-1) >= x){
                cout<<ans-1<<endl; 
            }
            else{
                cout<<ans<<endl; 
            }
        }
    }
}