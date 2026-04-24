#include <iostream>

class InsufficientFunds {
    private:
        double neededAmount;

    public:
        InsufficientFunds(double d) {
            neededAmount = d;
        }

        double getShortfall() const { return neededAmount; }
};

class BankAccount {
    protected:
        double balance;

    public:
        BankAccount(double m) {
            balance = m;
        }

        void withdraw(double amount) {
            if (amount > balance) throw InsufficientFunds(amount-balance);
            balance -= amount;
            std::cout << "Withdrawal Successful!\nRemaining Balance: " << balance << "\n\n";
        }
};

int main(void) {
    BankAccount A1(500);

    try {
        std::cout << "Attempting to withdraw 1000.....\n\n";
        A1.withdraw(1000);
    }
    catch (InsufficientFunds& e) {
        std::cout << "Error: You need " << e.getShortfall() << " more in your account!\n\n";
    }
}
