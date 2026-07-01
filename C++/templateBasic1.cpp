#include <iostream>

template <typename T> // Wrote a template T; T can be anything, int, float, string, you name it.
void swapValues(T& a, T& b) { // Passed values by reference, using the & instead of passing copies. Saves Memory.
    T temp = std::move(a); // Used std::move() instead of directly copy-pasting, which moves ownership; larger values shouldn't be copy-pasted.
    a = std::move(b);
    b = std::move(temp);
}

int main(void) {
    int x = 3, y = 5;
    swapValues<int>(x, y);
    std::cout << "Now x is " << x << " and y is " << y;

    std::string s1 = "Hello ", s2 = "World ";
    swapValues<std::string>(s1, s2);
    std::cout << "\n" << s1 << s2;

    return 0;
}
