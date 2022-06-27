bool isPalindrome(string str, int s, int e)
{
    while (s <= e)
    {
        if (str[s++] != str[e--])
            return false;
    }
    return true;
}

void func(int idx, string str, vector<string> &path, vector<vector<string>> &ds)
{
    if (idx == str.size())
    {
        ds.push_back(path);
        return;
    }
    for (int i = idx; i < str.size(); i++)
    {
        if (isPalindrome(str, idx, i))
        {
            path.push_back(str.substr(idx, i - idx + 1));
            func(i + 1, str, path, ds);
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(string &s)
{
    vector<string> path;
    vector<vector<string>> ds;
    func(0, s, path, ds);
    return ds;
}