#include <queue>
using namespace std;

class Stack
{
    queue<int> q;

public:
    Stack()
    {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize()
    {
        return q.size();
    }

    bool isEmpty()
    {
        return q.empty();
    }

    void push(int element)
    {
        q.push(element);
        int size = q.size() - 1;
        while (size--)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {
        if (isEmpty())
            return -1;
        int ans = q.front();
        q.pop();
        return ans;
    }

    int top()
    {
        if (isEmpty())
            return -1;
        return q.front();
    }
};