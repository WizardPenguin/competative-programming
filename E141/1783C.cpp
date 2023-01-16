// we can take atmax x wins using smallest x elements such that sum <= m
// after then we have 2 choices remove largest out of x and try to win x+1th element
// or x+1th element has already lost in that case we can get x+1th position (n-x-1)
// otherwise we are always going to have xth position (n -x -1) as best position
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> v(n);
        for (auto &elm : v)
            cin >> elm;
        auto tp = v;
        sort(tp.begin(), tp.end());
        // for (auto &elm : tp)
        //     cerr << elm << " ";
        // cerr << endl;
        int i = 0;
        while (i < n and m >= tp[i])
        {
            m -= tp[i];
            i += 1;
        }
        // cerr << i << endl;
        if (not i)
        {
            // we haven't got anythig yet
            cout << n + 1 << endl;
        }
        else if (i == n)
        {
            cout << 1 << endl;
        }
        else if (m + tp[i - 1] >= v[i])
        {
            cout << n - i << endl;
        }
        else
        {
            cout << n - i + 1 << endl;
        }
    }
}