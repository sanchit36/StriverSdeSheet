#include <bits/stdc++.h>
vector<vector<int>> findTriplets(vector<int> arr, int n, int K)
{
    vector<vector<int>> res;
    if (arr.empty())
        return res;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        int target_2 = K - arr[i];
        int l = i + 1;
        int r = n - 1;
        while (l < r)
        {
            int sum = arr[l] + arr[r];
            if (sum > target_2)
                r--;
            else if (sum < target_2)
                l++;
            else
            {
                vector<int> tri;
                tri.push_back(arr[i]);
                tri.push_back(arr[l]);
                tri.push_back(arr[r]);
                res.push_back(tri);
                while (l < r && arr[l] == tri[1])
                    ++l;
                while (l < r && arr[r] == tri[2])
                    --r;
            }
        }
        while (i + 1 < n && arr[i + 1] == arr[i])
            ++i;
    }
    return res;
}