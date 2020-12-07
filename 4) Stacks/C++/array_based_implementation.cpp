#include<iostream>
using namespace std;
#define MAX_SIZE 101

class Stack
{
private:
    int A[MAX_SIZE];    // array to store the stack
    int top;            //variable to mark the top index of the stack

public:
    // constructor
    Stack()
    {
        top = -1;       // for empty array set top = -1
    }

    void Push(int x)
    {
        if(top == MAX_SIZE - 1)
        {
            cout<<"Error: stack is full";
            return;
        }
        top++;
        A[top] = x;
    }

    void Pop()
    {
        if(top == -1)
        {
            cout<<"Error: stack is empty\n";
            return;
        }
        top--;
    }

    int Top()
    {
        return A[top];
    }

    int Is_Empty()
    {
        if(top == -1)
        {
            return 1;
        }
        return 0;
    }

    void Print()
    {
        int i;
        cout<<"Stack: ";
        for(i=0; i<=top; i++)
        {
            cout<<A[i]<<" ";
        }
        cout<<"\n";
    }
};

int main()
{
    Stack S;
    S.Push(1);
    S.Print();
    S.Push(2);
    S.Print();
    S.Push(3);
    S.Print();
    S.Push(4);
    S.Print();
    S.Push(5);
    S.Print();


    S.Pop();
    S.Print();
    S.Pop();
    S.Print();
    S.Pop();
    S.Print();
    S.Pop();
    S.Print();


}

/*
Stack: 1
Stack: 1 2
Stack: 1 2 3
Stack: 1 2 3 4
Stack: 1 2 3 4 5
Stack: 1 2 3 4
Stack: 1 2 3
Stack: 1 2
Stack: 1
*/
