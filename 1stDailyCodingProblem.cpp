/* Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17*/

#include <bits/stdc++.h>
using namespace std;
bool hasArrayTwoNumber(int arr[], int k,int n)
{
    unordered_set<int> s;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        int sum = k - arr[i];
        if (s.find(sum) != s.end())
        {
            flag = true;
            return true;
        }
        else
        {
            s.insert(arr[i]);
        }
    }
    return false;
}
int main()
{
    int arr[] = {10, 15, 3, 7};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k = 17;
    cout << hasArrayTwoNumber(arr,k,n);
    return 0;
}
