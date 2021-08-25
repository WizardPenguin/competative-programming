#include<bits/stdc++.h>
using namespace std; 
#define MAX 1000000007
int main(){
    int test; 
    cin>>test; 
    while(test--){
        int n;
        cin>>n; 
        int iteration ;
        cin>>iteration; 
        string s; 
        cin>>s;
        // update endtime of each node by triversing from both side
        vector<int> v(n+1,MAX);
        if(s[0] == '1') v[0] = 0;
        for(int i=1;i<n;i++){
            if(s[i] == '1'){
                v[i] = 0; 
            }
            else{
                v[i] = min(v[i],v[i-1] + 1); 
            }
        }
        for(int i=n-2; i >=0;i--){
            if(s[i] == '1') continue; 
            if(v[i] == v[i+1] + 1){
                // it gives same distance from each side 
                v[i] = MAX;
            }
            else v[i] = min(v[i],v[i+1] + 1);
        }
        for(int i=0;i<n;i++){
            // cout<<v[i]<<" ";
            if(v[i] <= iteration){
                s[i] = '1';
            }
        }
        // cout<<endl; 
        cout<<s<<endl; 
    }
    return 0; 
}