/*Ques-58:->An sorted array of integers was rotated an unknown number of times.

Given such an array, find the index of the element in the array in faster than linear time. If the element doesn't exist in the array, return null.

For example, given the array [13, 18, 25, 2, 8, 10] and the element 8, return 4 (the index of 8 in the array).

You can assume all the integers in the array are unique.

 */

package DailyCodingProblem;

public class DailyCodingProblem58 {
    public static int search(int a[], int l, int h, int key) {
        while (l <= h) {
            int m = (l + h) / 2;
            if (a[m] == key) {
                return m;
            } else if (a[l] <= a[m]) {
                // left part is sorted ...a[l]<=key<=a[m]
                if (a[l] <= key && key <= a[m]) {
                    h = m - 1;
                } else
                    l = m + 1;
            } else {
                // right part is sorted...a[m]<=key<=a[h]
                if (a[m] <= key && key <= a[h]) {
                    l = m + 1;
                } else
                    h = m - 1;
            }
        }
        return -1;
    }

    public static void main(String args[]) {
        int arr1[] = { 5, 6, 7, 8, 9, 10, 1, 2, 3 };
        int n = arr1.length - 1;
        int l = 0;
        int key = 5;
        System.out.println("Index of the element is : "
                + search(arr1, l, n, key));
    }

}
