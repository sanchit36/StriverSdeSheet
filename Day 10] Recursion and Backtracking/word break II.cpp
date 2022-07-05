#include <bits/stdc++.h>
using namespace std;

void f(int ind, string &s, set<string> &dic, vector<string> &ds, vector<string> &cur)
{
    if (ind == s.size())
    {
        string temp = "";
        for (string str : cur)
        {
            temp += str;
        }
        ds.push_back(temp);
        return;
    }
    string str = "";
    for (int i = ind; i < s.size(); i++)
    {
        str += s[i];
        if (dic.find(str) != dic.end())
        {
            cur.push_back(str + " ");
            f(i + 1, s, dic, ds, cur);
            cur.pop_back();
        }
    }
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    vector<string> ds, cur;
    set<string> dic;
    for (string str : dictionary)
        dic.insert(str);
    f(0, s, dic, ds, cur);
    return ds;
}