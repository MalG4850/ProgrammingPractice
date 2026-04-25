#include <iostream>

class OverheatException {
    private:
        int temperature;

    public:
        OverheatException(int t) { temperature = t; }
        void getTemp() { std::cout << "Current Temperature: " << temperature; }
};

int main(void) {
    int currentTemp = 110;

    try { if (currentTemp > 100) throw OverheatException(currentTemp); }

    catch (OverheatException& e) { std::cout << "Alert! System has shut down at " << currentTemp << " degrees."; }

    catch (int& e) { std::cout << "Alert! This is an integer error."; }

    catch (...) { std::cout << "Alert! Generic error detected."; }

    return 0;
}
