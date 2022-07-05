#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, int n, vector<vector<int>> board)
{
    int duprow = row;
    int dupcol = col;

    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 1)
            return false;
        row--;
        col--;
    }

    col = dupcol;
    row = duprow;
    while (col >= 0)
    {
        if (board[row][col] == 1)
            return false;
        col--;
    }

    row = duprow;
    col = dupcol;
    while (row < n && col >= 0)
    {
        if (board[row][col] == 1)
            return false;
        row++;
        col--;
    }
    return true;
}

void f(int &col, int n, vector<vector<int>> &board, vector<vector<int>> &ds)
{
    if (col == n)
    {
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ans.push_back(board[i][j]);
            }
        }
        ds.push_back(ans);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, n, board))
        {
            board[row][col] = 1;
            col++;
            f(col, n, board, ds);
            col--;
            board[row][col] = 0;
        }
    }
}

vector<vector<int>> solveNQueens(int n)
{
    vector<vector<int>> ds;
    vector<vector<int>> board(n, vector<int>(n, 0));
    int col = 0;
    f(col, n, board, ds);
    return ds;
}