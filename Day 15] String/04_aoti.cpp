#include <bits/stdc++.h>
using namespace std;

int atoi(string str)
{
    int exp = 1;
    int ans = 0;
    for (int i = str.size() - 1; i >= 0; i--)
    {
        char ch = str[i];
        if (ch >= '0' && ch <= '9')
        {
            ans += exp * (ch - '0');
            exp = exp * 10;
        }
    }

    return str[0] == '-' ? -ans : ans;
}