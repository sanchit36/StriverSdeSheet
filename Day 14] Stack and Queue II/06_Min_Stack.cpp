#include <bits/stdc++.h>
using namespace std;

// Implement class for minStack.
class minStack
{
    stack<int> s;
    int mini;

public:
    // Constructor
    minStack()
    {
        // 			mini = INT_MAX;
    }

    // Function to add another element equal to num at the top of stack.
    void push(int num)
    {
        if (s.empty())
        {
            s.push(num);
            mini = num;
        }
        else
        {
            if (num < mini)
            {
                s.push(2 * num - mini);
                mini = num;
            }
            else
            {
                s.push(num);
            }
        }
    }

    // Function to remove the top element of the stack.
    int pop()
    {
        if (s.empty())
            return -1;

        int curr = s.top();
        s.pop();
        if (curr > mini)
        {
            return curr;
        }
        else
        {
            int prevMin = mini;
            mini = 2 * mini - curr;
            return prevMin;
        }
    }

    // Function to return the top element of stack if it is present. Otherwise return -1.
    int top()
    {
        if (s.empty())
            return -1;

        int curr = s.top();
        if (curr < mini)
        {
            return mini;
        }

        return curr;
    }

    // Function to return minimum element of stack if it is present. Otherwise return -1.
    int getMin()
    {
        if (s.empty())
            return -1;
        return mini;
    }
};