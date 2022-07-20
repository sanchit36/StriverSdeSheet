int bs(int s, int e, int *a, int key)
{
    while (s <= e)
    {
        int m = s + (e - s) / 2;
        if (a[m] == key)
            return m;
        else if (key < a[m])
        {
            e = m - 1;
        }
        else
        {
            s = m + 1;
        }
    }
    return -1;
}
int search(int *arr, int n, int key)
{
    if (n == 1)
        return key == arr[0] ? 0 : -1;
    int start = 0, end = n - 1;
    int pivotIndex = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        int next = (mid + 1) % n;
        int prev = (mid + n - 1) % n;
        if (arr[mid] <= arr[next] && arr[mid] <= arr[prev])
        {
            pivotIndex = mid;
            break;
        }
        else if (arr[start] <= arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    int ans1 = bs(0, pivotIndex - 1, arr, key);
    int ans2 = bs(pivotIndex, n - 1, arr, key);
    if (ans1 != -1)
        return ans1;
    if (ans2 != -1)
        return ans2;
    return -1;
}