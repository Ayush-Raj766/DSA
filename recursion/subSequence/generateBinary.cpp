#include <bits/stdc++.h>
using namespace std;

bool checkCountinuty(string str)
{
    for (int i = 1; i < str.length(); i++)
    {
        if (str[i] == str[i - 1] && str[i] == '1')
        {
            return false;
        }
    }
    return true;
}

void generateBinary(int n)
{
    int total = pow(2, n);
    for (int i = 0; i < total; i++)
    {
        int num = i;
        string str = "";
        for (int j = n - 1; j >= 0; j--)
        {
            if(num % 2 == 0)
            {
                str = "0" + str;
            }
            else
            {
                str = "1" + str;
            }
            num /= 2;
        }

        if (checkCountinuty(str))
        {
            cout << str << endl;
        }
    }
}

int main()
{
    int n;
    cout << "Enter the length of binary strings: ";
    cin >> n;
    generateBinary(n);

    return 0;
}
