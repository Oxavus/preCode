import java.util.*;
public class App {
    public static void main(String[] args) throws Exception {
        @SuppressWarnings("resource")
        Scanner scanner = new Scanner(System.in);
        int age;
        System.out.println("Hello, World!");
        System.err.print("enter you age :");
        age = Integer.parseInt(scanner.next());
        System.out.println("Your age is " + age);
        if (age >= 18){
            System.out.println("you can vote");
        }else if (age < 18){
            System.out.println("you can't vote");
        }else{
            System.out.println("invaled input !");
        }
     
    }
}
