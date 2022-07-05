// INSERTION SORT TYPES ALGO
// TC         SC
// O(nm)      O(1)
#include <bits/stdc++.h>
vector<int> ninjaAndSortedArrays(vector<int> &arr1, vector<int> &arr2, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        if (arr1[i] > arr2[0])
        {
            swap(arr1[i], arr2[0]);
            int first = arr2[0];
            int k;
            for (k = 1; k < n && arr2[k] < first; k++)
            {
                arr2[k - 1] = arr2[k];
            }
            arr2[k - 1] = first;
        }
    }
    for (int i = 0; i < n; i++)
    {
        arr1[m + i] = arr2[i];
    }
    return arr1;
}

// GAP ALGO
// TC                   SC
// O(n+m*log(n+m))     O(1)
#include <bits/stdc++.h>
int nextGap(int gap)
{
    if (gap <= 1)
        return 0;
    return (gap / 2) + (gap % 2);
}

vector<int> ninjaAndSortedArrays(vector<int> &arr1, vector<int> &arr2, int m, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr1[m + i] = arr2[i];
    }
    int gap = n + m;
    for (gap = nextGap(gap); gap > 0; gap = nextGap(gap))
    {
        for (int i = 0; i + gap < n + m; i++)
        {
            if (arr1[i] > arr1[i + gap])
                swap(arr1[i], arr1[i + gap]);
        }
    }
    return arr1;
}