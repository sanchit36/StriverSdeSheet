int removeDuplicates(vector<int> &arr, int n)
{
    int sz = arr.size();
    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] == arr[i])
            sz--;
    }
    return sz;
}