// we have to make moves max;
// if point is at end then to move max we need opposit ends 
// if point is in mid then move towards it's opposite diagonal ends
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--){
        int m,n,i,j;
        cin>>n>>m; 
        cin>>i>>j; 
        if((i==1 and j==1) or (i == n and j == n) ){
            cout<<n<<" "<<1<<" "<<1<<" "<<m<<endl; 
        }
        else{
            cout<<1<<" "<<1<<" "<<n<<" "<<m<<endl; 
        }
    }
}