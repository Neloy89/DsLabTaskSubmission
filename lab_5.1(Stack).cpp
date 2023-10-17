#include <iostream>
using namespace std;

#define size 10
int arr[size], top=-1;

bool empty()
{
    if(top==-1)
    return true;
    else
    return false;
}

void push (int value)
{
    if(top==size-1)
    {
        cout<<"stack is full"<<endl;
    }
    else {
        top++;
        arr[top]=value;
    }
}

void pop()
{
    if(empty())
    {
        cout<<"Stac is empty"<<endl;
    }
    else
    {
        top--;
    }
}

void show_top()
{
    if(empty())
    {
        cout<<"stack is empty"<<endl;
    }
    else
    {
        cout<<"Element at top is:"<<arr[top]<<endl;
    }
}

void display()
{
    if(empty())
    {
        cout<<"stack is empty"<<endl;
    }
    else
    {
        for(int i=0;i<=top;i++)
        {
            cout<<arr[i]<<" ";

        }
    }
}


int main()
{
    push(5);
    push(10);

    cout << "Stack elements: "<<endl;
    display();

    cout<< endl;

    cout << "Top of the stack: "<<endl;
    show_top();

    cout<< endl;

    pop();

    cout << "Stack elements after popping: ";
    display();

    return 0;
}
