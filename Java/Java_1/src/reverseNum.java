import java.util.*;
public class reverseNum {
    public static void main(String[] args) {
      Scanner scanner = new Scanner(System.in);
      int total = 0;
      int num;
         List<Integer> numbers = new ArrayList<>();
         System.out.println("Enter integers (type 'done' to finish)");
        System.err.print("number :");
        while (scanner.hasNextInt()) {
           
            num = Integer.parseInt(scanner.next());
            numbers.add(num);
            total += num;
        }
        scanner.close();
        Collections.reverse(numbers);
        System.out.println("Reversed list: " + numbers);
        System.out.println("Total :" + total);
    }

}