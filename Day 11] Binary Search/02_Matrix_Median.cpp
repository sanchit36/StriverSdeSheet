#include <bits/stdc++.h>
int count(vector<vector<int>> &matrix, int mid)
{
    int cnt = 0;
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; i++)
    {
        auto it = upper_bound(matrix[i].begin(), matrix[i].end(), mid);
        cnt += it - matrix[i].begin();
    }
    return cnt;
}

int getMedian(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int left = 1;
    int right = 1e9;
    while (left <= right)
    {
        int mid = (left + right) >> 1;
        int cnt = count(matrix, mid);
        if (cnt <= (n * m) / 2)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}