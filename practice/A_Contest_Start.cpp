#include<bits/stdc++.h>
using namespace std; 
int main(){
    int test; 
    cin>>test; 
    while(test--){
        int n,x,t; 
        cin>>n>>x>>t; 
        // we need dissatisfaction w.r.t each person 
        int d = (t)/x;
        long long diss = 0; 
        if(n <= d){
            diss = ((n-1)*1ll*(n))/2;
        } 
        else{
            diss = n*1ll*d - (d*1ll*(d+1))/2;
            // diss = (d*1ll*(2*n - d - 1))/2;
        }
        cout<<diss<<endl; 
    }
}