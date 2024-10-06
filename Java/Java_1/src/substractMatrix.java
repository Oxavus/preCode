
public class substractMatrix {
    public static void main(String[] args) {
        int[][] A = { { 3, 2 }, 
                      { 3, 1 } };
        int[][] B = { { 1, 2 }, 
                      { 3, 1 } };
        int[][] result = new int[2][2];

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                result[i][j] = A[i][j] - B[i][j];
            }
        }

        System.out.println("subtract Matrix:");
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                System.out.print(result[i][j] + " ");
            }
            System.out.println();
        }
    }

}