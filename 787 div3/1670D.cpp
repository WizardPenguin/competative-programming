#include<bits/stdc++.h>
using namespace std;
#define N 1000000009
int main() {
    int test; 
    cin>>test; 
    vector<int> res; 
    vector<int> steps; 
    int sum = 0; 
    int i = 1; 
    bool taken = false; 
    int s = 1;  
    while(sum < N){
        if(i&1){
            sum += i*2; 
            i+=1; 
        }
        else{
            if(taken){
                sum += i*2; 
                i+=1; 
                taken = false; 
            }
            else{
                sum += i*2; 
                taken = true; 
            }
        }
        s += 1; 
        res.push_back(sum); 
        steps.push_back(s); 
    }
    while(test--){
        int n; 
        cin>>n; 
        int lb = lower_bound(res.begin(),res.end(),n) - res.begin(); 
        cout<<steps[lb]<<endl; 
    }
}
