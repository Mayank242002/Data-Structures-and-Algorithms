#include <iostream>
using namespace std;

class Stack
{
public:
    int top;
    int size;
    int *s;
    bool isEmpty();
    bool isFull();
    void push(int x);
    int pop();
    void display();
};

bool Stack::isEmpty()
{
    if (top == -1)
        return true;
    else
        return false;
}

bool Stack::isFull()
{
    if (top == size - 1)
        return true;
    else
        return false;
}

void Stack::push(int x)
{
    if (isFull())
        cout << "overflow" << endl;
    else
    {
        top++;
        s[top] = x;
    }
}

int Stack::pop()
{
    int x = -1;
    if (isEmpty())
        cout << "Stack Underflow" << endl;
    else
    {
        x = s[top];
        top--;
    }
    return x;
}

void Stack::display()
{
    int i;
    for (i = top; i >= 0; i--)
        cout << s[i] << " ";
    cout << " ";
}

class Queue
{
private:
    Stack s1;
    Stack s2;

public:
    Queue(int size)
    {
        s1.size = size;
        s2.size = size;

        s1.top = -1;
        s2.top = -1;

        s1.s = new int[size];
        s2.s = new int[size];
    }

    ~Queue()
    {
        delete[] s1.s;
        delete[] s2.s;
    }

    void enqueue(int x)
    {
        s1.push(x);
    }

    int dequeue()
    {
        int x = -1;
        if (s2.isEmpty())
        {
            if (s1.isEmpty())
            {
                cout << "Both Queue underflow" << endl;
                return x;
            }
            else
            {
                while (!s1.isEmpty())
                {
                    s2.push(s1.pop());
                }
            }
        }
        x = s2.pop();
        return x;
    }

    void Display()
    {
        s1.display();
        s2.display();
    }
};

int main()
{
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.dequeue();

    q.Display();
}