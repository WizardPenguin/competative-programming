#include<bits/stdc++.h>
using namespace std; 
int main(){
    int test; 
    cin>>test; 
    while(test--){
        int n; 
        cin>>n; 
        vector<int> v(n);
        // we are bound to take all > final answer 
        int finalAnwer = 0; 
        for(int i=0;i<n;i++){
            cin>>v[i];
            finalAnwer += v[i]; 
        }
        if(finalAnwer%n == 0){
            finalAnwer/=n; 
        }
        else{
            cout<<(-1)<<endl; 
            continue; 
        }
        int ans = 0; 
        for(int i=0;i<n;i++){
            ans += (v[i] > finalAnwer);
        }
        cout<<ans<<endl; 
    }
}