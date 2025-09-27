#include <bits/stdc++.h>
using namespace std;

int precedence(char c)
{
    if (c == '^')
    {
        return 3;
    }
    if (c == '*' || c == '/')
    {
        return 2;
    }
    if (c == '+' || c == '-')
    {
        return 1;
    }
    return -1;
}

void infixToPostfix(string s)
{
    stack<char> st;
    string result;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9')
        {
            result += c;
        }

        else if (c == '(')
        {
            st.push('(');
        }
        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop(); // pop the '('
        }

        else
        {
            while (!st.empty() && 
          ((c != '^' && precedence(c) <= precedence(st.top())) || 
           (c == '^' && precedence(c) < precedence(st.top())))) 
            {
                // st.push(s[i]);
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }
    cout << "postfix ix " << result << endl;
}

int main()
{
    string exp = "a+b^(c^d-c)*6/r";
    cout << "Infix expression: " << exp << endl;
    infixToPostfix(exp);
    return 0;
    return 0;
}