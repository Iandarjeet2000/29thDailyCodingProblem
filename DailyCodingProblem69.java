/*Ques-69:-Given a list of integers, return the largest product that can be made by multiplying any three integers.

For example, if the list is [-10, -10, 5, 2], we should return 500, since that's -10 * -10 * 5.

You can assume the list has at least three integers. */

package DailyCodingProblem;

public class DailyCodingProblem69 {
    public static int maxProduct(int[] a,int n){
        if (n < 3)
        return -1;
    int maxA = Integer.MIN_VALUE,
        maxB = Integer.MIN_VALUE,
        maxC = Integer.MIN_VALUE;
    int minA = Integer.MAX_VALUE,
        minB = Integer.MAX_VALUE;
   
    for(int i = 0; i < n; i++)
    {
        if (a[i] > maxA)
        {
            maxC = maxB;
            maxB = maxA;
            maxA = a[i];
        }
        else if (a[i] > maxB)
        {
            maxC = maxB;
            maxB = a[i];
        }
        else if (a[i] > maxC)
            maxC = a[i];
        if (a[i] < minA)
        {
            minB = minA;
            minA = a[i];
        }
        else if(a[i] < minB)
            minB = a[i];
    }
   
    return Math.max(minA * minB * maxA,
                    maxA * maxB * maxC);
}
public static void main(String[] args)
{
    int []arr = {-10,-10,5,2};
    int n = arr.length;
   
    int max = maxProduct(arr, n);
   
    if (max == -1)
        System.out.print("No Triplet Exists");
    else
        System.out.print("Maximum product is " + max);
}
}; 


    

