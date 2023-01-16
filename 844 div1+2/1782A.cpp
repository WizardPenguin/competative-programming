#include <bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int f, s, t;
        cin >> f >> s >> t;
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int ans1 = 2 * f - (x1 + x2) + abs(y1 - y2);
        int ans2 = (x1 + x2) + abs(y1 - y2);
        int ans3 = (2 * s) - (y1 + y2) + abs(x2 - x1);
        int ans4 = y1 + y2 + abs(x2 - x1);
        cout << min({ans1, ans2, ans3, ans4}) + t << endl;
    }
}