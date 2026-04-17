#include <chrono>
#include <cmath>
#include <iostream>
#include <thread>
#include <vector>

int main(void) {
    const int width = 40;
    const int height = 40;

    float angle = 0.0f;

    while(1) {
        std::vector<std::string> canvas(height, std::string (width, ' '));

        // Center of the screen
        // Radius of 7 characters is used
        int x = (width / 2) + (int)(15 * cos(angle));
        int y = (height / 2) + (int)(7 * sin(angle));

        //Placing character on the canvas
        if (x >= 0 && x < width && y >= 0 && y < height)
            canvas[y][x] = '*';

        //Teleporting the cursor to the top left
        std::cout << "\x1b[H";

        for (int i = 0; i < height; i++) {
            std::cout << canvas[i] << "\n";
        }

        angle += 0.1f;
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    return 0;
}
