// he wan't to destroy least and greates element
// either he goes from one side towards both
// or go from both end to get both of them
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
        int idMax = max_element(v.begin(),v.end()) - v.begin(); 
        int idMin = min_element(v.begin(),v.end()) - v.begin(); 
        int ans1 = max(idMax,idMin) + 1; 
        int ans2 = n - min(idMin,idMax) ;
        // removing left elements and adding smaller id +1 to make it inclusive
        int ans3 = n - abs(idMax - idMin) +1;
        cout<<min(ans1,min(ans2,ans3))<<endl; 
    }
}