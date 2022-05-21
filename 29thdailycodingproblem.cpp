#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> run_length(string s)
{
    vector<string> v;
    if (s.empty() || s.size() == 1)
    {
        v.push_back(s);
        return v;
    }

    int c = 1;
    for (int i = 1; i < s.size(); ++i)
    {
        if (s[i] == s[i - 1])
            c++;
        else
        {
            if (c > 1)
            {
                v.push_back(to_string(c));
            }
            v.push_back((string(1, s[i - 1])));
            c = 1;
        }
    }
    if (c > 1)
    {
        v.push_back(to_string(c));
    }
    v.push_back(string(1, s[s.size() - 1]));

    return v;
}

int main()
{
    string str = "AAAABBBCCDAA";
    auto result = run_length(str);

    for (auto it : result)
        cout << it ;

    cin.get();
}