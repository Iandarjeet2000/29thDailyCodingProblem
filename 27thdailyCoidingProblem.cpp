/*Q.No-27:-Given a string of round, curly, and square open and closing brackets, return whether the brackets are balanced (well-formed).

For example, given the string "([])[]({})", you should return true.

Given the string "([)]" or "((()", you should return false.*/


#include <bits/stdc++.h>
using namespace std;

bool areBalanced(string str)
{
    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        if (s.empty())
        {
            s.push(str[i]);
        }
        else if ((s.top() == '(' && str[i] == ')') || (s.top() == '{' && str[i] == '}') || (s.top() == '[' && str[i] == ']'))
        {
            s.pop();
        }
        else
        {
            s.push(str[i]);
        }
    }
    if (s.empty())
    {
        return true;
    }
    return false;
}
int main()
{
    string expr = "{()}[]";
        cout << areBalanced(expr);
    return 0;
}