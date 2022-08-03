class Queue
{
    int *arr;
    int f;
    int r;
    int size;

public:
    Queue()
    {
        size = 100000;
        arr = new int[size];
        f = 0;
        r = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty()
    {
        return (r == f);
    }

    void enqueue(int data)
    {
        if (r == size)
            return;
        arr[r++] = data;
    }

    int dequeue()
    {
        if (isEmpty())
            return -1;
        int ans = arr[f];
        f++;
        if (f == r)
        {
            f = 0;
            r = 0;
        }
        return ans;
    }

    int front()
    {
        if (isEmpty())
            return -1;
        return arr[f];
    }
};