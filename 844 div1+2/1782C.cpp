// try to have only x characters in string
// then we know n/x is final frequency of our characters
// check most frequent x characters and excess characters, which are going to be used to deal deficiency

#include <bits/stdc++.h>
using namespace std;
vector<int> freq;
int check(string &s, int k)
{
    int ans = 0;
    if (s.length() % k)
        return INT_MAX;
    int steps = (s.length()) / k;
    for (int i = 0; i < k; i += 1) // find nodes at their correct positions
    {
        ans += min(freq[i], steps);
    }
    return s.length() - ans;
}
void form(string &s, int k)
{
    // find extra character and given them to make all k charcters have same frequency
    vector<vector<int>> ids(26);
    vector<int> sortId(26);
    iota(sortId.begin(), sortId.end(), 0);
    for (int i = 0; i < s.length(); i += 1)
        ids[s[i] - 'a'].push_back(i);
    sort(sortId.begin(), sortId.end(), [&](int a, int b)
         { return ids[a].size() > ids[b].size(); });
    vector<int> extraIds;
    int finalFreq = s.length() / k;
    for (int i = 0; i < 26; i += 1)
    {
        while ((i < k and ids[sortId[i]].size() > finalFreq) or (i >= k and ids[sortId[i]].size()))
        {
            extraIds.push_back(ids[sortId[i]].back());
            ids[sortId[i]].pop_back();
        }
    }
    // now add extraIds to needy ones
    for (int i = 0; i < k; i += 1)
    {
        while (ids[sortId[i]].size() < finalFreq)
        {
            ids[sortId[i]].push_back(extraIds.back());
            s[extraIds.back()] = char(sortId[i] + 'a');
            extraIds.pop_back();
        }
    }
    return;
}
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n;
        string s;
        cin >> n >> s;
        freq = vector<int>(26, 0);
        for (auto &ch : s)
            freq[ch - 'a'] += 1;
        sort(freq.begin(), freq.end(), greater<int>());
        int minSteps = INT_MAX;
        int minId = 0;
        for (int i = 1; i <= 26; i += 1)
        {
            auto steps = check(s, i);
            if (steps < minSteps)
                minSteps = steps, minId = i;
        }
        form(s, minId);
        cout << minSteps << endl;
        cout << s << endl;
    }
}