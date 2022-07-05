#include <bits/stdc++.h>
vector<vector<int>> pairSum(vector<int> &arr, int s)
{
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int i = 0, j = n - 1;
    vector<vector<int>> ans;
    while (i < j)
    {
        if (arr[i] + arr[j] == s)
        {
            int maxi = 0;
            int x = arr[i];
            int y = arr[j];
            if (arr[i] == arr[j])
            {
                int c = 0;
                while (arr[i] == x)
                {
                    i++;
                    j--;
                    c++;
                }
                maxi = c * (c - 1) / 2;
            }
            else
            {
                int cI = 0;
                int cJ = 0;
                while (arr[i] == x)
                {
                    i++;
                    cI++;
                }
                while (arr[j] == y)
                {
                    j--;
                    cJ++;
                }
                maxi = cI * cJ;
            }
            while (maxi--)
            {
                ans.push_back({x, y});
            }
        }
        else if (arr[i] + arr[j] > s)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return ans;
}