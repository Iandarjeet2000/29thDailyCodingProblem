/*Given an array of integers and a number k, where 1 <= k <= length of the array, compute the maximum values of each subarray of length k.

For example, given array = [10, 5, 2, 7, 8, 7] and k = 3, we should get: [10, 7, 8, 8], since:

10 = max(10, 5, 2)
7 = max(5, 2, 7)
8 = max(2, 7, 8)
8 = max(7, 8, 7)
*/



#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
     vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
       deque<int>q;
    int i;
    vector<int>ans;
       for ( i = 0; i < k; i++)
       {
           while (!q.empty() && arr[q.back()]<=arr[i])
           {
               q.pop_back();
           }
           q.push_back(i);
           
       }
       ans.push_back(arr[q.front()]);
       int j=0;
       for (; i < n; i++)
       {
           while (!q.empty() && q.front()<=j)
           {
               q.pop_front();
           }
              while (!q.empty() && arr[q.back()]<=arr[i])
           {
               q.pop_back();
           }
           q.push_back(i);
           j++;
           ans.push_back(arr[q.front()]);
           

           
       }
       return ans;
       
   
    }
};
int main() {
        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;

    return 0;
}  