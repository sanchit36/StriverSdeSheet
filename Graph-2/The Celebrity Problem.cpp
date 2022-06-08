#include<bits/stdc++.h>
int findCelebrity(int n) {
    stack<int> s;
    int C;
    for (int i = 0; i < n; i++)
        s.push(i);
    while (s.size() > 1)
    {   int A = s.top();
        s.pop();
        int B = s.top();
        s.pop();
        if (knows(A, B))
        {
          s.push(B);
        }
        else
        {
          s.push(A);
        }
    }

    C = s.top();
    s.pop();
    for (int i = 0; i < n; i++)
    {
        if ( (i != C) && (knows(C, i) || !knows(i, C)) )
            return -1;
    }
    return C;
}