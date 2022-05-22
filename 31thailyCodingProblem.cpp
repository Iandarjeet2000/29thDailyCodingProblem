#include<bits/stdc++.h>
using namespace std;

int min(int x, int y, int z)
{
    return min(min(x, y), z);
}

int distance(string s1, string s2, int n1, int n2)
{
    int ld[n1+1][n2+1];

    for (int i=0; i<=n1; i++)
    {
        for (int j=0; j<=n2; j++)
        {
            if (i==0)
                ld[i][j] = j;

            else if (j==0)
                ld[i][j] = i;


            else if (s1[i-1] == s2[j-1])
                ld[i][j] = ld[i-1][j-1];

            else
                ld[i][j] = 1 + min(ld[i][j-1], ld[i-1][j], ld[i-1][j-1]);
        }
    }

    return ld[n1][n2];
}

int main()
{
    string str1,str2;
    cout << "Enter the strings" <<endl;
    cin >> str1 >> str2;
    
    cout <<distance(str1, str2, str1.length(), str2.length());

    return 0;
}