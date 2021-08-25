// sort whole array
// impute elements btw other half 
// n is always even
#include<bits/stdc++.h>
using namespace std; 
int main(){
    int test; 
    cin>>test; 
    while(test--){
        int n; 
        cin>>n;
        n *= 2;  
        vector<int> v(n); 
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        int half = n/2;
        for(int i=half ;i<n;i++){
            cout<<v[i]<<" ";
            cout<<v[i-half]<<" ";
        }
        cout<<endl; 
    }
}