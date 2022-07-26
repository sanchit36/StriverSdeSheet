#include <bits/stdc++.h>
using namespace std;

void calculateZ(string &input, vector<int> &z)
{
    int left = 0;
    int right = 0;
    z[0] = 0;
    for (int k = 1; k < input.size(); k++)
    {
        if (k > right)
        {
            left = right = k;
            while (right < input.size() && input[right] == input[right - left])
                right++;
            z[k] = right - left;
            right--;
        }
        else
        {
            // we are operating inside box
            int k1 = k - left;
            // if value does not touches the right bound then just copy it
            if (z[k1] < right - k + 1)
            {
                z[k] = z[k1];
            }
            else
            { // otherwise try more matches
                left = k;
                while (right < input.size() && input[right] == input[right - left])
                    right++;
                z[k] = right - left;
                right--;
            }
        }
    }
}

int zAlgorithm(string s, string p, int n, int m)
{
    string newString = p + '$' + s;
    int cnt = 0;
    vector<int> z(n + m + 1);
    calculateZ(newString, z);
    for (int i = 0; i < n + m + 1; i++)
    {
        if (z[i] == m)
        {
            cnt++;
        }
    }
    return cnt;
}