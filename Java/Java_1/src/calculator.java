import java.util.Scanner;

public class calculator {
    public static void main(String[] args) {
        @SuppressWarnings("resource")
        Scanner scanner = new Scanner(System.in);
        int x,y;
        String _operator;
        System.err.print("x : ");
        x = Integer.parseInt(scanner.next());
        System.err.print("y : ");
        y = Integer.parseInt(scanner.next());
        System.err.print("operator : ");
        _operator = scanner.next();
      switch (_operator) {
        case "+":
            System.out.println(x+"+"+y+"="+x+y);
            break;
        case "-":
             System.out.println(x+"-"+y+"="+(x-y));
        break;
        case "*":
            System.out.println(x+"*"+y+"="+x*y);
            break;
        case "/":
            System.out.println(x+"/"+y+"="+x/y);
            break; 
        default: 
            System.out.println("error");
            break;
      }
    }
}
