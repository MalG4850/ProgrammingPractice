#include <iostream>

int main(void) {
    int age = 15;
    try { if (age < 18) throw age; }
    catch (int age) { std::cout << "Access denied. Age is " << age << " but needed is 18."; }
    return 0;
}
