#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int l = 0;
    int h = n - 1;
    int n1 = 0;
    int n2 = 0;
    int s = 0;
    while (l <= h)
    {
        if (a[l] < a[h])
        {
            if (a[l] > n1)
            {
                n1 = a[l];
            }
            else
            {
                s = s + (n1 - a[l]);
            }
            l++;
        }
        else
        {
            if (a[h] > n2)
            {
                n2 = a[h];
            }
            else
            {
                s = s + (n2 - a[h]);
            }
            h--;
        }
    }
    cout << "The units of water store is"<< " " << s << endl;
    return 0;
}