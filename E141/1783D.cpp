// seems like it can't be predicted mathematically
// try using dynamic programming
// for each index,valueAtIndex can form dp state
// valueAtIndex can be at max 300*300 which is in bound
// dp states are 300*300*300 -> 27*10^6 -> 3*10^7

// it is very hard to detect when there will be duplicate states
// when current number is 0 it won't make 2 different cases instaed we have only 1 case
#include <bits/stdc++.h>
using namespace std;
#define N 301
const int MOD = 998244353;
vector<vector<int>> dp;
set<vector<int>> res;
int recursive(vector<int> &v, int i, int prev)
{
    // this is unique state as we know exactly about this and previous
    // previous will change by this operation but that is predictible and is currencurent to next state change
    if (i == v.size() - 1)
        return 1;
    if (dp[i][prev + N * N] != -1)
        return dp[i][prev + N * N];
    // otherwise we have 2 options
    if (prev == 0)
        return dp[i][prev + N * N] = recursive(v, i + 1, v[i + 1] + prev);
    return dp[i][prev + N * N] = (recursive(v, i + 1, v[i + 1] + prev) + recursive(v, i + 1, v[i + 1] - prev)) % MOD;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    dp = vector<vector<int>>(n, vector<int>(2 * N * N, -1));
    for (auto &elm : v)
        cin >> elm;
    cout << recursive(v, 1, v[1]) << endl;
}