#include <bits/stdc++.h>
using namespace std;

class Stack
{
    int *arr;
    int top;
    int size;

public:
    Stack(int n)
    {
        size = n;
        top = -1;
        arr = new int[size];
    }

    void push(int element)
    {
        if (top + 1 != size)
        {
            arr[++top] = element;
        }
        else
        {
            cout << "Stack Overflow" << endl;
        }
    }

    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "Stack Underflow" << endl;
        }
    }

    int peek()
    {
        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

int main()
{
    Stack st(5);
    st.push(22);
    st.push(43);
    st.push(44);
    cout << st.peek() << endl;
    st.pop();
    cout << st.peek() << endl;
    st.pop();
    cout << st.peek() << endl;
    st.pop();
    cout << st.peek() << endl;

    return 0;
}