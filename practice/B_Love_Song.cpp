#include<bits/stdc++.h>
using namespace std; 
int main(){
    int n,t; 
    cin>>n>>t; 
    string s; 
    cin>>s; 
    // precomputation
    vector<vector<int> > pre(n + 1);
    vector<int> previous(26,0);
    pre[0] = previous; 
    for(int i=0;i<n;i++){
        previous[s[i] - 'a']++; 
        pre[i + 1] = previous;
    }
    while(t--){
        int l,r;
        cin>>l>>r; 
        for(int i=0;i<26;i++){
            previous[i] = pre[r][i] - pre[l-1][i];
        }
        int cost = 0; 
        for(int i=0;i<26;i++){
            cost += previous[i]* ( i +1); 
        }
        cout<<cost<<endl; 
    }
    return 0; 
}