bool isValid(int n, int m, vector<int> time, long long int mid)
{
    int day = 1;
    long long int reqTime = 0;
    for (int i = 0; i < m; i++)
    {
        reqTime += time[i];
        if (reqTime > mid)
        {
            day++;
            reqTime = time[i];
        }
        if (day > n)
        {
            return false;
        }
    }
    return true;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time)
{
    long long maxSum = 0;
    int maxEle = 0;
    for (int num : time)
    {
        maxSum += num;
        maxEle = max(maxEle, num);
    }
    long long start = maxEle;
    long long end = maxSum;
    long long res = -1;
    while (start <= end)
    {
        long long mid = start + (end - start) / 2;
        if (isValid(n, m, time, mid))
        {
            res = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return res;
}