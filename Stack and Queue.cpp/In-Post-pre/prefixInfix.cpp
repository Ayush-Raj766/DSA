#include <bits/stdc++.h>
using namespace std;

// int precedence(char c)
// {
//     if (c == '^')
//     {
//         return 3;
//     }
//     if (c == '*' || c == '/')
//     {
//         return 2;
//     }
//     if (c == '+' || c == '-')
//     {
//         return 1;
//     }
//     return -1;
// }

void prefixToInfix(string s)
{
    stack<string> st;
    string result;

    for (int i = s.length() - 1; i >= 0; i--)
    {
        char c = s[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            // result += c;
            st.push(string(1,c));
        }

        else
        {
            string op2 = st.top();
            st.pop();
            string op1 = st.top();
            st.pop();
            string temp = "(" + op2 + c + op1 + ")";
            st.push(temp);
        }

        // else if (c == ')')
        // {
        //     while (!st.empty() && st.top() != '(')
        //     {
        //         result += st.top();
        //         st.pop();
        //     }
        //     if (!st.empty())
        //         st.pop(); // pop the '('
        // }

        // else
        // {
        //     while (!st.empty() &&
        //   ((c != '^' && precedence(c) <= precedence(st.top())) ||
        //    (c == '^' && precedence(c) < precedence(st.top()))))
        //     {
        //         // st.push(s[i]);
        //         result += st.top();
        //         st.pop();
        //     }
        //     st.push(c);
        // }
    }
    // while (!st.empty())
    // {
    //     result += st.top();
    //     st.pop();
    // }
    // cout << "postfix ix " << result << endl;
    cout << "Infix: " << st.top() << endl;

}

int main()
{
    string s = "*+AB-CD";
    prefixToInfix(s);
    return 0;
}