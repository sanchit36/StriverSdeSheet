#include <bits/stdc++.h>
int uniqueSubstrings(string s)
{
    vector<int> chars(128);
    int left = 0;
    int right = 0;
    int ans = 0;
    int n = s.size();

    while (right < n)
    {
        char r = s[right];
        chars[r]++;
        while (chars[r] > 1)
        {
            char l = s[left];
            chars[l]--;
            left++;
        }
        ans = max(ans, (right - left + 1));
        right++;
    }
    return ans;
}