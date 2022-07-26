#include <bits/stdc++.h>
using namespace std;

string reverseString(string str)
{
    stack<string> st;
    string temp = "";
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ')
        {
            while (i < str.length() && str[i] != ' ')
            {
                temp += str[i];
                i++;
            }
            st.push(temp);
            temp = "";
        }
    }

    string ans = "";
    while (!st.empty())
    {
        ans += st.top() + " ";
        st.pop();
    }
    return ans;
}