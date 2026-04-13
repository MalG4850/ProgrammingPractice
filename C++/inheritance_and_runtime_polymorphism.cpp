#include <iostream>

class Payment {
    protected:
        float amount;

    public:
        Payment() { amount = 0; }
        virtual void processPayment() { std::cout << "Processing a payment of ₹" << amount; }
};

class creditCardPayment: public Payment {
    private:
        float fee = 0.1 * amount;

    public:
        creditCardPayment(double a) {
            amount = a;
            fee = 0.1 * a;
        };
        void processPayment() override { std::cout << "Processing Credit Card payment.\nTotal with fee: ₹" << amount + fee; }
};

int main(void) {
    creditCardPayment c1(15000);
    Payment* p1 = &c1;
    p1 -> processPayment();

    return 0;
}
