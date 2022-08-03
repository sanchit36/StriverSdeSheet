#include <bits/stdc++.h>
using namespace std;

vector<int> findSpans(vector<int> &price)
{
    int n = price.size();
    vector<int> ans(n);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        int cnt = 1;
        while (!st.empty() and price[i] >= price[st.top()])
        {
            cnt += ans[st.top()];
            st.pop();
        }
        st.push(i);
        ans[i] = cnt;
    }
    return ans;
}