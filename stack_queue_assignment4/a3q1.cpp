/** 
 *
 * @author - Ayush
 * @title - a3q1.cpp
 * @createdOn - 2020-10-12
 * 
 **/
#include <iostream>
#include <cmath>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef vector<vector<int>> int_vec_2d;
typedef vector<int>:: iterator vi_it;
typedef map<int, int>::iterator mii_it;

class Stack
{
    private:
        int a[1000];
        int size;
        
    public:
        Stack()
        {
            size = 0;
        }
        int Pop();
        int Top();
        void Push(int data);
        int Size();
        bool IsEmpty();
        bool IsFull();
};

inline int Stack::Pop()
{
    if(size > 0)
    {
        return a[size-- - 1];
    }
    else
    {
        throw "StackUnderflowExceeption";
    }
}

inline int Stack::Top()
{
    return a[size - 1];
}

inline void Stack::Push(int data)
{
    if(size<1000)
    {
        a[size++] = data;
    }
    else
    {
        throw "StackOverflowException";
    }
    return;
}

inline int Stack::Size()
{
    return size;
}

inline bool Stack::IsEmpty()
{
    if(size == 0)
        return true;
    return false;
}

inline bool Stack::IsFull()
{
    if(size == 1000)
        return true;
    return false;
}


int main()
{

    Stack st = *(new Stack());
    int t;
    cout << "enter how many values you want to enter in stack: ";
    cin >> t;
    cout << "enter data: ";
    for (int i = 0; i < t; i++)
    {
        int data;
        cin >> data;
        st.Push(data);
    }

    while(!st.IsEmpty())
    {
        cout << st.Pop() << " ";
    }
    
    return 0;
}