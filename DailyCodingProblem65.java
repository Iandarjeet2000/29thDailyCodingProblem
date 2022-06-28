package DailyCodingProblem;

public class DailyCodingProblem65 {
    static void clockwisePrint(int m, int n, int a[][])
    {
        int i, b = 0, c = 0;
  
        while (b < m && c< n) {
            for (i = b; i < n; ++i) {
                System.out.print(a[b][i] + " ");
            }
            b++;
            for (i = b; i < m; ++i) {
                System.out.print(a[i][n - 1] + " ");
            }
            n--;
            if (b < m) {
                for (i = n - 1; i >= c; --i) {
                    System.out.print(a[m - 1][i] + " ");
                }
                m--;
            }
            if (c < n) {
                for (i = m - 1; i >= b; --i) {
                    System.out.print(a[i][c] + " ");
                }
                c++;
            }
        }
    }
    public static void main(String[] args)
    {
        int R = 4;
        int C = 4;
        // int a[][] =  {{1, 2, 3, 4},
        //            {5, 6, 7, 8},
        //            {9, 10, 11, 12},
        //            {13, 14, 15, 16}};
        int a[][]={{1,  2,  3,  4,  5},
        {6,  7,  8,  9,  10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20}};
        clockwisePrint(R, C, a);
    }
    
}
