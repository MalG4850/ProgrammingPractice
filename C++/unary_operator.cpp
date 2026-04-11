#include <iostream>

class coordinates {
    private:
        double x, y;

    public:
        coordinates(int x1, int y1): x(x1), y(y1) {}

        void operator - () {
            x = -x;
            y = -y;
        }

        void display() { std::cout << "\nAssigned Coordinates: " << x << ", " << y << "\n\n"; }
};

int main(void) {
    std::cout << "\nThis is a program to overload a unary operator.\n\n";
    double x1, y1;

    std::cout << "Enter the x coordinate: ";
    std::cin >> x1;

    std::cout << "\nEnter the y coordinate: ";
    std::cin >> y1;

    coordinates c(x1, y1);
    c.display();

    -c;
    std::cout << "Now here are the opposite quadrant coordinates:\n";
    c.display();

    return 0;
}
