#include <bits/stdc++.h>
using namespace std;

class minStack
{
    stack<int> st;
    int min = INT_MAX;

    public:

    void Push(int val)
    {
        if (st.empty())
        {
            st.push(val);
            min = val;
        }
        else
        {
            if (min < val)
            {
                st.push(val);
            }
            else
            {
                st.push(2 * val - min);

                min = val;
            }
        }
    }

    int Pop()
    {
        if (st.empty())
        {
            return -1;
        }
        else
        {
            int n = st.top();
            st.pop();
            if (n < min)
            {
                int prevmin = 2 * min - n;
                int res = prevmin;
                min = prevmin;

                return res;
            }
            else
            {
                return n;
            }
        }
    }

    int Top()
    {
        if (st.top() < min)
        {
            return min;
        }
        else
        {
            return st.top();
        }
    }
    int getMin()
    {
        return min;
    }
};

int main()
{
    minStack ms;

    ms.Push(-20);
    ms.Push(0);
    ms.Push(-3);
    ms.Push(-16);
    ms.Push(6);


    cout << ms.getMin() << endl; // -3
    ms.Pop();
    cout << ms.Top() << endl;    // 0
    cout << ms.getMin() << endl; // -2
    return 0;
}