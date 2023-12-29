
interface Account {
    void deposit(double amount);
    void withdraw(double amount);
    double checkBalance();
}


abstract class AbstractAccount implements Account {
    protected double balance;

    public AbstractAccount(double initialBalance) {
        this.balance = initialBalance;
    }

    @Override
    public void deposit(double amount) {
        balance += amount;
        System.out.println("Deposited: $" + amount);
    }

    @Override
    public void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            System.out.println("Withdrawn: $" + amount);
        } else {
            System.out.println("Insufficient funds. Withdrawal not allowed.");
        }
    }

    @Override
    public double checkBalance() {
        System.out.println("Current Balance: $" + balance);
        return balance;
    }
}


class SavingsAccount extends AbstractAccount {
    private double interestRate;

    public SavingsAccount(double initialBalance, double interestRate) {
        super(initialBalance);
        this.interestRate = interestRate;
    }

    public void addInterest() {
        double interestAmount = balance * interestRate;
        balance += interestAmount;
        System.out.println("Interest added: $" + interestAmount);
    }
}


class CheckingAccount extends AbstractAccount {
    private double overdraftLimit;

    public CheckingAccount(double initialBalance, double overdraftLimit) {
        super(initialBalance);
        this.overdraftLimit = overdraftLimit;
    }

    @Override
    public void withdraw(double amount) {
        if (amount <= balance + overdraftLimit) {
            balance -= amount;
            System.out.println("Withdrawn: $" + amount);
        } else {
            System.out.println("Exceeds overdraft limit. Withdrawal not allowed.");
        }
    }
}


class LoanAccount extends AbstractAccount {
    private double interestRate;

    public LoanAccount(double initialBalance, double interestRate) {
        super(initialBalance);
        this.interestRate = interestRate;
    }

    public void accrueInterest() {
        double interestAmount = balance * interestRate;
        balance += interestAmount;
        System.out.println("Interest accrued: $" + interestAmount);
    }
}


public class BankingApplication {
    public static void main(String[] args) {
        SavingsAccount savingsAccount = new SavingsAccount(1000, 0.05);
        CheckingAccount checkingAccount = new CheckingAccount(1500, 500);
        LoanAccount loanAccount = new LoanAccount(2000, 0.1);

        savingsAccount.deposit(500);
        savingsAccount.addInterest();
        savingsAccount.checkBalance();

        checkingAccount.withdraw(200);
        checkingAccount.checkBalance();

        loanAccount.accrueInterest();
        loanAccount.checkBalance();
    }
}
