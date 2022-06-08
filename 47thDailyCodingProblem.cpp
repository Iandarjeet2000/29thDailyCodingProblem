/*Given a array of numbers representing the stock prices of a company in chronological order, write a function that calculates the maximum profit you could have made from buying and selling that stock once. You must buy before you can sell it.

For example, given [9, 11, 8, 5, 7, 10], you should return 5, since you could buy the stock at 5 dollars and sell it at 10 dollars.*/

#include <bits/stdc++.h>
using namespace std;

int maxProfit(int price[], int size)
{
 
    int maxprofit=0;
    int minSofar=price[0];
    for(int i=0;i<size;i++){
        minSofar=min(minSofar,price[i]);
        int profit=price[i]-minSofar;
        maxprofit=max(profit,maxprofit);
    }
    return maxprofit;
}
 
// Driver code
int main()
{
    int price[] = { 9, 11, 8, 5, 7, 10 };
    int n = sizeof(price) / sizeof(price[0]);
 
    cout << maxProfit(price,n);
 
    return 0;
}