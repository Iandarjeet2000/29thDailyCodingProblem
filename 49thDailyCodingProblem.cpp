/* Ques-49:-Given an array of numbers, find the maximum sum of any contiguous subarray of the array.

For example, given the array [34, -50, 42, 14, -5, 86], the maximum sum would be 137, since we would take elements 42, 14, -5, and 86.

Given the array [-5, -1, -8, -9], the maximum sum would be 0, since we would not take any elements.

Do this in O(N) time.*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int c=0;
    for(int i=0;i<n;i++){
        if(arr[i]<0){
            c++;
        }
    }
    if(c==n){
        cout<<0;
    }
    else{
    int max=INT_MIN;
    int max_till_now=0;
    for(int i=0;i<n;i++){
        max_till_now=max_till_now+arr[i];
        if(max_till_now > max){
            max=max_till_now;
        }
        if(max_till_now<0){
            max_till_now=0;
        }
    }
    cout<<max;}
    return 0;

}