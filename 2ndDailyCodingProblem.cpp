/* Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.

For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6]. */

#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(int arr[] ,int n)
{
    vector<int> nums;
    vector<int> ans(n, 1);
    if (n == 1)
    {
        ans[0] = 0;
        return ans;
    }
    for(int i=0;i<n;i++){
        nums.push_back(arr[i]);
    }

    for (int i = 1; i < n; i++)
    {
        ans[i] = ans[i - 1] * nums[i - 1];
    }
    vector<int> ans2(n, 1);
    for (int j = n - 2; j >= 0; j--)
    {
        ans2[j] = ans2[j + 1] * nums[j + 1];
    }
    for (int i = 0; i < n; i++)
    {
        ans[i] = ans[i] * ans2[i];
    }
    return ans;
}

int main() {
   int n = 5;
    int array[] = { 10, 3, 5, 6, 2 };
    vector<int> ans;
    ans=productExceptSelf(array,n);
      for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}