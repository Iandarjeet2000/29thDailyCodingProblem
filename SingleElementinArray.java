/* Ques-40th:-Given an array of integers where every integer occurs three times except for one integer, which only occurs once, find and return the non-duplicated integer.

For example, given [6, 1, 3, 3, 3, 6, 6], return 1. Given [13, 19, 13, 13], return 19. */

import java.util.*;

public class SingleElementinArray {
    static int singleElement(int[] arr, int N) {

        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < N; i++) {
            if (map.containsKey(arr[i])) {
                map.put(arr[i], map.get(arr[i]) + 1);
            } else {
                map.put(arr[i], 1);
            }
        }
        for (int i = 0; i < N; i++) {
            int occ = map.get(arr[i]);
            if (occ == 1) {
                return arr[i];
            }
        }
        return -1;

    }

    public static void main(String[] args) {
        int a[] = { 12, 1, 12, 3, 12, 1, 1, 2, 3, 2, 2, 3, 7 };
        int n = a.length;
        System.out.println("The element with single "
                + "occurrence is " + singleElement(a, n));
    }

}
