import java.util.Scanner;

public class odd_even {
    public static void main(String[] args) {
     @SuppressWarnings("resource")
        Scanner scanner = new Scanner(System.in);
        int num;
        System.out.println("Hello, World!");
        System.err.print("enter number :");
        num = Integer.parseInt(scanner.next());
        System.out.println("Your number " + num);
        if (num % 2 == 0){
            System.out.println("num is even");
        }else{
            System.out.println("numb is odd");
        }
    }
}
