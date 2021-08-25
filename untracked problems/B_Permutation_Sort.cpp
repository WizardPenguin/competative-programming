// if it's in descending order
// 4.3.2.1
// i requires 3 steps
#include<bits/stdc++.h>
using namespace std; 
int main(){
    int test; 
    cin>>test; 
    while(test--){
        int n; 
        cin>>n; 
        vector<int> v(n); 
        for(int i=0;i<n;i++) cin>>v[i];
        bool sorted = true; 
        for(int i=0;i<n-1;i++){
            if(v[i] > v[i+1]) sorted = false; 
        }
        if(sorted) cout<<0<<endl; 
        else if(v[0] == 1 or v[n-1] == n) cout<<1<<endl; 
        else if(v[0] == n and v[n-1] == 1) cout<<3<<endl; 
        else{
            cout<<2<<endl; 
        }
    }
}