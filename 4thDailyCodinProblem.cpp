/* 4th-Given an array of integers, find the first missing positive integer in linear time and constant space. In other words, find the lowest positive integer that does not exist in the array. The array can contain duplicates and negative numbers as well.

For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.*/


#include <bits/stdc++.h>
using namespace std;

int firstMissingPositive(int arr[], int n)
{
	int ptr = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == 1) {
			ptr = 1;
			break;
		}
	}
	if (ptr == 0)
		return 1;
	for (int i = 0; i < n; i++)
		if (arr[i] <= 0 || arr[i] > n)
			arr[i] = 1;
	for (int i = 0; i < n; i++)
		arr[(arr[i] - 1) % n] += n;
	for (int i = 0; i < n; i++)
		if (arr[i] <= n)
			return i + 1;
	return n + 1;
}

int main()
{
	int arr[] = { 2, 3, -7, 6, 8, 1, -10, 15 };
	int n = sizeof(arr) / sizeof(arr[0]);

	int ans = firstMissingPositive(arr, n);

	cout << ans;

	return 0;
}