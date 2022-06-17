void fun(int i, int &curSum, vector<int> &num, vector<int> &ds)
{
    if (i >= num.size())
    {
        ds.push_back(curSum);
        return;
    }
    fun(i + 1, curSum, num, ds);
    curSum += num[i];
    fun(i + 1, curSum, num, ds);
    curSum -= num[i];
}

vector<int> subsetSum(vector<int> &num)
{
    vector<int> ds;
    int curSum = 0;
    fun(0, curSum, num, ds);
    sort(ds.begin(), ds.end());
    return ds;
}