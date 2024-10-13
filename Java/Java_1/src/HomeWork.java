class BankAccount{
    String accountNumber;
    String accountHolder;
    double balance;
    
    BankAccount(String accountNumber, String accountHolder){
       this.accountHolder = accountHolder;
       this.accountNumber = accountNumber;
       balance = 0.0; 
    }
    void deposit(double balance){
        this.balance += balance;
    }
    void withdraw(double balance){
        this.balance -= balance;
    }
    double getBalance(){
        return balance;
    }
    String getAccountDetails(int index){
        String details[] = new String[3];
        details[0] = accountNumber;
        details[1] = accountHolder;
        details[2] = String.valueOf(balance);
        return details[index];
    }
}


public class HomeWork {
    public static void main(String[] args) {
        BankAccount account = new BankAccount("89237968716412","Sarun");
        account.deposit(123.123);
        account.withdraw(12.4);
        System.err.println("AccountNumber : "+ account.getAccountDetails(0)+"\nAccountHolder : "+account.getAccountDetails(1)+"\nBalance : "+account.getAccountDetails(2));
    }
    
}