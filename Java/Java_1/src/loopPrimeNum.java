import java.util.Scanner;

public class loopPrimeNum {
    public static void main(String[] args) {
        int num = 0;
        @SuppressWarnings("resource")
        Scanner scanner = new Scanner(System.in);
        System.err.print("enter loop interation :");
        num = Integer.parseInt(scanner.next());
        for(int i = 0; i < num ; i++){
            if (i%2==1){
                System.out.print(i+",");
            }
        }
    }
}
