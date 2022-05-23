/*33.Compute the running median of a sequence of numbers. That is, given a stream of numbers, print out the median of the list so far on each new element.

Recall that the median of an even-numbered list is the average of the two middle numbers.

For example, given the sequence [2, 1, 5, 7, 2, 0, 5], your algorithm should print out:

2
1.5
2
3.5
2
2
2*/

#include <bits/stdc++.h>
using namespace std;

priority_queue<double> max1;
priority_queue<double, vector<double>, greater<double>> min1;
double median = 0;
void insert(int x)
{
        if (max1.size() == min1.size())
    {
        if (x > median)
        {
            min1.push(x);
            median = min1.top();
        }
        else
        {
            max1.push(x);
            median = max1.top();
        }
    }
    else if (min1.size() > max1.size())
    {
        if (x > median)
        {
            max1.push(min1.top());
            min1.pop();
            min1.push(x);
        }
        else
            max1.push(x);
        median = (min1.top() + max1.top()) / 2;
    }
    else
    {
        if (x > median)
        {
            min1.push(x);
        }
        else
        {
            min1.push(max1.top());
            max1.pop();
            max1.push(x);
        }
        median = (min1.top() + max1.top()) / 2;
    }
}
double findMedian()
{
    return median;
}
int main()
{
    int arr[] = {2, 1, 5, 7, 2, 0, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "[";
    for (int i = 0; i < n; i++)
    {
        insert(arr[i]);
        cout << findMedian();
        if (i != n - 1)
            cout << ", ";
    }
    cout << "]";
    return 0;
}
