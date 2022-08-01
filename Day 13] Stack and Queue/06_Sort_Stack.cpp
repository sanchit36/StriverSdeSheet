void sortedInsert(stack<int> &s, int num)
{
    if (s.empty() || s.top() < num)
    {
        s.push(num);
        return;
    }
    int x = s.top();
    s.pop();
    sortedInsert(s, num);
    s.push(x);
}

void sortStack(stack<int> &s)
{
    if (s.empty())
        return;
    int num = s.top();
    s.pop();
    sortStack(s);
    sortedInsert(s, num);
}