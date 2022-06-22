#include <bits/stdc++.h>
string fourSum(vector<int> arr, int target, int n)
{
    if (arr.empty())
        return "Yes";
    sort(arr.begin(), arr.end());
    vector<long long int> nums;
    for (int i = 0; i < n; i++)
    {
        nums.push_back(arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            long long int target_2 = target - nums[i] - nums[j];
            int l = j + 1;
            int r = n - 1;
            while (l < r)
            {
                long long int sum = nums[l] + nums[r];
                if (sum > target_2)
                    r--;
                else if (sum < target_2)
                    l++;
                else
                {
                    return "Yes";
                }
            }
            while (j + 1 < n && nums[j + 1] == nums[j])
                ++j;
        }
        while (i + 1 < n && nums[i + 1] == nums[i])
            ++i;
    }
    return "No";
}
