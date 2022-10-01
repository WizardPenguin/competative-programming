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

void solve() {
    ll n, k;cin >> n >> k;
    string s;cin >> s;
    int a, b;

    a = s.find('1');
    b = s.rfind('1');

    int one = count(all(s), '1');
    if (one == 0)
        cout << 0 << endl;
    else
    {
        //checking the last 1 is replaceable or not
        if (k >= n - b - 1 && b != n - 1) {
            swap(s[n - 1], s[b]);
            k -= n - b - 1;
        }

        //checking the first 1 is replaceable or not
        if (k >= a) {
            if (a != 0 && a != n - 1)
            {
                swap(s[0], s[a]);
                k -= a;
            }
        }
        int ans = 0;

        for (int i = 0;i < n - 1;i++) {
            if (s[i] == '1' && s[i + 1] == '1')
                ans += 11;
            else if (s[i] == '1' && s[i + 1] == '0')
                ans += 10;
            else if (s[i] == '0' && s[i + 1] == '1')
                ans += 1;
        }
        cout << ans << endl;
    }

}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}