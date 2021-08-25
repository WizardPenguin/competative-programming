// brew the portion
// make the ration = required in min steps
// 100 test cases; 
// find highest common divisor and remove it from portion to do task in min steps
#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    if(a == 0) return b; 
    return gcd(b%a,a);
}
int main(){
    int test; 
    cin>>test; 
    while(test--){
        int k;
        cin>>k;
        int portion1 = k; 
        int portion2 = 100 - k; 
        // we need lcm of portion 1 and 2 and remove it from them 
        int g = gcd(portion1,portion2); 
        portion1/= g;
        portion2/= g; 
        // cout<<k<<" "<<g<<" "<<endl; 
        cout<<(portion1 + portion2)<<endl; 
    }
}