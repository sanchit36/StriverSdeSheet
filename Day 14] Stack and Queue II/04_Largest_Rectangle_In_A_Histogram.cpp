#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &heights, int n)
{
    vector<int> ans(n);
    stack<int> s;
    s.push(-1);
    for (int i = n - 1; i >= 0; i--)
    {
        int cur = heights[i];
        while (s.top() != -1 && heights[s.top()] >= cur)
            s.pop();
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

vector<int> prevSmallerElement(vector<int> &heights, int n)
{
    vector<int> ans(n);
    stack<int> s;
    s.push(-1);
    for (int i = 0; i < n; i++)
    {
        int cur = heights[i];
        while (s.top() != -1 && heights[s.top()] >= cur)
            s.pop();
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

int largestRectangle(vector<int> &heights)
{
    int n = heights.size();

    vector<int> next(n); // index of next smaller element
    next = nextSmallerElement(heights, n);

    vector<int> prev(n); // index of prev smaller element
    prev = prevSmallerElement(heights, n);

    int maxArea = 0;
    for (int i = 0; i < n; i++)
    {
        int l = heights[i];
        if (next[i] == -1)
        {
            next[i] = n;
        }
        int b = next[i] - prev[i] - 1;
        int area = l * b;
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

int largestRectangleSinglePass(vector<int> &heights)
{
    stack<int> s;
    int maxA = 0;
    int n = heights.size();
    for (int i = 0; i <= n; i++)
    {
        while (!s.empty() && (i == n || heights[s.top()] >= heights[i]))
        {
            int height = heights[s.top()];
            s.pop();
            int width;
            if (s.empty())
                width = i;
            else
                width = i - s.top() - 1;
            maxA = max(maxA, width * height);
        }
        s.push(i);
    }
    return maxA;
}