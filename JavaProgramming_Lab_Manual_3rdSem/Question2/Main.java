import java.util.Scanner;

class Solution {

    // Function to multiply two matrices
    static void matProduct(int[][] A, int[][] B, int m, int n, int p) {
        int[][] C = new int[m][p];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < p; j++) {
                for (int k = 0; k < n; k++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }

        System.out.println("\nProduct Matrix:");
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < p; j++) {
                System.out.print(C[i][j] + " ");
            }
            System.out.println();
        }
    }

    // Function to find transpose and diagonal sums
    static void transposeAndDiagonalSum(int[][] A, int n) {
        int[][] T = new int[n][n];
        int primary = 0, secondary = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                T[j][i] = A[i][j];
            }

            primary += A[i][i];
            secondary += A[i][n - 1 - i];
        }

        System.out.println("\nTranspose Matrix:");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(T[i][j] + " ");
            }
            System.out.println();
        }

        System.out.println("Principal Diagonal Sum: " + primary);
        System.out.println("Secondary Diagonal Sum: " + secondary);
        System.out.println("Total Diagonal Sum: " + (primary + secondary));
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter m, n and p: ");
        int m = sc.nextInt();
        int n = sc.nextInt();
        int p = sc.nextInt();

        int[][] A = new int[m][n];
        int[][] B = new int[n][p];

        System.out.println("Enter elements of Matrix A:");
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                A[i][j] = sc.nextInt();

        System.out.println("Enter elements of Matrix B:");
        for (int i = 0; i < n; i++)
            for (int j = 0; j < p; j++)
                B[i][j] = sc.nextInt();

        Solution.matProduct(A, B, m, n, p);

        if (m == n) {
            Solution.transposeAndDiagonalSum(A, n);
        } else {
            System.out.println("\nTranspose and diagonal sum require a square matrix.");
        }

        sc.close();
    }
}