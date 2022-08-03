#include <stack>
using namespace std;

class Queue
{
    // Define the data members(if any) here.
    stack<int> input;
    stack<int> output;

public:
    Queue()
    {
        // Initialize your data structure here.
    }

    void enQueue(int val)
    {
        input.push(val);
    }

    int deQueue()
    {
        if (output.empty() && input.empty())
            return -1;
        if (output.empty())
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }
        int ans = output.top();
        output.pop();
        return ans;
    }

    int peek()
    {
        if (output.empty() && input.empty())
            return -1;
        if (output.empty())
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }

    bool isEmpty()
    {
        return output.empty() && input.empty();
    }
};