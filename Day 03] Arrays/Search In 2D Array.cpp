// https://www.codingninjas.com/codestudio/problems/980531
#include <bits/stdc++.h>
#include <vector>

bool findTargetInMatrix(vector<vector<int>> &mat, int m, int n, int target)
{
    int rowIdx = -1;
    for (int i = 0; i < m; i++)
    {
        if (mat[i][n - 1] == target)
            return true;
        if (mat[i][n - 1] > target)
        {
            rowIdx = i;
            break;
        }
    }
    //     cout << rowIdx << endl;
    if (rowIdx == -1)
        return false;
    for (int i = 0; i < n; i++)
    {
        if (mat[rowIdx][i] == target)
            return true;
    }
    return false;
}

// Binary Search in 2D Array
// If matrix is sorted in increasing order of rows and columns, then we can use binary search.
// So we can apply binary search to search the matrix. Consider the 2D matrix as a 1D matrix
// having indices from 0 to (m*n)-1 and apply binary search.
// Time Complexity: O(log(m*n))
/*
Approach:
i)  Initially have a low index as the first index of the considered 1D matrix(i.e: 0) and
    high index as the last index of the considered 1D matrix(i.e: (m*n)-1).
ii) Now apply binary search. Run a while loop with the condition low<=high.
    Get the middle index as (low+high)/2. We can get the element at middle
    index using matrix[middle/m][middle%m]. m is number of columns.
*/

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int lo = 0;
        if (!matrix.size())
            return false;
        int hi = (matrix.size() * matrix[0].size()) - 1;

        while (lo <= hi)
        {
            int mid = (lo + (hi - lo) / 2);
            if (matrix[mid / matrix[0].size()][mid % matrix[0].size()] == target)
            {
                return true;
            }
            if (matrix[mid / matrix[0].size()][mid % matrix[0].size()] < target)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        return false;
    }
};