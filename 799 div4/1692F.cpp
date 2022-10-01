#include<bits/stdc++.h>
using namespace std;

#define endl "\n" 
#define ll long long
#define rep(i,n) for(ll i=0;i<n;i++)
#define loop(i,a,b) for(ll i=a;i<=b;i++)
#define deb(x) cout<<#x<<'='<<x<<endl
#define vi vector <int>
#define vs vector <string>
#define vc vector <char>
#define vl vector <ll>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define pb push_back
#define F first
#define S second
#define all(c) (c).begin(),(c).end()
#define max3(a,b,c) max(max(a,b),c)
#define min3(a,b,c) min(min(a,b),c)
#define prv(v) cout<<#v<<" => "; for(auto val:v) cout<<val<<" "; cout<<endl;
#define prvp(v) cout<<#v<<endl; for(auto val:v) cout<<val.first<<" "<<val.second<<endl; cout << "---------" << endl;
#define mod 1000000007
int gcd(int a, int b) { if (b == 0) return a; return gcd(b, a % b); }
set<vector<int>> v;

void solve() {
    ll n;cin >> n;
    map<int, int> m;;
    rep(i, n) {
        int x;cin >> x;
        x %= 10;
        m[x]++;
    };
    for (auto val : v) {
        // cout << val[0] << val[1] << val[2] << endl;
        if (m[val[0]]) {
            m[val[0]]--;
            if (m[val[1]]) {
                m[val[1]]--;
                if (m[val[2]]) {
                    cout << "YES" << endl;
                    return;
                }
                else {
                    m[val[1]]++;
                    m[val[0]]++; 
                }
            }
            else
                m[val[0]]++;
        }
    }

    cout << "NO" << endl;


}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    for (int i = 0;i < 10;i++) {
        for (int j = 0;j < 10;j++) {
            for (int k = 0;k < 10;k++) {
                vector<int> t(3);
                if (i + j + k == 3 || i + j + k == 13 || i + j + k == 23)
                {
                    t[0] = i;
                    t[1] = j;
                    t[2] = k;
                    sort(all(t));
                    v.insert(t);
                }
            }
        }
    }
    while (T--)
    {
        solve();
    }
    return 0;
}