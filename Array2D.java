import java.util.Scanner;

public class Array2D {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter rows and columns: ");
        int rows = sc.nextInt();
        int cols = sc.nextInt();

        int[][] arr = new int[rows][cols];

        System.out.println("Enter elements:");
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                arr[i][j] = sc.nextInt();

        System.out.println("\n2D Array:");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                System.out.print(arr[i][j] + "\t");
            System.out.println();
        }

        int sum = 0;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                sum += arr[i][j];
        System.out.println("\nSum of all elements: " + sum);

        System.out.println("\nTranspose:");
        for (int j = 0; j < cols; j++) {
            for (int i = 0; i < rows; i++)
                System.out.print(arr[i][j] + "\t");
            System.out.println();
        }
        sc.close();
    }
}
