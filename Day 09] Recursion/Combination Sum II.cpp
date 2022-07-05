#include <bits/stdc++.h>
void func(int idx, int k, vector<int> &nums, vector<int> &cur, vector<vector<int>> &ds)
{
    if (k == 0)
        ds.push_back(cur);
    for (int i = idx; i < nums.size(); i++)
    {
        if (i > idx && nums[i] == nums[i - 1])
            continue;
        cur.push_back(nums[i]);
        func(i + 1, k - nums[i], nums, cur, ds);
        cur.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> ds;
    vector<int> cur;
    func(0, target, arr, cur, ds);
    return ds;
}
