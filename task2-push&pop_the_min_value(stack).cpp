#include <iostream>
using namespace std;

#define size 10
int arr[size], top = -1;

bool empty()
{
    if (top == -1)
        return true;
    else
        return false;
}

void push(int value)
{
    if (top == size - 1)
    {
        cout << "Stack is full" << endl;
    }
    else
    {
        top++;
        arr[top] = value;
    }
}

void pop()
{
    if (empty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        top--;
    }
}

void show_top()
{
    if (empty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Element at top is: " << arr[top] << endl;
    }
}

void display()
{
    if (empty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << " ";
        }
    }
}

int main()
{
    cout << "Input some elements onto the stack:\n";
    push(5);
    push(2);
    push(4);
    push(7);

    cout << "Stack elements are:\n";
    display();
    cout << endl;

    int lowest = arr[0];
    int lowestIndex = 0;

    for (int i = 1; i <= top; i++)
    {
        if (arr[i] < lowest)
        {
            lowest = arr[i];
            lowestIndex = i;
        }
    }

    cout << "Find and remove the lowest element " << lowest << " from the stack.\n";


    for (int i = lowestIndex; i < top; i++)
    {
        arr[i] = arr[i + 1];
    }

    top--;

    cout << "Stack elements are:\n";
    display();
    cout << endl;

    cout << "Input two more elements:\n";
    push(2);
    push(-1);

    cout << "Stack elements are:\n";
    display();
    cout << endl;

    lowest = arr[0];
    lowestIndex = 0;

    for (int i = 1; i <= top; i++)
    {
        if (arr[i] < lowest)
        {
            lowest = arr[i];
            lowestIndex = i;
        }
    }

    cout << "Find and remove the lowest element " << lowest << " from the stack.\n";


    for (int i = lowestIndex; i < top; i++)
    {
        arr[i] = arr[i + 1];
    }

    top--;

    cout << "Stack elements are:\n";
    display();
    cout << endl;

    return 0;
}
