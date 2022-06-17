void func(int i, vector<int> &cur, vector<int> &arr, int k, vector<vector<int>> &ds)
{
    if (i >= arr.size())
    {
        if (k == 0)
            ds.push_back(cur);
        return;
    }
    func(i + 1, cur, arr, k, ds);
    cur.push_back(arr[i]);
    func(i + 1, cur, arr, k - arr[i], ds);
    cur.pop_back();
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<vector<int>> ds;
    vector<int> cur;
    func(0, cur, arr, k, ds);
    return ds;
}