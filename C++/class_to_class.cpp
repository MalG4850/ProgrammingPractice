#include <iostream>

class Dollar {
private:
    float value;

public:
    Dollar(float v) : value(v) {}
    float getValue() const {
        return value;
    }
};

class Euro {
private:
    float value;

public:
    Euro() : value(0.0) {}
    Euro(float v) : value(v) {}

    Euro(const Dollar& d) {
        value = d.getValue() * 0.85f;
    }

    void display() const {
        std::cout << "Euro: " << value << "\n\n";
    }
};


int main() {
    Dollar myDollar(100.0);

    Euro myEuro = myDollar;

    myEuro.display();

    return 0;
}
